/* $0d34c pausa_messaggio: pausa dopo un messaggio (65 pause brevi), interrompibile; con spazio premuto aspetta il rilascio */

/* pausa dopo un messaggio (65 pause brevi), interrompibile; con spazio premuto aspetta il rilascio
    */

void pausa_messaggio(void)

{
  short sVar1;
  undefined1 *extraout_A0;
  undefined1 *puVar2;
  
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

