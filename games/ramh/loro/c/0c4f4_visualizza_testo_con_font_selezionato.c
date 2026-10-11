/* $0c4f4 visualizza_testo_con_font_selezionato: Attiva flag selezione font, processa e visualizza testo formattato, poi disattiva il flag */

/* Attiva flag selezione font, processa e visualizza testo formattato, poi disattiva il flag */

void visualizza_testo_con_font_selezionato(void)

{
  flag_selezione_font = 1;
  processa_e_visualizza_testo_formattato();
  flag_selezione_font = 0;
  return;
}

