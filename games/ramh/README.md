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

Base di caricamento: **`0x8000` CONFERMATA** — 11/31 JMP/JSR assoluti cadono
esattamente su start-funzione Ghidra solo a base `0x8000` (0 per le altre
candidate `0x1000`-`0x7000`). Coerente con stack `$80000` e BSS in coda.
Import Ghidra con padding di `0x8000` zeri (`rstar_pad.bin`, solo TEMP).

- `0x00000-0x08100`: codice M68k (startup: stack, kill OS, `COLOR00`).
- `0x08100+`: dati/testi/dialoghi (encoding: `0xA0`=spazio, hi-bit font).
  `EVEN` = parola inglese nei testi, non un marker.
- `0x3D9C4`, `0x432AD`: byte `000003F3` in dati (coincidenze, nessun CODE).
- Ghidra: **120 funzioni** (`0x859A`-`0x13B...`), 8 con ref ai custom
  (`INTENA`, `INTREQ`, ...). → `config/units.json` (120 unit), baseline 0%.

## `boot`: loader criptato (analisi)

`boot` (Hunk, 1 CODE 3676 B, entropia 7.73 dopo i primi 256 B) = stub
anti-debug + payload cifrato. Meccanismi mappati (non ancora eseguiti):

1. **Trap via vettore `$10`** (istruzione illegale): `PEA $C(PC)` +
   `MOVE.L (A7)+,$10` installa il vettore, `ILLEGAL @0x0A` → `0x10`;
   seconda coppia → `$10=0x40`; `dc.w $4E7A @0x1C` (= illegale su 68000)
   → trap a `0x40`. `tools/m68k_flow.py` segue questi trap (pre-scan
   PEA→`$10` + self-test).
2. **`@0x40`: 8 LONG sullo stack** (stato), **`$24` (vettore trace) = SP+6**,
   **`SR=$A71F`** (supervisor + trace + IPL7). Da `@0x80` il controllo è
   dinamico (ogni istruzione passa dal trace handler): l'analisi statica è
   cieca per disegno — serve emulazione (cfr. `m68k/`+`amiga/` di Disk-Utilities).
3. Base RSTAR `0x8000` resta assunzione di lavoro (forte ma non confermata):
   stack `$80000`, 593/593 ref in-range, BSS in coda.
4. **Emulazione** (Disk-Utilities `m68k/`+`amiga/`, compilati MinGW statici):
   il trap `$10` confermato live (`0x4000A→0x4000C`, `0x4001C→0x4002C`),
   trace mode ON, loop EOR a `0xF4A` eseguito (326 insn), 8 byte decrittati
   in place a `0x4045E`, crash a `0x40466` su `SysBase ($4)` avvelenato
   (niente ExecBase/DOS nell'emulatore). Gotcha copylock: il `:` del drive
   collide con `nome:base` → usare path relativi. Tool: `tools/emu_mem.py`,
   `tools/emu_trace.py`. Per proseguire servirebbe SysBase finto + DOS.

## Il resto (112 funzioni): riassemblatore — FATTO 120/120

`python tools/reasm.py --all` genera `asm/*.s` byte-identici per le unit
senza sorgenti (label per salti in-slice, dc.w per fuori slice/dati),
con loop di convergenza via listing vasm (max 4 round). Non tocca mai
`asm/*.s` scritti a mano (né con `--force`, che rispetta i non-generati).
Poi: `python tools/diff_m68k.py ...` → report. Lavoro manuale dopo:
rinominare label/funzioni e portare in C dove il decompilatore è fedele.
Stato: **143/143 func, 100% codice** — le 8 a mano + 112 generate + 23 gap.
Ghidra trova 120 funzioni; `tools/find_gaps.py` ne trova altre 23 nei gap
(code/data interleaved; bound-check anti-wrap incluso dopo un falso positivo).
Il resto (data/testi/grafica) non e' codice matchabile.

1. `python tools/split_hunk.py --raw game-ramh/RSTAR --out-dir orig --manifest orig/manifest-rstar.json --base 0x8000`
2. Ghidra headless su `rstar_pad.bin` → `game-ramh/symbols-rstar.json`
3. `python tools/symbols_to_units.py ...` → 120 unit, 0 skip
4. `python tools/diff_m68k.py ...` → `build/report.json` (0/9586 B)

## Matching asm: regole verificate (8/8 custom_refs a 100%)

- Trascrizione in `asm/*.s` (vasm mot) + `diff` a payload Hunk (`_payload`,
  tolleranza pad `4E71`/`00` di allineamento sezione).
- `opt o-` in testa: vasm ottimizza `cmp.b #0,d0` in `tst.b` (byte diversi).
- `btst #n,Dn` vuole `.l` (`.b` solo per memoria); se vasm dice
  `illegal opcode extension` su un assoluto, aggiungere `.l`.
- `movem` = 4 byte (una mask word), non 12: contare i NOP sled di conseguenza.
- Displacement PC-relativi (Bcc/DBcc/BSR/LEA): base = insn+2 **sempre**.
  Il rendering `$xyz` di capstone = addr+disp+2 (corretto solo se size=2).
- Riferimenti fuori slice (LEA/BSR esterni): `dc.w` coi byte letterali
  dall'hexdump, mai derivati dal rendering. Il loop di diff li becca tutti.
- Quirk vasm: `move.b #1,(a1)` assembla `12BC 0001` (lettura PC-rel!);
  se serve davvero, usare `dc.w` esplicito.

## Chain su `boot` (loader, 3676 B)

1. `python tools/split_hunk.py game-ramh/boot --out-dir orig --manifest orig/manifest-boot.json`
2. `make analyze GHIDRA_DIR=... EXE=orig/hunk0_CODE.bin` (progetto `RAMH`)
3. `make units` → `config/units.json`
4. `make decompile` → `decompiled/` — leggere il loader: indirizzo di
   caricamento di RSTAR + struttura partidopo `EVEN`.
