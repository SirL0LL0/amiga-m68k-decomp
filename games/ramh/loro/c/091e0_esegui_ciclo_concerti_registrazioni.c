/* $091e0 esegui_ciclo_concerti_registrazioni: Esegue 6 turni di concerti/registrazioni: inizializza schermo, gestisce soldi BCD, input, audio e aggiorna stato gioco per ogni turno */

/* Esegue 6 turni di concerti/registrazioni: inizializza schermo, gestisce soldi BCD, input, audio e
   aggiorna stato gioco per ogni turno */

void esegui_ciclo_concerti_registrazioni(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  uVar2 = 6;
  azzera_buffer_8_byte();
  somma_bcd_ripetuta();
  sottrai_soldi_gestisci_underflow();
  if (flag_saldo_negativo != '\0') {
    return;
  }
  attendi_input_gioco_con_timeout_59_frame();
  attiva_stato_audio();
  uVar3 = uVar2;
  while( true ) {
    cVar1 = (char)uVar2;
    inizializza_schermo_principale_completo(uVar2,uVar3);
    incrementa_valore_128cd();
    decrementa_livello_129c3();
    gestisci_input_e_carica_rock();
    gestisci_eventi_audio_slot_band();
    if (flag_saldo_negativo != '\0') break;
    aggiorna_stato_ciclo_gioco_principale();
    if ((((flag_saldo_negativo != '\0') || (flag_sequenza_completata != '\0')) ||
        (flag_slot_4_attivo != '\0')) || (tipo_controllo == '\0')) break;
    uVar2 = (uint)(byte)(cVar1 - 1U);
    if ((byte)(cVar1 - 1U) == 0) {
      resetta_stato_audio();
      attendi_input_gioco_con_timeout_59_frame();
      return;
    }
  }
  resetta_stato_audio();
  return;
}

