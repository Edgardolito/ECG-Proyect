/*
 * Monitor de Salud del Paciente (Versión Renovada)
 *
 * I2C (SDA=21, SCL=22): BME280 @0x76, ADS1115 @0x48
 * ADS1115 AIN0: AD8232 ECG (250 SPS, sin bloqueo por canal NTC)
 * ECG_SDN -> D5, LO+ -> D18, LO- -> D19
 * Soporta mDNS (http://medmonitor.local), reconexión WiFi automática,
 * filtro digital pasa-bajos/Notch 60 Hz conmutable, cálculo de intervalo R-R y HRV (RMSSD).
 */
 
#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Wire.h>
#include <math.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "dashboard_page.h"
 
// Cambia estos valores por el nombre y la contraseña de tu red WiFi
const char* WIFI_SSID = "Arevalo";
const char* WIFI_PASSWORD = "wear2001";
const char* MDNS_HOSTNAME = "medmonitor";
 
static const int I2C_SDA_PIN = 21;
static const int I2C_SCL_PIN = 22;
static const int ECG_SDN_PIN = 5;
static const int LO_PLUS_PIN = 18;
static const int LO_MINUS_PIN = 19;
 
static const uint8_t ECG_CHANNEL = 0;
static const uint8_t ADS1115_I2C_ADDR = 0x48;
static const uint8_t BME280_I2C_ADDR = 0x76;
 
static const uint16_t SAMPLE_INTERVAL_MS = 8;     // ~125 Hz de muestreo ECG
static const uint16_t SLOW_SENSOR_MS = 2000;      // Lectura ambiental cada 2 s
static const uint16_t WIFI_CHECK_MS = 10000;      // Verificación de reconexión WiFi cada 10 s
// 128 muestras = ~1 s de margen: evita huecos en la señal cuando se ve por Internet (latencia alta)
static const uint8_t ECG_QUEUE_SIZE = 128;
static const uint8_t RR_HISTORY_SIZE = 8;
 
WebServer server(80);
Adafruit_ADS1115 ads;
Adafruit_BME280 bme;
 
bool bmeOk = false;
bool mdnsOk = false;
 
unsigned long lastSampleMs = 0;
unsigned long lastSlowMs = 0;
unsigned long lastDebugMs = 0;
unsigned long lastWiFiCheckMs = 0;
 
int lastEcgValue = 512;
int lastRawAdc = 0;
float lastVoltage = 0.0f;
bool lastLeadsOff = true;
int lastLoPlus = 0;
int lastLoMinus = 0;
 
// Estado del filtro digital de ECG (activado por defecto)
bool digitalFilterEnabled = true;
float ecgFilteredState = 512.0f;
int ecgPrevSample1 = 512;
int ecgPrevSample2 = 512;
 
int ecgQueue[ECG_QUEUE_SIZE];
volatile uint8_t ecgQWrite = 0;
volatile uint8_t ecgQRead = 0;
 
int ecgBpm = -1;
int lastRRMs = 0;
int ecgHrvMs = 0;
uint16_t rrHistory[RR_HISTORY_SIZE];
uint8_t rrHistCount = 0;
uint8_t rrHistIndex = 0;
 
int32_t ecgBaseline = 512;
int ecgSignalLevel = 0;
bool ecgBeatArmed = true;
unsigned long lastRPeakMs = 0;
 
float roomTempC = 0.0f;
float roomHumidity = 0.0f;
 
char jsonBuffer[1024];  // Cabe la cola completa de ECG (128 muestras x hasta 5 caracteres) + campos extra
 
bool leadsOff() {
  lastLoPlus = digitalRead(LO_PLUS_PIN);
  lastLoMinus = digitalRead(LO_MINUS_PIN);
  return (lastLoPlus == HIGH) || (lastLoMinus == HIGH);
}
 
int readEcgValue() {
  lastRawAdc = ads.readADC_SingleEnded(ECG_CHANNEL);
  lastVoltage = ads.computeVolts(lastRawAdc);
  int mapped = map(lastRawAdc, 0, 32767, 0, 1023);
  return constrain(mapped, 0, 1023);
}
 
