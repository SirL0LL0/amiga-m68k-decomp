/* $09338 avvia_sequenza_intro_con_audio_attivo: Esegue sequenza di avvio con attivazione stato audio all'inizio come 092ce */

/* Esegue sequenza di avvio con attivazione stato audio all'inizio come 092ce */

void avvia_sequenza_intro_con_audio_attivo(void)

{
  resetta_stato_audio();
  inizializza_schermo_gioco_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_gioco_completo();
  avvia_sequenza_audio_testo_lungo();
  inizializza_schermo_gioco_completo();
  aggiorna_riquadro_menu_e_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  aggiorna_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}

