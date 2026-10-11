/* $093c8 aggiorna_ciclo_principale_gioco: Ciclo principale di gioco: ogni 16 frame gestisce acquisti modalita testo, avvio partita alto livello, classifiche e transizioni testo modale */

/* Ciclo principale di gioco: ogni 16 frame gestisce acquisti modalita testo, avvio partita alto
   livello, classifiche e transizioni testo modale */

void aggiorna_ciclo_principale_gioco(void)

{
  if ((((flag_saldo_negativo == '\0') && (tipo_controllo != '\0')) &&
      (flag_sequenza_completata == '\0')) && (flag_slot_4_attivo == '\0')) {
    processa_acquisto_testo_soldi();
    contatore_cicli_principale = contatore_cicli_principale - 1 & 0xf;
    if (contatore_cicli_principale == 0) {
      contatore_cicli_principale = 0xc;
      avvia_partita_livello_avanzato();
    }
    else if (contatore_cicli_principale == 3) {
      gestisci_classifica_punteggi_attiva();
    }
    gestisci_transizione_testo_modale();
  }
  return;
}

