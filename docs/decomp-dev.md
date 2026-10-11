# Integrazione decomp.dev

decomp.dev fa solo tracking: legge `build/report.json` dagli artifact della CI.
Contratto verificato nel sorgente (`crates/github/src/lib.rs`):

- **Nome artifact** deve matchare `^(versione)[_-]report(...)?$`.
  Noi usiamo `m68k-report` → versione **`m68k`**.
- **Dentro lo zip** serve un file con stem `report` (o `<versione>_report`).
  `upload-artifact` con `path: build/report.json` produce `report.json` ✓.
- Il JSON viene parsato come `objdiff Report` + `migrate()`.
  Il nostro formato v2 non richiede migrazioni ✓.

## Registrare il progetto (istanza pubblica decomp.dev)

`/manage/new`, valori:

| Campo | Valore |
|---|---|
| owner / repo | `SirL0LL0` / `amiga-m68k-decomp` |
| name | `Amiga M68k decomp` (libero) |
| platform | vuoto (Amiga non esiste in `Platform`; `platform` è `Option`) |
| workflow | `build.yml` |
| default version | `m68k` (= nome artifact prima di `-report`) |
| default category | `all` (o `code`) |

Note:

- Il progetto resta **nascosto finché il match è < 0.5%** (`project_visibility`
  in `crates/core/src/models.rs`). Normale all'inizio.
- Solo i run `push` sul default branch alimentano i report; le PR ottengono
  commenti col diff (`enable_pr_comments`, via `objdiff`-changes sui report).
- Il primo run CI fallisce finché `config/units.json` non punta a target reali:
  `check_for_reports` (validazione di `/manage/new`) cerca run completati con
  artifact validi.

## Self-host (alternativa)

Clona `encounter/decomp.dev`, `cp config.example.yml config.yml`, token GitHub
con scope `public_repo`, `dev_mode: true` in locale. Stesso meccanismo: punta
il progetto a questo repo e al workflow `build.yml`.
