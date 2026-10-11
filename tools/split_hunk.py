#!/usr/bin/env python3
"""split_hunk.py - estrae le sezioni da un eseguibile Amiga Hunk.

Formato Amiga Hunk (big-endian, unita' da 32 bit):
  HUNK_HEADER ($3F3): [n_hunks, first, last, size0..sizeN, ...]
  poi per ogni hunk: [type, ...dati..., HUNK_END ($3F2)]
  tipi: CODE=$3E9, DATA=$3EA, BSS=$3EB (solo dimensione), RELOC32=$3EC,
        SYMBOL=$3F0, DEBUG=$3F1, END=$3F2

Uso:
    python tools/split_hunk.py game.exe --out-dir orig
    python tools/split_hunk.py --self-test
"""

import argparse
import json
import os
import struct
import sys

HUNK_HEADER = 0x3F3
HUNK_CODE = 0x3E9
HUNK_DATA = 0x3EA
HUNK_BSS = 0x3EB
HUNK_RELOC32 = 0x3EC
HUNK_SYMBOL = 0x3F0
HUNK_DEBUG = 0x3F1
HUNK_END = 0x3F2

# bit "hunk loadable" / memoria (MEMF_CHIP etc.) nei type word
TYPE_MASK = 0x3FFFFFFF


def u32be(data, off):
    return struct.unpack_from(">I", data, off)[0]


def parse_hunks(data: bytes):
    """Ritorna lista di dict {index, type, name, data/size}."""
    if len(data) < 4 or u32be(data, 0) != HUNK_HEADER:
        raise ValueError("non e' un eseguibile Hunk (manca HUNK_HEADER $3F3)")
    off = 4
    # header: skip strings (nomi residenti, di solito 0)
    while True:
        n = u32be(data, off); off += 4
        if n == 0:
            break
        off += n * 4
    n_hunks = u32be(data, off); off += 4
    first = u32be(data, off); off += 4
    last = u32be(data, off); off += 4
    sizes = []
    for _ in range(last - first + 1):
        sizes.append(u32be(data, off) & 0x3FFFFFFF); off += 4

    hunks = []
    for i in range(first, last + 1):
        htype = u32be(data, off) & TYPE_MASK; off += 4
        if htype == HUNK_CODE or htype == HUNK_DATA:
            nlongs = u32be(data, off); off += 4
            raw = data[off:off + nlongs * 4]; off += nlongs * 4
            hunks.append({"index": i, "type": htype,
                          "name": "CODE" if htype == HUNK_CODE else "DATA",
                          "data": raw})
        elif htype == HUNK_BSS:
            nlongs = u32be(data, off); off += 4
            hunks.append({"index": i, "type": htype, "name": "BSS",
                          "size": nlongs * 4})
        else:
            raise ValueError(f"hunk {i}: tipo non gestito ${htype:X} a offset {off-4}")
        # consuma blocchi opzionali fino a HUNK_END
        while True:
            tag = u32be(data, off) & TYPE_MASK; off += 4
            if tag == HUNK_END:
                break
            elif tag == HUNK_RELOC32:
                while True:
                    n = u32be(data, off); off += 4
                    if n == 0:
                        break
                    off += 4 + n * 4  # hunk_num + offsets
            elif tag in (HUNK_SYMBOL, HUNK_DEBUG):
                while True:
                    n = u32be(data, off); off += 4
                    if n == 0:
                        break
                    off += n * 4 + 4  # nome + valore
            else:
                raise ValueError(f"hunk {i}: blocco ${tag:X} non gestito")
    return hunks


def split_to_dir(exe_path, out_dir, manifest_path=None, base_addr=0x0):
    with open(exe_path, "rb") as f:
        data = f.read()
    hunks = parse_hunks(data)
    os.makedirs(out_dir, exist_ok=True)
    manifest = []
    addr = base_addr
    for h in hunks:
        size = h.get("size", len(h.get("data", b"")))
        if h["name"] == "BSS":
            # BSS = solo zeri, salva placeholder di dimensione nota
            path = os.path.join(out_dir, "hunk%d_BSS.bss" % h["index"])
            open(path, "wb").write(b"\x00" * size)
        else:
            path = os.path.join(out_dir, "hunk%d_%s.bin" % (h["index"], h["name"]))
            open(path, "wb").write(h["data"])
        manifest.append({"hunk": h["index"], "type": h["name"], "file": path,
                         "size": size, "base": "0x%x" % addr})
        print("  hunk %d %-4s %8d bytes base=0x%x -> %s"
              % (h["index"], h["name"], size, addr, path))
        addr += (size + 3) & ~3  # hunk allineati a 4 byte, caricati in sequenza
    if manifest_path:
        with open(manifest_path, "w", encoding="utf-8") as f:
            json.dump({"exe": exe_path, "load_base": "0x%x" % base_addr,
                       "hunks": manifest}, f, indent=2)
        print("manifest: " + manifest_path)
    return manifest


def make_test_exe():
    """Costruisce un finto eseguibile Hunk: 1 CODE (NOP+RTS) + 1 DATA."""
    code = bytes.fromhex("4e714e75")  # NOP, RTS
    data = bytes.fromhex("00010203")
    out = struct.pack(">I", HUNK_HEADER)
    out += struct.pack(">I", 0)          # no resident names
    out += struct.pack(">III", 2, 0, 1)  # 2 hunks: 0..1
    out += struct.pack(">II", 1, 1)      # sizes in longwords
    out += struct.pack(">II", HUNK_CODE, len(code) // 4) + code
    out += struct.pack(">I", HUNK_END)
    out += struct.pack(">II", HUNK_DATA, len(data) // 4) + data
    out += struct.pack(">I", HUNK_END)
    return out


def self_test():
    import tempfile
    print("== split_hunk.py self-test ==")
    exe = make_test_exe()
    hunks = parse_hunks(exe)
    assert len(hunks) == 2, hunks
    assert hunks[0]["name"] == "CODE" and hunks[0]["data"] == bytes.fromhex("4e714e75")
    assert hunks[1]["name"] == "DATA"
    print("  [ok] parse 1 CODE + 1 DATA")
    with tempfile.TemporaryDirectory() as d:
        p = os.path.join(d, "game.exe")
        open(p, "wb").write(exe)
        man = split_to_dir(p, os.path.join(d, "orig"))
        assert len(man) == 2 and man[0]["size"] == 4
        print("  [ok] split su disco")
    # file non-hunk -> errore chiaro
    try:
        parse_hunks(b"MZ\x90\x00")
        raise AssertionError("doveva fallire")
    except ValueError as e:
        print(f"  [ok] rifiuta non-Hunk ({e})")
    print("ALL SELF-TESTS PASSED")


def main(argv=None):
    ap = argparse.ArgumentParser(description="Split eseguibile Amiga Hunk in orig/")
    ap.add_argument("exe", nargs="?", help="eseguibile Amiga (formato Hunk)")
    ap.add_argument("--out-dir", default="orig")
    ap.add_argument("--manifest", default=None,
                    help="scrive manifest JSON (basi di caricamento hunk)")
    ap.add_argument("--base", default="0x0",
                    help="indirizzo di caricamento hunk0 (default 0x0)")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        self_test()
        return 0
    if not a.exe:
        ap.error("serve un file .exe Hunk (o --self-test)")
    split_to_dir(a.exe, a.out_dir, manifest_path=a.manifest,
                 base_addr=int(a.base, 16))
    return 0


if __name__ == "__main__":
    sys.exit(main())
