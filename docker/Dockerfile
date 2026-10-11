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
    wget \
    tar \
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

# 3. vbcc PRECOMPILATO multi-target per Linux x64 (binari ufficiali ibaug).
#    Include gia': vbccm68k + vc, config aos68k, target m68k-amigaos
#    (stessa famiglia del pacchetto Windows, verificato: config+target presenti).
#    Niente compilazione dai sorgenti: 'make TARGET=m68k' falliva (exit 2).
RUN wget -q -O /tmp/vbcc_linux_x64.tar.gz http://www.ibaug.de/vbcc/vbcc_linux_x64.tar.gz && \
    mkdir -p /opt/vbcc && tar -xzf /tmp/vbcc_linux_x64.tar.gz -C /opt/vbcc && \
    rm /tmp/vbcc_linux_x64.tar.gz && \
    test -f /opt/vbcc/vbcc/config/aos68k \
      || (echo "LAYOUT INATTESO, contenuto:" && ls -R /opt/vbcc | head -30 && exit 1) && \
    test -d /opt/vbcc/vbcc/targets/m68k-amigaos \
      || (echo "MANCA targets/m68k-amigaos:" && ls /opt/vbcc/vbcc/targets && exit 1) && \
    test -x /opt/vbcc/vbcc/bin/vbccm68k && test -x /opt/vbcc/vbcc/bin/vc && \
    cp /opt/vbcc/vbcc/bin/vbccm68k /opt/vbcc/vbcc/bin/vc /usr/local/bin/ && \
    echo "vbcc OK:" && ls /opt/vbcc/vbcc/targets/m68k-amigaos

ENV VBCC=/opt/vbcc/vbcc

# ---- Runtime ----
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    make \
    python3 \
    python3-pip \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/* \
    && pip3 install --no-cache-dir capstone pyelftools

COPY --from=builder /usr/local/bin/vasmm68k_mot /usr/local/bin/
COPY --from=builder /usr/local/bin/vlink /usr/local/bin/
COPY --from=builder /usr/local/bin/vbccm68k /usr/local/bin/
COPY --from=builder /usr/local/bin/vc /usr/local/bin/
COPY --from=builder /opt/vbcc/vbcc /opt/vbcc/vbcc

ENV VBCC=/opt/vbcc/vbcc
ENV PATH="${PATH}:/usr/local/bin"

# Smoke test: compila un C minimale col target aos68k (vbccm68k + vasm)
RUN printf 'void f(void){}\n' > /tmp/t.c && \
    vc +aos68k -c /tmp/t.c -o /tmp/t.o && ls -l /tmp/t.o && rm /tmp/t.c /tmp/t.o

WORKDIR /workspace

CMD ["make"]
