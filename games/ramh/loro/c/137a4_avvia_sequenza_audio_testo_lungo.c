/* $137a4 avvia_sequenza_audio_testo_lungo: Avvia audio con testo lungo, copia 1024 byte e attende pressione fuoco */

/* Avvia audio con testo lungo, copia 1024 byte e attende pressione fuoco */

void avvia_sequenza_audio_testo_lungo(void)

{
  char cVar1;
  char unaff_D6b;
  
  flag_interruzione_pattern = 0;
  uRam000133d1 = 6;
  struttura_dati_musica = "rock5";
  azzera_buffer_testo();
  cVar1 = (&DAT_00013c64)[(byte)(unaff_D6b << 1)];
  if ((&DAT_00013c65)[(byte)(unaff_D6b << 1)] == '\0') {
    for (; cVar1 != '\0'; cVar1 = cVar1 + -1) {
    }
    copia_stringa_1024_byte();
    inizializza_e_avvia_audio();
    do {
      do {
        attendi_passaggio_pennello();
      } while ((ciaa_pra_joystick & 0x40) == 0);
    } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
    return;
  }
  for (; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  copia_stringa_512_byte();
  inizializza_e_avvia_audio();
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  return;
}

