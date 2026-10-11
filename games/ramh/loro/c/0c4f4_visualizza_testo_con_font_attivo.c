/* $0c4f4 visualizza_testo_con_font_attivo: Attiva flag selezione font, processa e visualizza testo formattato con codici controllo, poi disattiva flag */

/* Attiva flag selezione font, processa e visualizza testo formattato con codici controllo, poi
   disattiva flag */

void visualizza_testo_con_font_attivo(void)

{
  flag_selezione_font = 1;
  processa_e_visualizza_testo_formattato();
  flag_selezione_font = 0;
  return;
}

