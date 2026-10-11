#!/usr/bin/env python3
"""adf_extract.py - legge filesystem AmigaDOS (OFS/FFS) da .ADF ed estrae file.

Uso:
    python tools/adf_extract.py game.adf --list
    python tools/adf_extract.py game.adf --extract-all out/
    python tools/adf_extract.py game.adf --get NomeFile -o fuori.bin
"""

import argparse
import os
import struct
import sys

BS = 512
T_HEADER, T_DATA, T_LIST = 2, 8, 16
ST_ROOT, ST_FILE, ST_DIR = 1, -3, 2


def u32(b, o):
    return struct.unpack_from(">I", b, o)[0]


def i32(b, o):
    return struct.unpack_from(">i", b, o)[0]


class ADF:
    def __init__(self, path):
        self.data = open(path, "rb").read()
        if len(self.data) % BS != 0:
            raise ValueError("dimensione non multipla di 512")
        self.nblocks = len(self.data) // BS
        self.dostype = self.data[0:4]
        self.ffs = self.dostype in (b"DOS\x01", b"DOS\x02", b"DOS\x03",
                                    b"DOS\x04", b"DOS\x05", b"DOS\x06", b"DOS\x07")
        # rootblock: standard 880 (floppy DD)
        self.root = 880 if self.nblocks > 880 else self.nblocks // 2

    def blk(self, n):
        if not (0 <= n < self.nblocks):
            raise ValueError("blocco %d fuori range" % n)
        return self.data[n * BS:(n + 1) * BS]

    def bname(self, b):
        n = b[0]
        return b[1:1 + n].decode("latin-1", "replace")

    def walk(self):
        """Ritorna [(path, header_block)]."""
        out = []
        rb = self.blk(self.root)
        if u32(rb, 0) != T_HEADER or i32(rb, BS - 4) != ST_ROOT:
            raise ValueError("rootblock non valido (disco NDOS?)")
        def rec(blkno, prefix):
            b = self.blk(blkno)
            for i in range(72):
                h = u32(b, 24 + i * 4)
                while h:
                    hb = self.blk(h)
                    if u32(hb, 0) != T_HEADER:
                        break
                    st = i32(hb, BS - 4)
                    # filename BCPL a offset 432 (verificato: checksum ok + len coerenti
                    # su root, dir e file di questo disco)
                    nm = self.bname(hb[432:464])
                    p = prefix + "/" + nm if prefix else nm
                    if st == ST_DIR:
                        out.append((p + "/", h))
                        rec(h, p)
                    elif st == ST_FILE:
                        out.append((p, h))
                    h = u32(hb, BS - 16)  # next hash chain
        rec(self.root, "")
        return out

    def read_file(self, header_blk):
        # Layout verificato su disco Codemasters (checksums ok):
        # size @324, extension-next @504, parent @500, highSeq @8, firstData @16.
        # I data block OFS portano SEQ @8: l'ordine vero viene da li',
        # non dalla posizione nella tabella puntatori.
        hb = self.blk(header_blk)
        size = u32(hb, 324)
        ptrs = [u32(hb, 24 + i * 4) for i in range(72)]
        ext = u32(hb, 504)
        while ext:
            eb = self.blk(ext)
            if u32(eb, 0) not in (T_LIST,):
                break
            ptrs += [u32(eb, 24 + i * 4) for i in range(72)]
            ext = u32(eb, 504)
        seqdata = []
        for bn in ptrs:
            if not bn:
                continue
            db = self.blk(bn)
            if u32(db, 0) != T_DATA:
                continue
            seqdata.append((u32(db, 8), db[24:BS]))
        seqdata.sort(key=lambda t: t[0])
        out = bytearray()
        for _, chunk in seqdata:
            out += chunk
        return bytes(out[:size])


def main(argv=None):
    ap = argparse.ArgumentParser(description="Estrae file da ADF AmigaDOS")
    ap.add_argument("adf", nargs="?")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--extract-all", metavar="DIR", default=None)
    ap.add_argument("--get", default=None)
    ap.add_argument("-o", "--output", default=None)
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    fs = ADF(a.adf)
    print("dostype=%r ffs=%s blocchi=%d" % (fs.dostype, fs.ffs, fs.nblocks))
    files = fs.walk()
    if a.list or (not a.extract_all and not a.get):
        for p, h in files:
            print("  %-40s blk=%d" % (p, h))
    if a.extract_all:
        os.makedirs(a.extract_all, exist_ok=True)
        for p, h in files:
            if p.endswith("/"):
                continue
            with open(os.path.join(a.extract_all, p.replace("/", "_")), "wb") as f:
                f.write(fs.read_file(h))
        print("estratti %d file in %s" % (len([f for f in files if not f[0].endswith("/")]), a.extract_all))
    if a.get:
        for p, h in files:
            if p.rstrip("/") == a.get:
                open(a.output or os.path.basename(p), "wb").write(fs.read_file(h))
                print("scritto %s" % (a.output or p))
                return 0
        print("file non trovato: %s" % a.get, file=sys.stderr)
        return 1
    return 0


def self_test():
    import tempfile
    print("== adf_extract.py self-test ==")
    # costruisci ADF FFS minimo: boot + root + 1 file "ciao" (5 byte)
    n = 1760
    img = bytearray(n * BS)
    img[0:4] = b"DOS\x01"
    root = 880
    rb = bytearray(BS)
    struct.pack_into(">I", rb, 0, T_HEADER)
    struct.pack_into(">i", rb, BS - 4, ST_ROOT)
    img[root * BS:(root + 1) * BS] = rb
    # file header blk 881 (nome @432, size @324), dati blk 882 (SEQ 1)
    fb = bytearray(BS)
    struct.pack_into(">I", fb, 0, T_HEADER)
    struct.pack_into(">I", fb, 24, 882)
    struct.pack_into(">I", fb, 324, 5)
    fb[432] = 4
    fb[433:437] = b"ciao"
    struct.pack_into(">i", fb, BS - 4, ST_FILE)
    img[881 * BS:882 * BS] = fb
    db = bytearray(BS)
    struct.pack_into(">I", db, 0, T_DATA)
    struct.pack_into(">I", db, 8, 1)
    db[24:29] = b"hello"
    img[882 * BS:883 * BS] = db
    # link root -> 881
    struct.pack_into(">I", img, root * BS + 24, 881)
    with tempfile.TemporaryDirectory() as d:
        p = os.path.join(d, "t.adf")
        open(p, "wb").write(img)
        fs = ADF(p)
        files = fs.walk()
        assert files == [("ciao", 881)], files
        assert fs.read_file(881) == b"hello"
        print("  [ok] root + 1 file FFS")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
