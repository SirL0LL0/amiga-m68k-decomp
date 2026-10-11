# amiga-m68k-decomp

Toolchain e pipeline per la **decompilazione matching di giochi Amiga (M68k)**,
con progress tracking compatibile con [decomp.dev](https://github.com/encounter/decomp.dev).

```
gioco.exe (Hunk) ── make split ──▶ orig/*.bin ──┐
                                                 │  make analyze (Ghidra headless)
                                                 │  make units   (funzioni -> unit)
                 src/*.c, asm/*.s ── vbcc/vasm ─▶ build/*.o ── make report ─▶ build/report.json
```

`build/report.json` usa lo stesso formato di `objdiff` (`REPORT_VERSION = 2`),
quindi puo' alimentare decomp.dev. Nota: **objdiff non supporta M68k**
(solo arm/arm64/mips/ppc/superh/x86): il matching e' fatto da
`tools/diff_m68k.py`. Dettagli in [ARCHITETTURA.md](ARCHITETTURA.md).

## Requisiti

| Cosa | Dove serve | Note |
|---|---|---|
| Python 3 + `pip install -r tools/requirements.txt` | ovunque | capstone per il fuzzy matching |
| Ghidra + estensione `ghidra-amiga` | solo locale | `make analyze` (mai in CI) |
| Docker | build toolchain | `make docker-build`, oppure vbcc/vasm/vlink nativi |
| gcc host | solo `make verify` | test layout header |

## Quickstart (senza gioco: verifica i tool)

```sh
make verify
```

## Uso con un gioco

```sh
# 1. split dell'eseguibile (una tantum)
make split EXE=/path/gioco.exe BASE=0x0

# 2. analisi Ghidra headless (locale; GHIDRA_PROJDIR deve esistere)
make analyze GHIDRA_DIR="/path/Ghidra" EXE=orig/hunk0_CODE.bin

# 3. funzioni -> unit di matching + header LVO
make units

# 4. scrivi src/<funzione>.c o asm/<funzione>.s, poi:
make report   # in Docker: toolchain Amiga reale
```

## Struttura

- `docker/` — vbcc + vasm + vlink + target m68k-amiga
- `tools/split_hunk.py` — parser Hunk -> `orig/`
- `tools/ghidra/AnalyzeAmiga.java` — export funzioni/simboli/LVO da Ghidra
- `tools/ghidra/amiga_data.json` — mappa memoria, registri custom, LVO Exec (verificati vs NDK)
- `tools/symbols_to_units.py` — funzioni -> `config/units.json` + `include/amiga_lvo.h`
- `tools/diff_m68k.py` — matching -> `build/report.json` (formato decomp.dev v2)
- `include/amiga_hardware.h` — registri custom (offset verificati)
- `.github/workflows/build.yml` — CI: build + report + artifact per decomp.dev
