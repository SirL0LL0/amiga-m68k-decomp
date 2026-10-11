/* $0c31e schermata_testo_con_transizione: Esegue transizione schermo con fade, disegna bitmap mascherata e renderizza testo formattato con timer */

/* Esegue transizione schermo con fade, disegna bitmap mascherata e renderizza testo formattato con
   timer */

void schermata_testo_con_transizione(void)

{
  undefined4 unaff_D6;
  
  esegue_transizione_schermo_con_testo();
  disegna_bitmap_mascherata(unaff_D6);
  visualizza_testo_con_font_selezionato();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  return;
}

