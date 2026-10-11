/* $0c6d8 disegna_sequenza_elementi_mascherati: Disegna sequenza di elementi mascherati incrementando offset finestra */

/* Disegna sequenza di elementi mascherati incrementando offset finestra */

void disegna_sequenza_elementi_mascherati(void)

{
  char unaff_D4b;
  char unaff_D6b;
  
  valore_minimo_trovato = '\0';
  do {
    trova_elemento_e_imposta_finestra(unaff_D4b);
    disegna_grafica_mascherata();
    unaff_D4b = unaff_D4b + '\a';
    valore_minimo_trovato = indice_elemento_attivo + '\x01';
    unaff_D6b = unaff_D6b + -1;
  } while (unaff_D6b != '\0');
  return;
}

