/* $08466 inizializza_gioco_e_attendi_input: Inizializza schermo, audio e attende input fuoco giocatore in sequenza per avviare la partita */

/* Inizializza schermo, audio e attende input fuoco giocatore in sequenza per avviare la partita */

void inizializza_gioco_e_attendi_input(void)

{
  int iVar1;
  
  flag_stato_audio = 1;
  renderizza_schermo_completo_con_colori();
  iVar1 = 0;
  aggiorna_riquadro_menu_con_grafica(0);
  salva_area_memoria_video();
  pausa_messaggio();
  routine_vuota();
  attiva_stato_audio();
  iVar1 = iVar1 + 1;
  attendi_input_gioco_con_timeout_59_frame(iVar1);
  iVar1 = iVar1 + 1;
  attendi_input_gioco_con_timeout_59_frame(iVar1);
  resetta_stato_audio();
  attendi_input_gioco_con_timeout_59_frame(iVar1 + 1);
  attiva_stato_audio();
  attendi_input_gioco_con_timeout_59_frame();
  resetta_stato_audio();
  return;
}

