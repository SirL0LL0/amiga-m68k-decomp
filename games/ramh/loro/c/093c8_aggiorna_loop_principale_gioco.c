/* $093c8 aggiorna_loop_principale_gioco: Gestisce stato principale: acquisti, avvio partita alto livello, classifiche e transizioni testo modale a intervalli regolari */

/* Gestisce stato principale: acquisti, avvio partita alto livello, classifiche e transizioni testo
   modale a intervalli regolari */

void aggiorna_loop_principale_gioco(void)

{
  if ((((flag_saldo_negativo == '\0') && (tipo_controllo != '\0')) &&
      (flag_sequenza_completata == '\0')) && (flag_slot_4_attivo == '\0')) {
    processa_acquisto_modalita_testo_soldi();
    contatore_cicli_principale = contatore_cicli_principale - 1 & 0xf;
    if (contatore_cicli_principale == 0) {
      contatore_cicli_principale = 0xc;
      gestisci_avvio_partita_livello_alto();
    }
    else if (contatore_cicli_principale == 3) {
      gestisci_classifica_punteggi_condizionale();
    }
    gestisci_transizione_testo_modale();
  }
  return;
}

