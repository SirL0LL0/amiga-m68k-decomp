/* $092f6 inizializza_schermo_e_attendi_fuoco: Inizializza schermo gioco, attende pressione fuoco, renderizza scena iniziale */

/* Inizializza schermo gioco, attende pressione fuoco, renderizza scena iniziale */

void inizializza_schermo_e_attendi_fuoco(void)

{
  inizializza_schermo_principale_completo();
  aggiorna_riquadro_menu_con_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}

