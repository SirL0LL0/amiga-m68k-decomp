/* $0a324 gestisci_evento_audio_flag2: Gestisce sequenza audio con flag 2, inizializza schermi e addebita somma */

/* Gestisce sequenza audio con flag 2, inizializza schermi e addebita somma */

void gestisci_evento_audio_flag2(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 2;
  flag_stato_audio = 0;
  inizializza_schermo_audio_e_renderizza();
  inizializza_schermo_gioco_completo();
  avvia_sequenza_audio_buffer_ausiliario();
  addebita_somma_con_underflow();
  pausa_messaggio();
  flag_stato_audio = uVar1;
  aggiorna_scena_grafica_base();
  return;
}

