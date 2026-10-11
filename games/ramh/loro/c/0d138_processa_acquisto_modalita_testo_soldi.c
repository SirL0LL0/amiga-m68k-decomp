/* $0d138 processa_acquisto_modalita_testo_soldi: In modalita testo azzera timer, sottrae soldi BCD, mostra messaggio e aggiorna interfaccia */

/* WARNING: Removing unreachable block (ram,0x0000d15e) */
/* WARNING: Removing unreachable block (ram,0x0000d176) */
/* WARNING: Removing unreachable block (ram,0x0000d1ec) */
/* WARNING: Removing unreachable block (ram,0x0000d1ae) */
/* In modalita testo azzera timer, sottrae soldi BCD, mostra messaggio e aggiorna interfaccia */

void processa_acquisto_modalita_testo_soldi(void)

{
  if (flag_modalita_testo == '\0') {
    if (0x95 < valore_cursore_y) {
      gestisci_timer_attesa_ciclica();
    }
  }
  else if (contatore_timer_attesa == '\0') {
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_gioco_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    azzera_buffer_8_byte();
    flag_sottratto_soldi = 1;
    sottrai_soldi_gestisci_underflow();
    pausa_messaggio();
    aggiorna_scena_grafica_base();
    aggiorna_stato_gioco_principale();
    flag_modalita_testo = 0;
    return;
  }
  return;
}

