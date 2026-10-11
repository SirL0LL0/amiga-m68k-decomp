// Esporta il C del decompilatore Ghidra per ogni funzione (best-effort).
//
// Uso headless (dopo AnalyzeAmiga.java, stesso progetto; serve -process):
//   analyzeHeadless <projdir> <proj> -process <programma> -noanalysis \
//     -scriptPath tools/ghidra \
//     -postScript DecompileFunctions.java <out_dir> [SoloQuesta ...]
//
// Scrive <out_dir>/<funzione>.c col C decompilato + header con indirizzo/size.
// Le funzioni che il decompilatore non supporta vengono saltate (exit 0 comunque):
// in quel caso l'agent parte da uno skeleton generato dal disassembly.
// @category Amiga

import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class DecompileFunctions extends GhidraScript {

    @Override
    public String getCategory() {
        return "Amiga";
    }

    private static String safeName(String name) {
        String s = name.replaceAll("[^A-Za-z0-9_]", "_");
        if (s.isEmpty() || Character.isDigit(s.charAt(0))) {
            s = "f_" + s;
        }
        return s;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Uso: DecompileFunctions.java <out_dir> [funzione ...]");
            return;
        }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        Set<String> only = new HashSet<>();
        for (int i = 1; i < args.length; i++) {
            only.add(args[i]);
        }

        DecompInterface di = new DecompInterface();
        di.setOptions(new DecompileOptions());
        if (!di.openProgram(currentProgram)) {
            println("ERRORE: decompilatore non disponibile per " +
                currentProgram.getLanguage().getLanguageID());
            return;
        }
        int ok = 0, skipped = 0;
        Set<String> seen = new HashSet<>();
        try {
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            while (it.hasNext()) {
                Function fn = it.next();
                String name = fn.getName();
                if (!only.isEmpty() && !only.contains(name)) {
                    continue;
                }
                if (fn.isExternal() || fn.isThunk()) {
                    skipped++;
                    continue;
                }
                String uname = safeName(name);
                if (!seen.add(uname)) {
                    uname = uname + String.format("_%x", fn.getEntryPoint().getOffset());
                    seen.add(uname);
                }
                try {
                    DecompileResults res = di.decompileFunction(fn, 60, monitor);
                    if (res == null || !res.decompileCompleted()) {
                        println("skip " + name + ": decompilazione fallita");
                        skipped++;
                        continue;
                    }
                    String c = res.getDecompiledFunction().getC();
                    File out = new File(outDir, uname + ".c");
                    try (FileWriter w = new FileWriter(out)) {
                        w.write("/* " + name + " @ " + fn.getEntryPoint() +
                            " size " + fn.getBody().getNumAddresses() +
                            " -- da Ghidra, da rifinire per il matching */\n");
                        w.write(c);
                        if (!c.endsWith("\n")) {
                            w.write("\n");
                        }
                    }
                    ok++;
                }
                catch (Exception e) {
                    println("skip " + name + ": " + e.getMessage());
                    skipped++;
                }
            }
        }
        finally {
            di.dispose();
        }
        println("decompilate: " + ok + ", saltate: " + skipped + " -> " + outDir);
    }
}
