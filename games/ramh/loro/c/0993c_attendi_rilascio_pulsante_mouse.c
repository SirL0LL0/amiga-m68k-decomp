/* $0993c attendi_rilascio_pulsante_mouse: Attende il rilascio dei pulsanti del mouse e aggiorna lo stato degli input. */

/* Attende il rilascio dei pulsanti del mouse e aggiorna lo stato degli input. */

void attendi_rilascio_pulsante_mouse(void)

{
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  flag_stato_mouse_sinistro = 1;
  aggiorna_riquadro_menu_con_grafica();
  flag_stato_mouse_destro = 1;
  ciclo_principale_menu_joystick();
  return;
}

