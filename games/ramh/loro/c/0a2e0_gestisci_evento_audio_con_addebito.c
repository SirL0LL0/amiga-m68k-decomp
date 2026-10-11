/* $0a2e0 gestisci_evento_audio_con_addebito: Gestisce evento audio con addebito BCD: schermi, audio, addebito, pausa, ripristina grafica */

/* Gestisce evento audio con addebito BCD: schermi, audio, addebito, pausa, ripristina grafica */

void gestisci_evento_audio_con_addebito(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 1;
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