// Filtro digital ligero para atenuar ruido de 60 Hz (a 125 Hz de muestreo) y centrar la línea base
int applyEcgFilter(int rawSample) {
  if (!digitalFilterEnabled) {
    ecgPrevSample2 = ecgPrevSample1;
    ecgPrevSample1 = rawSample;
    ecgFilteredState = (float)rawSample;
    return rawSample;
  }
  // Promedio ponderado de 3 muestras (atenúa fuertemente cerca de Nyquist / 60 Hz conservando el pico R)
  float notchApprox = (0.25f * (float)ecgPrevSample2) + (0.50f * (float)ecgPrevSample1) + (0.25f * (float)rawSample);
  ecgPrevSample2 = ecgPrevSample1;
  ecgPrevSample1 = rawSample;
 
  // Suavizado IIR rápido
  ecgFilteredState = (0.75f * notchApprox) + (0.25f * ecgFilteredState);
  return constrain((int)(ecgFilteredState + 0.5f), 0, 1023);
}
 
void ecgQueueClear() {
  ecgQRead = 0;
  ecgQWrite = 0;
}
 
void ecgQueuePush(int value) {
  const uint8_t next = (uint8_t)((ecgQWrite + 1) % ECG_QUEUE_SIZE);
  if (next == ecgQRead) {
    ecgQRead = (uint8_t)((ecgQRead + 1) % ECG_QUEUE_SIZE);
  }
  ecgQueue[ecgQWrite] = value;
  ecgQWrite = next;
}
 
uint8_t ecgQueueDrain(int* out, uint8_t maxOut) {
  uint8_t count = 0;
  while (ecgQRead != ecgQWrite && count < maxOut) {
    out[count++] = ecgQueue[ecgQRead];
    ecgQRead = (uint8_t)((ecgQRead + 1) % ECG_QUEUE_SIZE);
  }
  return count;
}
 
void resetEcgBpm() {
  ecgBpm = -1;
  lastRRMs = 0;
  ecgHrvMs = 0;
  rrHistCount = 0;
  rrHistIndex = 0;
  ecgBaseline = 512;
  ecgSignalLevel = 0;
  ecgBeatArmed = true;
  lastRPeakMs = 0;
  ecgFilteredState = 512.0f;
  ecgPrevSample1 = 512;
  ecgPrevSample2 = 512;
  ecgQueueClear();
}
 
// Calcula RMSSD (raíz cuadrada de la media de diferencias sucesivas al cuadrado) en ms
void recordRRInterval(uint16_t rrMs) {
  lastRRMs = (int)rrMs;
  rrHistory[rrHistIndex] = rrMs;
  rrHistIndex = (uint8_t)((rrHistIndex + 1) % RR_HISTORY_SIZE);
  if (rrHistCount < RR_HISTORY_SIZE) {
    rrHistCount++;
  }
 
  if (rrHistCount >= 2) {
    uint32_t sumSqDiff = 0;
    uint8_t pairs = rrHistCount - 1;
    // Recorrer en orden cronológico
    uint8_t oldest = (rrHistCount == RR_HISTORY_SIZE) ? rrHistIndex : 0;
    for (uint8_t i = 0; i < pairs; i++) {
      uint8_t idxA = (uint8_t)((oldest + i) % RR_HISTORY_SIZE);
      uint8_t idxB = (uint8_t)((oldest + i + 1) % RR_HISTORY_SIZE);
      int32_t diff = (int32_t)rrHistory[idxB] - (int32_t)rrHistory[idxA];
      sumSqDiff += (uint32_t)(diff * diff);
    }
    ecgHrvMs = (int)(sqrtf((float)sumSqDiff / (float)pairs) + 0.5f);
  }
}
 
