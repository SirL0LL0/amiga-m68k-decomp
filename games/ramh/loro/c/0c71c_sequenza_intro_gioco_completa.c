/* $0c71c sequenza_intro_gioco_completa: Sequenza intro completa con ramificazione modalità testo: fade, riempimento, testi, immagini, 4 bitmap, audio finale */

/* Sequenza intro completa con ramificazione modalità testo: fade, riempimento, testi, immagini, 4
   bitmap, audio finale */

void sequenza_intro_gioco_completa(void)

{
  undefined *puVar1;
  
  sfonda_colori_e_pulisci_schermo();
  riempi_schermo_colore_7();
  stato_font_corrente = 0;
  flag_disabilita_sfondo = 1;
  if (flag_modalita_testo == '\0') {
    processa_e_visualizza_testo_formattato();
    disegna_immagine_4_bitplane();
  }
  else {
    processa_e_visualizza_testo_formattato();
    processa_e_visualizza_testo_formattato();
    visualizza_testo_con_font_attivo(flag_modalita_testo);
    visualizza_testo_con_font_attivo();
    decrementa_valore_128ce();
    decrementa_valore_128ce();
  }
  visualizza_testo_con_font_attivo();
  flag_selezione_font = 1;
  puVar1 = &puntatore_bitmap_mascherata;
  disegna_bitmap_mascherata(&puntatore_bitmap_mascherata);
  disegna_bitmap_mascherata(puVar1);
  disegna_bitmap_mascherata(puVar1);
  disegna_bitmap_mascherata();
  flag_selezione_font = 0;
  renderizza_testo_da_tabella(tipo_controllo);
  disegna_sequenza_elementi_mascherati();
  stato_font_corrente = 1;
  flag_disabilita_sfondo = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  avvia_sequenza_audio_testo_lungo();
  sfonda_colori_e_pulisci_schermo();
  return;
}

