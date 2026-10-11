/* $138f2 avvia_sequenza_audio_buffer_ausiliario: Avvia audio con buffer ausiliario, copia testo e attende pressione fuoco */

/* Avvia audio con buffer ausiliario, copia testo e attende pressione fuoco */

void avvia_sequenza_audio_buffer_ausiliario(void)

{
  char cVar1;
  char unaff_D6b;
  
  flag_interruzione_pattern = 0;
  uRam000133d1 = 6;
  struttura_dati_musica = &DAT_0002a8ec;
  azzera_buffer_2ab44();
  cVar1 = (&DAT_00013c74)[(byte)(unaff_D6b << 1)];
  if ((&DAT_00013c75)[(byte)(unaff_D6b << 1)] == '\0') {
    for (; cVar1 != '\0'; cVar1 = cVar1 + -1) {
    }
    copia_1024_byte_in_buffer_ausiliario();
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
  copia_512_byte_in_buffer_ausiliario();
  inizializza_e_avvia_audio();
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  return;
}

