/* $0a346 gestisci_ritorno_menu_audio: Salva stato audio, gestisce menu principale e ripristina audio per ritorno da slot band */

/* Salva stato audio, gestisce menu principale e ripristina audio per ritorno da slot band */

void gestisci_ritorno_menu_audio(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 4;
  resetta_stato_audio();
  attendi_input_gioco_con_timeout_59_frame();
  gestisci_menu_principale_soldi();
  flag_stato_audio = uVar1;
  routine_vuota();
  return;
}

