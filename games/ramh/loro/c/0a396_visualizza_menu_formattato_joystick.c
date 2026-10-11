/* $0a396 visualizza_menu_formattato_joystick: Renderizza menu con testo formattato multiplo, input joystick e transizioni schermo */

/* WARNING: Removing unreachable block (ram,0x0000a3b4) */
/* WARNING: Removing unreachable block (ram,0x0000a46a) */
/* WARNING: Removing unreachable block (ram,0x0000a496) */
/* WARNING: Removing unreachable block (ram,0x0000a4a0) */
/* WARNING: Removing unreachable block (ram,0x0000a4aa) */
/* WARNING: Removing unreachable block (ram,0x0000a4b0) */
/* WARNING: Removing unreachable block (ram,0x0000a4d8) */
/* WARNING: Removing unreachable block (ram,0x0000a4e2) */
/* WARNING: Removing unreachable block (ram,0x0000a4ec) */
/* WARNING: Removing unreachable block (ram,0x0000a4f2) */
/* WARNING: Removing unreachable block (ram,0x0000a50e) */
/* WARNING: Removing unreachable block (ram,0x0000a524) */
/* Renderizza menu con testo formattato multiplo, input joystick e transizioni schermo */

void visualizza_menu_formattato_joystick(void)

{
  char cVar1;
  short sVar2;
  
  if ((flag_eventi_classifiche_pending & 0x80) == 0) {
    menu_attendi_scelta();
  }
  inizializza_schermo_principale_completo();
  contatore_righe_testo = 0xc;
  flag_stato_mouse_sinistro = 1;
  aggiorna_riquadro_menu_con_grafica();
  cVar1 = '\r';
  sVar2 = 0x38;
  do {
    processa_e_visualizza_testo_formattato(cVar1,sVar2);
    sVar2 = sVar2 + 1;
    cVar1 = cVar1 + '\x01';
  } while (cVar1 != '\x17');
  ciclo_principale_menu_joystick();
  sommatore_valori_tabella = 0;
  flag_primo_accesso_menu = indirizzo_tabella_dati;
  inizializza_schermo_principale_completo();
  attendi_rilascio_pulsante_mouse();
  decrementa_livello_129c3();
  decrementa_livello_129c3();
  calcola_posizione_cursore_menu();
  flag_eventi_classifiche_pending = flag_eventi_classifiche_pending | 0x40;
  contatore_righe_testo = 0;
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  aggiorna_stato_ciclo_gioco_principale();
  return;
}

