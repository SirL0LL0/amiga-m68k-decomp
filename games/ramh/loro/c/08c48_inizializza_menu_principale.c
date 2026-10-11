/* $08c48 inizializza_menu_principale: Configura controlli input e avvia gestione menu principale con selezione tipo controllo */

/* Configura controlli input e avvia gestione menu principale con selezione tipo controllo */

void inizializza_menu_principale(void)

{
  configura_controlli_input();
  if (tipo_controllo != '\x01') {
    elabora_scelta_menu_principale();
  }
  gestisci_menu_principale_soldi();
  return;
}

