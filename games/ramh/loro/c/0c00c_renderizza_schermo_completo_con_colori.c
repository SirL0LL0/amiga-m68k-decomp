/* $0c00c renderizza_schermo_completo_con_colori: Renderizza schermo completo: copia grafica, scena, interfaccia, buffer, colori copper */

/* Renderizza schermo completo: copia grafica, scena, interfaccia, buffer, colori copper */

void renderizza_schermo_completo_con_colori(void)

{
  copia_grafica_5c70a_su_schermo();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  return;
}

