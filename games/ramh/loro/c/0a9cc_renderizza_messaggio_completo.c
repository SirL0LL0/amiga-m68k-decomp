/* $0a9cc renderizza_messaggio_completo: Processa elenco stringhe, disegna sfondo area testo, stampa testo, copia schermo in buffer, imposta colori copper e avvia brano musicale */

/* Processa elenco stringhe, disegna sfondo area testo, stampa testo, copia schermo in buffer,
   imposta colori copper e avvia brano musicale */

void renderizza_messaggio_completo(void)

{
  byte bVar1;
  byte unaff_D4b;
  undefined4 unaff_D6;
  
  valore_minimo_trovato = 0;
  for (bVar1 = unaff_D4b; bVar1 != 0; bVar1 = bVar1 - 1) {
  }
  flag_controllo_secondario = unaff_D4b;
  processa_elenco_stringhe(unaff_D6);
  disegna_sfondo_area_testo();
  stampa_testo();
  copia_schermo_intero_in_buffer
            ((&tabella_buffer_schermo)[flag_controllo_secondario],(uint)flag_controllo_secondario);
  imposta_colori_copper_4();
  avvia_sequenza_musicale_rock5();
  return;
}

