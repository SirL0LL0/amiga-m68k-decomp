# Lavoro precedente (decomp/ di RAMH traduzione)

Importato con `python tools/import_loro.py` (fonte citata per voce).

- `c/`: ricostruzioni C per funzione (alcune in 2 varianti = disaccordo
  da risolvere). Nomi file con indirizzi +0x100 rispetto ai miei
  (verificato su 143/165 per conteggio istruzioni); vedi `index.json`.
- `funzioni.json`: metadati (chiama/chiamanti in decimali, ANCH'ESSI
  +0x100: sottrarre lo shift prima dell'uso), hw toccati, livelli.
- `globali.json`: 294 globali con nomi italiani (indirizzi veri).
- `gioco.c`, `livelli.txt`: combinato e livelli call graph.

ATTENZIONE: gli split funzione loro non sono affidabili come confini
(verificati inizi mid-code); usare nomi/desc/C come riferimento
semantico, non i boundaries. I byte fanno fede: `orig/func/`.
