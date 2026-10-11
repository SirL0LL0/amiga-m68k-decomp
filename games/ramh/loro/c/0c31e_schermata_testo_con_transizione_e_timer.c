/* $0c31e schermata_testo_con_transizione_e_timer: Esegue transizione con fade, disegna bitmap mascherata, visualizza testo, gestisce timer e copia schermo */

/* Esegue transizione con fade, disegna bitmap mascherata, visualizza testo, gestisce timer e copia
   schermo */

void schermata_testo_con_transizione_e_timer(void)

{
  undefined4 unaff_D6;
  
  esegue_transizione_schermo_testo_bitmap();
  disegna_bitmap_mascherata(unaff_D6);
  visualizza_testo_con_font_attivo();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  return;
}

