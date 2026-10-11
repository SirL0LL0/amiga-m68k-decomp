/* $092f6 inizializza_schermo_attesa_fuoco: Inizializza schermo gioco, attende pressione fuoco e renderizza scena iniziale */

/* Inizializza schermo gioco, attende pressione fuoco e renderizza scena iniziale */

void inizializza_schermo_attesa_fuoco(void)

{
  inizializza_schermo_gioco_completo();
  aggiorna_riquadro_menu_e_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  aggiorna_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}

