/* $0ae30 ciclo_principale_rendering_gioco: Ciclo rendering principale: disegna caratteri, simboli, testo formattato, copia schermo in buffer, imposta colori copper, gestisce input fuoco */

/* Ciclo rendering principale: disegna caratteri, simboli, testo formattato, copia schermo in
   buffer, imposta colori copper, gestisce input fuoco */

void ciclo_principale_rendering_gioco(void)

{
  char unaff_D4b;
  char unaff_D6b;
  char *unaff_A3;
  undefined1 uVar1;
  
  do {
    flag_alternanza_render = flag_alternanza_render ^ 3;
    contatore_frame_globale = contatore_frame_globale + '\x01';
    disegna_carattere_grafico(unaff_A3,unaff_D4b,unaff_D6b);
    flag_selezione_font = 1;
    disegna_simbolo_grafico();
    flag_selezione_font = 0;
    processa_e_visualizza_testo_formattato();
    leggi_valore_tabella_4byte();
    if (*unaff_A3 == -2) {
      processa_e_visualizza_testo_formattato(unaff_D6b + '\x05');
      leggi_valore_tabella_4byte();
      uVar1 = pubblico_band;
      pubblico_band = pubblico_band_salvato;
      copia_schermo_intero_in_buffer((&array_inizializzazione_9byte)[flag_primo_accesso_menu]);
      imposta_colori_copper_4();
      gestisci_input_e_carica_rock();
      pubblico_band = uVar1;
    }
    else {
      leggi_valore_tabella_4byte(*unaff_A3,unaff_D6b + '\x05');
      renderizza_messaggio_completo();
    }
    unaff_D6b = unaff_D6b + '\x01';
    unaff_A3 = unaff_A3 + -1;
    unaff_D4b = unaff_D4b + -1;
  } while (unaff_D4b != '\0');
  flag_alternanza_render = 0;
  return;
}

