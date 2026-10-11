/* $089aa gestisci_selezione_menu_principale: Elabora input menu, inizializza schermo, attende rilascio mouse e gestisce validazione */

/* Elabora input menu, inizializza schermo, attende rilascio mouse e gestisce validazione */

void gestisci_selezione_menu_principale(void)

{
  char unaff_D6b;
  
  elabora_input_e_stringhe_ff();
  inizializza_schermo_gioco_completo();
  attendi_rilascio_pulsante_mouse();
  if (unaff_D6b != '\0') {
    inizializza_schermo_gioco_completo();
    buffer_stato_controlli = 0;
    gestisci_input_menu_con_validazione();
    return;
  }
  buffer_stato_controlli = 1;
  return;
}

