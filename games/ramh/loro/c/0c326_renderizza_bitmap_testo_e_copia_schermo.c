/* $0c326 renderizza_bitmap_testo_e_copia_schermo: Disegna bitmap mascherata, visualizza testo con font, processa testo formattato, copia schermo e imposta colori copper */

/* Disegna bitmap mascherata, visualizza testo con font, processa testo formattato, copia schermo e
   imposta colori copper */

void renderizza_bitmap_testo_e_copia_schermo(void)

{
  disegna_bitmap_mascherata();
  visualizza_testo_con_font_attivo();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  return;
}

