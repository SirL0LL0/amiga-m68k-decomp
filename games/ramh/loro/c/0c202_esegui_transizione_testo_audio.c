/* $0c202 esegui_transizione_testo_audio: Gestisce transizioni schermo con fade, renderizza bitmap/testo, sincronizza timer e audio */

/* WARNING: Removing unreachable block (ram,0x0000c292) */
/* WARNING: Removing unreachable block (ram,0x0000c298) */
/* WARNING: Removing unreachable block (ram,0x0000c2a6) */
/* WARNING: Removing unreachable block (ram,0x0000c2b4) */
/* WARNING: Removing unreachable block (ram,0x0000c2bc) */
/* WARNING: Removing unreachable block (ram,0x0000c2fa) */
/* WARNING: Removing unreachable block (ram,0x0000c2cc) */
/* WARNING: Removing unreachable block (ram,0x0000c2fe) */
/* Gestisce transizioni schermo con fade, renderizza bitmap/testo, sincronizza timer e audio */

void esegui_transizione_testo_audio(void)

{
  char cVar1;
  
  attendi_input_gioco_con_timeout_59_frame();
  esegue_transizione_schermo_testo_bitmap();
  gestisci_timer_attesa_ciclica();
  cVar1 = stato_transizione_schermo;
  do {
    gestisci_timer_attesa_ciclica();
  } while (cVar1 == -0x79);
  stato_transizione_schermo = 0x87;
  renderizza_bitmap_testo_e_copia_schermo();
  flag_disabilita_sfondo = 0;
  stato_font_corrente = 1;
  avvia_sequenza_audio_testo_lungo();
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  resetta_stato_audio();
  aggiorna_stato_ciclo_gioco_principale();
  return;
}

