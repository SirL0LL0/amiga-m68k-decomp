/* $09944 menu_attendi_scelta: aspetta il rilascio del fuoco e la fine della pausa, poi gestisce il menu; restituisce la scelta in d6 */

/* aspetta il rilascio del fuoco e la fine della pausa, poi gestisce il menu; restituisce la scelta
   in d6 */

void menu_attendi_scelta(void)

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

