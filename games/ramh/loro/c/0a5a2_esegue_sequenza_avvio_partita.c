/* $0a5a2 esegue_sequenza_avvio_partita: Esegue sequenza inizializzazione schermo/audio per nuova partita in modalita speciale */

/* WARNING: Removing unreachable block (ram,0x0000a60e) */
/* Esegue sequenza inizializzazione schermo/audio per nuova partita in modalita speciale */

void esegue_sequenza_avvio_partita(void)

{
  if ((soldi_cifra_milioni != '\0') && ((flag_stato_gioco & 8) == 0)) {
    flag_stato_gioco = flag_stato_gioco | 8;
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    flag_sequenza_audio = 0;
    attendi_input_gioco_con_timeout_59_frame();
    attiva_stato_audio();
    attendi_input_gioco_con_timeout_59_frame();
    flag_stato_audio = 0;
    aggiorna_schermo_base_grafica();
    aggiorna_stato_ciclo_gioco_principale();
  }
  return;
}

