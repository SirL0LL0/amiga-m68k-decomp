# Architettura decompilazione Amiga M68k (base: decomp.dev)

## Ruoli

`decomp.dev` fa solo **tracking dei progressi + frontend + bot GitHub**.
Non disassembla, non compila, non matcha. La pipeline M68k sta in questo repo:

```
gioco.exe (Hunk) ──tools/split_hunk.py──▶ orig/*.bin
                                            │   ┌── src/*.c, asm/*.s
                                            │   ▼
                                            │  vbcc/vasm/vlink (docker/) ▶ build/*.o
                                            ▼
                                   tools/diff_m68k.py ──▶ build/report.json (v2)
                                            │
              decomp.dev ◀── CI artifact ────┘   (dashboard + bot GitHub)
```

## Decisione 1: niente objdiff per il matching M68k

`objdiff` **non supporta M68k**. Verificato in `objdiff-core/src/arch/mod.rs`
(`new_arch` gestisce solo `arm, arm64, mips, ppc, superh, x86`; nessun ramo M68k).
Il matching e' quindi fatto da `tools/diff_m68k.py`:

- confronto byte-perfect per unit + fuzzy via disassembly capstone-M68K;
- semantica di skip identica a `objdiff report`: unit senza target = skippata
  con warning, target senza base = 0% conteggiata;
- emette `report.json` **identico al formato objdiff** (`REPORT_VERSION = 2`,
  cfr. `objdiff-core/protos/report.proto`: `measures/units/version/categories`).

## Decisione 2: decomp.dev senza platform Amiga

`crates/core/src/models.rs` (enum `Platform`) non ha Amiga/M68k: solo
ps, win32, n64, ps2, gba, gc, xbox, nds, psp, xbox360, wii, 3ds, switch.
Il progetto su decomp.dev va quindi creato con `platform: null`/vuoto, oppure
forkando decomp.dev per aggiungere la platform. Il resto del contratto
(`owner/repo`, `workflow_id`, ingestione report JSON) e' riusabile invariato:
la CI carica `build/report.json` come artifact e il job di decomp.dev lo legge.

## Layout repo (Fase 1)

| Path | Cosa |
|---|---|
| `docker/Dockerfile` | vbcc + vasmm68k_mot + vlink + target `m68k-amiga` (da `Team-Boingo/AmiCC/vendor`, archivio upstream verificato) + python/capstone per il diff |
| `Makefile` | `build` (vbcc/vasm) → `report` (diff_m68k.py) → `verify` (self-test, no toolchain) → `split` (una tantum) |
| `tools/split_hunk.py` | parser Hunk (HEADER/CODE/DATA/BSS/RELOC32/SYMBOL/END) → `orig/` |
| `tools/diff_m68k.py` | matching + `report.json` v2 decomp.dev-compatibile |
| `tools/check_hw.c` | test layout `struct Custom` (usato da `make verify`) |
| `config/units.json` | mappa unit target↔base (opzionale: auto-discover `build/<x>` ↔ `orig/<x>`) |
| `include/amiga_hardware.h` | registri custom al loro offset reale (verificati: 18/18 con gcc host) |
| `.github/workflows/build.yml` | CI: docker build → self-test → build → report → upload artifact |

## Uso

```sh
# 0. verifica senza toolchain (solo python + gcc host)
make verify

# 1. una tantum: split del gioco
make split EXE=/path/gioco.exe   # -> orig/hunkN_*.bin

# 2. aggiorna config/units.json con le unit reali, scrivi src/*.c e asm/*.s

# 3. ciclo di matching (in Docker, toolchain Amiga)
make docker-build                 # build immagine una volta
docker run --rm -v $PWD:/workspace amiga-decomp-toolchain make report
```

## Verifiche eseguite (Fase 1)

- `tools/diff_m68k.py --self-test`: 5/5 (identico→100%, 1-byte-diff→3/4,
  skip senza target, 0% senza base, flag complete).
- `tools/split_hunk.py --self-test`: 3/3 (parse CODE+DATA, split su disco,
  rifiuto non-Hunk).
- `tools/check_hw.c` con gcc host: 18/18 offset corretti, `sizeof = 0x1C0`.
- Demo end-to-end split→diff: 2 unit (100% + 75%) → aggregato 87.5%, report v2.

## Prossimo (Fase 2/3, non ancora fatto)

## Fase 2: Ghidra -> unit per-funzione (FATTO, verificato live)

- `tools/ghidra/AnalyzeAmiga.java` (headless o GUI): importa raw come
  `68000:BE:32:default`, crea label `CUSTOM_*` a `$DFF000+off`, esporta
  `symbols.json` {funzioni, label, custom_refs, lvo_table, custom_map}.
- **Java, non Python**: in Ghidra 12 gli script `.py` sono serviti dal provider
  PyGhidra, non inizializzato in headless
  (`Ghidra was not started with PyGhidra` — errore osservato live). Java
  funziona sempre. Verificato con Ghidra 12.1.3 headless.
- Fallback `entry`: se l'auto-analisi non crea funzioni (raw senza entry),
  disassembla dalla image base e crea `entry` — la chain produce sempre ≥1 unit.
- `tools/symbols_to_units.py`: ritaglia ogni funzione dagli hunk in
  `orig/func/<nome>.bin`, (ri)genera `config/units.json` (preserva `complete`),
  genera `include/amiga_lvo.h`. Skip: external/thunk, size 0, fuori hunk (ROM).
- `tools/ghidra/amiga_data.json`: unica fonte (mappa memoria, 52 custom reg,
  40 LVO Exec). **LVO verificati 40/40** contro `exec_lib.fd` dell'estensione
  `ghidra-amiga` (Bartman/Abyss) presente in Ghidra, che fornisce anche
  `amiga_ndk39.gdt` (struct NDK) e gli `.fd/.sfd` di tutte le librerie.
- Uso: `make split EXE=... BASE=0x0` -> `make analyze GHIDRA_DIR=... EXE=orig/hunk0_CODE.bin`
  -> `make units` -> scrivi `src/<f>.c` -> `make report`.
- Verifiche live: script compila e gira headless; 83 label create; `entry @0 size 14`
  (LINK..RTS esatti); `custom_refs entry:[0x180]` (MOVE a COLOR00 rilevato);
  slice byte-identici; diff 0% -> 100% copiando la base.

## Prossimo (Fase 3, non ancora fatto)

- Deploy decomp.dev (`config.yml`, `/manage/new`) puntato a questo repo/CI.
- Agente di decompilazione (Ghidra decompiler -> C -> vbcc -> diff -> refine).
