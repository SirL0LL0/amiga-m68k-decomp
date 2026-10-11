/* $089aa elabora_scelta_menu_principale: Elabora input menu, inizializza schermo, attende rilascio mouse e gestisce validazione selezione */

/* Elabora input menu, inizializza schermo, attende rilascio mouse e gestisce validazione selezione
    */

void elabora_scelta_menu_principale(void)

{
  char unaff_D6b;
  
  elabora_input_e_stringhe_ff();
  inizializza_schermo_principale_completo();
  attendi_rilascio_pulsante_mouse();
  if (unaff_D6b != '\0') {
    inizializza_schermo_principale_completo();
    buffer_stato_controlli = 0;
    gestisci_input_testo_menu_validato();
    return;
  }
  buffer_stato_controlli = 1;
  return;
}

