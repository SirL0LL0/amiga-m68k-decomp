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
| vbcc nativo **oppure** Docker | build/matching reale | vedi sotto |
| gcc host | solo `make verify` | test layout header |

## Toolchain vbcc (due strade, stesso `+aos68k`)

**A. Nativa Windows — pronta subito, niente reboot.**
Binari ufficiali multi-target (vbccm68k, vc, vasmm68k_mot, vlink + target
`m68k-amigaos` con config `aos68k`):

```powershell
# una tantum: scarica http://www.ibaug.de/vbcc/vbcc_win_x64.zip (16 MB)
# ed estrailo in .toolchain/vbcc-win  (su questa macchina: gia' fatto)
. .\tools\env.ps1
vc +aos68k -c -Iinclude src/main.c -o build/main.o
```

Agent con vbcc reale (va lanciato dalla root: `-Iinclude` è relativo):

```powershell
python tools/agent/loop.py --config tools/agent/config.native-win.json --units config/units.json
```

**B. Docker (CI + Linux).** Richiede `wsl --install` + reboot + Docker Desktop,
poi `make docker-build` e `make report` nel container. Il Dockerfile compila
vbcc dai sorgenti ufficiali (`ibaug.de/vbcc/vbcc.tar.gz`).

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

# 4. C di partenza dal decompilatore (locale, opzionale)
make decompile GHIDRA_DIR="/path/Ghidra" GHIDRA_PROG=game.bin

# 5. scrivi src/<funzione>.c o lancia l'agent automatico, poi:
make agent    # varianti -> compile -> diff, tiene il meglio
make report   # in Docker: toolchain Amiga reale
```

## Struttura

- `docker/` — vbcc + vasm + vlink + target m68k-amiga
- `tools/split_hunk.py` — parser Hunk -> `orig/`
- `tools/ghidra/AnalyzeAmiga.java` — export funzioni/simboli/LVO da Ghidra
- `tools/ghidra/amiga_data.json` — mappa memoria, registri custom, LVO Exec (verificati vs NDK)
- `tools/symbols_to_units.py` — funzioni -> `config/units.json` + `include/amiga_lvo.h`
- `tools/ghidra/DecompileFunctions.java` — C del decompilatore -> `decompiled/`
- `tools/agent/` — loop automatico compile/diff/refine (`loop.py`, `backends.py`, `config.json`)
- `tools/reasm.py` — riassembla le unit senza sorgenti in `asm/*.s` byte-identici
- `tools/m68k_flow.py` — disassembly ricorsivo M68k (segue salti + trap `$10`)
- `docs/decomp-dev.md` — registrazione progetto e contratto artifact
- `tools/diff_m68k.py` — matching -> `build/report.json` (formato decomp.dev v2)
- `include/amiga_hardware.h` — registri custom (offset verificati)
- `.github/workflows/build.yml` — CI: build + report + artifact per decomp.dev
