// Analisi Amiga M68k per Ghidra (headless o GUI).
//
// Uso headless (Ghidra >= 10, processore 68000, import raw + base address 0):
//   analyzeHeadless <projdir> <proj> -import game.bin -processor 68000:BE:32:default \
//     -scriptPath tools/ghidra -postScript AnalyzeAmiga.java symbols.json tools/ghidra/amiga_data.json
//
// Poi: python tools/symbols_to_units.py --symbols symbols.json --orig-dir orig
//
// Scritto in Java (non Python) perche' in Ghidra 12 gli script .py vengono
// serviti dal provider PyGhidra, non inizializzato in modalita' headless
// ("Ghidra was not started with PyGhidra"). Java funziona sempre.
// @category Amiga

import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;

public class AnalyzeAmiga extends GhidraScript {

    private static final long CUSTOM_BASE = 0xDFF000L;
    private static final long CUSTOM_SIZE = 0x1000L;
    private static final int MAX_FUNCTIONS_REFS = 5000;

    @Override
    public String getCategory() {
        return "Amiga";
    }

    @SuppressWarnings("unchecked")
    private Map<String, Object> loadData(String path) throws Exception {
        try (FileReader r = new FileReader(path)) {
            return new Gson().fromJson(r, Map.class);
        }
    }

    private boolean labelAddress(SymbolTable symtab, long addr, String name) {
        Address gaddr;
        try {
            gaddr = toAddr(addr);
        }
        catch (Exception e) {
            return false;
        }
        try {
            if (symtab.getSymbols(gaddr).length > 0) {
                return true;
            }
        }
        catch (Exception e) {
            // ignora, prova a creare
        }
        try {
            symtab.createLabel(gaddr, name, SourceType.USER_DEFINED);
            return true;
        }
        catch (Exception e) {
            println("WARN label " + name + ": " + e.getMessage());
            return false;
        }
    }

    private boolean hasCode(List<Map<String, Object>> functions) {
        for (Map<String, Object> f : functions) {
            if (!Boolean.TRUE.equals(f.get("external")) && !Boolean.TRUE.equals(f.get("thunk"))) {
                return true;
            }
        }
        return false;
    }

