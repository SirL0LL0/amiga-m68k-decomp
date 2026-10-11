/* $0bd54 aggiorna_scorrimento_tavolozza: Aggiorna coordinata schermo e ricarica tavolozza per scorrimento fluido */

/* Aggiorna coordinata schermo e ricarica tavolozza per scorrimento fluido */

void aggiorna_scorrimento_tavolozza(void)

{
  if (flag_blocco_input != '\0') {
    return;
  }
  if (flag_scroll_attivo == '\0') {
    if (flag_scroll_direzione == '\0') {
      if (codice_azione_input == '\0') {
        return;
      }
      if (codice_azione_input == '\x01') {
        return;
      }
      if (codice_azione_input == '\x02') goto l_0bdbe;
      codice_azione_input = '\0';
    }
    if (coordinata_x_schermo_d081 != coordinata_x_schermo_max) {
      attendi_passaggio_pennello();
      coordinata_x_schermo_d081 = coordinata_x_schermo_d081 + '\x01';
      carica_tavolozza_schermo_1();
    }
  }
  else {
l_0bdbe:
    codice_azione_input = '\0';
    if (coordinata_x_schermo_d081 != coordinata_x_schermo_min) {
      attendi_passaggio_pennello();
      coordinata_x_schermo_d081 = coordinata_x_schermo_d081 + -1;
      carica_tavolozza_schermo_1();
      return;
    }
  }
  return;
}

