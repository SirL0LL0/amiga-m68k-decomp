/* $0977a gestisci_turno_giocatore_acquisto: Gestisce turno giocatore: input menu, transazioni BCD soldi, verifica saldo e aggiorna stato */

/* Gestisce turno giocatore: input menu, transazioni BCD soldi, verifica saldo e aggiorna stato */

void gestisci_turno_giocatore_acquisto(void)

{
  char cVar1;
  
  if (tipo_controllo == '\x01') {
    mappatura_controlli_attiva = 0x73;
  }
  else {
    mappatura_controlli_attiva = 0x87;
  }
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  azzera_tre_buffer_8_byte();
  (&buffer_bcd_destinazione)[(byte)(&tabella_indirizzi_bcd_dest)[(uint)indirizzo_tabella_dati * 2]]
       = (&tabella_valori_bcd_sorgente)[(uint)indirizzo_tabella_dati * 2];
  somma_bcd_ripetuta();
  attendi_input_gioco_con_timeout_59_frame();
  cVar1 = '\f' - indirizzo_tabella_dati;
  do {
    incrementa_contatori_129b7();
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  verifica_e_aggiorna_saldo_soldi();
  aggiorna_stato_ciclo_gioco_principale();
  return;
}

