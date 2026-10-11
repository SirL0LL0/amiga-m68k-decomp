/* $0bd3e attendi_pressione_fuoco: Cicla in lettura joystick fino a rilevare pressione tasto fuoco, poi azzera il codice azione. */

/* Cicla in lettura joystick fino a rilevare pressione tasto fuoco, poi azzera il codice azione. */

void attendi_pressione_fuoco(void)

{
  do {
    leggi_input_joystick_fuoco();
  } while (codice_azione_input != '\x01');
  codice_azione_input = 0;
  return;
}

