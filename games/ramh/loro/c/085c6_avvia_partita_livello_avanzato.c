/* $085c6 avvia_partita_livello_avanzato: Inizializza schermo, audio e variabili per nuova partita a livello avanzato (livello > 9) */

/* WARNING: Removing unreachable block (ram,0x0000860a) */
/* WARNING: Removing unreachable block (ram,0x00008646) */
/* WARNING: Removing unreachable block (ram,0x00008618) */
/* Inizializza schermo, audio e variabili per nuova partita a livello avanzato (livello > 9) */

void avvia_partita_livello_avanzato(void)

{
  if ((9 < livello_selezionato_129c3) && (99 < qualita_esibizione_band)) {
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    gestisci_timer_attesa_ciclica();
    if (indirizzo_tabella_dati == '\0') {
      inizializza_schermo_principale_completo();
      incrementa_livello_129c3();
      incrementa_valore_128ce();
      avvia_sequenza_audio_testo_lungo();
    }
    else {
      inizializza_schermo_principale_completo();
      aggiorna_maschera_128ce();
      decrementa_timer_attesa();
      avvia_sequenza_audio_testo_lungo();
      schermata_menu_controllo_testo();
    }
    aggiorna_schermo_base_grafica();
    aggiorna_stato_ciclo_gioco_principale();
  }
  return;
}

