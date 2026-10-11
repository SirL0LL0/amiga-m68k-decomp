/* $0a0ea avvia_nuova_partita_da_menu: Avvia nuova partita dal menu: inizializza schermo, attende scelta, processa acquisto, esegue loop render/input/audio fino a fine partita */

/* Avvia nuova partita dal menu: inizializza schermo, attende scelta, processa acquisto, esegue loop
   render/input/audio fino a fine partita */

void avvia_nuova_partita_da_menu(void)

{
  char cVar1;
  
  indice_sequenza_corrente = '\0';
  riempi_memoria_byte_d6();
  flag_schermo_inizializzato = 1;
  flag_audio_attivo = 1;
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  azzera_buffer_8_byte();
  if (indirizzo_tabella_dati != 6) {
    pubblico_band_salvato = pubblico_band;
    contatore_cicli_gioco = (&tabella_indirizzi_dati)[indirizzo_tabella_dati];
    dato_tabella_indice_basso = (&tabella_byte_basso)[(byte)(indirizzo_tabella_dati << 1)];
    dato_tabella_indice_alto = (&tabella_byte_alto)[(byte)(indirizzo_tabella_dati << 1)];
    sottrai_soldi_gestisci_underflow();
    aggiorna_stato_ciclo_gioco_principale();
    if ((flag_saldo_negativo == '\0') && (flag_sequenza_completata == '\0')) {
      sfonda_colori_e_pulisci_schermo();
      contatore_cicli_ritardo = 4;
      renderizza_schermo_completo_con_colori();
      attendi_input_gioco_con_timeout_59_frame();
      cVar1 = contatore_cicli_gioco;
      do {
        do {
          aggiorna_stato_ciclo_gioco_principale();
          if ((flag_saldo_negativo != '\0') || (flag_sequenza_completata != '\0')) goto l_0a234;
          cVar1 = cVar1 + -1;
        } while (cVar1 != '\0');
        inizializza_schermo_principale_completo();
        ciclo_input_menu_nuova_partita();
        cVar1 = contatore_cicli_gioco;
      } while (indice_sequenza_corrente != '\n');
      decrementa_livello_129c3();
      decrementa_livello_129c3();
      incrementa_valore_128cd();
      incrementa_valore_128cd();
      flag_sequenza_audio = 1;
      attendi_input_gioco_con_timeout_59_frame();
      esegue_sequenza_avvio_partita();
    }
  }
l_0a234:
  contatore_cicli_ritardo = 1;
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  return;
}

