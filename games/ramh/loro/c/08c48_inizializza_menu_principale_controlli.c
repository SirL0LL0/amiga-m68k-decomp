/* $08c48 inizializza_menu_principale_controlli: Configura controlli input e avvia gestione menu principale in base al tipo di controllo */

/* Configura controlli input e avvia gestione menu principale in base al tipo di controllo */

void inizializza_menu_principale_controlli(void)

{
  configura_controlli_input();
  if (tipo_controllo != '\x01') {
    gestisci_selezione_menu_principale();
  }
  gestisci_menu_principale();
  return;
}

