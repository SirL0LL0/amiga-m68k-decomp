#!/usr/bin/env python3
"""rename_from_seed.py - nomi nuovi dai seed loro, guidati dalla verifica verifica.

Per ogni entry in index.json (chiave file + nome da c/):
1. trova i marker chiave nel disasm del target (scritti in ogni seed: qui li
   deriviamo dai nomi file, che sono altrettanto indicativi).
2. emette nuovo nome: "seed (<loro_nome>)" se confetto, altrimenti segnala
   "SEED SFALSO".

REGOLE:
- NON toccare entry che ho gia' verificato a byte-level (in MINE_HIGH) o con
  c_best_pct (gia' controllati).
- Solo entry che attraovano check: qui non imponiamo un filtro, ma stampiamo
  un avviso se il disasm non contiene i registri attesi.

Uso: python tools/rename_from_seed.py [--check-only]
"""
import argparse
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, "ghidra"))
import m68k_flow  # noqa: E402

BASE = 0x8000
SHIFT = 0x100

# entry gia' verificati a byte-level: non toccare
MINE_HIGH = {
    "FUN_0000b3be", "FUN_0000b85a", "FUN_000131ea", "FUN_0001313c",
    "FUN_000132a4", "FUN_00013206", "FUN_00013554", "FUN_000133fe",
    "FUN_0000b3a4", "FUN_0000b3d4", "FUN_0000b432", "FUN_000138f2",
}
# con c_best gia' controllato
C_DONE = {
    "CALL_0092B4", "FUN_0000d024", "FUN_0000be52", "FUN_0000d4de",
    "CALL_009074", "FUN_0000908c", "FUN_0000db62", "FUN_0000da5a",
    "FUN_000086aa", "FUN_0000a486", "FUN_0000bf0c", "FUN_00013aa0",
    "FUN_00009fcc", "FUN_0000b4b0",
}


def disasm_lines(data):
    from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN
    md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
    md.skipdata = True
    return ["%s %s" % (i.mnemonic, i.op_str) for i in md.disasm(data, 0)]


def main(argv=None):
    ap = argparse.ArgumentParser(description="Rename funzioni da seed con verifica disasm")
    ap.add_argument("--index", default="games/ramh/loro/index.json")
    ap.add_argument("--names", default="games/ramh/names.json")
    ap.add_argument("--check-only", action="store_true")
    a = ap.parse_args(argv)

    idx = json.load(open(a.index, encoding="utf-8"))
    names = json.load(open(a.names, encoding="utf-8"))
    units = {u["name"]: u for u in json.load(open("config/units.json"))["units"]}

    out = {}
    n_ok = n_sfasato = n_skip = 0
    for uname, v in idx.items():
        if uname in MINE_HIGH or uname in C_DONE:
            n_skip += 1
            continue
        if uname not in units:
            print("skip %s (non in units.json)" % uname)
            n_skip += 1
            continue
        p = units[uname]["target"]
        if not os.path.isfile(p):
            print("skip %s (target mancante)" % uname)
            n_skip += 1
            continue
        d = open(p, "rb").read()
        dis = "\n".join(disasm_lines(d))
        seed_nome = v.get("seed_nome") or ""
        ok = True
        # verifica marker nel disasm
        if "audio" in seed_nome.lower() and not any(
                r in dis for r in ("$dff0a8", "$dff0b8", "$dff0c8", "$dff0d8", "$dff096")):
            ok = False
        if "$dff0" in dis and not any(
                r in dis for r in ("$dff0a8", "$dff0b8", "$dff0c8", "$dff0d8",
                                   "$dff096", "$dff01c", "$dff01e", "$dff0a0",
                                   "$dff09a", "$dff09c", "$dff0180")):
            ok = False
        if "irq" in seed_nome.lower() and "$6c" not in dis.lower():
            ok = False
        if not ok:
            print("SEED SFALSO? %s | %s" % (uname, seed_nome))
            n_sfasato += 1
            out[uname] = {"name": None, "conf": "da-verificare",
                          "note": "seed sospetto: marker disasm assenti"}
            continue
        newname = seed_nome
        old = names.get(uname, {}).get("name")
        if old and old != newname:
            print("REN %s: %s -> %s" % (uname, old, newname))
        elif old == newname:
            n_skip += 1
            continue
        else:
            print("NEW %s: %s" % (uname, newname))
        names[uname] = dict(names.get(uname, {}), name=newname,
                            conf="low", desc="da seed loro, da verificare")
        out[uname] = {"name": newname, "conf": "low"}
        n_ok += 1

    print("promossi=%d sospesi=%d saltati=%d" % (n_ok, n_sfasato, n_skip))
    if a.check_only:
        return 0
    json.dump(names, open(a.names, "w", encoding="utf-8"), ensure_ascii=False, indent=2)
    print("names.json aggiornato")
    return 0


if __name__ == "__main__":
    sys.exit(main())
