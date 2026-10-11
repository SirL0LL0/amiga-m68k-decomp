/* $0932e inizializza_schermata_e_audio: Resetta lo stato audio, aggiorna gli elementi grafici e carica le immagini di sfondo nel buffer video. */

/* Resetta lo stato audio, aggiorna gli elementi grafici e carica le immagini di sfondo nel buffer
   video. */

void inizializza_schermata_e_audio(void)

{
  resetta_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  inizializza_schermo_principale_completo();
  aggiorna_riquadro_menu_con_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}

