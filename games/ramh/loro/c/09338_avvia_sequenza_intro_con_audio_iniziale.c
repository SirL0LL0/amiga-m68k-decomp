/* $09338 avvia_sequenza_intro_con_audio_iniziale: Esegue sequenza intro con attivazione audio iniziale: attiva audio, reset, 3 schermi, 2 audio-testo, attesa fuoco */

/* Esegue sequenza intro con attivazione audio iniziale: attiva audio, reset, 3 schermi, 2
   audio-testo, attesa fuoco */

void avvia_sequenza_intro_con_audio_iniziale(void)

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

