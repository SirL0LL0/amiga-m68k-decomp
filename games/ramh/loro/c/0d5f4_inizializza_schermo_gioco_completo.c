/* $0d5f4 inizializza_schermo_gioco_completo: Copia grafica di base, renderizza strati con ritardo, visualizza testo senza sfondo, salva area video e copia grafica parziale */

/* Copia grafica di base, renderizza strati con ritardo, visualizza testo senza sfondo, salva area
   video e copia grafica parziale */

void inizializza_schermo_gioco_completo(void)

{
  copia_grafica_5c70a_su_schermo();
  renderizza_strati_grafici_con_ritardo();
  flag_disabilita_sfondo = 1;
  stato_font_corrente = 0;
  processa_e_visualizza_testo_formattato();
  stato_font_corrente = 1;
  flag_disabilita_sfondo = 0;
  salva_area_memoria_video();
  copia_parziale_grafica_6f8c6();
  return;
}

