# Rock Star Ate My Hamster (Europe) — note decompilazione

Gioco Codemasters 1989. Lavoro sul branch `game/rock-star-ate-my-hamster`.
Il disco/IPF e i file estratti NON sono nel repo (gitignored): qui solo note
riproducibili.

## Provenienza

- `Rock Star Ate My Hamster (Europe).ipf` (CAPS, ~1 MB) →
  `disk-analyse game.ipf game.adf` → `T0.0-79.1: AmigaDOS`, ADF 901120 B.
- Volume `ROCK`, OFS (`DOS\0`). Layout header verificato sui checksum:
  filename @432, size @324, parent @500, ext-next @504.

## File sul disco

| File | Size | Note |
|---|---|---|
| `s/startup-sequence` | 5 B | contiene `boot` |
| `boot` | 3712 B | eseguibile Hunk (1 CODE, 3676 B) = loader |
| `RSTAR` | 453974 B | binario M68K raw, parte da codice (stack `$80000`, kill OS, `COLOR00`) |

## RSTAR: mappa (verificata)

Base di caricamento assunta: **`0x8000`** (stack `$80000` in testa, BSS dopo
`0x6ED56`, 593/593 ref assoluti in-range; da confermare col loader decrittato).
Import Ghidra con padding di `0x8000` zeri (`rstar_pad.bin`, solo TEMP).

- `0x00000-0x08100`: codice M68k (startup: stack, kill OS, `COLOR00`).
- `0x08100+`: dati/testi/dialoghi (encoding: `0xA0`=spazio, hi-bit font).
  `EVEN` = parola inglese nei testi, non un marker.
- `0x3D9C4`, `0x432AD`: byte `000003F3` in dati (coincidenze, nessun CODE).
- Ghidra: **120 funzioni** (`0x859A`-`0x13B...`), 8 con ref ai custom
  (`INTENA`, `INTREQ`, ...). → `config/units.json` (120 unit), baseline 0%.

## `boot`: loader criptato

`boot` (Hunk, 1 CODE 3676 B, entropia 7.73 dopo i primi 256 B) = stub
decryptor + payload cifrato ("ROCK lock"?). Niente stringhe/JSR visibili.
Il decryptor va emulato o analizzato per trovare indirizzo/part di RSTAR.
Tool nuovo: `tools/m68k_flow.py` (disassembly ricorsivo, segue `$addr`).

## Chain su RSTAR (fatta)

1. `python tools/split_hunk.py --raw game-ramh/RSTAR --out-dir orig --manifest orig/manifest-rstar.json --base 0x8000`
2. Ghidra headless su `rstar_pad.bin` → `game-ramh/symbols-rstar.json`
3. `python tools/symbols_to_units.py ...` → 120 unit, 0 skip
4. `python tools/diff_m68k.py ...` → `build/report.json` (0/9586 B)

## Chain su `boot` (loader, 3676 B)

1. `python tools/split_hunk.py game-ramh/boot --out-dir orig --manifest orig/manifest-boot.json`
2. `make analyze GHIDRA_DIR=... EXE=orig/hunk0_CODE.bin` (progetto `RAMH`)
3. `make units` → `config/units.json`
4. `make decompile` → `decompiled/` — leggere il loader: indirizzo di
   caricamento di RSTAR + struttura partidopo `EVEN`.
