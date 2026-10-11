/* $085c6 gestisci_avvio_partita_livello_alto: Inizializza schermo e audio per nuovo gioco ad alto livello, gestisce transizioni e contatori */

/* WARNING: Removing unreachable block (ram,0x0000860a) */
/* WARNING: Removing unreachable block (ram,0x00008646) */
/* WARNING: Removing unreachable block (ram,0x00008618) */
/* Inizializza schermo e audio per nuovo gioco ad alto livello, gestisce transizioni e contatori */

void gestisci_avvio_partita_livello_alto(void)

{
  if ((9 < livello_selezionato_129c3) && (99 < valore_cursore_y)) {
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_gioco_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    gestisci_timer_attesa_ciclica();
    if (indirizzo_tabella_dati == '\0') {
      inizializza_schermo_gioco_completo();
      incrementa_livello_129c3();
      incrementa_valore_128ce();
      avvia_sequenza_audio_testo_lungo();
    }
    else {
      inizializza_schermo_gioco_completo();
      aggiorna_maschera_128ce();
      decrementa_timer_attesa();
      avvia_sequenza_audio_testo_lungo();
      schermata_menu_controllo_testo();
    }
    aggiorna_scena_grafica_base();
    aggiorna_stato_gioco_principale();
  }
  return;
}

