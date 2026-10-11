/* $0d816 aggiorna_riquadro_menu_e_grafica: Legge valori tabella, imposta coordinate finestra, pulisce riga e bordi riquadro, visualizza testo, copia grafica condizionale */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Legge valori tabella, imposta coordinate finestra, pulisce riga e bordi riquadro, visualizza
   testo, copia grafica condizionale */

void aggiorna_riquadro_menu_e_grafica(void)

{
  short unaff_D4w;
  short unaff_D5w;
  
  leggi_valore_tabella_4byte();
  _coordinata_y_finestra = unaff_D5w + 1;
  _coordinata_x_finestra = unaff_D4w + -1;
  cancella_resto_riga();
  pulisci_bordi_riquadro();
  processa_e_visualizza_testo_formattato();
  indirizzo_tabella_dati = 0;
  if (flag_stato_mouse_sinistro == '\0') {
    copia_grafica_6f8c6_in_buffer_video();
    copia_grafica_707c6_in_buffer_video();
  }
  flag_stato_mouse_sinistro = 0;
  return;
}

