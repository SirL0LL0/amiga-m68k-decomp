/* $08dec gestisci_menu_principale_2: Gestisce il flusso del menu principale: rileva click, inizializza schermo, attende scelta giocatore e aggiorna interfaccia */

/* WARNING: Removing unreachable block (ram,0x00008e3c) */
/* WARNING: Removing unreachable block (ram,0x00008e22) */
/* WARNING: Removing unreachable block (ram,0x00008e88) */
/* WARNING: Removing unreachable block (ram,0x00008e14) */
/* WARNING: Removing unreachable block (ram,0x00008e30) */
/* WARNING: Removing unreachable block (ram,0x00008ec6) */
/* Gestisce il flusso del menu principale: rileva click, inizializza schermo, attende scelta
   giocatore e aggiorna interfaccia */

void gestisci_menu_principale_2(void)

{
  gestisci_click_menu_principale();
  inizializza_schermo_principale_completo();
  if (area_menu_selezionata == '\0') {
    menu_attendi_scelta();
    aggiorna_schermo_menu_con_animazione();
    return;
  }
  if (flag_sequenza_audio == '\0') {
    menu_attendi_scelta();
  }
  else {
    menu_attendi_scelta();
  }
  inizializza_schermo_attendi_mouse();
  return;
}

