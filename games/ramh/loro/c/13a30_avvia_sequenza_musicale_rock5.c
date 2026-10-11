/* $13a30 avvia_sequenza_musicale_rock5: Su input joystick+fuoco, prepara e avvia brano 'rock5' copiando e trasponendo dati audio su canali. */

/* Su input joystick+fuoco, prepara e avvia brano 'rock5' copiando e trasponendo dati audio su
   canali. */

void avvia_sequenza_musicale_rock5(void)

{
  int iVar1;
  char unaff_D4b;
  byte unaff_D6b;
  undefined4 extraout_A0;
  int extraout_A0_00;
  undefined4 extraout_A1;
  undefined *puVar2;
  
  if ((((ciaa_pra_joystick & 0x40) != 0) && ((char)ciaa_pra_joystick < '\0')) &&
     (flag_blocco_input == '\0')) {
    puVar2 = &tabella_stati_joystick;
    for (; unaff_D4b != '\0'; unaff_D4b = unaff_D4b + -1) {
      puVar2 = puVar2 + 4;
    }
    if (flag_seleziona_buffer_dati != '\0') {
      unaff_D6b = registro_canale_audio;
    }
    parametro_canale_input = unaff_D6b & 7;
    stato_joystick_y = puVar2[2];
    stato_joystick_x = *puVar2;
    direzione_input_sinistra = puVar2[1];
    direzione_input_destra = puVar2[3];
    posizione_cursore_x = 0xff;
    flag_interruzione_pattern = 0;
    uRam000133d1 = 6;
    struttura_dati_musica = "rock5";
    pausa_cicli_d4();
    gestisci_timer_attesa_ciclica(extraout_A0,extraout_A1,puVar2);
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
  iVar1 = 0x10;
  do {
    pausa_breve();
    iVar1 = iVar1 + -1;
  } while ((char)iVar1 != '\0');
  return;
}

