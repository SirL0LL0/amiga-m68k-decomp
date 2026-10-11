/* $08d28 gestisci_menu_principale_soldi: Azzera buffer, calcola somme BCD per tipo controllo, inizializza schermo, attende scelta menu e verifica saldo soldi */

/* WARNING: Removing unreachable block (ram,0x00008dd8) */
/* WARNING: Removing unreachable block (ram,0x00008dce) */
/* Azzera buffer, calcola somme BCD per tipo controllo, inizializza schermo, attende scelta menu e
   verifica saldo soldi */

void gestisci_menu_principale_soldi(void)

{
  azzera_tre_buffer_8_byte();
  esegui_tre_somme_bcd();
  if (((tipo_controllo != '\x01') && (esegui_tre_somme_bcd(), tipo_controllo != '\x02')) &&
     (esegui_tre_somme_bcd(), tipo_controllo != '\x03')) {
    esegui_tre_somme_bcd();
  }
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  stato_schermata_corrente = 3;
  verifica_e_aggiorna_saldo_soldi();
  return;
}

