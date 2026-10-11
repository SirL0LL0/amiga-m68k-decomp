/* $091e0 esegui_ciclo_principale_rock: Ciclo principale dell'attività rock (concerto/registrazione) per 6 iterazioni con gestione soldi, audio e input */

/* Ciclo principale dell'attività rock (concerto/registrazione) per 6 iterazioni con gestione
   soldi, audio e input */

void esegui_ciclo_principale_rock(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  inizializza_schermo_gioco_completo();
  menu_attendi_scelta();
  uVar2 = 6;
  azzera_buffer_8_byte();
  somma_bcd_ripetuta();
  sottrai_soldi_gestisci_underflow();
  if (flag_saldo_negativo != '\0') {
    return;
  }
  attendi_input_gioco_con_timeout();
  attiva_stato_audio();
  uVar3 = uVar2;
  while( true ) {
    cVar1 = (char)uVar2;
    inizializza_schermo_gioco_completo(uVar2,uVar3);
    incrementa_valore_128cd();
    decrementa_livello_129c3();
    gestisci_input_e_carica_rock();
    processa_stato_slot_audio();
    if (flag_saldo_negativo != '\0') break;
    aggiorna_stato_gioco_principale();
    if ((((flag_saldo_negativo != '\0') || (flag_sequenza_completata != '\0')) ||
        (flag_slot_4_attivo != '\0')) || (tipo_controllo == '\0')) break;
    uVar2 = (uint)(byte)(cVar1 - 1U);
    if ((byte)(cVar1 - 1U) == 0) {
      resetta_stato_audio();
      attendi_input_gioco_con_timeout();
      return;
    }
  }
  resetta_stato_audio();
  return;
}