void updateEcgBpm(int sample) {
  ecgBaseline = (ecgBaseline * 995 + sample * 5) / 1000;
  const int hp = abs(sample - (int)ecgBaseline);
 
  ecgSignalLevel = (ecgSignalLevel * 127 + hp) / 128;
  const int threshold = max(18, (ecgSignalLevel * 3) / 2);
 
  const unsigned long now = millis();
  // Periodo refractario mínimo de 260 ms para evitar doble conteo por onda T
  if (hp > threshold && ecgBeatArmed && (lastRPeakMs == 0 || (now - lastRPeakMs) >= 260)) {
    if (lastRPeakMs > 0) {
      const unsigned long interval = now - lastRPeakMs;
      if (interval >= 300 && interval <= 2000) {
        recordRRInterval((uint16_t)interval);
        const int bpm = (int)(60000UL / interval);
        ecgBpm = (ecgBpm < 0) ? bpm : ((ecgBpm * 3) + bpm) / 4;
      }
    }
    lastRPeakMs = now;
    ecgBeatArmed = false;
  } else if (hp < threshold / 3) {
    ecgBeatArmed = true;
  }
 
  // Si pasan más de 3 segundos sin detectar pulso, reiniciar BPM a espera
  if (lastRPeakMs > 0 && (now - lastRPeakMs) > 3200) {
    ecgBpm = -1;
    lastRRMs = 0;
  }
}
 
void updateEcgSample() {
  const unsigned long now = millis();
  if (now - lastSampleMs < SAMPLE_INTERVAL_MS) {
    return;
  }
  lastSampleMs = now;
 
  lastLeadsOff = leadsOff();
  if (lastLeadsOff) {
    resetEcgBpm();
    lastEcgValue = 512;
    ecgQueuePush(512);
  } else {
    const int rawVal = readEcgValue();
    lastEcgValue = applyEcgFilter(rawVal);
    ecgQueuePush(lastEcgValue);
    updateEcgBpm(lastEcgValue);
  }
}
 
void updateSlowSensors() {
  const unsigned long now = millis();
  if (now - lastSlowMs < SLOW_SENSOR_MS) {
    return;
  }
  lastSlowMs = now;
 
  if (bmeOk) {
    roomTempC = bme.readTemperature();
    roomHumidity = bme.readHumidity();
  }
 
  if (now - lastDebugMs >= 2000) {
    lastDebugMs = now;
    Serial.printf(
      "Ambiente: %.1f C  Humedad: %.1f%%  Filtro60Hz: %s\n",
      roomTempC, roomHumidity, digitalFilterEnabled ? "ON" : "OFF"
    );
    Serial.printf(
      "ECG plot=%d  raw=%d  %.3fV  bpm=%d  RR=%dms  HRV=%dms  leads=%s\n",
      lastEcgValue, lastRawAdc, lastVoltage, ecgBpm, lastRRMs, ecgHrvMs, lastLeadsOff ? "OFF" : "ON"
    );
  }
}
 
void checkWiFiConnection() {
  const unsigned long now = millis();
  if (now - lastWiFiCheckMs < WIFI_CHECK_MS) {
    return;
  }
  lastWiFiCheckMs = now;
 
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(F("WiFi desconectado. Intentando reconectar..."));
    WiFi.disconnect();
    WiFi.reconnect();
  } else if (!mdnsOk) {
    if (MDNS.begin(MDNS_HOSTNAME)) {
      MDNS.addService("http", "tcp", 80);
      mdnsOk = true;
      Serial.printf("mDNS activo: http://%s.local\n", MDNS_HOSTNAME);
    }
  }
}
 
void handleRoot() {
  server.send_P(200, "text/html", DASHBOARD_PAGE);
}
 
