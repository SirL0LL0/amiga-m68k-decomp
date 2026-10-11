/* $0d24c gestisci_classifica_punteggi_attiva: Se classifiche attive e cursore basso, avvia audio, verifica soldi e aggiorna stato gioco */

/* WARNING: Removing unreachable block (ram,0x0000d326) */
/* WARNING: Removing unreachable block (ram,0x0000d336) */
/* WARNING: Removing unreachable block (ram,0x0000d306) */
/* WARNING: Removing unreachable block (ram,0x0000d308) */
/* WARNING: Removing unreachable block (ram,0x0000d310) */
/* WARNING: Removing unreachable block (ram,0x0000d2f6) */
/* WARNING: Removing unreachable block (ram,0x0000d2f0) */
/* Se classifiche attive e cursore basso, avvia audio, verifica soldi e aggiorna stato gioco */

void gestisci_classifica_punteggi_attiva(void)

{
  if (((flag_classifiche_attive == '\0') && (flag_eventi_classifiche_pending != '\0')) &&
     (199 < qualita_esibizione_band)) {
    inizializza_schermo_audio_e_renderizza();
    flag_classifiche_attive = '\x01';
    flag_scrolling_attivo = 0xf;
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    menu_attendi_scelta();
    azzera_tre_buffer_8_byte(0xac);
    gestisci_timer_attesa_ciclica();
    contatore_verifica_soldi = 4;
    verifica_e_aggiorna_saldo_soldi();
    attendi_input_gioco_con_timeout_59_frame();
    aggiorna_schermo_base_grafica();
    aggiorna_stato_ciclo_gioco_principale();
  }
  return;
}

