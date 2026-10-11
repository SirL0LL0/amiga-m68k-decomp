/* $0d94a ciclo_principale_menu_joystick: Ciclo menu principale: aggiorna bitplane, tavolozza, input joystick, renderizza scena */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Ciclo menu principale: aggiorna bitplane, tavolozza, input joystick, renderizza scena */

void ciclo_principale_menu_joystick(void)

{
  char cVar1;
  undefined4 unaff_D4;
  undefined2 unaff_D5w;
  undefined4 local_4;
  
  if (flag_modalita_schermo == '\0') {
    local_4 = CONCAT22((short)((uint)unaff_D4 >> 0x10),_coordinata_x_finestra);
    coordinata_y_schermo_d080 = (char)_coordinata_x_finestra * '\b' + -6;
    coordinata_x_schermo_d081 = (char)(_coordinata_x_finestra >> 5) - 4;
    coordinata_x_schermo_max =
         (char)(CONCAT11((char)((ushort)unaff_D5w >> 8),coordinata_y_finestra) >> 5) + -0xc;
    register0x0000003c = (BADSPACEBASE *)&local_4;
    coordinata_x_schermo_min = coordinata_x_schermo_d081;
  }
  indirizzo_tabella_dati = flag_modalita_schermo != '\0';
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9a4;
  aggiorna_bitplane_e_grafica();
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9a8;
  attendi_passaggio_pennello();
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9ac;
  carica_tavolozza_schermo_1();
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9b0;
  attesa_rilascio_tasto_destro_mouse();
  while( true ) {
    *(undefined4 *)register0x0000003c = 0xd9b6;
    leggi_input_joystick_fuoco();
    *(undefined4 *)register0x0000003c = 0xd9ba;
    aggiorna_scorrimento_tavolozza();
    if (codice_azione_input == '\x01') break;
    if (((coordinata_x_schermo_d081 & 7) == 0) || ((coordinata_x_schermo_d081 & 7) == 7)) {
      cVar1 = ((coordinata_x_schermo_d081 >> 3) - coordinata_x_finestra) + '\x01';
      if (indirizzo_tabella_dati != cVar1) {
        *(undefined4 *)register0x0000003c = 0xda22;
        indirizzo_tabella_dati = cVar1;
        copia_bitplane_2_in_1();
        *(undefined4 *)register0x0000003c = 0xda26;
        aggiorna_bitplane_e_grafica();
      }
    }
  }
  codice_azione_input = 0;
  *(undefined4 *)register0x0000003c = 0xd9ce;
  renderizza_scena_condizionale();
  *(undefined4 *)register0x0000003c = 0xd9d2;
  renderizza_interfaccia_gioco_completa();
  *(undefined4 *)register0x0000003c = 0xd9d6;
  copia_grafica_6f8c6_in_buffer_video();
  *(undefined4 *)register0x0000003c = 0xd9da;
  copia_grafica_707c6_in_buffer_video();
  *(undefined4 *)register0x0000003c = 0xd9de;
  carica_tavolozza_schermo_2();
  return;
}

