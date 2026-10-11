/* $09356 gestisci_transizione_testo_modale: Se modalita testo attiva, esegue transizione con fade, audio lungo e ricarica schermo completo */

/* Se modalita testo attiva, esegue transizione con fade, audio lungo e ricarica schermo completo */

void gestisci_transizione_testo_modale(void)

{
  if ((flag_modalita_testo != '\0') &&
     (contatore_modalita_testo = contatore_modalita_testo + -1, contatore_modalita_testo == '\0')) {
    attendi_input_gioco_con_timeout_59_frame();
    schermata_testo_con_transizione_e_timer();
    flag_disabilita_sfondo = 0;
    stato_font_corrente = 1;
    avvia_sequenza_audio_testo_lungo();
    aggiorna_maschera_128ce();
    sfonda_colori_e_pulisci_schermo();
    renderizza_schermo_completo_con_colori();
  }
  return;
}

