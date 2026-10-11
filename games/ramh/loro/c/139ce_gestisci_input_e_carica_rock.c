/* $139ce gestisci_input_e_carica_rock: Verifica la pressione del pulsante di fuoco e avvia il caricamento della risorsa rock5. */

/* Verifica la pressione del pulsante di fuoco e avvia il caricamento della risorsa rock5. */

void gestisci_input_e_carica_rock(void)

{
  char cVar1;
  byte unaff_D6b;
  undefined4 extraout_A0;
  int extraout_A0_00;
  undefined4 extraout_A1;
  
  if ((((ciaa_pra_joystick & 0x40) != 0) && ((char)ciaa_pra_joystick < '\0')) &&
     (flag_blocco_input == '\0')) {
    parametro_canale_input = unaff_D6b & 7;
    stato_joystick_y = tasto_su;
    stato_joystick_x = tasto_giu;
    if (unaff_D6b < 8) {
      direzione_input_sinistra = tasto_sinistra;
      direzione_input_destra = tasto_destra;
    }
    else {
      direzione_input_sinistra = tasto_destra;
      direzione_input_destra = tasto_sinistra;
    }
    posizione_cursore_x = pubblico_band;
    flag_interruzione_pattern = 0;
    uRam000133d1 = 6;
    struttura_dati_musica = "rock5";
    pausa_cicli_d4();
    gestisci_timer_attesa_ciclica(extraout_A0,extraout_A1);
    pausa_cicli_d6();
    copia_blocco_dati_512();
    pausa_cicli_d4();
    pausa_cicli_d6();
    copia_blocco_dati_512();
    pausa_cicli_d4();
    pausa_cicli_d6();
    if (*(byte *)(extraout_A0_00 + 5) < 0xaa) {
      trasponi_e_copia_dati_traccia();
    }
    else {
      copia_blocco_dati_512();
    }
    pausa_cicli_d4();
    pausa_cicli_d6();
    copia_blocco_dati_512();
    inizializza_e_avvia_audio();
    return;
  }
  cVar1 = '\x10';
  do {
    pausa_breve();
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

