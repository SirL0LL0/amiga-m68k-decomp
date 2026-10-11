# ==============================================================================
# Dockerfile: Amiga M68k Cross-Toolchain (vbcc + vasm + vlink)
# NOTA: objdiff / decomp.dev NON supportano M68k (verificato in
# objdiff-core/src/arch/mod.rs: solo arm, arm64, mips, ppc, superh, x86).
# Il diffing per M68k e' fatto da tools/diff_m68k.py (capstone), che emette
# un report.json compatibile con decomp.dev (REPORT_VERSION = 2).
# ==============================================================================
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    wget \
    tar \
    lhasa \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt

# 1. vasm (CPU=m68k, SYNTAX=mot) -> vasmm68k_mot
RUN wget -q http://sun.hasenbraten.de/vasm/release/vasm.tar.gz && \
    tar -xzf vasm.tar.gz && \
    cd vasm && \
    make CPU=m68k SYNTAX=mot && \
    cp vasmm68k_mot /usr/local/bin/ && \
    cd .. && rm -rf vasm*

# 2. vlink
RUN wget -q http://sun.hasenbraten.de/vlink/release/vlink.tar.gz && \
    tar -xzf vlink.tar.gz && \
    cd vlink && \
    make && \
    cp vlink /usr/local/bin/ && \
    cd .. && rm -rf vlink*

# 3. vbcc (sorgenti ufficiali; URL verificato 200: ibaug.de, snapshot 2026-01-10.
#     NOTA: i vecchi URL sun.hasenbraten.de/vbcc/release e compilers.de/downloads
#     non esistono piu' (404). Precompilati per host: vedi README sezione toolchain.)
RUN mkdir -p vbcc && cd vbcc && \
    wget -q http://www.ibaug.de/vbcc/vbcc.tar.gz && \
    tar -xzf vbcc.tar.gz && \
    mkdir -p bin && \
    make TARGET=m68k && \
    cp bin/vbccm68k bin/vc /usr/local/bin/ && \
    cd .. && rm -rf vbcc

# 4. Target m68k-amigaos per vbcc (config + include + lib).
# Fonte verificata: vendor/ di Team-Boingo/AmiCC (contiene l'archivio
# upstream non modificato vbcc_target_m68k-amiga.lha).
ENV VBCC=/opt/vbcc_target
RUN mkdir -p ${VBCC} && \
    wget -q -O /tmp/vbcc_target.lha https://github.com/Team-Boingo/AmiCC/raw/main/vendor/targets/vbcc_target_m68k-amiga.lha && \
    lhasa x -w=${VBCC} /tmp/vbcc_target.lha && \
    rm /tmp/vbcc_target.lha && \
    ls -R ${VBCC} | head -50

# ---- Runtime ----
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    make \
    python3 \
    python3-pip \
    lhasa \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/* \
    && pip3 install --no-cache-dir capstone pyelftools

COPY --from=builder /usr/local/bin/vasmm68k_mot /usr/local/bin/
COPY --from=builder /usr/local/bin/vlink /usr/local/bin/
COPY --from=builder /usr/local/bin/vbccm68k /usr/local/bin/
COPY --from=builder /usr/local/bin/vc /usr/local/bin/
COPY --from=builder /opt/vbcc_target /opt/vbcc_target

ENV VBCC=/opt/vbcc_target
ENV PATH="${PATH}:/usr/local/bin"

WORKDIR /workspace

CMD ["make"]
