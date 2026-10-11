/* $0a586 somma_valore_tabella_128ba: Somma alla variabile 128be un valore letto dalla tabella 128ba all'offset A3. */

/* Somma alla variabile 128be un valore letto dalla tabella 128ba all'offset A3. */

void somma_valore_tabella_128ba(void)

{
  int unaff_A3;
  
  sommatore_valori_tabella =
       *(char *)((uint)indirizzo_tabella_dati + unaff_A3) + sommatore_valori_tabella;
  return;
}

