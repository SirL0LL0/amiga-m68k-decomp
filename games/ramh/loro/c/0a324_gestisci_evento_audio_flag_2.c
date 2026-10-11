/* $0a324 gestisci_evento_audio_flag_2: Gestisce evento audio flag 2: schermi, audio, addebito BCD, pausa, ripristina grafica */

/* Gestisce evento audio flag 2: schermi, audio, addebito BCD, pausa, ripristina grafica */

void gestisci_evento_audio_flag_2(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 2;
  flag_stato_audio = 0;
  inizializza_schermo_audio_e_renderizza();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_buffer_ausiliario();
  addebita_somma_con_underflow();
  pausa_messaggio();
  flag_stato_audio = uVar1;
  aggiorna_schermo_base_grafica();
  return;
}

