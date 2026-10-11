/* $138a4 esegui_sequenza_audio_attendi_fuoco: Avvia sequenza audio 'hamster', sincronizza col pennello video e attende pressione fuoco joystick */

/* Avvia sequenza audio 'hamster', sincronizza col pennello video e attende pressione fuoco joystick
    */

void esegui_sequenza_audio_attendi_fuoco(void)

{
  registro_audio_iniziale = 0xd;
  flag_interruzione_pattern = 0;
  uRam000133d1 = 6;
  struttura_dati_musica = "hamster";
  esegui_sequenza_audio_visualizzata();
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  return;
}

