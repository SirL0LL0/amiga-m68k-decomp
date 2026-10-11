/* $0a2e0 gestisci_evento_audio_sottrattivo: Gestisce sequenza audio, inizializza schermi, addebita somma e aggiorna grafica */

/* Gestisce sequenza audio, inizializza schermi, addebita somma e aggiorna grafica */

void gestisci_evento_audio_sottrattivo(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 1;
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

