/* $0a248 processa_stato_slot_audio: Smista eventi audio in base a flag slot, soldi BCD e stato gioco: timer ciclico, menu ritorno o evento audio flag2 */

/* WARNING: Removing unreachable block (ram,0x0000a288) */
/* WARNING: Removing unreachable block (ram,0x0000a296) */
/* Smista eventi audio in base a flag slot, soldi BCD e stato gioco: timer ciclico, menu ritorno o
   evento audio flag2 */

void processa_stato_slot_audio(void)

{
  if ((flag_slot_attivi != '\0') && ((buffer_bcd_soldi != '\0' || (flag_modalita_speciale != '\0')))
     ) {
    if ((flag_stato_gioco & 1) == 0) {
      gestisci_timer_attesa_ciclica();
    }
    if (((flag_stato_gioco & 2) != 0) ||
       (gestisci_timer_attesa_ciclica(), flag_slot_3_attivo == '\0')) {
      if ((flag_stato_gioco & 4) == 0) {
        gestisci_stato_audio_menu_ritorno();
      }
      return;
    }
    gestisci_evento_audio_flag2();
  }
  return;
}

