/* $0d24c gestisci_classifica_punteggi_condizionale: Se flag classifiche attivo e cursore basso, avvia sequenza audio, verifica soldi e aggiorna stato */

/* WARNING: Removing unreachable block (ram,0x0000d326) */
/* WARNING: Removing unreachable block (ram,0x0000d336) */
/* WARNING: Removing unreachable block (ram,0x0000d306) */
/* WARNING: Removing unreachable block (ram,0x0000d308) */
/* WARNING: Removing unreachable block (ram,0x0000d310) */
/* WARNING: Removing unreachable block (ram,0x0000d2f6) */
/* WARNING: Removing unreachable block (ram,0x0000d2f0) */
/* Se flag classifiche attivo e cursore basso, avvia sequenza audio, verifica soldi e aggiorna stato
    */

void gestisci_classifica_punteggi_condizionale(void)

{
  if (((flag_classifiche_attive == '\0') && (flag_eventi_classifiche_pending != '\0')) &&
     (199 < valore_cursore_y)) {
    inizializza_schermo_audio_e_renderizza();
    flag_classifiche_attive = '\x01';
    flag_scrolling_attivo = 0xf;
    inizializza_schermo_gioco_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    menu_attendi_scelta();
    azzera_tre_buffer_8_byte(0xac);
    gestisci_timer_attesa_ciclica();
    contatore_verifica_soldi = 4;
    verifica_e_aggiorna_saldo_soldi();
    attendi_input_gioco_con_timeout();
    aggiorna_scena_grafica_base();
    aggiorna_stato_gioco_principale();
  }
  return;
}

