/* $0a346 gestisci_stato_audio_menu_ritorno: Salva stato audio, attende input, gestisce menu principale e ripristina stato audio precedente */

/* Salva stato audio, attende input, gestisce menu principale e ripristina stato audio precedente */

void gestisci_stato_audio_menu_ritorno(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 4;
  resetta_stato_audio();
  attendi_input_gioco_con_timeout();
  gestisci_menu_principale();
  flag_stato_audio = uVar1;
  routine_vuota();
  return;
}

