/* $0a630 gestisci_menu_membri_band: Menu gestione 4 slot musicisti: assunzione/licenziamento con costi BCD, stati slot attivi, transizioni schermo e aggiornamento interfaccia */

/* WARNING: Removing unreachable block (ram,0x0000a862) */
/* WARNING: Removing unreachable block (ram,0x0000a7e2) */
/* WARNING: Removing unreachable block (ram,0x0000a7f0) */
/* WARNING: Removing unreachable block (ram,0x0000a84e) */
/* WARNING: Removing unreachable block (ram,0x0000a85a) */
/* WARNING: Removing unreachable block (ram,0x0000a7dc) */
/* Menu gestione 4 slot musicisti: assunzione/licenziamento con costi BCD, stati slot attivi,
   transizioni schermo e aggiornamento interfaccia */

void gestisci_menu_membri_band(void)

{
  char cVar1;
  byte bVar2;
  byte unaff_D6b;
  uint uVar3;
  
  trova_minimo_array_4_elementi();
  indice_elemento_attivo = indice_elemento_selezionato;
  indice_elemento_attivo_salvato = indice_elemento_selezionato;
  if (8 < unaff_D6b) {
    decrementa_contatori_129b7();
    contatore_ritardo_cicli = 0;
    gestisci_timer_attesa_ciclica();
    return;
  }
  azzera_tre_buffer_8_byte();
  gestisci_timer_attesa_ciclica();
  bVar2 = indice_elemento_selezionato;
  buffer_temporaneo_2byte = 9;
  if (unaff_D6b < 4) {
    gestisci_timer_attesa_ciclica();
    contatore_ritardo_cicli = 0;
    uVar3 = (uint)indice_elemento_selezionato;
    cVar1 = indice_elemento_selezionato + 0x48;
    indirizzo_testo_slot2 = cVar1;
    indirizzo_testo_condiviso = cVar1;
    if (flag_slot_2_attivo == '\0') {
      inizializza_schermo_principale_completo();
      attendi_rilascio_pulsante_mouse();
      if (cVar1 == '\0') {
        verifica_e_aggiorna_saldo_soldi();
        decrementa_contatori_129b7();
        (&array_valori_slot)[uVar3] = 0x14;
        return;
      }
      goto l_0a78a;
    }
  }
  else {
    contatore_ritardo_cicli = 0;
    uVar3 = (uint)indice_elemento_selezionato;
    cVar1 = indice_elemento_selezionato + 0x48;
    indirizzo_testo_slot3 = cVar1;
    indirizzo_testo_condiviso = cVar1;
    if (flag_slot_3_attivo == '\0') {
      inizializza_schermo_principale_completo();
      attendi_rilascio_pulsante_mouse();
      if (cVar1 == '\0') {
        verifica_e_aggiorna_saldo_soldi();
        decrementa_contatori_129b7();
        (&array_valori_slot)[bVar2] = 0xf;
        return;
      }
      attiva_stato_audio();
      attendi_input_gioco_con_timeout_59_frame();
      (&array_contatori_4_byte)[bVar2] = 2;
      return;
    }
  }
  contatore_ritardo_cicli = 0;
  attendi_input_gioco_con_timeout_59_frame();
l_0a78a:
  attiva_stato_audio();
  attendi_input_gioco_con_timeout_59_frame();
  (&array_stato_attivo_4_elementi)[uVar3] = 0x80;
  tipo_controllo = tipo_controllo + -1;
  aggiorna_maschera_128ce();
  routine_vuota();
  disegna_elementi_controllo_mascherati();
  renderizza_schermo_completo_con_colori();
  return;
}

