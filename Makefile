# ==============================================================================
# Makefile per decompilazione Amiga M68k (vbcc + vasm + vlink + diff_m68k.py)
#
# NOTA: objdiff NON supporta M68k (solo arm/arm64/mips/ppc/superh/x86).
# Il matching byte-perfect e' fatto da tools/diff_m68k.py (capstone),
# che emette build/report.json in formato decomp.dev (REPORT_VERSION = 2).
# ==============================================================================
# Toolchain (override da env o da Docker: docker/Dockerfile)
VC      ?= vc
VCFLAGS ?= +aos68k -c -Iinclude -O1
VASM    ?= vasmm68k_mot
VASMFLAGS ?= -Fhunk -m68000 -Iinclude
VLINK   ?= vlink
PYTHON  ?= python3

BUILD_DIR  := build
TARGET_DIR := orig
REPORT     := $(BUILD_DIR)/report.json
SYMBOLS    := symbols.json
UNITS      := config/units.json

# Ghidra headless (solo locale, non in CI). Override: make analyze GHIDRA_DIR=...
GHIDRA_DIR ?= /opt/ghidra
GHIDRA_PROJDIR ?= $(HOME)/ghidra_projects/amiga
GHIDRA_PROJ ?= game
GHIDRA_PROG ?= game.bin
AGENT_WORK ?= agent/work

SRC_C   := $(wildcard src/*.c)
SRC_ASM := $(wildcard asm/*.s asm/*.asm)
OBJ_C   := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC_C))
OBJ_ASM := $(patsubst asm/%,$(BUILD_DIR)/%,$(SRC_ASM))
OBJ_ASM := $(OBJ_ASM:.s=.o)
OBJ_ASM := $(OBJ_ASM:.asm=.o)

.PHONY: all build report diff check-tools verify split analyze units decompile agent reasm docker-build clean

all: build

build: $(BUILD_DIR) $(OBJ_C) $(OBJ_ASM)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(TARGET_DIR)

$(BUILD_DIR)/%.o: src/%.c
	$(VC) $(VCFLAGS) $< -o $@

$(BUILD_DIR)/%.o: asm/%.s
	$(VASM) $(VASMFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: asm/%.asm
	$(VASM) $(VASMFLAGS) -o $@ $<

# Report decomp.dev-compatibile: confronta TARGET_DIR (binario originale
# splittato) con BUILD_DIR (oggetti ricompilati). Vedi tools/diff_m68k.py.
report: build
	$(PYTHON) tools/diff_m68k.py --target-dir $(TARGET_DIR) --build-dir $(BUILD_DIR) -o $(REPORT)
	@echo "--- report: $(REPORT) ---"
	@$(PYTHON) -c "import json; r=json.load(open('$(REPORT)')); m=r['measures']; print('code %6.2f%% (%d/%d bytes), func %d/%d' % (m['matched_code_percent'], m['matched_code'], m['total_code'], m['matched_functions'], m['total_functions']))"

diff: report

check-tools:
	@which $(VC) || (echo "MISSING: vc (vbcc). Usa Docker: make docker-build"; exit 1)
	@which $(VASM) || (echo "MISSING: vasmm68k_mot. Usa Docker: make docker-build"; exit 1)
	@$(PYTHON) -c "import capstone" || (echo "MISSING: pip install -r tools/requirements.txt"; exit 1)

# Split dell'eseguibile originale (una tantum per gioco)
split:
	$(PYTHON) tools/split_hunk.py $(EXE) --out-dir $(TARGET_DIR) --manifest $(TARGET_DIR)/manifest.json --base $(BASE)

# Analisi Ghidra headless (solo locale, non in CI): importa BIN grezzo come
# 68000 big-endian a base 0 ed esporta symbols.json. Richiede EXE (file .bin
# da importare) e GHIDRA_PROJDIR esistente.
# Es: make analyze GHIDRA_DIR="C:/.../Ghidra" EXE=orig/hunk0_CODE.bin
analyze:
	"$(GHIDRA_DIR)/support/analyzeHeadless" $(GHIDRA_PROJDIR) $(GHIDRA_PROJ) \
	  -import $(EXE) -overwrite -processor 68000:BE:32:default \
	  -scriptPath tools/ghidra \
	  -postScript AnalyzeAmiga.java $(SYMBOLS) tools/ghidra/amiga_data.json

# symbols.json -> unit per-funzione + header LVO (preserva flag complete)
units:
	$(PYTHON) tools/symbols_to_units.py --symbols $(SYMBOLS) --orig-dir $(TARGET_DIR)

# C del decompilatore Ghidra -> decompiled/*.c (locale, best-effort).
# Richiede programma gia' importato (vedi analyze); GHIDRA_PROG = nome in progetto.
decompile:
	"$(GHIDRA_DIR)/support/analyzeHeadless" $(GHIDRA_PROJDIR) $(GHIDRA_PROJ) \
	  -process $(GHIDRA_PROG) -noanalysis -scriptPath tools/ghidra \
	  -postScript DecompileFunctions.java decompiled

# Agent automatico: varianti C -> compile -> diff -> tiene il meglio.
# Backend default da tools/agent/config.json (heuristic; llm con OPENAI_API_KEY).
agent:
	$(PYTHON) tools/agent/loop.py --units $(UNITS)

# Riassembla le unit senza sorgenti in asm/*.s byte-identici (vasm nativo).
# Non tocca mai asm/*.s o src/*.c esistenti (lavoro manuale al sicuro).
reasm:
	$(PYTHON) tools/reasm.py --units $(UNITS)

# Verifica senza toolchain: self-test dei tool + layout header col gcc host
verify:
	$(PYTHON) tools/diff_m68k.py --self-test
	$(PYTHON) tools/split_hunk.py --self-test
	$(PYTHON) tools/symbols_to_units.py --self-test
	$(PYTHON) tools/agent/loop.py --self-test
	$(PYTHON) tools/reasm.py --self-test
	$(PYTHON) tools/m68k_flow.py --self-test
	$(PYTHON) tools/adf_extract.py --self-test
	gcc -I include tools/check_hw.c -o $(BUILD_DIR)/check_hw && ./$(BUILD_DIR)/check_hw

docker-build:
	docker build -t amiga-decomp-toolchain -f docker/Dockerfile .

clean:
	rm -rf $(BUILD_DIR)
