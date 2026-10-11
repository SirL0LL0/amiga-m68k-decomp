#!/usr/bin/env python3
"""import_loro.py - fonde il lavoro precedente (decomp/) nel repo.

- nomi/desc loro -> games/ramh/names.json (campi loro_*, mai sovrascrive i miei)
- c/*.c -> games/ramh/loro/c/ + index.json (unit mia <-> file, con varianti)
- globali.json, funzioni.json, livelli.txt, gioco.c -> games/ramh/loro/ (ref)
- gli indirizzi entry loro sono +0x100 rispetto ai miei (verificato 143/165
  per conteggio istruzioni); i contenuti (C, chiamate, hw, globali) usano
  indirizzi veri e NON vanno shiftati, tranne chiama/chiamanti.

Uso: python tools/import_loro.py [--check-only]
"""
import json
import os
import re
import shutil
import sys

BASE = 0x8000
SHIFT = 0x100
LORO = "C:/Users/lollo/Downloads/RAMH traduzione/decomp/"
DEST = "games/ramh/loro"


def addr_of(name):
    m = re.search(r"_([0-9A-Fa-f]+)$", name)
    return int(m.group(1), 16) if m else None


def load():
    lorof = json.load(open(LORO + "funzioni.json", encoding="utf-8"))
    loron = json.load(open(LORO + "nomi.json", encoding="utf-8"))
    mie = json.load(open("config/units.json"))["units"]
    mine = json.load(open("games/ramh/names.json", encoding="utf-8"))
    return lorof, loron, mie, mine


def build_map(lorof, mie):
    """Mappa mia_addr -> chiave loro (mia_addr + SHIFT)."""
    by_my = {}
    for u in mie:
        a = addr_of(u["name"])
        if a is None:
            continue
        k = "%05x" % (a + SHIFT)
        if k in lorof:
            by_my[u["name"]] = k
    return by_my


