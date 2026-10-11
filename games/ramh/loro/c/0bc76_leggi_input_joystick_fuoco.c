/* $0bc76 leggi_input_joystick_fuoco: Legge stato joystick e tasto fuoco, imposta codice azione in base a input */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Legge stato joystick e tasto fuoco, imposta codice azione in base a input */

void leggi_input_joystick_fuoco(void)

{
  ushort uVar1;
  char cVar2;
  
  cVar2 = stato_precedente_joystick;
  codice_azione_input = 0;
  if ((ciaa_pra_joystick & 0x40) == 0) {
    codice_azione_input = 1;
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
    return;
  }
  if (-1 < (char)ciaa_pra_joystick) {
    codice_azione_input = 1;
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x80) == 0);
    return;
  }
  if (flag_blocco_input != '\0') {
    codice_azione_input = 1;
    do {
    } while (flag_blocco_input != '\0');
    return;
  }
  if (flag_scroll_direzione != '\0') {
    codice_azione_input = 3;
    return;
  }
  if (flag_scroll_attivo == '\0') {
    stato_precedente_joystick = DAT_00dff00a;
    if (cVar2 == DAT_00dff00a) {
      if (((_DAT_00dff00c & 2) == 0) && ((_DAT_00dff00c & 0x200) == 0)) {
        uVar1 = _DAT_00dff00c ^ _DAT_00dff00c >> 1;
        if ((uVar1 & 1) != 0) {
          codice_azione_input = 3;
          return;
        }
        if ((uVar1 & 0x100) != 0) {
          codice_azione_input = 2;
          return;
        }
      }
      return;
    }
    if ((char)(cVar2 - DAT_00dff00a) < '\0') {
      codice_azione_input = 3;
      return;
    }
  }
  codice_azione_input = 2;
  return;
}

