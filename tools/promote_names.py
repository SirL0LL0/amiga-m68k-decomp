#!/usr/bin/env python3
"""promote_names.py - promuove loro_nome -> name dove affidabile.

Regole (in ordine):
1. se ho gia' name/conf high: tengo il mio, niente da fare.
2. validazione istruzioni ok (mia slice vs loro count entro [0.8,1.25])
   + fonte manuale -> conf med.
3. validazione ok + fonte LLM -> conf low.
4. senza validazione -> conf da-verificare (nome comunque promosso:
   ipotesi di lavoro esplicita, mai byte toccati).
5. crea voci mancanti per unit senza entry.

Uso: python tools/promote_names.py [--check-only]
"""
import json
import os
import re
import sys

BASE = 0x8000
SHIFT = 0x100
LORO = "C:/Users/lollo/Downloads/RAMH traduzione/decomp/"


def addr_of(name):
    m = re.search(r"_([0-9A-Fa-f]+)$", name)
    return int(m.group(1), 16) if m else None


def main(argv=None):
    check_only = "--check-only" in (argv or [])
    lorof = json.load(open(LORO + "funzioni.json", encoding="utf-8"))
    mie = json.load(open("config/units.json"))["units"]
    mine = json.load(open("games/ramh/names.json", encoding="utf-8"))

    try:
        from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN
        md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
        md.skipdata = True
        have_cs = True
    except Exception:
        have_cs = False

    # crea voci mancanti
    for u in mie:
        if u["name"] not in mine:
            mine[u["name"]] = {}

    stats = {"tenuti": 0, "med": 0, "low": 0, "verificare": 0}
    for uname, e in sorted(mine.items()):
        if uname.startswith("$") or not isinstance(e, dict):
            continue
        if e.get("name"):
            # mai sovrascrivere un nome esistente (curato a mano o promosso
            # in run precedenti): solo riempire dove manca.
            stats["tenuti"] += 1
            continue
        ln = e.get("loro_nome")
        if not ln or ln.startswith("f_"):
            continue  # niente nome utile
        # validazione istruzioni?
        valid = None
        a = addr_of(uname)
        if a is not None and have_cs:
            k = "%05x" % (a + SHIFT)
            f = lorof.get(k)
            u = next((x for x in mie if x["name"] == uname), None)
            if f and u and os.path.isfile(u["target"]):
                d = open(u["target"], "rb").read()
                n = sum(1 for _ in md.disasm(d, 0))
                li = f.get("istruzioni") or 0
                r = n / li if li else 9
                valid = 0.8 <= r <= 1.25
        fonte = e.get("loro_fonte", "")
        if valid:
            conf = "med" if fonte == "manuale" else "low"
        else:
            conf = "da-verificare"
        e["name"] = ln
        e["desc"] = e.get("loro_desc", "")
        e["conf"] = conf
        stats[conf if conf in stats else "verificare"] += 1

    print(stats)
    if check_only:
        return 0
    json.dump(mine, open("games/ramh/names.json", "w", encoding="utf-8"),
              ensure_ascii=False, indent=2)
    print("names.json aggiornato")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