def main(argv=None):
    check_only = "--check-only" in (argv or [])
    lorof, loron, mie, mine = load()
    by_my = build_map(lorof, mie)
    print("unit mie: %d, mappate su voci loro: %d" % (len(mie), len(by_my)))

    # 1) names.json: aggiungi campi loro_* senza toccare i miei
    n_new = 0
    # range mie unit per sub-mapping (fileoff, fileoff+size, nome)
    import re as _re

    def _sz(u):
        p = u["target"]
        try:
            return __import__("os").path.getsize(p)
        except OSError:
            return 0

    myranges = []
    for u in mie:
        a = addr_of(u["name"])
        if a is not None:
            myranges.append((a - BASE, a - BASE + _sz(u), u["name"]))
    for uname, k in sorted(by_my.items()):
        e = mine.setdefault(uname, {})
        if "loro_nome" in e:
            continue
        n = loron.get(k, {})
        f = lorof.get(k, {})
        e["loro_addr"] = "0x" + k
        e["loro_nome"] = n.get("nome", f.get("nome", "?"))
        e["loro_desc"] = n.get("desc", "")
        e["loro_fonte"] = n.get("fonte", "?")
        e["loro_chiama"] = ["0x%x" % (c - SHIFT) for c in f.get("chiama", [])]
        n_new += 1
    print("names.json: %d voci arricchite" % n_new)
    # sub-voci: entry loro che cadono DENTRO una mia unit (split diversi)
    n_sub = 0
    mapped_keys = set("%05x" % (addr_of(u["name"]) + SHIFT) for u in mie
                      if addr_of(u["name"]) is not None)
    for k in sorted(lorof, key=lambda x: int(x, 16)):
        if k in mapped_keys:
            continue
        a = int(k, 16) - SHIFT - BASE  # fileoff presunto
        for s, ee, uname in myranges:
            if s <= a < ee:
                e = mine.setdefault(uname, {})
                subs = e.setdefault("loro_sub", [])
                if not any(x.get("addr") == "0x" + k for x in subs):
                    n = loron.get(k, {})
                    subs.append({"addr": "0x" + k, "off": a - s,
                                 "nome": n.get("nome", "?"),
                                 "desc": (n.get("desc", "") or "")[:120],
                                 "conf": "da-verificare"})
                    n_sub += 1
                break
    print("names.json: %d sub-voci (da verificare)" % n_sub)

    # 2) c/*.c -> loro/c/ + index (solo per unit mappate)
    idx = {}
    files = sorted(os.listdir(LORO + "c"))
    # range per sub-mapping file -> unit contenitrice
    units_by_addr = {}
    for u in mie:
        a = addr_of(u["name"])
        if a is not None:
            p = u["target"]
            try:
                sz = os.path.getsize(p)
            except OSError:
                sz = 0
            units_by_addr[u["name"]] = (a - BASE, a - BASE + sz)
    for fn in files:
        m = re.match(r"([0-9a-fA-F]+)_.*\.c$", fn)
        if not m:
            continue
        a = int(m.group(1), 16) - SHIFT
        uname = next((u["name"] for u in mie if addr_of(u["name"]) == a), None)
        if uname is None:
            foff = a - BASE
            uname = next((n for n, (s, e) in units_by_addr.items()
                          if s <= foff < e), None)
            if uname is None:
                idx.setdefault("NON_MAPPATI", []).append(fn)
                continue
            idx.setdefault(uname + " (sub)", []).append(fn)
            continue
        idx.setdefault(uname, []).append(fn)
    n_map = sum(len(v) for k, v in idx.items() if k != "NON_MAPPATI")
    print("c/*.c: %d file su %d mappati su unit" % (n_map, len(files)))
    print("non mappati: %d es: %s" % (len(idx.get("NON_MAPPATI", [])),
                                      idx.get("NON_MAPPATI", [])[:5]))
    multi = {k: v for k, v in idx.items() if k != "NON_MAPPATI" and len(v) > 1}
    print("unit con varianti multiple: %d" % len(multi))

    if check_only:
        return 0
    os.makedirs(DEST + "/c", exist_ok=True)
    for fn in files:
        shutil.copyfile(LORO + "c/" + fn, DEST + "/c/" + fn)
    json.dump(idx, open(DEST + "/index.json", "w", encoding="utf-8"), indent=1)
    for f in ("globali.json", "funzioni.json", "livelli.txt", "gioco.c"):
        src = LORO + f
        if os.path.isfile(src):
            shutil.copyfile(src, DEST + "/" + f)
    with open(DEST + "/README.md", "w", encoding="utf-8") as fh:
        fh.write(
            "# Lavoro precedente (decomp/ di RAMH traduzione)\n\n"
            "Importato con `python tools/import_loro.py` (fonte citata per voce).\n\n"
            "- `c/`: ricostruzioni C per funzione (alcune in 2 varianti = disaccordo\n"
            "  da risolvere). Nomi file con indirizzi +0x100 rispetto ai miei\n"
            "  (verificato su 143/165 per conteggio istruzioni); vedi `index.json`.\n"
            "- `funzioni.json`: metadati (chiama/chiamanti in decimali, ANCH'ESSI\n"
            "  +0x100: sottrarre lo shift prima dell'uso), hw toccati, livelli.\n"
            "- `globali.json`: 294 globali con nomi italiani (indirizzi veri).\n"
            "- `gioco.c`, `livelli.txt`: combinato e livelli call graph.\n\n"
            "ATTENZIONE: gli split funzione loro non sono affidabili come confini\n"
            "(verificati inizi mid-code); usare nomi/desc/C come riferimento\n"
            "semantico, non i boundaries. I byte fanno fede: `orig/func/`.\n")
    json.dump(mine, open("games/ramh/names.json", "w", encoding="utf-8"),
              ensure_ascii=False, indent=2)
    print("scritto: %s/ + names.json aggiornato" % DEST)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
