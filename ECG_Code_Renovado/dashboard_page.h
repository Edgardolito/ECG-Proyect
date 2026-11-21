#ifndef DASHBOARD_PAGE_H
#define DASHBOARD_PAGE_H
 
const char DASHBOARD_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es-MX" data-theme="light">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0, viewport-fit=cover" />
  <title>Monitor de Salud del Paciente</title>
  <link rel="preconnect" href="https://fonts.googleapis.com" />
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
  <link href="https://fonts.googleapis.com/css2?family=Plus+Jakarta+Sans:wght@500;600;700;800&display=swap" rel="stylesheet" />
  <style>
    :root {
      --bg-1: #eef4ff;
      --bg-2: #e8f0fe;
      --sidebar: #0f172a;
      --sidebar-hover: #1e293b;
      --sidebar-active: #2563eb;
      --card: rgba(255,255,255,0.94);
      --card-border: rgba(226,232,240,0.9);
      --text: #0f172a;
      --text-secondary: #475569;
      --muted: #64748b;
      --blue: #2563eb;
      --cyan: #06b6d4;
      --green: #16a34a;
      --red: #ef4444;
      --orange: #f59e0b;
      --green-soft: #dcfce7;
      --red-soft: #fee2e2;
      --orange-soft: #fef3c7;
      --blue-soft: #dbeafe;
      --shadow: 0 20px 50px rgba(15,23,42,0.14);
      --radius: 18px;
      --main-bg-1: #fafbff;
      --main-bg-2: #f1f5f9;
      --page-bg-1: #f0f4fa;
      --page-bg-2: #e8eef6;
      --dash-bg-1: #f8faff;
      --dash-bg-2: #eef2ff;
      --topbar-bg-1: rgba(255,255,255,0.98);
      --topbar-bg-2: rgba(239,246,255,0.98);
      --topbar-border: rgba(148,163,184,0.15);
      --input-bg: #ffffff;
      --input-border: #e2e8f0;
      --table-th-bg: #f1f5f9;
      --table-th-text: #475569;
      --table-even-bg: #fafbfc;
      --table-hover-bg: #eff6ff;
      --table-border: #f1f5f9;
      --btn-sec-bg: #e2e8f0;
    }

    [data-theme="dark"] {
      --bg-1: #060b16;
      --bg-2: #0b1120;
      --card: rgba(30,41,59,0.92);
      --card-border: rgba(51,65,85,0.85);
      --text: #f1f5f9;
      --text-secondary: #cbd5e1;
      --muted: #94a3b8;
      --green-soft: rgba(22,163,74,0.2);
      --red-soft: rgba(239,68,68,0.2);
      --orange-soft: rgba(245,158,11,0.2);
      --blue-soft: rgba(37,99,235,0.22);
      --main-bg-1: #0b1120;
      --main-bg-2: #0f172a;
      --page-bg-1: #0b1120;
      --page-bg-2: #0f172a;
      --dash-bg-1: #0b1120;
      --dash-bg-2: #0f172a;
      --topbar-bg-1: rgba(15,23,42,0.98);
      --topbar-bg-2: rgba(30,41,59,0.98);
      --topbar-border: rgba(51,65,85,0.5);
      --input-bg: #0f172a;
      --input-border: #334155;
      --table-th-bg: #1e293b;
      --table-th-text: #cbd5e1;
      --table-even-bg: rgba(15,23,42,0.45);
      --table-hover-bg: rgba(37,99,235,0.15);
      --table-border: #1e293b;
      --btn-sec-bg: #334155;
    }

    * { margin: 0; padding: 0; box-sizing: border-box; }
    html, body { height: 100%; width: 100%; overflow: hidden; }
    body {
      font-family: "Plus Jakarta Sans", "Segoe UI", system-ui, sans-serif;
      color: var(--text);
      background:
        radial-gradient(circle at 8% 10%, rgba(37,99,235,0.18), transparent 30%),
        radial-gradient(circle at 92% 8%, rgba(6,182,212,0.16), transparent 28%),
        linear-gradient(135deg, var(--bg-1), var(--bg-2));
      display: flex;
      align-items: center;
      justify-content: center;
      padding: 0;
      transition: background 0.25s ease, color 0.25s ease;
    }
    .viewport-wrap {
      aspect-ratio: 15 / 9;
      width: min(100vw, calc(100vh * 15 / 9));
      height: min(100vh, calc(100vw * 9 / 15));
    }
    .app-shell {
      width: 100%;
      height: 100%;
      display: flex;
      border-radius: 0;
      overflow: hidden;
      box-shadow: none;
      border: none;
      background: var(--card);
    }
    .sidebar {
      width: 220px;
      flex-shrink: 0;
      background: linear-gradient(180deg, #0b1224 0%, #111827 55%, #0f172a 100%);
      color: #e2e8f0;
      display: flex;
      flex-direction: column;
      padding: 18px 12px;
      border-right: 1px solid rgba(255,255,255,0.06);
    }
    .sidebar-brand {
      display: flex;
      align-items: center;
      gap: 10px;
      padding: 8px 10px 20px;
      border-bottom: 1px solid rgba(255,255,255,0.08);
      margin-bottom: 14px;
    }
    .sidebar-logo {
      width: 42px; height: 42px; border-radius: 13px;
      background: linear-gradient(135deg, #f43f5e 0%, #e11d48 50%, #be123c 100%);
      display: grid; place-items: center;
      box-shadow: 0 6px 18px rgba(244,63,94,0.45);
      flex-shrink: 0;
    }
    .sidebar-logo svg {
      width: 24px; height: 24px;
      fill: none; stroke: #fff;
      stroke-width: 2.2; stroke-linecap: round; stroke-linejoin: round;
    }
    .sidebar-brand strong {
      display: block; font-size: 0.88rem; letter-spacing: -0.02em;
      background: linear-gradient(90deg, #fff, #fda4af);
      -webkit-background-clip: text; -webkit-text-fill-color: transparent;
      background-clip: text;
    }
    .sidebar-brand span {
      font-size: 0.68rem; color: #94a3b8;
    }
    .nav-label {
      font-size: 0.65rem; text-transform: uppercase;
      letter-spacing: 0.1em; color: #64748b;
      padding: 0 10px; margin-bottom: 8px;
    }
    .nav { flex: 1; display: flex; flex-direction: column; gap: 4px; }
    .nav-item {
      border: none; background: transparent; color: #cbd5e1;
      text-align: left; padding: 10px 12px;
      border-radius: 12px; font-size: 0.82rem; font-weight: 700;
      cursor: pointer; display: flex; align-items: center; gap: 10px;
      transition: background 0.15s, color 0.15s, transform 0.12s;
    }
    .nav-item:hover { background: var(--sidebar-hover); color: #fff; transform: translateX(2px); }
    .nav-item.active {
      background: linear-gradient(90deg, #2563eb, #3b82f6);
      color: #fff;
      box-shadow: 0 8px 22px rgba(37,99,235,0.4);
    }
    .nav-icon-wrap {
      width: 30px; height: 30px; border-radius: 9px;
      display: grid; place-items: center;
      font-size: 14px; flex-shrink: 0;
      background: rgba(255,255,255,0.08);
    }
    .nav-item.active .nav-icon-wrap { background: rgba(255,255,255,0.22); }
    .nav-item[data-page="dashboard"] .nav-icon-wrap { background: rgba(244,63,94,0.2); }
    .nav-item[data-page="patient"] .nav-icon-wrap { background: rgba(59,130,246,0.2); }
    .nav-item[data-page="logging"] .nav-icon-wrap { background: rgba(16,185,129,0.2); }
    .nav-item[data-page="alerts"] .nav-icon-wrap { background: rgba(245,158,11,0.2); }
    .nav-icon { width: auto; text-align: center; opacity: 1; }

    /* Apartado de Apariencia (Modo Oscuro / Claro) en Sidebar */
    .sidebar-theme-box {
      margin: 10px 0;
      padding: 10px;
      border-radius: 12px;
      background: rgba(255,255,255,0.04);
      border: 1px solid rgba(255,255,255,0.08);
    }
    .sidebar-theme-title {
      font-size: 0.63rem;
      text-transform: uppercase;
      letter-spacing: 0.08em;
      color: #94a3b8;
      font-weight: 800;
      margin-bottom: 7px;
      display: flex;
      align-items: center;
      gap: 6px;
    }
    .theme-switch-group {
      display: grid;
      grid-template-columns: 1fr 1fr;
      gap: 4px;
      background: rgba(15,23,42,0.65);
      padding: 3px;
      border-radius: 9px;
    }
    .theme-opt-btn {
      border: none;
      background: transparent;
      color: #94a3b8;
      font-family: inherit;
      font-size: 0.72rem;
      font-weight: 800;
      padding: 6px 4px;
      border-radius: 7px;
      cursor: pointer;
      display: flex;
      align-items: center;
      justify-content: center;
      gap: 4px;
      transition: background 0.15s, color 0.15s;
    }
    .theme-opt-btn:hover { color: #fff; }
    .theme-opt-btn.active {
      background: #2563eb;
      color: #fff;
      box-shadow: 0 2px 8px rgba(37,99,235,0.35);
    }

    .sidebar-foot {
      padding: 12px 10px 4px;
      border-top: 1px solid rgba(255,255,255,0.08);
      font-size: 0.72rem; color: #94a3b8;
    }
    .live-pill {
      display: flex; align-items: center; gap: 7px;
      margin-bottom: 6px; font-weight: 800; color: #e2e8f0;
    }
    .live-dot {
      width: 8px; height: 8px; border-radius: 50%;
      background: var(--green);
      animation: pulse 1.5s infinite;
    }
    .live-dot.off { background: var(--red); animation: none; }
    @keyframes pulse {
      0% { box-shadow: 0 0 0 0 rgba(22,163,74,0.5); }
      75% { box-shadow: 0 0 0 8px rgba(22,163,74,0); }
      100% { box-shadow: 0 0 0 0 rgba(22,163,74,0); }
    }
    .main {
      flex: 1; min-width: 0;
      display: flex; flex-direction: column;
      background: linear-gradient(180deg, var(--main-bg-1), var(--main-bg-2));
    }
    .topbar {
      flex-shrink: 0;
      padding: 10px 16px;
      display: flex; justify-content: space-between; align-items: center;
      gap: 12px;
      border-bottom: 1px solid var(--topbar-border);
      background: linear-gradient(90deg, var(--topbar-bg-1), var(--topbar-bg-2));
    }
    .topbar h1 {
      font-size: 1.12rem; letter-spacing: -0.03em; font-weight: 800;
    }
    .topbar p { font-size: 0.76rem; color: var(--muted); margin-top: 2px; font-weight: 600; }
    .topbar-actions {
      display: flex; align-items: center; gap: 10px;
      flex-shrink: 0;
    }
    .topbar-meta {
      text-align: right; font-size: 0.72rem; color: var(--muted); font-weight: 700;
      padding-left: 12px;
      border-left: 1px solid var(--input-border);
    }
    .topbar-meta strong { display: block; color: var(--text); font-size: 0.86rem; font-weight: 800; }
    .sound-toggle, .theme-toggle {
      width: 36px; height: 36px;
      border-radius: 11px;
      border: 1.5px solid var(--input-border);
      background: var(--input-bg);
      color: var(--muted);
      font-size: 16px; line-height: 1;
      cursor: pointer;
      display: grid; place-items: center;
      transition: background 0.15s, border-color 0.15s, color 0.15s, transform 0.12s;
      flex-shrink: 0;
    }
    .sound-toggle:hover, .theme-toggle:hover { border-color: #3b82f6; color: #3b82f6; }
    .sound-toggle:active, .theme-toggle:active { transform: scale(0.94); }
    .sound-toggle.muted { opacity: 0.55; }
    .sound-toggle:not(.muted) {
      background: var(--blue-soft);
      border-color: #3b82f6;
      color: #3b82f6;
    }
    .sound-toggle svg, .theme-toggle svg {
      width: 18px; height: 18px;
      stroke: currentColor; fill: none;
      stroke-width: 2; stroke-linecap: round; stroke-linejoin: round;
    }
    .sound-toggle .sound-off { display: none; }
    .sound-toggle.muted .sound-on { display: none; }
    .sound-toggle.muted .sound-off { display: block; }

    .theme-toggle .icon-sun { display: none; }
    .theme-toggle .icon-moon { display: block; }
    [data-theme="dark"] .theme-toggle .icon-sun { display: block; color: #fbbf24; }
    [data-theme="dark"] .theme-toggle .icon-moon { display: none; }

    .page-area {
      flex: 1; min-height: 0;
      overflow: hidden; position: relative;
    }
    .page {
      display: none;
      position: absolute;
      inset: 0;
      overflow-y: auto;
      overflow-x: hidden;
      padding: 14px 18px 16px;
      -webkit-overflow-scrolling: touch;
    }
    .page.active {
      display: block;
      z-index: 1;
    }
    #page-patient.page.active {
      display: flex;
      flex-direction: column;
      overflow: hidden;
      padding: 10px 14px 12px;
      background: linear-gradient(180deg, var(--page-bg-1) 0%, var(--page-bg-2) 100%);
    }
    .record-page {
      flex: 1; min-height: 0;
      display: flex; flex-direction: column; gap: 10px;
      overflow: hidden;
    }
    .record-banner {
      flex-shrink: 0;
      position: relative; overflow: hidden;
      border-radius: 18px;
      padding: 0;
    }
    .record-banner-bg {
      position: absolute; inset: 0;
      background: linear-gradient(120deg, #1e3a8a 0%, #2563eb 45%, #0891b2 100%);
    }
    .record-banner-bg::after {
      content: "";
      position: absolute; inset: 0;
      background:
        radial-gradient(circle at 85% 20%, rgba(255,255,255,0.2), transparent 42%),
        radial-gradient(circle at 12% 88%, rgba(255,255,255,0.12), transparent 38%);
    }
    .record-profile {
      position: relative; z-index: 1;
      display: flex; align-items: center; gap: 14px;
      padding: 16px 18px;
      color: #fff;
    }
    .record-avatar-ring {
      padding: 3px;
      border-radius: 20px;
      background: linear-gradient(135deg, rgba(255,255,255,0.95), rgba(255,255,255,0.35));
      flex-shrink: 0;
    }
    .record-profile .patient-avatar {
      width: 68px; height: 68px;
      border-radius: 16px;
      font-size: 1.4rem;
      box-shadow: 0 8px 20px rgba(0,0,0,0.2);
    }
    .record-profile-main { flex: 1; min-width: 0; }
    .record-profile-main h2 {
      margin: 0 0 8px;
      font-size: 1.45rem; font-weight: 900;
      letter-spacing: -0.03em;
      line-height: 1.15;
      word-break: break-word;
    }
    .record-profile .patient-chips {
      display: flex; flex-wrap: wrap; gap: 6px;
    }
    .record-profile .patient-chip {
      font-size: 0.78rem; font-weight: 800;
      padding: 5px 11px;
      border-radius: 999px;
      background: rgba(255,255,255,0.18);
      border: 1px solid rgba(255,255,255,0.35);
      color: #fff;
    }
    .record-profile .patient-chip.loc {
      color: #e0f2fe;
    }
    .record-banner.prev-mode .record-banner-bg {
      background: linear-gradient(120deg, #4c1d95 0%, #6d28d9 48%, #0e7490 100%);
    }
    .record-profile-actions {
      display: flex;
      align-items: center;
      gap: 8px;
      flex-shrink: 0;
      flex-wrap: wrap;
    }
    .btn-glow {
      flex-shrink: 0;
      box-shadow: 0 6px 20px rgba(15,23,42,0.25);
      background: #fff !important;
      color: #1d4ed8 !important;
      font-weight: 900;
      padding: 10px 16px;
      font-size: 0.8rem;
      white-space: nowrap;
    }
    .btn-danger-glow {
      flex-shrink: 0;
      box-shadow: 0 6px 20px rgba(15,23,42,0.22);
      background: rgba(254,226,226,0.96) !important;
      color: #b91c1c !important;
      border: 1px solid rgba(252,165,165,0.9) !important;
      font-weight: 900;
      padding: 10px 14px;
      font-size: 0.78rem;
      white-space: nowrap;
      transition: transform 0.12s, background 0.15s;
    }
    .btn-danger-glow:hover {
      background: #fecaca !important;
      transform: translateY(-1px);
    }
    .prev-patient-bar {
      flex-shrink: 0;
      padding: 11px 16px;
      border-radius: 14px;
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: 12px;
      flex-wrap: wrap;
      background: linear-gradient(90deg, rgba(109,40,217,0.1), rgba(6,182,212,0.08));
      border: 1px solid rgba(109,40,217,0.28);
    }
    [data-theme="dark"] .prev-patient-bar {
      background: linear-gradient(90deg, rgba(109,40,217,0.22), rgba(30,41,59,0.92));
      border-color: rgba(139,92,246,0.42);
    }
    .prev-patient-bar.active-prev {
      background: linear-gradient(90deg, rgba(16,185,129,0.14), rgba(109,40,217,0.1));
      border-color: rgba(16,185,129,0.4);
    }
    .prev-patient-info {
      display: flex;
      align-items: center;
      gap: 10px;
      font-size: 0.8rem;
      font-weight: 800;
      color: var(--text);
    }
    .prev-patient-icon {
      width: 34px;
      height: 34px;
      border-radius: 10px;
      background: rgba(109,40,217,0.14);
      color: #6d28d9;
      display: grid;
      place-items: center;
      font-size: 1rem;
      flex-shrink: 0;
    }
    [data-theme="dark"] .prev-patient-icon {
      background: rgba(139,92,246,0.25);
      color: #c4b5fd;
    }
    .prev-patient-sub {
      font-size: 0.7rem;
      font-weight: 600;
      color: var(--muted);
      display: block;
      margin-top: 2px;
    }
    .prev-patient-actions {
      display: flex;
      align-items: center;
      gap: 8px;
      flex-wrap: wrap;
    }
    .btn-prev-open {
      background: #6d28d9;
      color: #fff;
    }
    .btn-prev-open:hover {
      background: #5b21b6;
    }
    .record-scroll {
      flex: 1; min-height: 0;
      overflow-y: auto;
      overflow-x: hidden;
      -webkit-overflow-scrolling: touch;
      display: flex; flex-direction: column; gap: 10px;
      padding-bottom: 4px;
    }
    .record-section-title {
      font-size: 0.72rem; font-weight: 900;
      text-transform: uppercase; letter-spacing: 0.08em;
      color: var(--muted);
      margin: 0 0 8px 2px;
    }
    .record-stats-row {
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: 8px;
    }
    .record-stat {
      padding: 14px 10px;
      border-radius: 14px;
      text-align: center;
      display: flex; flex-direction: column; align-items: center; gap: 6px;
    }
    .record-stat-icon {
      width: 40px; height: 40px; border-radius: 12px;
      display: grid; place-items: center;
      font-size: 18px;
    }
    .record-stat.rc-age { background: linear-gradient(180deg, #eff6ff, #fff); border: 1px solid #bfdbfe; }
    .record-stat.rc-age .record-stat-icon { background: #dbeafe; }
    .record-stat.rc-gender { background: linear-gradient(180deg, #fdf2f8, #fff); border: 1px solid #fbcfe8; }
    .record-stat.rc-gender .record-stat-icon { background: #fce7f3; }
    .record-stat.rc-blood { background: linear-gradient(180deg, #fef2f2, #fff); border: 1px solid #fecaca; }
    .record-stat.rc-blood .record-stat-icon { background: #fee2e2; }

    [data-theme="dark"] .record-stat.rc-age { background: linear-gradient(180deg, rgba(37,99,235,0.16), rgba(30,41,59,0.9)); border-color: rgba(59,130,246,0.35); }
    [data-theme="dark"] .record-stat.rc-age .record-stat-icon { background: rgba(59,130,246,0.25); }
    [data-theme="dark"] .record-stat.rc-gender { background: linear-gradient(180deg, rgba(219,39,119,0.16), rgba(30,41,59,0.9)); border-color: rgba(236,72,153,0.35); }
    [data-theme="dark"] .record-stat.rc-gender .record-stat-icon { background: rgba(236,72,153,0.25); }
    [data-theme="dark"] .record-stat.rc-blood { background: linear-gradient(180deg, rgba(220,38,38,0.16), rgba(30,41,59,0.9)); border-color: rgba(239,68,68,0.35); }
    [data-theme="dark"] .record-stat.rc-blood .record-stat-icon { background: rgba(239,68,68,0.25); }

    .record-stat-label {
      font-size: 0.65rem; font-weight: 800;
      text-transform: uppercase; letter-spacing: 0.06em;
      color: var(--muted);
    }
    .record-stat-value {
      font-size: 1.05rem; font-weight: 900;
      color: var(--text); line-height: 1.2;
      word-break: break-word;
    }
    .record-contact-row {
      display: grid;
      grid-template-columns: 1fr 1fr;
      gap: 8px;
    }
    .record-detail-card {
      padding: 14px 16px;
      border-radius: 14px;
      display: flex; align-items: center; gap: 12px;
    }
    .record-detail-card.rc-phone {
      background: linear-gradient(135deg, #ecfdf5, #fff);
      border: 1px solid #bbf7d0;
    }
    .record-detail-card.rc-id {
      background: linear-gradient(135deg, #f5f3ff, #fff);
      border: 1px solid #ddd6fe;
    }
    [data-theme="dark"] .record-detail-card.rc-phone {
      background: linear-gradient(135deg, rgba(16,185,129,0.15), rgba(30,41,59,0.9));
      border-color: rgba(16,185,129,0.35);
    }
    [data-theme="dark"] .record-detail-card.rc-id {
      background: linear-gradient(135deg, rgba(124,58,237,0.15), rgba(30,41,59,0.9));
      border-color: rgba(139,92,246,0.35);
    }
    .record-detail-card .field-icon {
      width: 38px; height: 38px; font-size: 16px; border-radius: 11px;
      flex-shrink: 0;
    }
    .record-detail-label {
      font-size: 0.65rem; font-weight: 800;
      text-transform: uppercase; letter-spacing: 0.05em;
      color: var(--muted);
    }
    .record-detail-value {
      font-size: 0.95rem; font-weight: 800;
      color: var(--text); margin-top: 2px;
      word-break: break-word;
    }
    .record-notes-card {
      padding: 14px 16px;
      border-radius: 14px;
      background: linear-gradient(180deg, #fffbeb, #ffffff);
      border: 1px solid #fde68a;
    }
    [data-theme="dark"] .record-notes-card {
      background: linear-gradient(180deg, rgba(245,158,11,0.12), rgba(30,41,59,0.9));
      border-color: rgba(245,158,11,0.35);
    }
    .record-notes-card .record-section-title { margin-bottom: 10px; }
    .record-notes-body {
      padding: 12px 14px;
      background: var(--input-bg);
      border-radius: 10px;
      border: 1px solid var(--input-border);
      font-size: 0.92rem; font-weight: 600;
      color: var(--text-secondary); line-height: 1.55;
      min-height: 88px;
      word-break: break-word;
    }
    #page-logging.page.active,
    #page-alerts.page.active {
      display: flex;
      flex-direction: column;
      overflow: hidden;
      padding: 10px 14px 12px;
      gap: 10px;
      background: linear-gradient(180deg, var(--page-bg-1) 0%, var(--page-bg-2) 100%);
    }
    .logging-page, .alerts-page {
      flex: 1; min-height: 0;
      display: flex; flex-direction: column; gap: 10px;
    }
    .logging-toolbar {
      flex-shrink: 0;
      padding: 14px 16px;
      display: flex; align-items: center; justify-content: space-between;
      gap: 12px; flex-wrap: wrap;
      border-radius: 16px;
    }
    .logging-controls {
      display: flex; align-items: center; gap: 10px; flex-wrap: wrap;
    }
    .logging-controls label {
      font-size: 0.72rem; font-weight: 900;
      text-transform: uppercase; letter-spacing: 0.06em;
      color: var(--muted);
    }
    .logging-controls select {
      padding: 9px 12px; border-radius: 10px;
      border: 1px solid var(--input-border); background: var(--input-bg);
      font-size: 0.85rem; font-weight: 700;
      font-family: inherit; color: var(--text);
    }
    .btn-log { padding: 9px 14px; font-size: 0.78rem; }
    .btn-log-start { background: #16a34a; color: #fff; }
    .btn-log-stop { background: #ef4444; color: #fff; }
    .btn-log-export { background: #2563eb; color: #fff; }
    .logging-stats {
      display: flex; align-items: center; gap: 14px;
      font-size: 0.78rem; font-weight: 800; color: var(--muted);
    }
    .log-status-pill {
      padding: 5px 12px; border-radius: 999px;
      font-size: 0.68rem; font-weight: 900;
      letter-spacing: 0.05em; text-transform: uppercase;
    }
    .log-status-pill.stopped { background: var(--table-th-bg); color: var(--muted); }
    .log-status-pill.running { background: var(--green-soft); color: #22c55e; }
    .logging-table-wrap {
      flex: 1; min-height: 0;
      overflow: hidden;
      border-radius: 16px;
      display: flex; flex-direction: column;
    }
    .logging-table-head {
      flex-shrink: 0;
      padding: 12px 16px;
      border-bottom: 1px solid var(--input-border);
      display: flex; justify-content: space-between; align-items: center;
    }
    .logging-table-head h4 {
      font-size: 0.85rem; font-weight: 900;
      display: flex; align-items: center; gap: 8px;
    }
    .logging-table-scroll {
      flex: 1; min-height: 0; overflow: auto;
      -webkit-overflow-scrolling: touch;
    }
    .log-table {
      width: 100%; border-collapse: collapse;
      font-size: 0.78rem;
    }
    .log-table th {
      position: sticky; top: 0; z-index: 1;
      background: var(--table-th-bg);
      padding: 10px 12px;
      text-align: left; font-weight: 900;
      color: var(--table-th-text); text-transform: uppercase;
      letter-spacing: 0.05em; font-size: 0.68rem;
      border-bottom: 2px solid var(--input-border);
    }
    .log-table td {
      padding: 9px 12px;
      border-bottom: 1px solid var(--table-border);
      font-weight: 600; color: var(--text);
    }
    .log-table tbody tr:nth-child(even) { background: var(--table-even-bg); }
    .log-table tbody tr:hover { background: var(--table-hover-bg); }
    .log-empty {
      padding: 40px; text-align: center;
      color: var(--muted); font-weight: 700; font-size: 0.85rem;
    }
    .alerts-hero {
      flex-shrink: 0;
      padding: 14px 16px;
      display: flex; justify-content: space-between; align-items: center;
      gap: 12px;
      border-radius: 16px;
      background: linear-gradient(120deg, #7f1d1d 0%, #dc2626 40%, #ea580c 100%);
      color: #fff;
      box-shadow: 0 8px 28px rgba(220,38,38,0.25);
    }
    .alerts-hero h3 {
      font-size: 1.05rem; font-weight: 900;
      letter-spacing: -0.02em; margin: 0 0 3px;
      color: #fff;
    }
    .alerts-hero p {
      font-size: 0.72rem; color: rgba(255,255,255,0.85); margin: 0;
      font-weight: 600;
    }
    .alerts-status-badge {
      font-size: 0.68rem; font-weight: 900;
      padding: 8px 14px; border-radius: 999px;
      letter-spacing: 0.06em; text-transform: uppercase;
      flex-shrink: 0;
      background: rgba(255,255,255,0.95);
    }
    .alerts-status-badge.good { color: #16a34a; }
    .alerts-status-badge.watch { color: #b45309; }
    .alerts-status-badge.bad { color: #ef4444; }
    .alerts-summary {
      flex-shrink: 0;
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: 8px;
    }
    .alerts-summary-card {
      padding: 10px 12px;
      border-radius: 12px;
      text-align: center;
      font-size: 0.65rem; font-weight: 800;
      text-transform: uppercase; letter-spacing: 0.05em;
    }
    .alerts-summary-card span {
      display: block;
      font-size: 1.35rem; font-weight: 1000;
      letter-spacing: -0.04em;
      margin-bottom: 2px;
    }
    .alerts-summary-card.warn { background: #fff7ed; border: 1px solid #fdba74; color: #c2410c; }
    .alerts-summary-card.warn span { color: #ea580c; }
    .alerts-summary-card.ok { background: #f0fdf4; border: 1px solid #86efac; color: #15803d; }
    .alerts-summary-card.ok span { color: #16a34a; }
    .alerts-summary-card.info { background: #eff6ff; border: 1px solid #93c5fd; color: #1d4ed8; }
    .alerts-summary-card.info span { color: #2563eb; }

    [data-theme="dark"] .alerts-summary-card.warn { background: rgba(234,88,12,0.15); border-color: rgba(249,115,22,0.4); color: #fdba74; }
    [data-theme="dark"] .alerts-summary-card.warn span { color: #fb923c; }
    [data-theme="dark"] .alerts-summary-card.ok { background: rgba(22,163,74,0.15); border-color: rgba(34,197,94,0.4); color: #86efac; }
    [data-theme="dark"] .alerts-summary-card.ok span { color: #4ade80; }
    [data-theme="dark"] .alerts-summary-card.info { background: rgba(37,99,235,0.15); border-color: rgba(59,130,246,0.4); color: #93c5fd; }
    [data-theme="dark"] .alerts-summary-card.info span { color: #60a5fa; }

    .alerts-scroll {
      flex: 1; min-height: 0;
      overflow-y: auto;
      overflow-x: hidden;
      -webkit-overflow-scrolling: touch;
      display: flex; flex-direction: column; gap: 12px;
      padding-bottom: 4px;
    }
    .alerts-section-title {
      font-size: 0.7rem; font-weight: 900;
      text-transform: uppercase; letter-spacing: 0.08em;
      color: var(--muted);
      margin: 0 0 8px 2px;
      display: flex; align-items: center; gap: 6px;
    }
    .alert-row {
      display: flex; gap: 12px; align-items: flex-start;
      padding: 12px 14px;
      border-radius: 14px;
      margin-bottom: 8px;
      border: 1px solid var(--card-border);
      background: var(--card);
      transition: box-shadow 0.15s;
    }
    .alert-row:last-child { margin-bottom: 0; }
    .alert-row.alert-ok { border-left: 4px solid #22c55e; background: linear-gradient(90deg, #f0fdf4, #fff); }
    .alert-row.alert-warn { border-left: 4px solid #f59e0b; background: linear-gradient(90deg, #fffbeb, #fff); }
    .alert-row.alert-bad { border-left: 4px solid #ef4444; background: linear-gradient(90deg, #fef2f2, #fff); }
    .alert-row.alert-info { border-left: 4px solid #3b82f6; background: linear-gradient(90deg, #eff6ff, #fff); }

    [data-theme="dark"] .alert-row.alert-ok { background: linear-gradient(90deg, rgba(22,163,74,0.15), rgba(30,41,59,0.95)); }
    [data-theme="dark"] .alert-row.alert-warn { background: linear-gradient(90deg, rgba(245,158,11,0.15), rgba(30,41,59,0.95)); }
    [data-theme="dark"] .alert-row.alert-bad { background: linear-gradient(90deg, rgba(239,68,68,0.15), rgba(30,41,59,0.95)); }
    [data-theme="dark"] .alert-row.alert-info { background: linear-gradient(90deg, rgba(59,130,246,0.15), rgba(30,41,59,0.95)); }

    .alert-row-icon {
      width: 42px; height: 42px; flex-shrink: 0;
      border-radius: 12px;
      display: grid; place-items: center;
      font-size: 20px;
    }
    .alert-row.alert-ok .alert-row-icon { background: var(--green-soft); }
    .alert-row.alert-warn .alert-row-icon { background: var(--orange-soft); }
    .alert-row.alert-bad .alert-row-icon { background: var(--red-soft); }
    .alert-row.alert-info .alert-row-icon { background: var(--blue-soft); }
    .alert-row-body { flex: 1; min-width: 0; }
    .alert-row-top {
      display: flex; align-items: flex-start; justify-content: space-between;
      gap: 8px; margin-bottom: 4px;
    }
    .alert-row-top strong {
      font-size: 0.88rem; color: var(--text); line-height: 1.3;
    }
    .alert-pill {
      flex-shrink: 0;
      font-size: 0.58rem; font-weight: 900;
      padding: 3px 8px; border-radius: 999px;
      letter-spacing: 0.05em; text-transform: uppercase;
    }
    .alert-pill.ok { background: var(--green-soft); color: #22c55e; }
    .alert-pill.warn { background: var(--orange-soft); color: #f59e0b; }
    .alert-pill.bad { background: var(--red-soft); color: #ef4444; }
    .alert-pill.info { background: var(--blue-soft); color: #3b82f6; }
    .alert-row-body > p {
      font-size: 0.78rem; color: var(--text-secondary);
      line-height: 1.4; margin: 0 0 6px; font-weight: 600;
    }
    .alert-tip {
      font-size: 0.72rem; color: var(--muted);
      line-height: 1.4; margin: 0;
      padding: 7px 10px;
      background: var(--input-bg);
      border-radius: 8px;
      border: 1px dashed var(--input-border);
      font-weight: 600;
    }
    .alert-tip::before { content: "💡 "; }
    .alerts-suggestions {
      padding: 14px 16px;
      border-radius: 14px;
      background: linear-gradient(135deg, #eff6ff, #f0fdf4);
      border: 1px solid #bfdbfe;
    }
    [data-theme="dark"] .alerts-suggestions {
      background: linear-gradient(135deg, rgba(37,99,235,0.14), rgba(22,163,74,0.12));
      border-color: rgba(59,130,246,0.35);
    }
    .alerts-suggestions .alerts-section-title { color: #3b82f6; }
    .alert-suggest-list {
      list-style: none; margin: 0; padding: 0;
      display: flex; flex-direction: column; gap: 8px;
    }
    .alert-suggest-list li {
      font-size: 0.78rem; font-weight: 600;
      color: var(--text-secondary); line-height: 1.45;
      padding: 9px 12px 9px 32px;
      background: var(--input-bg);
      border-radius: 10px;
      border: 1px solid var(--input-border);
      position: relative;
    }
    .alert-suggest-list li::before {
      content: "✓";
      position: absolute; left: 10px; top: 9px;
      width: 18px; height: 18px; border-radius: 50%;
      background: var(--blue-soft); color: #3b82f6;
      font-size: 0.62rem; font-weight: 900;
      display: grid; place-items: center;
    }
    .patient-avatar {
      width: 76px; height: 76px; flex-shrink: 0;
      border-radius: 18px;
      background: linear-gradient(145deg, var(--blue), var(--cyan));
      color: #fff; font-size: 1.55rem; font-weight: 900;
      display: grid; place-items: center;
      box-shadow: 0 10px 24px rgba(37, 99, 235, 0.28);
      letter-spacing: 0.02em;
    }
    .patient-modal {
      display: none;
      position: fixed; inset: 0; z-index: 200;
      align-items: center; justify-content: center;
      padding: 16px;
    }
    .patient-modal.open { display: flex; }
    .patient-modal-backdrop {
      position: absolute; inset: 0;
      background: rgba(15, 23, 42, 0.6);
    }
    .patient-modal-card {
      position: relative; z-index: 1;
      width: min(580px, 100%);
      max-height: min(92vh, 640px);
      overflow-y: auto;
      padding: 18px 20px 20px;
      background: var(--main-bg-1);
    }
    .patient-modal-head {
      display: flex; justify-content: space-between; align-items: center;
      margin-bottom: 14px; padding-bottom: 10px;
      border-bottom: 1px solid var(--input-border);
    }
    .patient-modal-head h3 {
      font-size: 0.98rem; margin: 0;
      display: flex; align-items: center; gap: 8px;
    }
    .btn-icon {
      width: 32px; height: 32px; border-radius: 10px;
      border: 1px solid var(--input-border); background: var(--input-bg);
      color: var(--muted); font-size: 1.1rem; cursor: pointer;
      display: grid; place-items: center; line-height: 1;
    }
    #page-dashboard.page.active {
      display: flex;
      flex-direction: column;
      overflow: hidden;
      padding: 10px 14px 12px;
      gap: 10px;
      z-index: 2;
      background:
        radial-gradient(ellipse 70% 45% at 15% 0%, rgba(244,63,94,0.08), transparent),
        radial-gradient(ellipse 60% 40% at 85% 5%, rgba(37,99,235,0.1), transparent),
        radial-gradient(ellipse 50% 35% at 50% 100%, rgba(6,182,212,0.08), transparent),
        linear-gradient(180deg, var(--dash-bg-1) 0%, var(--dash-bg-2) 100%);
    }
    .med-dash {
      flex: 1; min-height: 0;
      display: flex; flex-direction: column; gap: 10px;
    }
    .med-status-bar {
      flex-shrink: 0;
      display: flex; align-items: center;
      gap: 8px;
      padding: 8px 10px;
      border-radius: 14px;
      background: #0f172a;
      color: #e2e8f0;
      border: 1px solid #1e293b;
      overflow: hidden;
    }
    .med-status-pill {
      display: flex; align-items: center; gap: 7px;
      padding: 6px 11px;
      border-radius: 999px;
      font-size: 0.68rem; font-weight: 800;
      letter-spacing: 0.05em;
      text-transform: uppercase;
      white-space: nowrap;
      flex-shrink: 0;
    }
    .med-status-pill.live-pill-dash {
      background: rgba(34,197,94,0.15);
      border: 1px solid rgba(34,197,94,0.35);
      color: #86efac;
    }
    .med-status-pill.ward-pill-dash {
      background: rgba(59,130,246,0.12);
      border: 1px solid rgba(59,130,246,0.3);
      color: #93c5fd;
    }
    .med-status-pill.ward-pill-dash svg {
      width: 14px; height: 14px;
      stroke: currentColor; fill: none;
      stroke-width: 2; stroke-linecap: round; stroke-linejoin: round;
    }
    .med-status-patient {
      flex: 1; min-width: 0;
      display: flex; align-items: center; gap: 8px;
      margin-left: auto;
      padding: 6px 12px 6px 8px;
      border-radius: 999px;
      background: rgba(255,255,255,0.1);
      border: 1px solid rgba(255,255,255,0.18);
      cursor: pointer;
      transition: background 0.15s, border-color 0.15s, transform 0.12s;
      user-select: none;
    }
    .med-status-patient:hover {
      background: rgba(59,130,246,0.28);
      border-color: rgba(147,197,253,0.55);
      transform: translateY(-1px);
    }
    .med-status-patient:active {
      transform: scale(0.98);
    }
    .privacy-gate-bar {
      flex-shrink: 0;
      padding: 12px 16px;
      border-radius: 14px;
      display: flex; align-items: center; justify-content: space-between;
      gap: 12px; flex-wrap: wrap;
      background: linear-gradient(90deg, rgba(37,99,235,0.1), rgba(15,23,42,0.05));
      border: 1px solid rgba(37,99,235,0.3);
    }
    [data-theme="dark"] .privacy-gate-bar {
      background: linear-gradient(90deg, rgba(37,99,235,0.18), rgba(30,41,59,0.9));
      border-color: rgba(59,130,246,0.4);
    }
    .privacy-gate-info {
      display: flex; align-items: center; gap: 10px;
      font-size: 0.8rem; font-weight: 800; color: var(--text);
    }
    .privacy-gate-sub {
      font-size: 0.7rem; font-weight: 600; color: var(--muted);
      display: block; margin-top: 2px;
    }
    .privacy-gate-form {
      display: flex; align-items: center; gap: 8px; flex-wrap: wrap;
    }
    .pin-input {
      width: 140px;
      padding: 8px 12px;
      border-radius: 10px;
      border: 1.5px solid var(--input-border);
      background: var(--input-bg);
      color: var(--text);
      font-family: inherit;
      font-size: 0.9rem;
      font-weight: 900;
      letter-spacing: 0.25em;
      text-align: center;
    }
    .pin-input::placeholder {
      letter-spacing: normal;
      font-size: 0.74rem;
      font-weight: 700;
    }
    .pin-input:focus {
      outline: none;
      border-color: var(--blue);
      box-shadow: 0 0 0 3px rgba(37,99,235,0.18);
    }
    .pin-error-msg {
      font-size: 0.72rem;
      font-weight: 800;
      color: #ef4444;
      width: 100%;
      margin-top: 2px;
      display: none;
    }
    .pin-error-msg.show {
      display: block;
    }
    .censored-text {
      filter: blur(5px);
      user-select: none;
      pointer-events: none;
      opacity: 0.65;
      transition: filter 0.25s ease, opacity 0.25s ease;
    }
    .med-status-patient .med-chip-icon {
      background: #3b82f6;
      color: #fff;
      font-size: 12px;
    }
    #dashPatientName {
      font-size: 0.78rem; font-weight: 800;
      text-transform: none; letter-spacing: -0.01em;
      color: #fff;
      white-space: nowrap; overflow: hidden; text-overflow: ellipsis;
      min-width: 0;
      flex: 1;
    }
    .med-status-dot {
      width: 8px; height: 8px; border-radius: 50%;
      background: #22c55e;
      animation: statusPulse 2s infinite;
      flex-shrink: 0;
    }
    @keyframes statusPulse {
      0%, 100% { opacity: 1; }
      50% { opacity: 0.5; }
    }
    .med-chip-icon {
      width: 28px; height: 28px; border-radius: 8px;
      background: rgba(255,255,255,0.14);
      display: grid; place-items: center; font-size: 13px;
      flex-shrink: 0;
    }
    .med-chip-icon svg {
      width: 15px; height: 15px;
      stroke: currentColor; fill: none;
      stroke-width: 2; stroke-linecap: round; stroke-linejoin: round;
    }
    /* Cuadrícula de 3 tarjetas: Frecuencia Cardíaca, Temp Ambiental, Humedad */
    .med-vitals-grid {
      flex-shrink: 0;
      display: grid;
      grid-template-columns: 1.2fr 1fr 1fr;
      gap: 10px;
      min-height: 0;
    }
    .med-vital {
      display: flex; align-items: center; gap: 14px;
      padding: 16px 18px;
      border-radius: 16px;
      position: relative;
      min-height: 112px;
      box-shadow: none !important;
      transition: border-color 0.25s ease, background 0.25s ease;
    }
    .med-vital-heart {
      background: #fff1f2;
      border: 1.5px solid #fecdd3;
    }
    .med-vital-room {
      background: #f0fdf4;
      border: 1.5px solid #bbf7d0;
    }
    .med-vital-hum {
      background: #ecfeff;
      border: 1.5px solid #a5f3fc;
    }
    [data-theme="dark"] .med-vital-heart {
      background: rgba(225,29,72,0.14);
      border-color: rgba(244,63,94,0.35);
    }
    [data-theme="dark"] .med-vital-room {
      background: rgba(22,163,74,0.14);
      border-color: rgba(34,197,94,0.35);
    }
    [data-theme="dark"] .med-vital-hum {
      background: rgba(8,145,178,0.14);
      border-color: rgba(6,182,212,0.35);
    }
    .med-vital-icon-wrap {
      flex-shrink: 0;
      width: 52px;
      display: flex; align-items: center; justify-content: center;
    }
    .vital-icon-box {
      width: 50px; height: 50px;
      border-radius: 14px;
      display: grid; place-items: center;
      transform-origin: center;
      box-shadow: none;
    }
    .vital-icon-heart {
      background: #e11d48;
      color: #fff;
    }
    .vital-icon-room {
      background: #16a34a;
      color: #fff;
    }
    .vital-icon-hum {
      background: #0891b2;
      color: #fff;
    }
    .vital-icon-heart.beating {
      animation: heartbeat var(--beat-dur, 0.85s) ease-in-out infinite;
      will-change: transform;
    }
    @keyframes heartbeat {
      0%, 100% { transform: scale(1); }
      14% { transform: scale(1.07); }
      28% { transform: scale(1); }
      42% { transform: scale(1.04); }
      56% { transform: scale(1); }
    }
    .vital-icon-heart svg {
      width: 26px; height: 26px;
      fill: currentColor;
    }
    .vital-icon-room svg, .vital-icon-hum svg {
      width: 24px; height: 24px;
      stroke: currentColor; fill: none;
      stroke-width: 2.2; stroke-linecap: round; stroke-linejoin: round;
    }
    .med-vital-body { flex: 1; min-width: 0; }
    .med-vital-top {
      display: flex; justify-content: space-between; align-items: center;
      margin-bottom: 6px; gap: 6px;
    }
    .med-vital-title {
      font-size: 0.7rem; font-weight: 700;
      text-transform: uppercase; letter-spacing: 0.08em;
      color: var(--muted);
      display: flex; align-items: center; gap: 6px;
    }
    .vt-ico {
      width: 18px; height: 18px; border-radius: 5px;
      display: grid; place-items: center;
      flex-shrink: 0;
    }
    .vt-ico svg {
      width: 11px; height: 11px;
      stroke: currentColor; fill: none;
      stroke-width: 2.2; stroke-linecap: round; stroke-linejoin: round;
    }
    .med-vital-heart .vt-ico { background: #ffe4e6; color: #e11d48; }
    .med-vital-room .vt-ico { background: #dcfce7; color: #16a34a; }
    .med-vital-hum .vt-ico { background: #cffafe; color: #0891b2; }
    [data-theme="dark"] .med-vital-heart .vt-ico { background: rgba(244,63,94,0.25); color: #fb7185; }
    [data-theme="dark"] .med-vital-room .vt-ico { background: rgba(34,197,94,0.25); color: #4ade80; }
    [data-theme="dark"] .med-vital-hum .vt-ico { background: rgba(6,182,212,0.25); color: #22d3ee; }

    .dash-section-label {
      font-size: 0.68rem; font-weight: 800;
      text-transform: uppercase; letter-spacing: 0.1em;
      color: var(--muted);
      padding: 0 2px;
      display: flex; align-items: center; gap: 6px;
    }
    .dash-section-label::before {
      content: "";
      width: 8px; height: 8px; border-radius: 50%;
      background: #22c55e;
      animation: statusPulse 2s infinite;
    }
    .med-vital-value {
      font-size: 2rem; font-weight: 800;
      letter-spacing: -0.04em; line-height: 1;
      margin-bottom: 4px;
      font-variant-numeric: tabular-nums;
      transition: color 0.3s ease;
    }
    #bpm.bpm-pulse {
      animation: bpmGlow 0.55s ease;
    }
    @keyframes bpmGlow {
      0%, 100% { opacity: 1; filter: none; }
      40% { opacity: 0.82; filter: brightness(1.15); }
    }
    @keyframes vitalSoft {
      0%, 100% { opacity: 1; }
      50% { opacity: 0.75; }
    }
    .med-vital-value.vital-flash { animation: vitalSoft 0.45s ease; }
    .med-vital-heart .med-vital-value { color: #9f1239; }
    .med-vital-room .med-vital-value { color: #15803d; }
    .med-vital-hum .med-vital-value { color: #0e7490; }
    [data-theme="dark"] .med-vital-heart .med-vital-value { color: #fda4af; }
    [data-theme="dark"] .med-vital-room .med-vital-value { color: #86efac; }
    [data-theme="dark"] .med-vital-hum .med-vital-value { color: #67e8f9; }

    .med-unit {
      font-size: 0.75rem; font-weight: 700;
      color: var(--muted); margin-left: 3px;
      letter-spacing: 0.02em;
    }
    .med-range {
      font-size: 0.65rem; font-weight: 600;
      color: var(--muted); margin-bottom: 6px;
    }
    .hrv-metrics-row {
      display: flex; flex-wrap: wrap; gap: 6px;
      margin-bottom: 7px;
    }
    .hrv-chip {
      font-size: 0.63rem; font-weight: 800;
      padding: 3px 8px; border-radius: 6px;
      background: rgba(225,29,72,0.1);
      color: #be123c;
      border: 1px solid rgba(225,29,72,0.2);
      font-variant-numeric: tabular-nums;
    }
    [data-theme="dark"] .hrv-chip {
      background: rgba(244,63,94,0.18);
      color: #fda4af;
      border-color: rgba(244,63,94,0.35);
    }
    .ecg-controls-bar {
      display: flex; align-items: center; gap: 6px; flex-wrap: wrap;
      margin-left: auto;
    }
    .ecg-ctrl-btn, .ecg-ctrl-select {
      padding: 5px 9px;
      border-radius: 8px;
      border: 1px solid var(--input-border);
      background: var(--input-bg);
      color: var(--text);
      font-family: inherit;
      font-size: 0.68rem;
      font-weight: 800;
      cursor: pointer;
      display: inline-flex; align-items: center; gap: 4px;
      transition: background 0.15s, border-color 0.15s, transform 0.1s;
    }
    .ecg-ctrl-btn:hover, .ecg-ctrl-select:hover {
      border-color: #3b82f6;
    }
    .ecg-ctrl-btn.active {
      background: #2563eb;
      color: #fff;
      border-color: #2563eb;
    }
    .ecg-ctrl-btn.paused {
      background: #f59e0b;
      color: #fff;
      border-color: #d97706;
    }
    .raw-ecg-bar {
      flex-shrink: 0;
      padding: 10px 14px;
      border-radius: 14px;
      display: flex; align-items: center; justify-content: space-between;
      gap: 10px; flex-wrap: wrap;
      background: linear-gradient(90deg, rgba(22,163,74,0.1), rgba(6,182,212,0.08));
      border: 1px solid rgba(22,163,74,0.3);
    }
    .raw-ecg-info {
      display: flex; align-items: center; gap: 10px; flex-wrap: wrap;
      font-size: 0.76rem; font-weight: 800; color: var(--text);
    }
    .raw-ecg-sub {
      font-size: 0.68rem; font-weight: 600; color: var(--muted);
    }
    .thresholds-card {
      flex-shrink: 0;
      padding: 10px 14px;
      border-radius: 14px;
      display: flex; align-items: center; justify-content: space-between;
      gap: 10px; flex-wrap: wrap;
    }
    .thresholds-inputs {
      display: flex; align-items: center; gap: 10px; flex-wrap: wrap;
    }
    .thresh-item {
      display: flex; align-items: center; gap: 5px;
      font-size: 0.7rem; font-weight: 800; color: var(--muted);
    }
    .thresh-item input {
      width: 62px; padding: 5px 7px;
      border-radius: 8px; border: 1px solid var(--input-border);
      background: var(--input-bg); color: var(--text);
      font-family: inherit; font-size: 0.76rem; font-weight: 800;
      text-align: center;
    }
    .med-bar {
      height: 5px; border-radius: 999px;
      background: rgba(148,163,184,0.2); overflow: hidden;
    }
    .med-vital .bar-fill {
      height: 100%; border-radius: inherit;
      transition: width 0.55s cubic-bezier(0.4, 0, 0.2, 1);
      position: relative;
    }
    .med-vital-heart .bar-fill { background: #f43f5e; }
    .med-vital-room .bar-fill { background: #22c55e; }
    .med-vital-hum .bar-fill { background: #06b6d4; }
    .med-vital .badge {
      position: static;
      font-size: 0.55rem;
      font-weight: 800;
      padding: 3px 8px;
      letter-spacing: 0.04em;
      border-radius: 6px;
    }
    .med-ecg {
      flex: 1 1 auto; min-height: 0;
      padding: 12px 14px 14px;
      background: #f0fdf4;
      border: 1.5px solid #bbf7d0;
      box-shadow: none !important;
    }
    [data-theme="dark"] .med-ecg {
      background: rgba(22,163,74,0.1);
      border-color: rgba(34,197,94,0.3);
    }
    .ecg-icon-wrap {
      width: 36px; height: 36px; border-radius: 10px;
      background: #16a34a;
      display: grid; place-items: center;
      color: #fff;
      box-shadow: none;
    }
    .ecg-icon-wrap svg {
      width: 18px; height: 18px;
      stroke: currentColor; fill: none;
      stroke-width: 2.2; stroke-linecap: round; stroke-linejoin: round;
    }
    .ecg-title-block {
      display: flex; align-items: center; gap: 10px;
    }
    .ecg-title-block h3 {
      font-size: 0.92rem; letter-spacing: -0.02em;
      margin: 0;
    }
    .ecg-overlay-labels {
      position: absolute; top: 8px; left: 10px; z-index: 2;
      display: flex; gap: 12px;
      font-size: 0.62rem; font-weight: 800;
      color: rgba(103,232,249,0.55);
      letter-spacing: 0.06em;
      text-transform: uppercase;
      pointer-events: none;
    }
    .glass {
      background: var(--card);
      border: 1px solid var(--card-border);
      border-radius: var(--radius);
      box-shadow: 0 8px 24px rgba(15,23,42,0.06);
    }
    .badge {
      position: absolute; top: 10px; right: 10px;
      font-size: 0.62rem; font-weight: 900; padding: 4px 8px;
      border-radius: 999px; letter-spacing: 0.05em;
    }
    .badge.good { background: var(--green-soft); color: #22c55e; }
    .badge.watch { background: var(--orange-soft); color: #f59e0b; }
    .badge.live { background: var(--blue-soft); color: #3b82f6; }
    .badge.bad { background: var(--red-soft); color: #ef4444; }
    #page-dashboard .ecg-wrap {
      flex: 1 1 auto;
      min-height: 0;
      display: flex;
      flex-direction: column;
    }
    .ecg-wrap {
      flex: 1;
      min-height: 0;
      display: flex;
      flex-direction: column;
    }
    #page-dashboard .ecg-head {
      margin-bottom: 8px;
      flex-shrink: 0;
    }
    #page-dashboard .ecg-stage {
      flex: 1 1 auto;
      min-height: 0;
    }
    .ecg-head {
      display: flex; justify-content: space-between; align-items: center;
      margin-bottom: 8px; gap: 10px;
      position: relative;
    }
    .ecg-head .ecg-badge-pill {
      position: static;
      flex-shrink: 0;
      font-size: 0.62rem; font-weight: 900;
      padding: 5px 12px; border-radius: 999px;
      letter-spacing: 0.06em; text-transform: uppercase;
      background: var(--blue-soft); color: #3b82f6;
    }
    .ecg-head .ecg-badge-pill.good { background: var(--green-soft); color: #22c55e; }
    .ecg-head .ecg-badge-pill.watch { background: var(--orange-soft); color: #f59e0b; }
    .ecg-head .ecg-badge-pill.bad { background: var(--red-soft); color: #ef4444; }
    .ecg-head .ecg-badge-pill.live { background: var(--blue-soft); color: #3b82f6; }
    .ecg-head h3 { font-size: 0.92rem; letter-spacing: -0.02em; }
    .ecg-head span { font-size: 0.72rem; color: var(--muted); }
    .ecg-stage {
      flex: 1;
      min-height: 0;
      border-radius: 14px;
      overflow: hidden;
      position: relative;
      background:
        linear-gradient(rgba(103,232,249,0.06) 1px, transparent 1px),
        linear-gradient(90deg, rgba(103,232,249,0.06) 1px, transparent 1px),
        linear-gradient(180deg, #06101d, #0f172a 62%, #08111f);
      background-size: 24px 24px;
      border: 1px solid rgba(15,23,42,0.1);
    }
    .ecg-stage canvas {
      position: absolute;
      inset: 0;
      width: 100%;
      height: 100%;
      display: block;
    }
    .form-grid {
      display: grid; grid-template-columns: 1fr 1fr; gap: 9px;
    }
    .form-field {
      display: flex; flex-direction: column; gap: 4px;
    }
    .form-field.full { grid-column: span 2; }
    .form-field label {
      display: flex; align-items: center; gap: 6px;
      font-size: 0.68rem; color: var(--muted); font-weight: 800;
      text-transform: uppercase; letter-spacing: 0.06em;
    }
    .field-icon {
      width: 22px; height: 22px; border-radius: 7px;
      display: grid; place-items: center;
      font-size: 12px; line-height: 1; flex-shrink: 0;
    }
    .field-icon.ic-name { background: #dbeafe; color: #2563eb; }
    .field-icon.ic-id { background: #ede9fe; color: #7c3aed; }
    .field-icon.ic-bed { background: #ccfbf1; color: #0d9488; }
    .field-icon.ic-ward { background: #ffedd5; color: #ea580c; }
    .field-icon.ic-age { background: #cffafe; color: #0891b2; }
    .field-icon.ic-blood { background: #fee2e2; color: #dc2626; }
    .field-icon.ic-gender { background: #fce7f3; color: #db2777; }
    .field-icon.ic-contact { background: #dcfce7; color: #16a34a; }
    .field-icon.ic-notes { background: #fef3c7; color: #d97706; }
    .form-field input, .form-field select, .form-field textarea {
      padding: 9px 11px; border-radius: 10px;
      border: 1px solid var(--input-border); background: var(--input-bg);
      font-size: 0.88rem; font-weight: 600; color: var(--text);
      font-family: inherit;
    }
    .form-field textarea { min-height: 72px; resize: vertical; }
    .form-field input:focus, .form-field select:focus, .form-field textarea:focus {
      outline: none; border-color: var(--blue);
      box-shadow: 0 0 0 3px rgba(37,99,235,0.18);
    }
    .form-actions {
      display: flex; gap: 8px; margin-top: 14px; flex-wrap: wrap;
    }
    .btn {
      padding: 10px 16px; border-radius: 10px; border: none;
      font-size: 0.82rem; font-weight: 800; cursor: pointer;
    }
    .btn-primary { background: var(--blue); color: #fff; }
    .btn-secondary { background: var(--btn-sec-bg); color: var(--text); }
    .btn-danger { background: var(--red-soft); color: var(--red); }
    .save-msg {
      font-size: 0.78rem; color: var(--green); font-weight: 800;
      margin-top: 8px; min-height: 1em;
    }
    .nav-text-short { display: none; }
 
    /* Tablet */
    @media (max-width: 1024px) {
      .med-vitals-grid { grid-template-columns: 1fr 1fr 1fr; }
    }
 
    /* Mobile */
    @media (max-width: 768px) {
      body {
        align-items: stretch;
        justify-content: stretch;
      }
      .viewport-wrap {
        width: 100vw;
        width: 100dvw;
        height: 100vh;
        height: 100dvh;
        max-width: none;
        max-height: none;
        aspect-ratio: auto;
      }
      .app-shell {
        flex-direction: column;
      }
      .main {
        flex: 1;
        min-height: 0;
        order: 1;
      }
      .sidebar {
        order: 2;
        width: 100%;
        flex-shrink: 0;
        flex-direction: column;
        padding: 0;
        border-right: none;
        border-top: 1px solid rgba(255,255,255,0.1);
      }
      .sidebar-brand,
      .nav-label,
      .sidebar-theme-box { display: none; }
      .sidebar-foot {
        display: flex;
        align-items: center;
        justify-content: space-between;
        padding: 6px 14px;
        border-top: none;
        border-bottom: 1px solid rgba(255,255,255,0.08);
        margin: 0;
      }
      .nav {
        flex-direction: row;
        flex: none;
        gap: 2px;
        padding: 4px 6px;
        padding-bottom: max(6px, env(safe-area-inset-bottom));
      }
      .nav-item {
        flex: 1;
        flex-direction: column;
        align-items: center;
        justify-content: center;
        gap: 3px;
        padding: 8px 2px;
        min-height: 54px;
        font-size: 0.58rem;
        text-align: center;
        transform: none;
        border-radius: 10px;
      }
      .nav-item:hover { transform: none; }
      .nav-text-long { display: none; }
      .nav-text-short { display: inline; }
      .nav-icon-wrap {
        width: 32px;
        height: 32px;
        font-size: 15px;
      }
      .topbar {
        padding: 8px 12px;
        gap: 8px;
      }
      .topbar h1 { font-size: 1rem; }
      .topbar p { font-size: 0.7rem; display: none; }
      .topbar-meta { font-size: 0.68rem; }
      .topbar-meta strong { font-size: 0.78rem; }
      .page {
        padding: 10px 10px 12px;
      }
      .page.active {
        overflow-y: auto;
        overflow-x: hidden;
        -webkit-overflow-scrolling: touch;
      }
      #page-dashboard.page.active,
      #page-patient.page.active,
      #page-logging.page.active,
      #page-alerts.page.active {
        overflow-y: auto;
        padding: 8px 10px 10px;
      }
      .med-dash {
        gap: 8px;
        min-height: min-content;
      }
      .med-status-bar {
        flex-wrap: wrap;
        gap: 6px;
        padding: 8px 10px;
      }
      .med-status-patient {
        flex: 1 1 100%;
        max-width: 100%;
        width: 100%;
        justify-content: flex-start;
      }
      .ward-pill-dash { display: none; }
      .topbar-actions { gap: 8px; }
      .sound-toggle, .theme-toggle { width: 32px; height: 32px; font-size: 14px; }
      .med-vitals-grid {
        grid-template-columns: 1fr;
        gap: 8px;
      }
      .med-vital {
        min-height: auto;
        padding: 12px 14px;
      }
      .med-vital-value { font-size: 1.85rem; }
      #page-dashboard .ecg-wrap {
        flex: none;
        min-height: 0;
      }
      #page-dashboard .ecg-stage {
        flex: none;
        min-height: 200px;
        height: 42vw;
        max-height: 280px;
      }
      .record-stats-row { grid-template-columns: 1fr; }
      .record-stat {
        flex-direction: row;
        align-items: center;
        justify-content: flex-start;
        text-align: left;
        padding: 12px 14px;
        gap: 12px;
      }
      .record-stat-label { flex: 1; margin: 0; }
      .record-stat-value { font-size: 1rem; flex-shrink: 0; }
      .record-contact-row { grid-template-columns: 1fr; }
      .record-profile {
        flex-wrap: wrap;
        padding: 14px;
        gap: 12px;
      }
      .record-profile-main { width: calc(100% - 82px); }
      .record-profile-main h2 { font-size: 1.25rem; }
      .record-profile-actions {
        width: 100%;
        display: flex;
        gap: 8px;
      }
      .record-profile .btn-glow,
      .record-profile .btn-danger-glow {
        flex: 1;
        margin-top: 2px;
      }
      .record-page { overflow: hidden; }
      #page-patient.page.active { overflow: hidden; }
      #page-alerts.page.active { overflow: hidden; }
      .alerts-summary { grid-template-columns: repeat(3, 1fr); gap: 6px; }
      .alerts-summary-card { padding: 8px 6px; font-size: 0.58rem; }
      .alerts-summary-card span { font-size: 1.15rem; }
      .alerts-hero { flex-wrap: wrap; padding: 12px 14px; }
      .alerts-hero h3 { font-size: 0.95rem; }
      .alert-row { padding: 11px 12px; gap: 10px; }
      .alert-row-icon { width: 38px; height: 38px; font-size: 17px; }
      .alert-row-top strong { font-size: 0.82rem; }
      .alert-tip { font-size: 0.68rem; padding: 6px 8px; }
      .logging-toolbar {
        flex-direction: column;
        align-items: stretch;
        gap: 10px;
      }
      .logging-controls {
        flex-direction: column;
        align-items: stretch;
      }
      .logging-controls select,
      .logging-controls .btn-log {
        width: 100%;
      }
      .logging-stats {
        justify-content: space-between;
        width: 100%;
      }
      .logging-table-scroll {
        overflow-x: auto;
        overflow-y: auto;
      }
      .log-table { min-width: 440px; font-size: 0.72rem; }
      .log-table th, .log-table td { padding: 8px 8px; }
      .form-grid { grid-template-columns: 1fr; }
      .form-field.full { grid-column: span 1; }
      .patient-modal { padding: 10px; align-items: flex-end; }
      .patient-modal-card {
        max-height: 92dvh;
        border-radius: 18px 18px 0 0;
        width: 100%;
      }
    }
 
    /* Teléfonos pequeños */
    @media (max-width: 400px) {
      .med-vital-icon-wrap { width: 48px; }
      .vital-icon-box { width: 44px; height: 44px; }
      .vital-icon-heart svg { width: 22px; height: 22px; }
      .med-vital-value { font-size: 1.65rem; }
      .nav-item { font-size: 0.52rem; min-height: 50px; }
      .ecg-overlay-labels { font-size: 0.55rem; gap: 8px; }
      #page-dashboard .ecg-stage {
        min-height: 160px;
        height: 38vw;
      }
    }
  </style>
</head>
<body>
  <div class="viewport-wrap">
    <div class="app-shell">
      <aside class="sidebar">
        <div class="sidebar-brand">
          <div class="sidebar-logo">
            <svg viewBox="0 0 24 24" aria-hidden="true">
              <path d="M4 12h2l2-4 3 8 2-5 2 5 3-8 2 4h2"/>
            </svg>
          </div>
          <div>
            <strong>MedMonitor</strong>
            <span>Monitoreo IoT</span>
          </div>
        </div>
        <div class="nav-label">Clínico</div>
        <nav class="nav">
          <button class="nav-item active" data-page="dashboard"><span class="nav-icon-wrap"><span class="nav-icon">&#128147;</span></span><span class="nav-text"><span class="nav-text-long">Monitor de Signos</span><span class="nav-text-short">Signos</span></span></button>
          <button class="nav-item" data-page="patient"><span class="nav-icon-wrap"><span class="nav-icon">&#128100;</span></span><span class="nav-text"><span class="nav-text-long">Expediente</span><span class="nav-text-short">Paciente</span></span></button>
          <button class="nav-item" data-page="logging"><span class="nav-icon-wrap"><span class="nav-icon">&#128202;</span></span><span class="nav-text"><span class="nav-text-long">Registro de Datos</span><span class="nav-text-short">Registro</span></span></button>
          <button class="nav-item" data-page="alerts"><span class="nav-icon-wrap"><span class="nav-icon">&#128680;</span></span><span class="nav-text"><span class="nav-text-long">Alertas Clínicas</span><span class="nav-text-short">Alertas</span></span></button>
        </nav>

        <!-- Apartado para cambiar entre Modo Claro y Modo Oscuro -->
        <div class="sidebar-theme-box">
          <div class="sidebar-theme-title">&#127912; Apariencia</div>
          <div class="theme-switch-group">
            <button type="button" class="theme-opt-btn active" id="btnThemeLight">&#9728;&#65039; Claro</button>
            <button type="button" class="theme-opt-btn" id="btnThemeDark">&#127769; Oscuro</button>
          </div>
        </div>

        <div class="sidebar-foot">
          <div class="live-pill"><span class="live-dot" id="liveDot"></span><span id="connText">Conectando</span></div>
          <span id="clock">--:--:--</span>
        </div>
      </aside>
 
      <div class="main">
        <header class="topbar">
          <div>
            <h1 id="pageTitle">Monitor de Signos</h1>
            <p id="pageSubtitle">Monitoreo cardíaco y ambiental en tiempo real</p>
          </div>
          <div class="topbar-actions">
            <button type="button" class="theme-toggle" id="btnThemeToggle" title="Cambiar entre modo claro y oscuro" aria-label="Cambiar tema">
              <svg class="icon-sun" viewBox="0 0 24 24" aria-hidden="true"><circle cx="12" cy="12" r="5"/><line x1="12" y1="1" x2="12" y2="3"/><line x1="12" y1="21" x2="12" y2="23"/><line x1="4.22" y1="4.22" x2="5.64" y2="5.64"/><line x1="18.36" y1="18.36" x2="19.78" y2="19.78"/><line x1="1" y1="12" x2="3" y2="12"/><line x1="21" y1="12" x2="23" y2="12"/><line x1="4.22" y1="19.78" x2="5.64" y2="18.36"/><line x1="18.36" y1="5.64" x2="19.78" y2="4.22"/></svg>
              <svg class="icon-moon" viewBox="0 0 24 24" aria-hidden="true"><path d="M21 12.79A9 9 0 1 1 11.21 3 7 7 0 0 0 21 12.79z"/></svg>
            </button>
            <button type="button" class="sound-toggle" id="btnSoundToggle" title="Activar/desactivar sonido del latido" aria-label="Activar/desactivar sonido del latido">
              <svg class="sound-on" viewBox="0 0 24 24" aria-hidden="true"><path d="M11 5L6 9H2v6h4l5 4V5z"/><path d="M15.54 8.46a5 5 0 0 1 0 7.07"/><path d="M19.07 4.93a10 10 0 0 1 0 14.14"/></svg>
              <svg class="sound-off" viewBox="0 0 24 24" aria-hidden="true"><path d="M11 5L6 9H2v6h4l5 4V5z"/><line x1="23" y1="9" x2="17" y2="15"/><line x1="17" y1="9" x2="23" y2="15"/></svg>
            </button>
            <div class="topbar-meta">
              <span>Última actualización</span>
              <strong id="lastUpdate">--</strong>
            </div>
          </div>
        </header>
 
        <div class="page-area">
          <!-- MONITOR DE SIGNOS VITALES (Sin SpO2 ni Temperatura Corporal) -->
          <section class="page active" id="page-dashboard">
            <div class="med-dash">
              <div class="med-status-bar">
                <div class="med-status-pill live-pill-dash">
                  <span class="med-status-dot"></span>
                  <span>En Vivo</span>
                </div>
                <div class="med-status-pill ward-pill-dash">
                  <svg viewBox="0 0 24 24" aria-hidden="true"><path d="M3 21h18M5 21V7l7-4 7 4v14M9 21v-6h6v6"/></svg>
                  <span>Monitor UCI</span>
                </div>
                <div class="med-status-patient" id="btnGoToPatient" title="Hacer clic para abrir el expediente del paciente" role="button" tabindex="0">
                  <span class="med-chip-icon">
                    <svg viewBox="0 0 24 24" aria-hidden="true"><path d="M20 21v-2a4 4 0 0 0-4-4H8a4 4 0 0 0-4 4v2"/><circle cx="12" cy="7" r="4"/></svg>
                  </span>
                  <span id="dashPatientName">Monitor de Paciente</span>
                  <span style="font-size:0.68rem;color:#93c5fd;font-weight:800;margin-left:4px">&#10140;</span>
                </div>
              </div>
 
              <div class="dash-section-label">Signos y Ambiente en Tiempo Real</div>
 
              <div class="med-vitals-grid">
                <!-- 1. Frecuencia Cardíaca -->
                <div class="med-vital med-vital-heart glass">
                  <div class="med-vital-icon-wrap">
                    <div class="vital-icon-box vital-icon-heart" id="heartIcon">
                      <svg viewBox="0 0 24 24" aria-hidden="true">
                        <path d="M12 21.35l-1.45-1.32C5.4 15.36 2 12.28 2 8.5 2 5.42 4.42 3 7.5 3c1.74 0 3.41.81 4.5 2.09C13.09 3.81 14.76 3 16.5 3 19.58 3 22 5.42 22 8.5c0 3.78-3.4 6.86-8.55 11.54L12 21.35z"/>
                      </svg>
                    </div>
                  </div>
                  <div class="med-vital-body">
                    <div class="med-vital-top">
                      <span class="med-vital-title"><span class="vt-ico"><svg viewBox="0 0 24 24"><path d="M12 21.35l-1.45-1.32C5.4 15.36 2 12.28 2 8.5 2 5.42 4.42 3 7.5 3c1.74 0 3.41.81 4.5 2.09C13.09 3.81 14.76 3 16.5 3 19.58 3 22 5.42 22 8.5c0 3.78-3.4 6.86-8.55 11.54L12 21.35z" fill="currentColor" stroke="none"/></svg></span>Frecuencia Cardíaca</span>
                      <span class="badge watch" id="bpmBadge">ESPERA</span>
                    </div>
                    <div class="med-vital-value" id="bpmWrap"><span id="bpm">--</span><span class="med-unit">BPM</span></div>
                    <div class="med-range" id="bpmRangeLabel">Rango normal: 60 – 100 BPM</div>
                    <div class="hrv-metrics-row">
                      <span class="hrv-chip" title="Intervalo entre picos R consecutivos">R-R: <strong id="rrVal">--</strong> ms</span>
                      <span class="hrv-chip" title="Variabilidad de la Frecuencia Cardíaca (RMSSD)">HRV: <strong id="hrvVal">--</strong> ms</span>
                    </div>
                    <div class="bar med-bar"><div class="bar-fill" id="bpmBar" style="width:6%"></div></div>
                  </div>
                </div>

                <!-- 2. Temperatura Ambiental -->
                <div class="med-vital med-vital-room glass">
                  <div class="med-vital-icon-wrap">
                    <div class="vital-icon-box vital-icon-room">
                      <svg viewBox="0 0 24 24" aria-hidden="true"><path d="M3 10.5L12 3l9 7.5V20a1 1 0 0 1-1 1h-5v-6H9v6H4a1 1 0 0 1-1-1v-9.5z"/></svg>
                    </div>
                  </div>
                  <div class="med-vital-body">
                    <div class="med-vital-top">
                      <span class="med-vital-title"><span class="vt-ico"><svg viewBox="0 0 24 24"><path d="M3 10.5L12 3l9 7.5V20a1 1 0 0 1-1 1h-5v-6H9v6H4a1 1 0 0 1-1-1z" fill="currentColor" stroke="none"/></svg></span>Temp. Ambiental</span>
                      <span class="badge watch" id="roomBadge">ESPERA</span>
                    </div>
                    <div class="med-vital-value" id="roomTempWrap"><span id="roomTemp">--</span><span class="med-unit">&deg;C</span></div>
                    <div class="med-range" id="roomRangeLabel">Rango ideal: 18 – 28 &deg;C</div>
                    <div class="bar med-bar"><div class="bar-fill" id="roomTempBar" style="width:6%"></div></div>
                  </div>
                </div>

                <!-- 3. Humedad Relativa -->
                <div class="med-vital med-vital-hum glass">
                  <div class="med-vital-icon-wrap">
                    <div class="vital-icon-box vital-icon-hum">
                      <svg viewBox="0 0 24 24" aria-hidden="true"><path d="M12 2.69l5.66 5.66a8 8 0 1 1-11.31 0z"/></svg>
                    </div>
                  </div>
                  <div class="med-vital-body">
                    <div class="med-vital-top">
                      <span class="med-vital-title"><span class="vt-ico"><svg viewBox="0 0 24 24"><path d="M12 2.69l5.66 5.66a8 8 0 1 1-11.31 0z" fill="currentColor" stroke="none"/></svg></span>Humedad Ambiental</span>
                      <span class="badge watch" id="humBadge">ESPERA</span>
                    </div>
                    <div class="med-vital-value" id="humidityWrap"><span id="humidity">--</span><span class="med-unit">% HR</span></div>
                    <div class="med-range">Rango ideal: 30 – 70 %</div>
                    <div class="bar med-bar"><div class="bar-fill" id="humBar" style="width:6%"></div></div>
                  </div>
                </div>
              </div>
 
              <div class="dash-section-label" style="margin-top:2px">Señal de Electrocardiograma (ECG)</div>
 
              <div class="ecg-wrap glass med-ecg">
                <div class="ecg-head">
                  <div class="ecg-title-block">
                    <div class="ecg-icon-wrap">
                      <svg viewBox="0 0 24 24" aria-hidden="true"><path d="M4 12h2l2-4 3 8 2-5 2 5 3-8 2 4h2"/></svg>
                    </div>
                    <div>
                      <h3>Electrocardiograma &middot; Derivación I</h3>
                    </div>
                  </div>
                  <div class="ecg-controls-bar">
                    <button type="button" class="ecg-ctrl-btn active" id="btnEcgFilter" title="Activar/desactivar filtro digital pasa-bajos / 60 Hz en el ESP32">&#128295; Filtro 60Hz: ON</button>
                    <select class="ecg-ctrl-select" id="selEcgGain" title="Ganancia de amplitud vertical">
                      <option value="0.5">Ganancia 0.5x</option>
                      <option value="1" selected>Ganancia 1.0x</option>
                      <option value="1.5">Ganancia 1.5x</option>
                      <option value="2">Ganancia 2.0x</option>
                    </select>
                    <select class="ecg-ctrl-select" id="selEcgSpeed" title="Velocidad de barrido horizontal">
                      <option value="1" selected>Barrido 25 mm/s</option>
                      <option value="2">Barrido 50 mm/s</option>
                      <option value="3">Barrido 75 mm/s</option>
                    </select>
                    <button type="button" class="ecg-ctrl-btn" id="btnEcgFreeze" title="Congelar o reanudar el trazo en pantalla">&#9208; Congelar</button>
                    <button type="button" class="ecg-ctrl-btn" id="btnEcgSnapshot" title="Descargar imagen PNG del trazo actual">&#128247; Captura PNG</button>
                    <span class="ecg-badge-pill live" id="ecgBadge">TRANSMITIENDO</span>
                  </div>
                </div>
                <div class="ecg-stage">
                  <div class="ecg-overlay-labels">
                    <span id="ecgGainLabel">1.0 mV/div</span>
                    <span id="ecgSpeedLabel">25 mm/s</span>
                    <span id="ecgFilterLabel">Filtro 60Hz Activo</span>
                  </div>
                  <canvas id="ecgCanvas"></canvas>
                </div>
              </div>
            </div>
          </section>
 
          <!-- EXPEDIENTE DEL PACIENTE -->
          <section class="page" id="page-patient">
            <div class="record-page">
              <div class="record-banner glass" id="recordBanner">
                <div class="record-banner-bg"></div>
                <div class="record-profile">
                  <div class="record-avatar-ring">
                    <div class="patient-avatar" id="viewAvatar">?</div>
                  </div>
                  <div class="record-profile-main">
                    <h2 id="viewName">Sin paciente registrado</h2>
                    <div class="patient-chips" id="viewChipsWrap">
                      <span class="patient-chip" id="viewRecordModeChip" style="display:none;background:rgba(254,243,199,0.28);border-color:#fde68a;color:#fef08a">&#128194; Expediente de Paciente Anterior (Sin Censura)</span>
                      <span class="patient-chip" id="viewId">Sin ID</span>
                      <span class="patient-chip loc">Cama <span id="viewBed">--</span> &middot; Sala <span id="viewWard">--</span></span>
                    </div>
                  </div>
                  <div class="record-profile-actions">
                    <button type="button" class="btn btn-primary btn-glow" id="btnEditPatient" style="display:none">&#9998; Editar</button>
                    <button type="button" class="btn btn-danger-glow" id="btnClearCurrentPatient" title="Borrar toda la información del paciente actual de una sola vez">&#128465; Borrar Paciente Actual</button>
                  </div>
                </div>
              </div>

              <!-- Barra para Re-abrir Expediente del Paciente Anterior (Sin Contraseña / Sin Censura) -->
              <div class="prev-patient-bar glass" id="prevPatientBar" style="display:none">
                <div class="prev-patient-info">
                  <span class="prev-patient-icon" id="prevPatientIcon">&#128194;</span>
                  <div>
                    <span id="prevPatientTitle">Expediente de Paciente Anterior Disponible</span>
                    <span class="prev-patient-sub" id="prevPatientSub">--</span>
                  </div>
                </div>
                <div class="prev-patient-actions">
                  <button type="button" class="btn btn-log btn-prev-open" id="btnReopenPrevPatient">&#128194; Re-abrir Expediente Anterior</button>
                  <button type="button" class="btn btn-log btn-primary" id="btnRestorePrevPatient" style="display:none">&#9989; Establecer como Paciente Actual</button>
                  <button type="button" class="btn btn-log btn-secondary" id="btnBackToCurrentPatient" style="display:none">&#8617; Volver al Paciente Actual</button>
                </div>
              </div>

              <!-- Barra de Privacidad y Desbloqueo con Clave Numérica (2468) — Solo para Paciente Actual -->
              <div class="privacy-gate-bar glass" id="privacyGateBar">
                <div class="privacy-gate-info">
                  <span style="font-size:1.25rem" id="privacyLockIcon">&#128274;</span>
                  <div>
                    <span id="privacyGateTitle">Información Privada Censurada (Paciente Actual)</span>
                    <span class="privacy-gate-sub" id="privacyGateSub">Ingresa la clave numérica de 4 dígitos para visualizar o editar los datos sensibles del paciente actual.</span>
                  </div>
                </div>
                <div class="privacy-gate-form">
                  <input type="password" class="pin-input" id="inpRecordPin" inputmode="numeric" pattern="[0-9]*" maxlength="4" placeholder="Clave numérica" autocomplete="off" />
                  <button type="button" class="btn btn-log btn-primary" id="btnUnlockRecord">&#128275; Desbloquear</button>
                  <button type="button" class="btn btn-log btn-secondary" id="btnLockRecord" style="display:none">&#128274; Censurar Datos</button>
                  <div class="pin-error-msg" id="pinErrorMsg">Clave incorrecta. Ingresa únicamente la clave numérica autorizada.</div>
                </div>
              </div>
 
              <div class="record-scroll">
                <div>
                  <h4 class="record-section-title">Información Personal</h4>
                  <div class="record-stats-row">
                    <div class="record-stat glass rc-age">
                      <span class="record-stat-icon">&#127874;</span>
                      <span class="record-stat-label">Edad</span>
                      <span class="record-stat-value" id="viewAge">--</span>
                    </div>
                    <div class="record-stat glass rc-gender">
                      <span class="record-stat-icon">&#9895;</span>
                      <span class="record-stat-label">Género</span>
                      <span class="record-stat-value" id="viewGender">--</span>
                    </div>
                    <div class="record-stat glass rc-blood">
                      <span class="record-stat-icon">&#128167;</span>
                      <span class="record-stat-label">Tipo de Sangre</span>
                      <span class="record-stat-value" id="viewBlood">--</span>
                    </div>
                  </div>
                </div>
 
                <div>
                  <h4 class="record-section-title">Contacto e Identificación</h4>
                  <div class="record-contact-row">
                    <div class="record-detail-card glass rc-phone">
                      <span class="field-icon ic-contact">&#128222;</span>
                      <div>
                        <div class="record-detail-label">Teléfono / Contacto</div>
                        <div class="record-detail-value" id="viewContact">--</div>
                      </div>
                    </div>
                    <div class="record-detail-card glass rc-id">
                      <span class="field-icon ic-id">&#127380;</span>
                      <div>
                        <div class="record-detail-label">ID del Paciente</div>
                        <div class="record-detail-value" id="viewIdDetail">--</div>
                      </div>
                    </div>
                  </div>
                </div>
 
                <div class="record-notes-card glass">
                  <h4 class="record-section-title">&#128221; Notas Clínicas</h4>
                  <div class="record-notes-body" id="viewNotes">Sin notas registradas.</div>
                </div>
              </div>
            </div>
          </section>
 
          <div class="patient-modal" id="patientModal">
            <div class="patient-modal-backdrop" id="patientModalBackdrop"></div>
            <div class="patient-modal-card glass">
              <div class="patient-modal-head">
                <h3><span class="field-icon ic-name">&#128100;</span>Editar Datos del Paciente</h3>
                <button type="button" class="btn-icon" id="btnClosePatientModal" title="Cerrar">&times;</button>
              </div>
              <form id="patientForm" class="form-grid">
                <div class="form-field">
                  <label for="inpName"><span class="field-icon ic-name">&#128100;</span>Nombre Completo</label>
                  <input type="text" id="inpName" name="name" placeholder="Nombre del paciente" />
                </div>
                <div class="form-field">
                  <label for="inpId"><span class="field-icon ic-id">&#127380;</span>ID del Paciente</label>
                  <input type="text" id="inpId" name="patientId" placeholder="Ej. PT-2048" />
                </div>
                <div class="form-field">
                  <label for="inpBed"><span class="field-icon ic-bed">&#128719;</span>Cama</label>
                  <input type="text" id="inpBed" name="bed" placeholder="Ej. 03" />
                </div>
                <div class="form-field">
                  <label for="inpWard"><span class="field-icon ic-ward">&#127973;</span>Sala / Área</label>
                  <input type="text" id="inpWard" name="ward" placeholder="Ej. UCI" />
                </div>
                <div class="form-field">
                  <label for="inpAge"><span class="field-icon ic-age">&#127874;</span>Edad</label>
                  <input type="number" id="inpAge" name="age" min="0" max="130" placeholder="Años" />
                </div>
                <div class="form-field">
                  <label for="inpBlood"><span class="field-icon ic-blood">&#128167;</span>Grupo Sanguíneo</label>
                  <select id="inpBlood" name="bloodGroup">
                    <option value="">Seleccionar</option>
                    <option value="A+">A+</option>
                    <option value="A-">A-</option>
                    <option value="B+">B+</option>
                    <option value="B-">B-</option>
                    <option value="AB+">AB+</option>
                    <option value="AB-">AB-</option>
                    <option value="O+">O+</option>
                    <option value="O-">O-</option>
                  </select>
                </div>
                <div class="form-field">
                  <label for="inpGender"><span class="field-icon ic-gender">&#9895;</span>Género</label>
                  <select id="inpGender" name="gender">
                    <option value="">Seleccionar</option>
                    <option value="Masculino">Masculino</option>
                    <option value="Femenino">Femenino</option>
                    <option value="Otro">Otro</option>
                  </select>
                </div>
                <div class="form-field">
                  <label for="inpContact"><span class="field-icon ic-contact">&#128222;</span>Contacto</label>
                  <input type="text" id="inpContact" name="contact" placeholder="Teléfono o correo" />
                </div>
                <div class="form-field full">
                  <label for="inpNotes"><span class="field-icon ic-notes">&#128221;</span>Notas Clínicas</label>
                  <textarea id="inpNotes" name="notes" placeholder="Observaciones médicas, alergias, antecedentes, etc."></textarea>
                </div>
              </form>
              <div class="form-actions">
                <button type="button" class="btn btn-primary" id="btnSavePatient">Guardar Cambios</button>
                <button type="button" class="btn btn-secondary" id="btnEmptyFormFields" title="Vaciar todas las casillas del formulario de una vez">&#129529; Vaciar Casillas</button>
                <button type="button" class="btn btn-danger" id="btnClearPatient" title="Borrar toda la información del paciente actual y respaldarlo como paciente anterior">&#128465; Borrar Paciente Actual</button>
                <button type="button" class="btn btn-secondary" id="btnCancelPatient">Cancelar</button>
              </div>
              <div class="save-msg" id="saveMsg"></div>
            </div>
          </div>
 
          <!-- REGISTRO DE DATOS (Sin SpO2 ni Temperatura Corporal) -->
          <section class="page" id="page-logging">
            <div class="logging-page">
              <div class="logging-toolbar glass">
                <div class="logging-controls">
                  <label for="logInterval">Intervalo</label>
                  <select id="logInterval">
                    <option value="2000">2 segundos</option>
                    <option value="3000">3 segundos</option>
                    <option value="5000" selected>5 segundos</option>
                    <option value="10000">10 segundos</option>
                    <option value="15000">15 segundos</option>
                    <option value="30000">30 segundos</option>
                    <option value="60000">60 segundos</option>
                  </select>
                  <button type="button" class="btn btn-log btn-log-start" id="btnLogStart">&#9654; Iniciar</button>
                  <button type="button" class="btn btn-log btn-log-stop" id="btnLogStop">&#9632; Detener</button>
                  <button type="button" class="btn btn-log btn-secondary" id="btnLogClear">Limpiar</button>
                  <button type="button" class="btn btn-log btn-log-export" id="btnLogExport">&#128196; Exportar a Excel</button>
                </div>
                <div class="logging-stats">
                  <span id="logCount">0 registros</span>
                  <span class="log-status-pill stopped" id="logStatus">Detenido</span>
                </div>
              </div>

              <!-- Captura de Onda ECG Cruda a 125 Hz para MATLAB / Python -->
              <div class="raw-ecg-bar glass">
                <div class="raw-ecg-info">
                  <span>&#128200; Captura de Onda ECG Cruda (125 Hz &middot; MATLAB / Python)</span>
                  <span class="raw-ecg-sub" id="rawEcgCount">0 muestras capturadas</span>
                  <span class="log-status-pill stopped" id="rawEcgStatus">En espera</span>
                </div>
                <div class="logging-controls">
                  <button type="button" class="btn btn-log btn-log-start" id="btnRawEcgStart">&#9210; Grabar ECG Crudo</button>
                  <button type="button" class="btn btn-log btn-log-stop" id="btnRawEcgStop">&#9209; Detener</button>
                  <button type="button" class="btn btn-log btn-secondary" id="btnRawEcgClear">Vaciar</button>
                  <button type="button" class="btn btn-log btn-log-export" id="btnRawEcgExport">&#11015; Exportar CSV (125 Hz)</button>
                </div>
              </div>

              <div class="logging-table-wrap glass">
                <div class="logging-table-head">
                  <h4>&#128202; Historial de Signos Vitales y Variabilidad Cardíaca</h4>
                  <span style="font-size:0.72rem;color:var(--muted);font-weight:700" id="logIntervalLabel">Cada 5s</span>
                </div>
                <div class="logging-table-scroll">
                  <table class="log-table">
                    <thead>
                      <tr>
                        <th>#</th>
                        <th>Fecha y Hora</th>
                        <th>BPM</th>
                        <th>Intervalo R-R (ms)</th>
                        <th>HRV RMSSD (ms)</th>
                        <th>Temp. Ambiental (&deg;C)</th>
                        <th>Humedad (%)</th>
                      </tr>
                    </thead>
                    <tbody id="logTableBody">
                      <tr><td colspan="7" class="log-empty">Aún no hay datos registrados. Presiona Iniciar para comenzar a grabar.</td></tr>
                    </tbody>
                  </table>
                </div>
              </div>
            </div>
          </section>
 
          <!-- ALERTAS CLÍNICAS (Sin SpO2 ni Temperatura Corporal) -->
          <section class="page" id="page-alerts">
            <div class="alerts-page">
              <div class="alerts-hero glass">
                <div>
                  <h3>&#128680; Centro de Alertas Clínicas</h3>
                  <p>Estado de sensores en vivo, umbrales personalizables y recomendaciones de cuidado</p>
                </div>
                <span class="alerts-status-badge good" id="alertBadge">SEGURO</span>
              </div>

              <!-- Panel de Umbrales Personalizables y Alarma Sonora Crítica -->
              <div class="thresholds-card glass">
                <div class="thresholds-inputs">
                  <span style="font-size:0.72rem;font-weight:900;text-transform:uppercase;color:var(--text)">&#9881; Umbrales Clínicos:</span>
                  <label class="thresh-item">BPM Mín. <input type="number" id="inpMinBpm" min="30" max="90" value="60" /></label>
                  <label class="thresh-item">BPM Máx. <input type="number" id="inpMaxBpm" min="80" max="200" value="100" /></label>
                  <label class="thresh-item">Temp. Amb. Máx. (&deg;C) <input type="number" id="inpMaxRoom" min="20" max="45" value="28" /></label>
                </div>
                <div class="logging-controls">
                  <button type="button" class="ecg-ctrl-btn active" id="btnCriticalAlarmToggle" title="Activar o silenciar alarma sonora cuando los signos salgan de los umbrales">&#128276; Alarma Crítica: ON</button>
                  <button type="button" class="btn btn-log btn-primary" id="btnSaveThresholds">Guardar Umbrales</button>
                </div>
              </div>
 
              <div class="alerts-summary">
                <div class="alerts-summary-card warn glass">
                  <span id="alertWarnCount">0</span>Advertencias
                </div>
                <div class="alerts-summary-card ok glass">
                  <span id="alertOkCount">0</span>Normales
                </div>
                <div class="alerts-summary-card info glass">
                  <span id="alertInfoCount">0</span>Información
                </div>
              </div>
 
              <div class="alerts-scroll">
                <div class="alerts-section">
                  <h4 class="alerts-section-title">&#10084; Monitoreo Cardíaco</h4>
                  <div class="alert-row alert-info glass" id="alertRow1">
                    <div class="alert-row-icon" id="alertIcon1">&#10084;</div>
                    <div class="alert-row-body">
                      <div class="alert-row-top">
                        <strong id="alertTitle1">Frecuencia Cardíaca</strong>
                        <span class="alert-pill info" id="alertPill1">INFO</span>
                      </div>
                      <p id="alertMsg1">Esperando datos del sensor...</p>
                      <p class="alert-tip" id="alertTip1">Rango normal en reposo: 60–100 BPM.</p>
                    </div>
                  </div>
                  <div class="alert-row alert-info glass" id="alertRow2">
                    <div class="alert-row-icon" id="alertIcon2">&#9889;</div>
                    <div class="alert-row-body">
                      <div class="alert-row-top">
                        <strong id="alertTitle2">Señal de ECG</strong>
                        <span class="alert-pill info" id="alertPill2">INFO</span>
                      </div>
                      <p id="alertMsg2">Verificando señal del electrocardiograma...</p>
                      <p class="alert-tip" id="alertTip2">Asegúrate de que los electrodos RA, LA y RL estén bien adheridos.</p>
                    </div>
                  </div>
                </div>
 
                <div class="alerts-section">
                  <h4 class="alerts-section-title">&#127968; Condiciones Ambientales</h4>
                  <div class="alert-row alert-info glass" id="alertRow5">
                    <div class="alert-row-icon" id="alertIcon5">&#127968;</div>
                    <div class="alert-row-body">
                      <div class="alert-row-top">
                        <strong id="alertTitle5">Ambiente de la Habitación</strong>
                        <span class="alert-pill info" id="alertPill5">INFO</span>
                      </div>
                      <p id="alertMsg5">Revisando temperatura y humedad ambiental...</p>
                      <p class="alert-tip" id="alertTip5">Ambiente ideal: 20–24 &deg;C, humedad entre 40–60%.</p>
                    </div>
                  </div>
                </div>
 
                <div class="alerts-section">
                  <h4 class="alerts-section-title">&#128225; Estado del Sistema</h4>
                  <div class="alert-row alert-info glass" id="alertRow6">
                    <div class="alert-row-icon" id="alertIcon6">&#128246;</div>
                    <div class="alert-row-body">
                      <div class="alert-row-top">
                        <strong id="alertTitle6">Conexión del Dispositivo</strong>
                        <span class="alert-pill info" id="alertPill6">INFO</span>
                      </div>
                      <p id="alertMsg6">Conectando con el monitor ESP32...</p>
                      <p class="alert-tip" id="alertTip6">Verifica que el ESP32 esté encendido y en la misma red WiFi.</p>
                    </div>
                  </div>
                </div>
 
                <div class="alerts-suggestions glass">
                  <h4 class="alerts-section-title">&#128161; Recomendaciones Clínicas</h4>
                  <ul class="alert-suggest-list" id="alertSuggestions">
                    <li>Inicializando todos los sistemas — las recomendaciones aparecerán al recibir datos.</li>
                  </ul>
                </div>
              </div>
            </div>
          </section>
        </div>
      </div>
    </div>
  </div>
 
  <script>
    const $ = (id) => document.getElementById(id);
    const pages = {
      dashboard: { title: "Monitor de Signos", sub: "Monitoreo cardíaco y ambiental en tiempo real" },
      patient: { title: "Expediente del Paciente", sub: "Consulta y edición de información del paciente" },
      logging: { title: "Registro de Datos", sub: "Grabación periódica de signos y exportación a Excel" },
      alerts: { title: "Alertas Clínicas", sub: "Advertencias del sistema y estado de los sensores" }
    };
    const ui = {
      clock: $("clock"), lastUpdate: $("lastUpdate"), pageTitle: $("pageTitle"), pageSubtitle: $("pageSubtitle"),
      bpm: $("bpm"),
      roomTemp: $("roomTemp"), humidity: $("humidity"),
      bpmBar: $("bpmBar"),
      roomTempBar: $("roomTempBar"), humBar: $("humBar"),
      bpmBadge: $("bpmBadge"),
      roomBadge: $("roomBadge"), humBadge: $("humBadge"),
      ecgBadge: $("ecgBadge"),
      alertBadge: $("alertBadge"),
      alertWarnCount: $("alertWarnCount"), alertOkCount: $("alertOkCount"), alertInfoCount: $("alertInfoCount"),
      alertSuggestions: $("alertSuggestions"),
      connText: $("connText"), liveDot: $("liveDot"),
      alertTitle1: $("alertTitle1"), alertMsg1: $("alertMsg1"), alertTip1: $("alertTip1"),
      alertIcon1: $("alertIcon1"), alertPill1: $("alertPill1"), alertRow1: $("alertRow1"),
      alertTitle2: $("alertTitle2"), alertMsg2: $("alertMsg2"), alertTip2: $("alertTip2"),
      alertIcon2: $("alertIcon2"), alertPill2: $("alertPill2"), alertRow2: $("alertRow2"),
      alertTitle5: $("alertTitle5"), alertMsg5: $("alertMsg5"), alertTip5: $("alertTip5"),
      alertIcon5: $("alertIcon5"), alertPill5: $("alertPill5"), alertRow5: $("alertRow5"),
      alertTitle6: $("alertTitle6"), alertMsg6: $("alertMsg6"), alertTip6: $("alertTip6"),
      alertIcon6: $("alertIcon6"), alertPill6: $("alertPill6"), alertRow6: $("alertRow6"),
      patientForm: $("patientForm"), saveMsg: $("saveMsg"),
      patientModal: $("patientModal"),
      viewAvatar: $("viewAvatar"),
      viewName: $("viewName"), viewId: $("viewId"), viewIdDetail: $("viewIdDetail"),
      viewBed: $("viewBed"), viewWard: $("viewWard"),
      viewAge: $("viewAge"), viewGender: $("viewGender"),
      viewBlood: $("viewBlood"),
      viewContact: $("viewContact"), viewNotes: $("viewNotes"),
      heartIcon: $("heartIcon"), dashPatientName: $("dashPatientName"),
      rrVal: $("rrVal"), hrvVal: $("hrvVal"),
      bpmRangeLabel: $("bpmRangeLabel"), roomRangeLabel: $("roomRangeLabel"),
      ecgGainLabel: $("ecgGainLabel"), ecgSpeedLabel: $("ecgSpeedLabel"), ecgFilterLabel: $("ecgFilterLabel")
    };
 
    const THEME_KEY = "phm_theme_v1";
    const PATIENT_KEY = "phm_patient_v1";
    const PREV_PATIENT_KEY = "phm_prev_patient_v1";
    const THRESH_KEY = "phm_thresholds_v1";
    const defaultPatient = {
      name: "", patientId: "", bed: "", ward: "",
      age: "", bloodGroup: "", gender: "", contact: "", notes: ""
    };
    let thresholds = { minBpm: 60, maxBpm: 100, maxRoom: 28, criticalSound: true };
 
    const PLOT_MAX = 1023;
    const ECG_POLL_MS = 25;
    const BPM_UI_MS = 1000;
    const ECG_Y_MARGIN = 24;
    let scrollStep = 1;
    let ecgGain = 1.0;
    let ecgFrozen = false;
    let ecgFilterOn = true;
    let ecgFail = 0, vitalsFail = 0;
    let connOnline = false;
    let connFailStreak = 0;
    const CONN_FAIL_LIMIT = 12;
    let canvasW = 0, canvasH = 0;
    let heightOld = 0;
    let traceReady = false;
    let ecgPollBusy = false;
    let leadsOffState = true;
    let lastVitals = { roomT: 0, hum: 0, bme: false };
    let latestRR = 0;
    let latestHrv = 0;
    let heartAudioCtx = null;
    let heartSoundOn = true;
    let heartSoundTimer = null;
    let lastSoundBpm = 0;
    let lastCriticalAlertMs = 0;
    let audioUnlocked = false;
    let latestBpm = 0;
    let displayedBpm = -1;
    let lastBpmUiTick = 0;
    let lastBeatAnimBpm = 0;
    let bpmUiReady = false;
    let prevLeadsOff = true;
    let logData = [];
    let logTimer = null;
    let logRunning = false;
    const LOG_KEY = "phm_log_es_v2";
    const MAX_LOG_ROWS = 500;

    // Grabación de señal cruda de ECG a 125 Hz (para MATLAB / Python)
    let rawEcgRecording = false;
    let rawEcgData = [];
    let rawEcgStartMs = 0;
    const MAX_RAW_ECG_SAMPLES = 15000; // ~2 minutos a 125 Hz
 
    const canvas = $("ecgCanvas");
    const ctx = canvas.getContext("2d");

    /* Gestión de Tema Claro / Oscuro */
    function applyTheme(theme) {
      const t = theme === "dark" ? "dark" : "light";
      document.documentElement.setAttribute("data-theme", t);
      const btnLight = $("btnThemeLight");
      const btnDark = $("btnThemeDark");
      if (btnLight) btnLight.classList.toggle("active", t === "light");
      if (btnDark) btnDark.classList.toggle("active", t === "dark");
      try { localStorage.setItem(THEME_KEY, t); } catch (e) {}
    }

    function initTheme() {
      let saved = "light";
      try {
        const s = localStorage.getItem(THEME_KEY);
        if (s === "dark" || s === "light") saved = s;
      } catch (e) {}
      applyTheme(saved);

      const btnLight = $("btnThemeLight");
      const btnDark = $("btnThemeDark");
      const btnToggle = $("btnThemeToggle");
      if (btnLight) btnLight.addEventListener("click", () => applyTheme("light"));
      if (btnDark) btnDark.addEventListener("click", () => applyTheme("dark"));
      if (btnToggle) {
        btnToggle.addEventListener("click", () => {
          const current = document.documentElement.getAttribute("data-theme");
          applyTheme(current === "dark" ? "light" : "dark");
        });
      }
    }
    initTheme();
 
    function navigateToPage(id) {
      if (!pages[id]) return;
      document.querySelectorAll(".nav-item").forEach((b) => {
        b.classList.toggle("active", b.dataset.page === id);
      });
      document.querySelectorAll(".page").forEach((p) => p.classList.remove("active"));
      const targetPage = $("page-" + id);
      if (targetPage) {
        targetPage.classList.add("active");
        targetPage.scrollTop = 0;
      }
      ui.pageTitle.textContent = pages[id].title;
      ui.pageSubtitle.textContent = pages[id].sub;
      const soundBtn = $("btnSoundToggle");
      if (soundBtn) soundBtn.style.display = id === "dashboard" ? "" : "none";
      if (id === "dashboard") requestAnimationFrame(resizeCanvas);
      window.scrollTo(0, 0);
    }

    document.querySelectorAll(".nav-item").forEach((btn) => {
      btn.addEventListener("click", () => {
        navigateToPage(btn.dataset.page);
      });
    });

    const btnGoToPatient = $("btnGoToPatient");
    if (btnGoToPatient) {
      btnGoToPatient.addEventListener("click", () => navigateToPage("patient"));
      btnGoToPatient.addEventListener("keydown", (e) => {
        if (e.key === "Enter" || e.key === " ") {
          e.preventDefault();
          navigateToPage("patient");
        }
      });
    }
 
    const ecgStage = () => canvas.parentElement;
 
    function resizeCanvas() {
      const stage = ecgStage();
      if (!stage) return;
      const w = stage.clientWidth;
      const h = stage.clientHeight;
      if (w < 10 || h < 10) return;
      if (w === canvasW && h === canvasH) return;
      canvasW = w;
      canvasH = h;
      canvas.width = w;
      canvas.height = h;
      ctx.setTransform(1, 0, 0, 1, 0, 0);
      ctx.clearRect(0, 0, w, h);
      heightOld = h * 0.54;
      traceReady = false;
    }
 
    if (window.ResizeObserver && ecgStage()) {
      const ro = new ResizeObserver(() => resizeCanvas());
      ro.observe(ecgStage());
    }
    window.addEventListener("resize", resizeCanvas);
    window.addEventListener("orientationchange", () => {
      setTimeout(() => {
        resizeCanvas();
      }, 200);
    });
    requestAnimationFrame(() => requestAnimationFrame(resizeCanvas));
 
    function setBar(el, pct) { if (el) el.style.width = Math.max(6, Math.min(pct, 100)) + "%"; }
    function flashVital(el) {
      if (!el) return;
      el.classList.remove("vital-flash");
      void el.offsetWidth;
      el.classList.add("vital-flash");
    }
    function pulseBpmValue() {
      const el = ui.bpm;
      if (!el) return;
      el.classList.remove("bpm-pulse");
      void el.offsetWidth;
      el.classList.add("bpm-pulse");
    }
    function setBadge(el, text, kind) {
      if (!el) return;
      el.textContent = text;
      if (el.id === "alertBadge") {
        el.className = "alerts-status-badge " + kind;
      } else if (el.id === "ecgBadge") {
        el.className = "ecg-badge-pill " + kind;
      } else {
        el.className = "badge " + kind;
      }
    }
    function fmtTime() {
      return new Date().toLocaleTimeString("es-MX", { hour: "2-digit", minute: "2-digit", second: "2-digit" });
    }
    function touchUpdate() { ui.lastUpdate.textContent = "Ahora mismo"; ui.clock.textContent = fmtTime(); }
 
    function setConn(ok) {
      if (connOnline === ok) return;
      connOnline = ok;
      ui.connText.textContent = ok ? "En línea" : "Sin conexión";
      ui.liveDot.className = ok ? "live-dot" : "live-dot off";
    }
 
    function markConnSuccess() {
      connFailStreak = 0;
      ecgFail = 0;
      setConn(true);
    }
 
    function markConnFailure() {
      connFailStreak++;
      if (connFailStreak >= CONN_FAIL_LIMIT) {
        setConn(false);
      }
    }
 
    function translateGender(g) {
      if (g === "Male") return "Masculino";
      if (g === "Female") return "Femenino";
      if (g === "Other") return "Otro";
      return g || "";
    }

    function loadPatientForm(data) {
      $("inpName").value = data.name || "";
      $("inpId").value = data.patientId || "";
      $("inpBed").value = data.bed || "";
      $("inpWard").value = data.ward || "";
      $("inpAge").value = data.age || "";
      $("inpBlood").value = data.bloodGroup || "";
      $("inpGender").value = translateGender(data.gender);
      $("inpContact").value = data.contact || "";
      $("inpNotes").value = data.notes || "";
    }
 
    function readPatientForm() {
      return {
        name: $("inpName").value.trim(),
        patientId: $("inpId").value.trim(),
        bed: $("inpBed").value.trim(),
        ward: $("inpWard").value.trim(),
        age: $("inpAge").value.trim(),
        bloodGroup: $("inpBlood").value,
        gender: $("inpGender").value,
        contact: $("inpContact").value.trim(),
        notes: $("inpNotes").value.trim()
      };
    }
 
    const RECORD_PIN = "2468";
    let recordUnlocked = false;
    let viewingPreviousPatient = false;

    function hasPatientInfo(data) {
      if (!data) return false;
      return !!(data.name || data.patientId || data.bed || data.ward || data.age || data.bloodGroup || data.gender || data.contact || data.notes);
    }

    function loadPreviousPatientData() {
      try {
        const saved = localStorage.getItem(PREV_PATIENT_KEY);
        if (saved) {
          const parsed = JSON.parse(saved);
          if (hasPatientInfo(parsed)) return { ...defaultPatient, ...parsed };
        }
      } catch (e) {}
      return null;
    }

    function archivePatientAsPrevious(patientObj) {
      if (!hasPatientInfo(patientObj)) return;
      try {
        const toArchive = {
          ...defaultPatient,
          ...patientObj,
          archivedAt: new Date().toLocaleTimeString("es-MX", { hour: "2-digit", minute: "2-digit" })
        };
        localStorage.setItem(PREV_PATIENT_KEY, JSON.stringify(toArchive));
      } catch (e) {}
    }

    function patientInitials(name) {
      const parts = (name || "").trim().split(/\s+/).filter(Boolean);
      if (!parts.length) return "?";
      if (parts.length === 1) return parts[0].slice(0, 2).toUpperCase();
      return (parts[0][0] + parts[parts.length - 1][0]).toUpperCase();
    }

    function applyCensoredClass(CENSORED_ELS, add) {
      CENSORED_ELS.forEach((el) => {
        if (!el) return;
        el.classList.toggle("censored-text", add);
      });
    }

    function updatePrevPatientBarUi() {
      const prevBar = $("prevPatientBar");
      const prevTitle = $("prevPatientTitle");
      const prevSub = $("prevPatientSub");
      const btnReopen = $("btnReopenPrevPatient");
      const btnRestore = $("btnRestorePrevPatient");
      const btnBack = $("btnBackToCurrentPatient");
      const prevData = loadPreviousPatientData();

      if (!prevBar) return;
      if (!prevData) {
        prevBar.style.display = "none";
        return;
      }

      prevBar.style.display = "";
      const pName = prevData.name || "Sin nombre";
      const pId = prevData.patientId ? " (ID: " + prevData.patientId + ")" : "";
      const timeNote = prevData.archivedAt ? " · Guardado a las " + prevData.archivedAt : "";

      if (viewingPreviousPatient) {
        prevBar.classList.add("active-prev");
        if (prevTitle) prevTitle.textContent = "Expediente Re-abierto: " + pName + pId;
        if (prevSub) prevSub.textContent = "Visualizando expediente del paciente anterior (no requiere contraseña de censura)." + timeNote;
        if (btnReopen) btnReopen.style.display = "none";
        if (btnRestore) btnRestore.style.display = "";
        if (btnBack) btnBack.style.display = "";
      } else {
        prevBar.classList.remove("active-prev");
        if (prevTitle) prevTitle.textContent = "Paciente Anterior: " + pName + pId;
        if (prevSub) prevSub.textContent = "Puedes re-abrir su expediente en cualquier momento sin necesidad de contraseña." + timeNote;
        if (btnReopen) btnReopen.style.display = "";
        if (btnRestore) btnRestore.style.display = "none";
        if (btnBack) btnBack.style.display = "none";
      }
    }

    function updatePatientPreview(data) {
      const prevData = loadPreviousPatientData();
      if (viewingPreviousPatient && !prevData) {
        viewingPreviousPatient = false;
      }
      const activeData = viewingPreviousPatient ? prevData : (data || loadPatientData());
      const currentHasInfo = hasPatientInfo(activeData);

      // El nombre del paciente (y su avatar) siempre son visibles
      ui.viewName.textContent = activeData.name || (viewingPreviousPatient ? "Paciente anterior" : "Sin paciente registrado");
      ui.viewAvatar.textContent = patientInitials(activeData.name);

      const privateEls = [
        ui.viewId, ui.viewIdDetail, ui.viewBed, ui.viewWard,
        ui.viewAge, ui.viewGender, ui.viewBlood, ui.viewContact, ui.viewNotes
      ];

      const banner = $("recordBanner");
      const modeChip = $("viewRecordModeChip");
      const gateBar = $("privacyGateBar");
      const lockIcon = $("privacyLockIcon");
      const gateTitle = $("privacyGateTitle");
      const gateSub = $("privacyGateSub");
      const inpPin = $("inpRecordPin");
      const btnUnlock = $("btnUnlockRecord");
      const btnLock = $("btnLockRecord");
      const btnEdit = $("btnEditPatient");
      const btnClearCurrent = $("btnClearCurrentPatient");
      const errEl = $("pinErrorMsg");

      if (banner) banner.classList.toggle("prev-mode", viewingPreviousPatient);
      if (modeChip) modeChip.style.display = viewingPreviousPatient ? "" : "none";

      // Si estamos viendo el expediente de un paciente anterior, NUNCA se censura ni pide contraseña
      if (viewingPreviousPatient) {
        ui.viewId.textContent = activeData.patientId || "Sin ID";
        ui.viewIdDetail.textContent = activeData.patientId || "--";
        ui.viewBed.textContent = activeData.bed || "--";
        ui.viewWard.textContent = activeData.ward || "--";
        ui.viewAge.textContent = activeData.age ? activeData.age + " años" : "--";
        ui.viewGender.textContent = translateGender(activeData.gender) || "--";
        ui.viewBlood.textContent = activeData.bloodGroup || "--";
        ui.viewContact.textContent = activeData.contact || "--";
        ui.viewNotes.textContent = activeData.notes || "Sin notas registradas.";
        applyCensoredClass(privateEls, false);

        if (gateBar) gateBar.style.display = "none";
        if (btnEdit) btnEdit.style.display = "none";
        if (btnClearCurrent) btnClearCurrent.style.display = "none";
        updatePrevPatientBarUi();
        updateDashPatient();
        return;
      }

      // Modo Paciente Actual: la opción de censura con contraseña aplica SOLO al paciente actual
      if (gateBar) gateBar.style.display = currentHasInfo ? "" : "none";
      if (btnClearCurrent) btnClearCurrent.style.display = currentHasInfo ? "" : "none";

      if (currentHasInfo && !recordUnlocked) {
        ui.viewId.textContent = "ID: ••••••";
        ui.viewIdDetail.textContent = "••••••••";
        ui.viewBed.textContent = "•••";
        ui.viewWard.textContent = "••••••";
        ui.viewAge.textContent = "•••";
        ui.viewGender.textContent = "••••••••";
        ui.viewBlood.textContent = "•••";
        ui.viewContact.textContent = "••••••••••";
        ui.viewNotes.textContent = "Información privada del paciente actual censurada. Ingresa la clave numérica en el panel superior para desbloquear.";
        applyCensoredClass(privateEls, true);

        if (gateBar) gateBar.classList.remove("unlocked");
        if (lockIcon) lockIcon.innerHTML = "&#128274;";
        if (gateTitle) gateTitle.textContent = "Información Privada Censurada (Paciente Actual)";
        if (gateSub) gateSub.textContent = "Ingresa la clave numérica de 4 dígitos para visualizar o editar los datos sensibles del paciente actual.";
        if (inpPin) inpPin.style.display = "";
        if (btnUnlock) btnUnlock.style.display = "";
        if (btnLock) btnLock.style.display = "none";
        if (btnEdit) btnEdit.style.display = "none";
      } else {
        ui.viewId.textContent = activeData.patientId || "Sin ID";
        ui.viewIdDetail.textContent = activeData.patientId || "--";
        ui.viewBed.textContent = activeData.bed || "--";
        ui.viewWard.textContent = activeData.ward || "--";
        ui.viewAge.textContent = activeData.age ? activeData.age + " años" : "--";
        ui.viewGender.textContent = translateGender(activeData.gender) || "--";
        ui.viewBlood.textContent = activeData.bloodGroup || "--";
        ui.viewContact.textContent = activeData.contact || "--";
        ui.viewNotes.textContent = activeData.notes || "Sin notas registradas.";
        applyCensoredClass(privateEls, false);

        if (gateBar) gateBar.classList.add("unlocked");
        if (lockIcon) lockIcon.innerHTML = "&#128275;";
        if (gateTitle) gateTitle.textContent = "Expediente Actual Desbloqueado";
        if (gateSub) gateSub.textContent = "La información confidencial del paciente actual es visible y editable.";
        if (inpPin) { inpPin.style.display = "none"; inpPin.value = ""; }
        if (btnUnlock) btnUnlock.style.display = "none";
        if (btnLock) btnLock.style.display = currentHasInfo ? "" : "none";
        if (btnEdit) {
          btnEdit.style.display = "";
          btnEdit.innerHTML = currentHasInfo ? "&#9998; Editar" : "&#10010; Registrar Paciente";
        }
        if (errEl) errEl.classList.remove("show");
      }

      updatePrevPatientBarUi();
      updateDashPatient();
    }

    function tryUnlockRecord() {
      const inpPin = $("inpRecordPin");
      const errEl = $("pinErrorMsg");
      if (!inpPin) return;
      const val = inpPin.value.replace(/[^0-9]/g, "");
      inpPin.value = val;
      if (val === RECORD_PIN) {
        recordUnlocked = true;
        if (errEl) errEl.classList.remove("show");
        updatePatientPreview(loadPatientData());
      } else {
        recordUnlocked = false;
        if (errEl) {
          errEl.textContent = "Clave incorrecta. Ingresa únicamente la clave numérica autorizada.";
          errEl.classList.add("show");
        }
        inpPin.value = "";
        inpPin.focus();
      }
    }

    function lockRecord() {
      recordUnlocked = false;
      const errEl = $("pinErrorMsg");
      if (errEl) errEl.classList.remove("show");
      updatePatientPreview(loadPatientData());
    }

    function openPatientModal() {
      const current = loadPatientData();
      if (hasPatientInfo(current) && !recordUnlocked && !viewingPreviousPatient) return;
      viewingPreviousPatient = false;
      loadPatientForm(current);
      ui.saveMsg.textContent = "";
      ui.patientModal.classList.add("open");
    }
 
    function closePatientModal() {
      ui.patientModal.classList.remove("open");
      ui.saveMsg.textContent = "";
    }
 
    function savePatient() {
      const data = readPatientForm();
      if (!data.name && !data.patientId) {
        ui.saveMsg.textContent = "Ingresa al menos el nombre o el ID del paciente.";
        ui.saveMsg.style.color = "#ef4444";
        return;
      }
      try {
        const existing = loadPatientData();
        // Si ya había un paciente distinto registrado, respaldarlo automáticamente como Paciente Anterior
        if (hasPatientInfo(existing) && (existing.name !== data.name || existing.patientId !== data.patientId)) {
          archivePatientAsPrevious(existing);
        }
        viewingPreviousPatient = false;
        localStorage.setItem(PATIENT_KEY, JSON.stringify(data));
        updatePatientPreview(data);
        ui.saveMsg.textContent = "Datos del paciente actual guardados.";
        ui.saveMsg.style.color = "#16a34a";
        setTimeout(closePatientModal, 400);
      } catch (e) {
        ui.saveMsg.textContent = "No se pudo guardar. El almacenamiento del navegador podría estar lleno.";
        ui.saveMsg.style.color = "#ef4444";
      }
    }

    // Vacía únicamente las casillas del formulario de una sola vez para no borrar campo por campo
    function emptyFormFieldsOnly() {
      loadPatientForm(defaultPatient);
      ui.saveMsg.textContent = "Todas las casillas fueron vaciadas. Escribe los nuevos datos o presiona Borrar Paciente Actual.";
      ui.saveMsg.style.color = "#3b82f6";
      const inpName = $("inpName");
      if (inpName) inpName.focus();
    }
 
    // Borra toda la información del paciente actual de una sola vez y lo respalda como Paciente Anterior
    function clearPatientForm() {
      const current = loadPatientData();
      if (hasPatientInfo(current)) {
        archivePatientAsPrevious(current);
      }
      viewingPreviousPatient = false;
      recordUnlocked = false;
      loadPatientForm(defaultPatient);
      try { localStorage.removeItem(PATIENT_KEY); } catch (e) {}
      updatePatientPreview(defaultPatient);
      ui.saveMsg.textContent = "Información del paciente actual borrada (respaldada en Paciente Anterior).";
      ui.saveMsg.style.color = "#64748b";
      setTimeout(closePatientModal, 450);
    }

    function clearCurrentPatientDirect() {
      const current = loadPatientData();
      if (!hasPatientInfo(current)) return;
      const pLabel = current.name || current.patientId || "actual";
      if (!confirm("¿Deseas borrar toda la información del paciente " + pLabel + " de una sola vez?\n\nSu expediente se guardará como 'Paciente Anterior' por si necesitas re-abrirlo más adelante.")) {
        return;
      }
      archivePatientAsPrevious(current);
      viewingPreviousPatient = false;
      recordUnlocked = false;
      loadPatientForm(defaultPatient);
      try { localStorage.removeItem(PATIENT_KEY); } catch (e) {}
      updatePatientPreview(defaultPatient);
    }

    // Re-abre el expediente del paciente anterior SIN pedir contraseña de censura
    function reopenPreviousPatient() {
      const prev = loadPreviousPatientData();
      if (!prev) return;
      viewingPreviousPatient = true;
      updatePatientPreview(prev);
    }

    function backToCurrentPatient() {
      viewingPreviousPatient = false;
      updatePatientPreview(loadPatientData());
    }

    function restorePreviousAsCurrentPatient() {
      const prev = loadPreviousPatientData();
      if (!prev) return;
      const current = loadPatientData();
      const cleanPrev = {
        name: prev.name || "",
        patientId: prev.patientId || "",
        bed: prev.bed || "",
        ward: prev.ward || "",
        age: prev.age || "",
        bloodGroup: prev.bloodGroup || "",
        gender: prev.gender || "",
        contact: prev.contact || "",
        notes: prev.notes || ""
      };
      try {
        if (hasPatientInfo(current)) {
          archivePatientAsPrevious(current);
        } else {
          localStorage.removeItem(PREV_PATIENT_KEY);
        }
        localStorage.setItem(PATIENT_KEY, JSON.stringify(cleanPrev));
      } catch (e) {}
      viewingPreviousPatient = false;
      // Al re-abrir/restaurar un paciente anterior, queda visible sin exigir contraseña
      recordUnlocked = true;
      updatePatientPreview(cleanPrev);
    }
 
    function loadPatientData() {
      try {
        const saved = localStorage.getItem(PATIENT_KEY);
        if (saved) return { ...defaultPatient, ...JSON.parse(saved) };
      } catch (e) {}
      return { ...defaultPatient };
    }

    function initPatientForm() {
      const data = loadPatientData();
      updatePatientPreview(data);

      const inpPin = $("inpRecordPin");
      const btnUnlock = $("btnUnlockRecord");
      const btnLock = $("btnLockRecord");
      if (inpPin) {
        inpPin.addEventListener("input", () => {
          inpPin.value = inpPin.value.replace(/[^0-9]/g, "");
          const errEl = $("pinErrorMsg");
          if (errEl) errEl.classList.remove("show");
        });
        inpPin.addEventListener("keydown", (e) => {
          if (e.key === "Enter") {
            e.preventDefault();
            tryUnlockRecord();
          }
        });
      }
      if (btnUnlock) btnUnlock.addEventListener("click", tryUnlockRecord);
      if (btnLock) btnLock.addEventListener("click", lockRecord);

      $("btnEditPatient").addEventListener("click", openPatientModal);
      if ($("btnClearCurrentPatient")) $("btnClearCurrentPatient").addEventListener("click", clearCurrentPatientDirect);
      if ($("btnEmptyFormFields")) $("btnEmptyFormFields").addEventListener("click", emptyFormFieldsOnly);
      if ($("btnReopenPrevPatient")) $("btnReopenPrevPatient").addEventListener("click", reopenPreviousPatient);
      if ($("btnBackToCurrentPatient")) $("btnBackToCurrentPatient").addEventListener("click", backToCurrentPatient);
      if ($("btnRestorePrevPatient")) $("btnRestorePrevPatient").addEventListener("click", restorePreviousAsCurrentPatient);
      $("btnClosePatientModal").addEventListener("click", closePatientModal);
      $("btnCancelPatient").addEventListener("click", closePatientModal);
      $("patientModalBackdrop").addEventListener("click", closePatientModal);
      $("btnSavePatient").addEventListener("click", savePatient);
      $("btnClearPatient").addEventListener("click", clearPatientForm);
      ui.patientForm.addEventListener("submit", (e) => { e.preventDefault(); savePatient(); });
    }
    initPatientForm();
 
    function fmtLogTime(d) {
      return d.toLocaleString("es-MX", {
        year: "numeric", month: "2-digit", day: "2-digit",
        hour: "2-digit", minute: "2-digit", second: "2-digit"
      });
    }
 
    function captureLogRow() {
      const bpmVal = parseInt(ui.bpm.textContent, 10);
      return {
        ts: fmtLogTime(new Date()),
        bpm: (!isNaN(bpmVal) && ui.bpm.textContent !== "--") ? bpmVal : "",
        rr: latestRR > 0 ? latestRR : "",
        hrv: latestHrv > 0 ? latestHrv : "",
        roomT: lastVitals.bme ? lastVitals.roomT.toFixed(1) : "",
        hum: lastVitals.bme ? lastVitals.hum.toFixed(1) : ""
      };
    }
 
    function updateLogTable() {
      const tbody = $("logTableBody");
      if (!logData.length) {
        tbody.innerHTML = '<tr><td colspan="7" class="log-empty">Aún no hay datos registrados. Presiona Iniciar para comenzar a grabar.</td></tr>';
        $("logCount").textContent = "0 registros";
        return;
      }
      $("logCount").textContent = logData.length + (logData.length === 1 ? " registro" : " registros");
      let html = "";
      const start = Math.max(0, logData.length - 200);
      for (let i = start; i < logData.length; i++) {
        const r = logData[i];
        html += "<tr><td>" + (i + 1) + "</td><td>" + r.ts + "</td><td>" + (r.bpm !== "" && r.bpm != null ? r.bpm : "--") +
          "</td><td>" + (r.rr !== "" && r.rr != null ? r.rr : "--") +
          "</td><td>" + (r.hrv !== "" && r.hrv != null ? r.hrv : "--") +
          "</td><td>" + (r.roomT !== "" && r.roomT != null ? r.roomT : "--") +
          "</td><td>" + (r.hum !== "" && r.hum != null ? r.hum : "--") + "</td></tr>";
      }
      tbody.innerHTML = html;
      const scroll = tbody.closest(".logging-table-scroll");
      if (scroll) scroll.scrollTop = scroll.scrollHeight;
    }
 
    function saveLogData() {
      try { localStorage.setItem(LOG_KEY, JSON.stringify(logData)); } catch (e) {}
    }
 
    function loadLogData() {
      try {
        const saved = localStorage.getItem(LOG_KEY);
        if (saved) logData = JSON.parse(saved);
      } catch (e) { logData = []; }
      updateLogTable();
    }
 
    function addLogEntry() {
      logData.push(captureLogRow());
      if (logData.length > MAX_LOG_ROWS) logData.shift();
      updateLogTable();
      saveLogData();
    }
 
    function getLogIntervalMs() {
      return parseInt($("logInterval").value, 10) || 5000;
    }
 
    function updateLogIntervalLabel() {
      const ms = getLogIntervalMs();
      const sec = ms / 1000;
      $("logIntervalLabel").textContent = "Cada " + sec + "s";
    }
 
    function startLogging() {
      if (logRunning) return;
      logRunning = true;
      $("logStatus").textContent = "Grabando";
      $("logStatus").className = "log-status-pill running";
      addLogEntry();
      logTimer = setInterval(addLogEntry, getLogIntervalMs());
    }
 
    function stopLogging() {
      logRunning = false;
      if (logTimer) { clearInterval(logTimer); logTimer = null; }
      $("logStatus").textContent = "Detenido";
      $("logStatus").className = "log-status-pill stopped";
    }
 
    function restartLoggingIfActive() {
      if (!logRunning) return;
      stopLogging();
      startLogging();
    }
 
    function clearLogging() {
      stopLogging();
      logData = [];
      try { localStorage.removeItem(LOG_KEY); } catch (e) {}
      updateLogTable();
    }
 
    function csvCell(v) {
      return '"' + String(v == null ? "" : v).replace(/"/g, '""') + '"';
    }
 
    function exportLogExcel() {
      if (!logData.length) {
        alert("No hay datos para exportar. Inicia el registro primero.");
        return;
      }
      const p = loadPatientData();
      const rows = [];
      rows.push(["Monitor de Salud del Paciente - Registro de Datos"]);
      rows.push([]);
      rows.push(["Nombre del Paciente", p.name || "N/D"]);
      rows.push(["ID del Paciente", p.patientId || "N/D"]);
      rows.push(["Cama", p.bed || "N/D"]);
      rows.push(["Sala / Área", p.ward || "N/D"]);
      rows.push(["Edad", p.age ? p.age + " años" : "N/D"]);
      rows.push(["Género", translateGender(p.gender) || "N/D"]);
      rows.push(["Grupo Sanguíneo", p.bloodGroup || "N/D"]);
      rows.push(["Contacto", p.contact || "N/D"]);
      rows.push(["Notas Clínicas", p.notes || "N/D"]);
      rows.push(["Fecha de Exportación", fmtLogTime(new Date())]);
      rows.push(["Intervalo de Registro", (getLogIntervalMs() / 1000) + " segundos"]);
      rows.push(["Total de Registros", logData.length]);
      rows.push([]);
      rows.push(["#", "Fecha y Hora", "BPM", "Intervalo R-R (ms)", "HRV RMSSD (ms)", "Temp. Ambiental (C)", "Humedad (%)"]);
      logData.forEach((r, i) => {
        rows.push([i + 1, r.ts, r.bpm, r.rr || "", r.hrv || "", r.roomT, r.hum]);
      });
      const csv = rows.map((row) => row.map(csvCell).join(",")).join("\r\n");
      const blob = new Blob(["\ufeff" + csv], { type: "application/vnd.ms-excel;charset=utf-8;" });
      const url = URL.createObjectURL(blob);
      const a = document.createElement("a");
      const date = new Date().toISOString().slice(0, 10);
      const pname = (p.name || "Paciente").replace(/[^a-z0-9]/gi, "_");
      a.href = url;
      a.download = "Monitor_Signos_" + pname + "_" + date + ".xls";
      document.body.appendChild(a);
      a.click();
      document.body.removeChild(a);
      URL.revokeObjectURL(url);
    }

    /* Grabación y Exportación de Señal Cruda de ECG a 125 Hz (MATLAB / Python) */
    function updateRawEcgUi() {
      const cntEl = $("rawEcgCount");
      const stEl = $("rawEcgStatus");
      if (cntEl) {
        const secs = (rawEcgData.length * 0.008).toFixed(1);
        cntEl.textContent = rawEcgData.length + " muestras (" + secs + " s)";
      }
      if (stEl) {
        stEl.textContent = rawEcgRecording ? "Grabando 125 Hz" : "En espera";
        stEl.className = rawEcgRecording ? "log-status-pill running" : "log-status-pill stopped";
      }
    }

    function startRawEcgRecording() {
      if (rawEcgRecording) return;
      if (!rawEcgData.length) rawEcgStartMs = Date.now();
      rawEcgRecording = true;
      updateRawEcgUi();
    }

    function stopRawEcgRecording() {
      rawEcgRecording = false;
      updateRawEcgUi();
    }

    function clearRawEcgRecording() {
      rawEcgRecording = false;
      rawEcgData = [];
      rawEcgStartMs = 0;
      updateRawEcgUi();
    }

    function exportRawEcgCsv() {
      if (!rawEcgData.length) {
        alert("No hay muestras crudas de ECG grabadas. Presiona 'Grabar ECG Crudo' primero.");
        return;
      }
      const p = loadPatientData();
      const lines = [];
      lines.push("# Monitor de Salud del Paciente - Senal Cruda ECG (~125 Hz)");
      lines.push("# Paciente: " + (p.name || "N/D") + " | ID: " + (p.patientId || "N/D") + " | Fecha: " + fmtLogTime(new Date()));
      lines.push("Muestra,Tiempo_ms,ADC_0_1023,Voltaje_Est_mV,BPM,Intervalo_RR_ms,HRV_RMSSD_ms,Electrodos_Desconectados");
      for (let i = 0; i < rawEcgData.length; i++) {
        const s = rawEcgData[i];
        lines.push([i + 1, s.t, s.adc, s.mv, s.bpm, s.rr, s.hrv, s.lo].join(","));
      }
      const blob = new Blob(["\ufeff" + lines.join("\r\n")], { type: "text/csv;charset=utf-8;" });
      const url = URL.createObjectURL(blob);
      const a = document.createElement("a");
      const date = new Date().toISOString().slice(0, 10);
      const pname = (p.name || "Paciente").replace(/[^a-z0-9]/gi, "_");
      a.href = url;
      a.download = "ECG_Crudo_125Hz_" + pname + "_" + date + ".csv";
      document.body.appendChild(a);
      a.click();
      document.body.removeChild(a);
      URL.revokeObjectURL(url);
    }
 
    function initLogging() {
      loadLogData();
      updateLogIntervalLabel();
      updateRawEcgUi();
      $("logInterval").addEventListener("change", () => {
        updateLogIntervalLabel();
        restartLoggingIfActive();
      });
      $("btnLogStart").addEventListener("click", startLogging);
      $("btnLogStop").addEventListener("click", stopLogging);
      $("btnLogClear").addEventListener("click", () => {
        if (!logData.length || confirm("¿Deseas borrar todos los datos registrados?")) clearLogging();
      });
      $("btnLogExport").addEventListener("click", exportLogExcel);

      $("btnRawEcgStart").addEventListener("click", startRawEcgRecording);
      $("btnRawEcgStop").addEventListener("click", stopRawEcgRecording);
      $("btnRawEcgClear").addEventListener("click", clearRawEcgRecording);
      $("btnRawEcgExport").addEventListener("click", exportRawEcgCsv);
    }
    initLogging();
 
    function updateRoomUi(roomT, hum, bmeOk) {
      if (bmeOk) {
        ui.roomTemp.textContent = roomT.toFixed(1);
        ui.humidity.textContent = hum.toFixed(1);
        flashVital($("roomTempWrap"));
        flashVital($("humidityWrap"));
        setBar(ui.roomTempBar, Math.min(roomT * 3, 100));
        setBar(ui.humBar, hum);
        const tempOk = roomT >= 18 && roomT <= thresholds.maxRoom;
        const humOk = hum >= 30 && hum <= 70;
        setBadge(ui.roomBadge, tempOk ? "NORMAL" : "REVISAR", tempOk ? "good" : "watch");
        setBadge(ui.humBadge, humOk ? "NORMAL" : "REVISAR", humOk ? "good" : "watch");
      } else {
        ui.roomTemp.textContent = "--";
        ui.humidity.textContent = "--";
        setBar(ui.roomTempBar, 6);
        setBar(ui.humBar, 6);
        setBadge(ui.roomBadge, "ESPERA", "watch");
        setBadge(ui.humBadge, "ESPERA", "watch");
      }
    }
 
    function getHeartAudioCtx() {
      if (!heartAudioCtx) {
        heartAudioCtx = new (window.AudioContext || window.webkitAudioContext)();
      }
      return heartAudioCtx;
    }
 
    async function unlockHeartAudio() {
      try {
        const ctx = getHeartAudioCtx();
        if (ctx.state === "suspended") await ctx.resume();
        const buffer = ctx.createBuffer(1, 1, 22050);
        const source = ctx.createBufferSource();
        source.buffer = buffer;
        source.connect(ctx.destination);
        source.start(0);
        audioUnlocked = true;
        if (heartSoundOn && latestBpm > 0 && !leadsOffState) startHeartSound(latestBpm);
      } catch (e) {}
    }

    function playCriticalAlarmBeep() {
      if (!thresholds.criticalSound || !audioUnlocked) return;
      const now = Date.now();
      if (now - lastCriticalAlertMs < 3500) return;
      lastCriticalAlertMs = now;
      try {
        const ctx = getHeartAudioCtx();
        const t = ctx.currentTime;
        const master = ctx.createGain();
        master.gain.setValueAtTime(0.18, t);
        master.connect(ctx.destination);
        [0, 0.16, 0.32].forEach((offset, idx) => {
          const osc = ctx.createOscillator();
          const g = ctx.createGain();
          osc.type = "triangle";
          osc.frequency.setValueAtTime(idx % 2 === 0 ? 1046 : 880, t + offset);
          g.gain.setValueAtTime(0.001, t + offset);
          g.gain.linearRampToValueAtTime(1, t + offset + 0.01);
          g.gain.exponentialRampToValueAtTime(0.001, t + offset + 0.12);
          osc.connect(g);
          g.connect(master);
          osc.start(t + offset);
          osc.stop(t + offset + 0.13);
        });
      } catch (e) {}
    }
 
    function playMonitorBeep() {
      if (!heartSoundOn || !audioUnlocked) return;
      try {
        const ctx = getHeartAudioCtx();
        const t = ctx.currentTime;
        const master = ctx.createGain();
        master.gain.setValueAtTime(0.14, t);
        master.connect(ctx.destination);
 
        const osc1 = ctx.createOscillator();
        const g1 = ctx.createGain();
        osc1.type = "sine";
        osc1.frequency.setValueAtTime(920, t);
        osc1.frequency.exponentialRampToValueAtTime(720, t + 0.05);
        g1.gain.setValueAtTime(0, t);
        g1.gain.linearRampToValueAtTime(1, t + 0.006);
        g1.gain.exponentialRampToValueAtTime(0.001, t + 0.065);
        osc1.connect(g1);
        g1.connect(master);
        osc1.start(t);
        osc1.stop(t + 0.07);
 
        const osc2 = ctx.createOscillator();
        const g2 = ctx.createGain();
        osc2.type = "sine";
        osc2.frequency.setValueAtTime(580, t + 0.09);
        g2.gain.setValueAtTime(0, t + 0.09);
        g2.gain.linearRampToValueAtTime(0.55, t + 0.1);
        g2.gain.exponentialRampToValueAtTime(0.001, t + 0.17);
        osc2.connect(g2);
        g2.connect(master);
        osc2.start(t + 0.09);
        osc2.stop(t + 0.18);
      } catch (e) {}
    }
 
    function stopHeartSound() {
      if (heartSoundTimer) {
        clearInterval(heartSoundTimer);
        heartSoundTimer = null;
      }
      lastSoundBpm = 0;
    }
 
    function startHeartSound(bpm) {
      if (!bpm || bpm <= 0 || leadsOffState) {
        stopHeartSound();
        return;
      }
      if (!heartSoundOn) {
        stopHeartSound();
        return;
      }
      if (heartSoundTimer && lastSoundBpm === bpm) return;
      stopHeartSound();
      lastSoundBpm = bpm;
      const interval = 60000 / bpm;
      if (audioUnlocked) playMonitorBeep();
      heartSoundTimer = setInterval(() => {
        if (audioUnlocked) playMonitorBeep();
      }, interval);
    }
 
    function syncSoundToggleBtn() {
      const btn = $("btnSoundToggle");
      if (!btn) return;
      btn.classList.toggle("muted", !heartSoundOn);
      btn.title = heartSoundOn ? "Silenciar sonido del latido" : "Activar sonido del latido";
      btn.setAttribute("aria-label", btn.title);
    }
 
    function initHeartSound() {
      syncSoundToggleBtn();
      const unlockOnce = () => { unlockHeartAudio(); };
      document.addEventListener("click", unlockOnce, { once: true, passive: true, capture: true });
      document.addEventListener("touchstart", unlockOnce, { once: true, passive: true, capture: true });
      $("btnSoundToggle").addEventListener("click", async (e) => {
        e.stopPropagation();
        await unlockHeartAudio();
        heartSoundOn = !heartSoundOn;
        syncSoundToggleBtn();
        if (heartSoundOn) {
          if (latestBpm > 0 && !leadsOffState) startHeartSound(latestBpm);
        } else {
          stopHeartSound();
        }
      });
    }
    initHeartSound();
 
    function updateDashPatient() {
      try {
        const saved = localStorage.getItem(PATIENT_KEY);
        if (saved) {
          const p = JSON.parse(saved);
          if (p.name) {
            ui.dashPatientName.textContent = p.name;
            return;
          }
        }
      } catch (e) {}
      ui.dashPatientName.textContent = "Monitor de Paciente";
    }
 
    function setHeartBeatAnim(bpm) {
      const el = ui.heartIcon;
      if (!el) return;
      const active = bpm > 0 && !leadsOffState;
      if (!active) {
        el.classList.remove("beating");
        lastBeatAnimBpm = 0;
        stopHeartSound();
        return;
      }
      if (!el.classList.contains("beating")) el.classList.add("beating");
      if (lastBeatAnimBpm !== bpm) {
        lastBeatAnimBpm = bpm;
        el.style.setProperty("--beat-dur", (60 / bpm) + "s");
      }
      startHeartSound(bpm);
    }
 
    function applyBpmUi(bpm) {
      displayedBpm = bpm;
      if (bpm > 0) {
        const changed = ui.bpm.textContent !== String(bpm);
        ui.bpm.textContent = bpm;
        if (changed) pulseBpmValue();
        setBar(ui.bpmBar, bpm);
        const normal = bpm >= thresholds.minBpm && bpm <= thresholds.maxBpm;
        setBadge(ui.bpmBadge, normal ? "NORMAL" : "REVISAR", normal ? "good" : "watch");
        setHeartBeatAnim(bpm);
        if (ui.rrVal) ui.rrVal.textContent = latestRR > 0 ? latestRR : Math.round(60000 / bpm);
        if (ui.hrvVal) ui.hrvVal.textContent = latestHrv > 0 ? latestHrv : "--";
      } else {
        ui.bpm.textContent = "--";
        if (ui.rrVal) ui.rrVal.textContent = "--";
        if (ui.hrvVal) ui.hrvVal.textContent = "--";
        setBar(ui.bpmBar, 6);
        setBadge(ui.bpmBadge, "ESPERA", "watch");
        setHeartBeatAnim(0);
      }
    }
 
    function maybeUpdateBpmUi(bpm) {
      latestBpm = bpm;
      const now = Date.now();
      const leadsChanged = prevLeadsOff !== leadsOffState;
      prevLeadsOff = leadsOffState;
      const urgent = bpm <= 0 || leadsOffState || leadsChanged;
      if (urgent) {
        lastBpmUiTick = now;
        bpmUiReady = false;
        applyBpmUi(bpm);
        return;
      }
      if (!bpmUiReady || now - lastBpmUiTick >= BPM_UI_MS) {
        lastBpmUiTick = now;
        bpmUiReady = true;
        applyBpmUi(bpm);
      }
    }
 
    function setAlertRow(n, cfg) {
      const row = ui["alertRow" + n];
      const pill = ui["alertPill" + n];
      if (!row || !pill) return cfg.state;
      ui["alertTitle" + n].textContent = cfg.title;
      ui["alertMsg" + n].textContent = cfg.msg;
      if (ui["alertTip" + n]) ui["alertTip" + n].textContent = cfg.tip;
      if (ui["alertIcon" + n]) ui["alertIcon" + n].textContent = cfg.icon;
      pill.textContent = cfg.pill;
      pill.className = "alert-pill " + cfg.state;
      row.className = "alert-row alert-" + cfg.state + " glass";
      return cfg.state;
    }
 
    /* Configuración de Umbrales Personalizables y Controles del Osciloscopio ECG */
    function syncThresholdsUi() {
      if ($("inpMinBpm")) $("inpMinBpm").value = thresholds.minBpm;
      if ($("inpMaxBpm")) $("inpMaxBpm").value = thresholds.maxBpm;
      if ($("inpMaxRoom")) $("inpMaxRoom").value = thresholds.maxRoom;
      if (ui.bpmRangeLabel) ui.bpmRangeLabel.textContent = "Rango normal: " + thresholds.minBpm + " – " + thresholds.maxBpm + " BPM";
      if (ui.roomRangeLabel) ui.roomRangeLabel.textContent = "Rango ideal: 18 – " + thresholds.maxRoom + " °C";
      const btnCrit = $("btnCriticalAlarmToggle");
      if (btnCrit) {
        btnCrit.classList.toggle("active", !!thresholds.criticalSound);
        btnCrit.innerHTML = thresholds.criticalSound ? "&#128276; Alarma Crítica: ON" : "&#128277; Alarma Crítica: OFF";
      }
    }

    function initThresholdsAndControls() {
      try {
        const s = localStorage.getItem(THRESH_KEY);
        if (s) thresholds = { ...thresholds, ...JSON.parse(s) };
      } catch (e) {}
      syncThresholdsUi();

      if ($("btnCriticalAlarmToggle")) {
        $("btnCriticalAlarmToggle").addEventListener("click", async () => {
          await unlockHeartAudio();
          thresholds.criticalSound = !thresholds.criticalSound;
          try { localStorage.setItem(THRESH_KEY, JSON.stringify(thresholds)); } catch (e) {}
          syncThresholdsUi();
        });
      }

      if ($("btnSaveThresholds")) {
        $("btnSaveThresholds").addEventListener("click", () => {
          const minB = parseInt($("inpMinBpm").value, 10) || 60;
          const maxB = parseInt($("inpMaxBpm").value, 10) || 100;
          const maxR = parseFloat($("inpMaxRoom").value) || 28;
          thresholds.minBpm = Math.min(minB, maxB - 5);
          thresholds.maxBpm = Math.max(maxB, thresholds.minBpm + 5);
          thresholds.maxRoom = maxR;
          try { localStorage.setItem(THRESH_KEY, JSON.stringify(thresholds)); } catch (e) {}
          syncThresholdsUi();
          if (displayedBpm > 0) applyBpmUi(displayedBpm);
          updateAlerts(leadsOffState, displayedBpm > 0 ? displayedBpm : latestBpm);
        });
      }

      if ($("selEcgGain")) {
        $("selEcgGain").addEventListener("change", (e) => {
          ecgGain = parseFloat(e.target.value) || 1.0;
          if (ui.ecgGainLabel) ui.ecgGainLabel.textContent = (1 / ecgGain).toFixed(1) + " mV/div (" + ecgGain.toFixed(1) + "x)";
        });
      }

      if ($("selEcgSpeed")) {
        $("selEcgSpeed").addEventListener("change", (e) => {
          scrollStep = parseInt(e.target.value, 10) || 1;
          const mms = scrollStep * 25;
          if (ui.ecgSpeedLabel) ui.ecgSpeedLabel.textContent = mms + " mm/s";
        });
      }

      if ($("btnEcgFreeze")) {
        $("btnEcgFreeze").addEventListener("click", () => {
          ecgFrozen = !ecgFrozen;
          const btn = $("btnEcgFreeze");
          btn.classList.toggle("paused", ecgFrozen);
          btn.innerHTML = ecgFrozen ? "&#9654; Reanudar" : "&#9208; Congelar";
          if (ecgFrozen) {
            setBadge(ui.ecgBadge, "CONGELADO", "watch");
          } else {
            setBadge(ui.ecgBadge, leadsOffState ? "ELECTRODOS DESC." : "EN VIVO", leadsOffState ? "watch" : "live");
          }
        });
      }

      if ($("btnEcgFilter")) {
        $("btnEcgFilter").addEventListener("click", async () => {
          const targetState = !ecgFilterOn;
          ecgFilterOn = targetState;
          syncEcgFilterUi();
          try {
            const r = await fetch("/api/filter?on=" + (targetState ? "1" : "0"), { cache: "no-store" });
            if (r.ok) {
              const d = await r.json();
              ecgFilterOn = !!d.flt;
              syncEcgFilterUi();
            }
          } catch (e) {}
        });
      }

      if ($("btnEcgSnapshot")) {
        $("btnEcgSnapshot").addEventListener("click", downloadEcgSnapshot);
      }
    }

    function syncEcgFilterUi() {
      const btn = $("btnEcgFilter");
      if (btn) {
        btn.classList.toggle("active", ecgFilterOn);
        btn.innerHTML = ecgFilterOn ? "&#128295; Filtro 60Hz: ON" : "&#128295; Filtro 60Hz: OFF";
      }
      if (ui.ecgFilterLabel) {
        ui.ecgFilterLabel.textContent = ecgFilterOn ? "Filtro 60Hz Activo" : "Señal Sin Filtro";
      }
    }

    function downloadEcgSnapshot() {
      if (!canvasW || !canvasH) return;
      const out = document.createElement("canvas");
      const headerH = 44;
      out.width = canvasW;
      out.height = canvasH + headerH;
      const octx = out.getContext("2d");

      octx.fillStyle = "#08111f";
      octx.fillRect(0, 0, out.width, out.height);

      // Cuadrícula de fondo
      octx.strokeStyle = "rgba(103,232,249,0.08)";
      octx.lineWidth = 1;
      for (let x = 0; x < out.width; x += 24) {
        octx.beginPath(); octx.moveTo(x, headerH); octx.lineTo(x, out.height); octx.stroke();
      }
      for (let y = headerH; y < out.height; y += 24) {
        octx.beginPath(); octx.moveTo(0, y); octx.lineTo(out.width, y); octx.stroke();
      }

      octx.drawImage(canvas, 0, headerH);

      // Banda superior con metadatos clínicos
      octx.fillStyle = "#0f172a";
      octx.fillRect(0, 0, out.width, headerH);
      octx.strokeStyle = "rgba(59,130,246,0.4)";
      octx.beginPath(); octx.moveTo(0, headerH); octx.lineTo(out.width, headerH); octx.stroke();

      const p = loadPatientData();
      const patName = p.name || "Paciente Sin Nombre";
      const bpmTxt = displayedBpm > 0 ? (displayedBpm + " BPM") : "-- BPM";
      const rrTxt = latestRR > 0 ? ("R-R: " + latestRR + " ms") : "";
      const hrvTxt = latestHrv > 0 ? ("HRV: " + latestHrv + " ms") : "";

      octx.fillStyle = "#f8fafc";
      octx.font = "bold 13px 'Plus Jakarta Sans', sans-serif";
      octx.fillText("MedMonitor ECG (Derivación I) · " + patName, 14, 18);

      octx.fillStyle = "#38bdf8";
      octx.font = "bold 12px 'Plus Jakarta Sans', sans-serif";
      octx.fillText([bpmTxt, rrTxt, hrvTxt, "Ganancia " + ecgGain + "x", (scrollStep * 25) + " mm/s", fmtLogTime(new Date())].filter(Boolean).join("   |   "), 14, 35);

      const url = out.toDataURL("image/png");
      const a = document.createElement("a");
      const pname = patName.replace(/[^a-z0-9]/gi, "_");
      a.href = url;
      a.download = "Captura_ECG_" + pname + "_" + new Date().toISOString().slice(0, 19).replace(/[:T]/g, "-") + ".png";
      document.body.appendChild(a);
      a.click();
      document.body.removeChild(a);
    }

    initThresholdsAndControls();

    function updateAlerts(leadsOff, bpm) {
      const v = lastVitals;
      let warnN = 0, okN = 0, infoN = 0;
      let criticalTriggered = false;
      const suggestions = [];
 
      function countState(s) {
        if (s === "ok") okN++;
        else if (s === "warn" || s === "bad") warnN++;
        else infoN++;
      }
 
      // 1 — Frecuencia Cardíaca y Variabilidad R-R
      const hrvExtra = (latestRR > 0 ? " (R-R: " + latestRR + " ms" + (latestHrv > 0 ? ", HRV: " + latestHrv + " ms)" : ")") : "");
      if (leadsOff) {
        countState(setAlertRow(1, {
          title: "Frecuencia Cardíaca — Electrodos Desconectados",
          msg: "No es posible medir los BPM sin los electrodos de ECG conectados.",
          tip: "Coloca las almohadillas RA, LA y RL. Limpia la piel con alcohol previamente.",
          icon: "\u26A0", pill: "ALERTA", state: "bad"
        }));
        suggestions.push("Reconecta los tres electrodos de ECG y verifica las conexiones de los cables.");
      } else if (bpm > thresholds.maxBpm) {
        criticalTriggered = true;
        countState(setAlertRow(1, {
          title: "Frecuencia Cardíaca Elevada (Taquicardia)",
          msg: bpm + " BPM detectados" + hrvExtra + " — supera el umbral configurado (" + thresholds.maxBpm + " BPM).",
          tip: "Asegúrate de que el paciente esté en reposo. Vuelve a verificar en 5 minutos.",
          icon: "\u2764", pill: "REVISAR", state: "warn"
        }));
        suggestions.push("Frecuencia cardíaca por encima de " + thresholds.maxBpm + " BPM — confirma reposo e hidratación.");
      } else if (bpm > 0 && bpm < thresholds.minBpm) {
        criticalTriggered = true;
        countState(setAlertRow(1, {
          title: "Frecuencia Cardíaca Baja (Bradicardia)",
          msg: bpm + " BPM detectados" + hrvExtra + " — inferior al umbral configurado (" + thresholds.minBpm + " BPM).",
          tip: "Verifica la colocación de los electrodos. Consulta al médico si persiste.",
          icon: "\u2764", pill: "REVISAR", state: "warn"
        }));
        suggestions.push("Bradicardia (< " + thresholds.minBpm + " BPM) — verifica el contacto de los electrodos y el estado del paciente.");
      } else if (bpm > 0 && latestHrv > 110) {
        countState(setAlertRow(1, {
          title: "Variabilidad R-R Elevada (Posible Irregularidad)",
          msg: bpm + " BPM con HRV RMSSD de " + latestHrv + " ms — variación alta entre latidos sucesivos.",
          tip: "Inspecciona el trazo PQRST usando el botón 'Congelar' para descartar artefactos o arritmia.",
          icon: "\u2764", pill: "REVISAR", state: "warn"
        }));
        suggestions.push("Variabilidad latido a latido alta (HRV > 110 ms) — revisa que el paciente no se esté moviendo.");
      } else if (bpm > 0) {
        countState(setAlertRow(1, {
          title: "Frecuencia Cardíaca y Ritmo Normal",
          msg: bpm + " BPM" + hrvExtra + " — dentro del rango saludable configurado.",
          tip: "Rango normal activo: " + thresholds.minBpm + "–" + thresholds.maxBpm + " BPM.",
          icon: "\u2705", pill: "NORMAL", state: "ok"
        }));
      } else {
        countState(setAlertRow(1, {
          title: "Detectando Latido Cardíaco",
          msg: "Electrodos conectados. Esperando una lectura estable de BPM.",
          tip: "Mantén al paciente en reposo para una detección precisa.",
          icon: "\u23F3", pill: "ESPERA", state: "info"
        }));
      }
 
      // 2 — Señal de ECG
      if (leadsOff) {
        countState(setAlertRow(2, {
          title: "Sin Señal de ECG",
          msg: "Forma de onda no disponible — electrodos desconectados.",
          tip: "Presiona firmemente los electrodos. Revisa los cables indicadores LO+ y LO-.",
          icon: "\u26A1", pill: "ALERTA", state: "bad"
        }));
      } else {
        countState(setAlertRow(2, {
          title: "ECG Transmitiendo en Vivo (" + (ecgFilterOn ? "Filtro 60Hz ON" : "Sin Filtro") + ")",
          msg: "Onda PQRST actualizándose a 125 Hz en el osciloscopio.",
          tip: "Usa los controles superiores para congelar el trazo, ajustar ganancia o capturar imagen PNG.",
          icon: "\u26A1", pill: "EN VIVO", state: "ok"
        }));
      }
 
      // 5 — Ambiente de la habitación
      if (v.bme) {
        let envState = "ok";
        let envPill = "NORMAL";
        let envTitle = "Ambiente de la Habitación Normal";
        let envMsg = "Temp. ambiental " + v.roomT.toFixed(1) + " \u00B0C \u00B7 Humedad " + v.hum.toFixed(1) + "%";
        let envTip = "Condiciones ambientales dentro del rango clínico confortable.";
        if (v.roomT > thresholds.maxRoom || v.roomT < 18) {
          envState = "warn"; envPill = "REVISAR";
          envTitle = "Alerta de Temperatura Ambiental";
          envMsg = "Temp. de la habitación " + v.roomT.toFixed(1) + " \u00B0C — fuera del rango ideal (18–" + thresholds.maxRoom + " \u00B0C).";
          envTip = "Ajusta la climatización o ventilación para mayor confort del paciente.";
          suggestions.push("Temperatura ambiental fuera de rango — revisa la ventilación de la sala.");
        }
        if (v.hum > 70 || v.hum < 30) {
          envState = "warn"; envPill = "REVISAR";
          envTitle = "Alerta de Humedad Ambiental";
          envMsg = "Humedad al " + v.hum.toFixed(1) + "% — fuera del rango ideal (30–70%).";
          envTip = "Utiliza un humidificador o deshumidificador según sea necesario.";
          suggestions.push("Humedad de la habitación fuera de rango — ajusta el control ambiental.");
        }
        countState(setAlertRow(5, {
          title: envTitle, msg: envMsg, tip: envTip,
          icon: "\uD83C\uDFE0", pill: envPill, state: envState
        }));
      } else {
        countState(setAlertRow(5, {
          title: "Sensor BME280 en Espera",
          msg: "El sensor de temperatura y humedad ambiental aún no está listo.",
          tip: "Revisa el cableado I2C del BME280 (SDA=21, SCL=22).",
          icon: "\uD83C\uDFE0", pill: "ESPERA", state: "info"
        }));
      }
 
      // 6 — Conexión
      if (connOnline) {
        countState(setAlertRow(6, {
          title: "Monitor Conectado",
          msg: "Enlace en vivo con el ESP32 activo (http://medmonitor.local). Datos transmitiéndose con normalidad.",
          tip: "Si las lecturas se congelan, recarga el navegador o revisa la señal WiFi.",
          icon: "\uD83D\uDCF6", pill: "EN VIVO", state: "ok"
        }));
      } else {
        countState(setAlertRow(6, {
          title: "Monitor Sin Conexión",
          msg: "Se perdió la conexión con el monitor de salud ESP32.",
          tip: "El ESP32 cuenta con reconexión WiFi automática; verifica que esté encendido.",
          icon: "\u274C", pill: "DESCONECTADO", state: "bad"
        }));
        suggestions.push("Dispositivo sin conexión — verifica la alimentación del ESP32 y la red WiFi.");
      }
 
      ui.alertWarnCount.textContent = warnN;
      ui.alertOkCount.textContent = okN;
      ui.alertInfoCount.textContent = infoN;
 
      if (!suggestions.length) {
        suggestions.push("Todos los parámetros monitoreados están dentro de los límites normales. Continúa con la supervisión de rutina.");
      }
      ui.alertSuggestions.innerHTML = suggestions.map((s) => "<li>" + s + "</li>").join("");
 
      const overall = warnN > 0 ? "watch" : (okN > 0 ? "good" : "watch");
      setBadge(ui.alertBadge, warnN > 0 ? "REVISAR" : "SEGURO", overall);
      if (criticalTriggered) playCriticalAlarmBeep();
    }
 
    function valueToY(v, h, leadsOff) {
      if (leadsOff) return h * 0.54;
      const plotH = h - ECG_Y_MARGIN * 2;
      // Escalar alrededor del punto medio (512) según la ganancia seleccionada
      const centered = (v - 512) * ecgGain + 512;
      const c = Math.max(0, Math.min(PLOT_MAX, centered));
      return ECG_Y_MARGIN + plotH * (1 - c / PLOT_MAX);
    }
 
    function drawEcgPoint(v, leadsOff) {
      if (ecgFrozen) return;
      const w = canvasW;
      const h = canvasH;
      if (w < 8 || h < 8) return;
      const step = Math.max(1, scrollStep);
 
      const y = valueToY(v, h, leadsOff);
 
      if (traceReady) {
        const imageData = ctx.getImageData(step, 0, w - step, h);
        ctx.putImageData(imageData, 0, 0);
        ctx.clearRect(w - step, 0, step, h);
      } else {
        traceReady = true;
        heightOld = y;
      }
 
      const x0 = Math.max(0, w - step - 1);
      const x1 = w - 1;
      ctx.beginPath();
      ctx.moveTo(x0, heightOld);
      ctx.lineTo(x1, y);
      ctx.strokeStyle = leadsOff ? "#67e8f9" : "#16a34a";
      ctx.lineWidth = 2.2;
      ctx.lineJoin = "round";
      ctx.lineCap = "round";
      ctx.stroke();
      heightOld = y;
    }
 
    function drawEcgSamples(samples, leadsOff) {
      if (!samples || !samples.length) return;
      for (let i = 0; i < samples.length; i++) {
        drawEcgPoint(samples[i], leadsOff);
      }
    }

    function recordRawEcgBatch(samples, d) {
      if (!rawEcgRecording || !samples || !samples.length) return;
      const nowOffset = Date.now() - rawEcgStartMs;
      for (let i = 0; i < samples.length; i++) {
        const adc = samples[i];
        // Estimación en mV a partir de la escala 0..1023 (~0..4096 mV en GAIN_ONE)
        const mvEst = Math.round((adc / 1023) * 3300);
        rawEcgData.push({
          t: nowOffset + i * 8,
          adc: adc,
          mv: mvEst,
          bpm: d.bpm > 0 ? d.bpm : "",
          rr: d.rr > 0 ? d.rr : "",
          hrv: d.hrv > 0 ? d.hrv : "",
          lo: d.lo ? 1 : 0
        });
        if (rawEcgData.length >= MAX_RAW_ECG_SAMPLES) {
          rawEcgRecording = false;
          break;
        }
      }
      updateRawEcgUi();
    }
 
    async function pollEcg() {
      if (ecgPollBusy) return;
      ecgPollBusy = true;
      try {
        const r = await fetch("/api/ecg", { cache: "no-store" });
        if (!r.ok) throw new Error("ecg");
        const d = await r.json();
        markConnSuccess();
        touchUpdate();
        leadsOffState = !!d.lo;
        if (typeof d.rr === "number") latestRR = d.rr;
        if (typeof d.hrv === "number") latestHrv = d.hrv;
        if (typeof d.flt === "number") {
          ecgFilterOn = !!d.flt;
          syncEcgFilterUi();
        }
        maybeUpdateBpmUi(d.bpm);
        if (!ecgFrozen) {
          setBadge(ui.ecgBadge, d.lo ? "ELECTRODOS DESC." : "EN VIVO", d.lo ? "watch" : "live");
        }
        const samples = Array.isArray(d.v) ? d.v : [d.v];
        drawEcgSamples(samples, d.lo);
        recordRawEcgBatch(samples, d);
        updateAlerts(leadsOffState, displayedBpm > 0 ? displayedBpm : d.bpm);
      } catch (e) {
        ecgFail++;
        markConnFailure();
        if (!connOnline) setBadge(ui.ecgBadge, "ERROR", "bad");
      } finally {
        ecgPollBusy = false;
      }
    }
 
    async function pollVitals() {
      try {
        const r = await fetch("/api/vitals", { cache: "no-store" });
        if (!r.ok) throw new Error("vitals");
        const d = await r.json();
        vitalsFail = 0;
        markConnSuccess();
        touchUpdate();
        lastVitals = { roomT: d.roomT, hum: d.hum, bme: !!d.bme };
        updateRoomUi(d.roomT, d.hum, d.bme);
        const bpm = displayedBpm > 0 ? displayedBpm : latestBpm;
        updateAlerts(leadsOffState, bpm > 0 ? bpm : -1);
      } catch (e) {
        vitalsFail++;
        markConnFailure();
      }
    }
 
    setInterval(() => { ui.clock.textContent = fmtTime(); }, 1000);
    setInterval(pollEcg, ECG_POLL_MS);
    setInterval(pollVitals, 1500);
    pollEcg();
    pollVitals();
  </script>
</body>
</html>
)rawliteral";
 
#endif

