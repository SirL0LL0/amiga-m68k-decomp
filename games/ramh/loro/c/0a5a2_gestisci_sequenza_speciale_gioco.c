/* $0a5a2 gestisci_sequenza_speciale_gioco: Esegue sequenza di inizializzazione schermo/audio e attende input in modalità speciale */

/* WARNING: Removing unreachable block (ram,0x0000a60e) */
/* Esegue sequenza di inizializzazione schermo/audio e attende input in modalità speciale */

void gestisci_sequenza_speciale_gioco(void)

{
  if ((flag_modalita_speciale != '\0') && ((flag_stato_gioco & 8) == 0)) {
    flag_stato_gioco = flag_stato_gioco | 8;
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_gioco_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    flag_sequenza_audio = 0;
    attendi_input_gioco_con_timeout();
    attiva_stato_audio();
    attendi_input_gioco_con_timeout();
    flag_stato_audio = 0;
    aggiorna_scena_grafica_base();
    aggiorna_stato_gioco_principale();
  }
  return;
}

