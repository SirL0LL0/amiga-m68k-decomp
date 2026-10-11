/* $08466 inizializza_gioco_principale: Inizializza lo schermo, audio e attende input giocatore in sequenza per avviare la partita */

/* Inizializza lo schermo, audio e attende input giocatore in sequenza per avviare la partita */

void inizializza_gioco_principale(void)

{
  int iVar1;
  
  flag_stato_audio = 1;
  renderizza_schermo_completo_con_colori();
  iVar1 = 0;
  aggiorna_riquadro_menu_e_grafica(0);
  salva_area_memoria_video();
  pausa_messaggio();
  routine_vuota();
  attiva_stato_audio();
  iVar1 = iVar1 + 1;
  attendi_input_gioco_con_timeout(iVar1);
  iVar1 = iVar1 + 1;
  attendi_input_gioco_con_timeout(iVar1);
  resetta_stato_audio();
  attendi_input_gioco_con_timeout(iVar1 + 1);
  attiva_stato_audio();
  attendi_input_gioco_con_timeout();
  resetta_stato_audio();
  return;
}

