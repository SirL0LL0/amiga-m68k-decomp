/* $0d348 attendi_input_gioco_con_timeout_59_frame: Inizializza schermo e attende input joystick/fuoco per 59 frame (circa 1 sec) o fino a pressione tasto */

/* Inizializza schermo e attende input joystick/fuoco per 59 frame (circa 1 sec) o fino a pressione
   tasto */

void attendi_input_gioco_con_timeout_59_frame(void)

{
  short sVar1;
  undefined1 *extraout_A0;
  undefined1 *puVar2;
  
  inizializza_schermo_principale_completo();
  codice_azione_input = '\0';
  sVar1 = 4;
  do {
    pausa_breve();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = 0x3b;
  while( true ) {
    pausa_breve();
    leggi_input_joystick_fuoco();
    if (flag_blocco_input != '\0') break;
    puVar2 = &codice_azione_input;
    if (codice_azione_input == '\x01') goto l_0d390;
    sVar1 = sVar1 + -1;
    if (sVar1 == -1) {
      return;
    }
  }
  do {
    puVar2 = extraout_A0;
  } while (flag_blocco_input != '\0');
l_0d390:
  *puVar2 = 0;
  return;
}

