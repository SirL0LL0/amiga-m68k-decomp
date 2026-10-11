/* $0a248 gestisci_eventi_audio_slot_band: Gestisce eventi audio per slot musicisti: verifica slot attivi, soldi BCD e flag stato per attivare timer, menu ritorno o sequenza audio flag2 */

/* WARNING: Removing unreachable block (ram,0x0000a288) */
/* WARNING: Removing unreachable block (ram,0x0000a296) */
/* Gestisce eventi audio per slot musicisti: verifica slot attivi, soldi BCD e flag stato per
   attivare timer, menu ritorno o sequenza audio flag2 */

void gestisci_eventi_audio_slot_band(void)

{
  if ((flag_slot_attivi != '\0') && ((buffer_bcd_soldi != '\0' || (soldi_cifra_milioni != '\0')))) {
    if ((flag_stato_gioco & 1) == 0) {
      gestisci_timer_attesa_ciclica();
    }
    if (((flag_stato_gioco & 2) != 0) ||
       (gestisci_timer_attesa_ciclica(), flag_slot_3_attivo == '\0')) {
      if ((flag_stato_gioco & 4) == 0) {
        gestisci_ritorno_menu_audio();
      }
      return;
    }
    gestisci_evento_audio_flag_2();
  }
  return;
}

