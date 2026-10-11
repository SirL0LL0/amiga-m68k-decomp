/* $0c37e visualizza_schermata_testo_con_grafica: Renderizza testo formattato con font, disegna grafica mascherata, imposta colori copper e avvia audio */

/* Renderizza testo formattato con font, disegna grafica mascherata, imposta colori copper e avvia
   audio */

void visualizza_schermata_testo_con_grafica(void)

{
  visualizza_testo_con_font_attivo();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  if (flag_elemento_controllo == '\0') {
    inizializza_elemento_controllo_attivo();
  }
  else {
    trova_elemento_e_imposta_finestra();
  }
  disegna_grafica_mascherata();
  indice_elemento_attivo_salvato = indice_elemento_attivo;
  flag_elemento_controllo = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  flag_disabilita_sfondo = 0;
  stato_font_corrente = 1;
  avvia_sequenza_audio_testo_lungo();
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  return;
}