    private List<Map<String, Object>> exportFunctions() {        List<Map<String, Object>> out = new ArrayList<>();
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            Function fn = it.next();
            try {
                Map<String, Object> m = new LinkedHashMap<>();
                m.put("name", fn.getName());
                m.put("address", String.format("0x%x", fn.getEntryPoint().getOffset()));
                m.put("size", fn.getBody().getNumAddresses());
                m.put("external", fn.isExternal());
                m.put("thunk", fn.isThunk());
                out.add(m);
            }
            catch (Exception e) {
                println("WARN funzione saltata: " + e.getMessage());
            }
        }
        Collections.sort(out, new Comparator<Map<String, Object>>() {
            @Override
            public int compare(Map<String, Object> a, Map<String, Object> b) {
                long x = Long.decode((String) a.get("address"));
                long y = Long.decode((String) b.get("address"));
                return Long.compare(x, y);
            }
        });
        return out;
    }

    private List<Map<String, String>> exportUserLabels(int limit) {
        List<Map<String, String>> out = new ArrayList<>();
        SymbolTable symtab = currentProgram.getSymbolTable();
        SymbolIterator it = symtab.getAllSymbols(false);
        int n = 0;
        while (it.hasNext() && n < limit) {
            Symbol s = it.next();
            try {
                if (s.isDynamic() || s.getSource() == null) {
                    continue;
                }
                Map<String, String> m = new LinkedHashMap<>();
                m.put("name", s.getName());
                m.put("address", String.format("0x%x", s.getAddress().getOffset()));
                out.add(m);
                n++;
            }
            catch (Exception e) {
                continue;
            }
        }
        return out;
    }

    /** Per funzione, offset custom ($DFFxxx) referenziati. Best-effort. */
    private Map<String, List<String>> scanCustomRefs(List<Map<String, Object>> functions) {
        Map<String, List<String>> refs = new TreeMap<>();
        int done = 0;
        for (Map<String, Object> fn : functions) {
            if (done >= MAX_FUNCTIONS_REFS) {
                break;
            }
            if (Boolean.TRUE.equals(fn.get("external")) || Boolean.TRUE.equals(fn.get("thunk"))) {
                continue;
            }
            done++;
            try {
                long entry = Long.decode((String) fn.get("address"));
                Function gfn = getFunctionAt(toAddr(entry));
                if (gfn == null) {
                    continue;
                }
                Map<String, Boolean> hits = new TreeMap<>();
                AddressSetView body = gfn.getBody();
                for (Address a : body.getAddresses(true)) {
                    for (Reference r : currentProgram.getReferenceManager().getReferencesFrom(a)) {
                        long to = r.getToAddress().getOffset();
                        if (to >= CUSTOM_BASE && to < CUSTOM_BASE + CUSTOM_SIZE) {
                            hits.put(String.format("0x%03x", to - CUSTOM_BASE), Boolean.TRUE);
                        }
                    }
                    if (hits.size() > 64) {
                        break;
                    }
                }
                if (!hits.isEmpty()) {
                    refs.put((String) fn.get("name"), new ArrayList<>(hits.keySet()));
                }
            }
            catch (Exception e) {
                println("WARN scan " + fn.get("name") + ": " + e.getMessage());
            }
        }
        return refs;
    }

    @Override
    @SuppressWarnings("unchecked")
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Uso: AnalyzeAmiga.java <symbols.json> [amiga_data.json]");
            return;
        }
        String outPath = args[0];
        String dataPath = args.length > 1 ? args[1] : "tools/ghidra/amiga_data.json";

        Map<String, Object> data = loadData(dataPath);
        Map<String, String> customRegs =
            (Map<String, String>) data.getOrDefault("custom_regs", new LinkedHashMap<>());
        Map<String, Double> lvo =
            (Map<String, Double>) data.getOrDefault("exec_lvo", new LinkedHashMap<>());
        int colorCount = ((Double) data.getOrDefault("color_count", 32.0)).intValue();
        long colorBase = Long.decode((String) data.getOrDefault("color_base", "0x180"));

        int tx = currentProgram.startTransaction("Amiga labels");
        try {
            SymbolTable symtab = currentProgram.getSymbolTable();
            for (Map.Entry<String, String> e : customRegs.entrySet()) {
                labelAddress(symtab, CUSTOM_BASE + Long.decode(e.getKey()), "CUSTOM_" + e.getValue());
            }
            for (int i = 1; i < colorCount; i++) {
                labelAddress(symtab, CUSTOM_BASE + colorBase + i * 2, "CUSTOM_color" + String.format("%02d", i));
            }
        }
        finally {
            currentProgram.endTransaction(tx, true);
        }

        List<Map<String, Object>> functions = exportFunctions();
        println("funzioni trovate: " + functions.size());
        if (!hasCode(functions)) {
            // Raw binary senza entry analizzata: disassembla dalla base e
            // crea 'entry', cosi' la chain produce sempre almeno una unit.
            println("nessuna funzione, creo 'entry' alla image base");
            int tx2 = currentProgram.startTransaction("Amiga entry");
            try {
                Address base = currentProgram.getImageBase();
                disassemble(base);
                createFunction(base, "entry");
            }
            catch (Exception e) {
                println("WARN entry: " + e.getMessage());
            }
            finally {
                currentProgram.endTransaction(tx2, true);
            }
            functions = exportFunctions();
            println("funzioni dopo fallback: " + functions.size());
        }
        List<Map<String, String>> labels = exportUserLabels(20000);
        Map<String, List<String>> customRefs = scanCustomRefs(functions);

        Map<String, Object> lvoOut = new LinkedHashMap<>();
        for (Map.Entry<String, Double> e : lvo.entrySet()) {
            lvoOut.put(e.getKey(), e.getValue().intValue());
        }

        Map<String, Object> doc = new LinkedHashMap<>();
        doc.put("program", currentProgram.getName());
        doc.put("custom_base", String.format("0x%x", CUSTOM_BASE));
        doc.put("lvo_table", lvoOut);
        doc.put("custom_map", customRegs);
        doc.put("functions", functions);
        doc.put("labels", labels);
        doc.put("custom_refs", customRefs);

        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        try (FileWriter w = new FileWriter(outPath)) {
            gson.toJson(doc, w);
        }
        println("simboli scritti in " + outPath);
    }
}
