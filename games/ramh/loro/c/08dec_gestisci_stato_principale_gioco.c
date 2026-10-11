/* $08dec gestisci_stato_principale_gioco: Gestisce lo stato principale del gioco: processa click menu, inizializza schermi, attende scelte giocatore e sincronizza sequenze audio */

/* WARNING: Removing unreachable block (ram,0x00008e3c) */
/* WARNING: Removing unreachable block (ram,0x00008e22) */
/* WARNING: Removing unreachable block (ram,0x00008e88) */
/* WARNING: Removing unreachable block (ram,0x00008e14) */
/* WARNING: Removing unreachable block (ram,0x00008e30) */
/* WARNING: Removing unreachable block (ram,0x00008ec6) */
/* Gestisce lo stato principale del gioco: processa click menu, inizializza schermi, attende scelte
   giocatore e sincronizza sequenze audio */

void gestisci_stato_principale_gioco(void)

{
  gestisci_click_area_interattiva();
  inizializza_schermo_gioco_completo();
  if (area_menu_selezionata == '\0') {
    menu_attendi_scelta();
    aggiorna_schermo_gioco_condizionale();
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