void handleEcgApi() {
  int samples[ECG_QUEUE_SIZE];
  uint8_t count = ecgQueueDrain(samples, ECG_QUEUE_SIZE);
  if (count == 0) {
    samples[0] = lastEcgValue;
    count = 1;
  }
 
  char* p = jsonBuffer;
  int rem = (int)sizeof(jsonBuffer);
  int n = snprintf(p, rem, "{\"v\":[");
  p += n;
  rem -= n;
 
  for (uint8_t i = 0; i < count && rem > 16; i++) {
    if (i > 0) {
      *p++ = ',';
      rem--;
    }
    n = snprintf(p, rem, "%d", samples[i]);
    p += n;
    rem -= n;
  }
 
  snprintf(
    p, rem,
    "],\"lo\":%d,\"raw\":%d,\"mv\":%d,\"lp\":%d,\"lm\":%d,\"bpm\":%d,\"rr\":%d,\"hrv\":%d,\"flt\":%d}",
    lastLeadsOff ? 1 : 0,
    lastRawAdc,
    (int)(lastVoltage * 1000.0f),
    lastLoPlus,
    lastLoMinus,
    ecgBpm,
    lastRRMs,
    ecgHrvMs,
    digitalFilterEnabled ? 1 : 0
  );
 
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "application/json", jsonBuffer);
}
 
void handleVitalsApi() {
  snprintf(
    jsonBuffer, sizeof(jsonBuffer),
    "{\"roomT\":%.1f,\"hum\":%.1f,\"bme\":%d}",
    roomTempC,
    roomHumidity,
    bmeOk ? 1 : 0
  );
 
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "application/json", jsonBuffer);
}
 
void handleFilterApi() {
  if (server.hasArg("on")) {
    digitalFilterEnabled = (server.arg("on").toInt() != 0);
  } else {
    digitalFilterEnabled = !digitalFilterEnabled;
  }
  snprintf(jsonBuffer, sizeof(jsonBuffer), "{\"flt\":%d}", digitalFilterEnabled ? 1 : 0);
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "application/json", jsonBuffer);
}
 
void setupWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.persistent(false);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  Serial.print(F("Conectando a WiFi"));
  uint8_t attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 40) {
    delay(500);
    Serial.print('.');
    attempts++;
  }
  Serial.println();
 
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(F("No se pudo conectar al WiFi inicialmente. Seguira intentando en segundo plano."));
    return;
  }
 
  Serial.print(F("Abrir IP: http://"));
  Serial.println(WiFi.localIP());
 
  if (MDNS.begin(MDNS_HOSTNAME)) {
    MDNS.addService("http", "tcp", 80);
    mdnsOk = true;
    Serial.printf("Abrir mDNS: http://%s.local\n", MDNS_HOSTNAME);
  }
}
 
void setup() {
  Serial.begin(115200);
  delay(500);
 
  pinMode(ECG_SDN_PIN, OUTPUT);
  digitalWrite(ECG_SDN_PIN, HIGH);
  pinMode(LO_PLUS_PIN, INPUT);
  pinMode(LO_MINUS_PIN, INPUT);
 
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
 
  if (!ads.begin(ADS1115_I2C_ADDR)) {
    Serial.println(F("ERROR: ADS1115 no encontrado"));
    while (true) {
      delay(1000);
      yield();
    }
  }
  ads.setGain(GAIN_ONE);
  // 250 SPS reduce a la mitad el tiempo de conversión I2C respecto a 128 SPS, mejorando la fluidez del ECG
  ads.setDataRate(RATE_ADS1115_250SPS);
  Serial.println(F("ADS1115 OK (ECG en AIN0 a 250 SPS)"));
 
  bmeOk = bme.begin(BME280_I2C_ADDR);
  Serial.println(bmeOk ? F("BME280 OK") : F("BME280 no encontrado"));
 
  setupWiFi();
 
  server.on("/", handleRoot);
  server.on("/api/ecg", handleEcgApi);
  server.on("/api/vitals", handleVitalsApi);
  server.on("/api/filter", handleFilterApi);
  server.begin();
 
  Serial.println(F("Monitor de Salud del Paciente listo"));
}
 
void loop() {
  server.handleClient();
  checkWiFiConnection();
 
  if (WiFi.status() == WL_CONNECTED) {
    updateEcgSample();
    updateSlowSensors();
    server.handleClient();
  }
 
  yield();
}
