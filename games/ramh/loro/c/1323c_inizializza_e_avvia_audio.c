/* $1323c inizializza_e_avvia_audio: Inizializza il driver audio, avvia la riproduzione e attende interruzione pattern o pressione tasto fuoco per fermarsi. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Inizializza il driver audio, avvia la riproduzione e attende interruzione pattern o pressione
   tasto fuoco per fermarsi. */

void inizializza_e_avvia_audio(void)

{
  tempo_musica_predefinito = 2;
  tempo_musica_predefinito = 2;
  ptr_stato_audio._0_1_ = 0;
  inizializza_driver_audio();
  stato_riproduzione_audio = 1;
  _vettore_interrupt_salvato = _vettore_interrupt_sistema;
  do {
    if (flag_interruzione_pattern != '\0') {
      _vettore_interrupt_sistema = uRam000132f6;
      _intena_registro = 0xc008;
      disattiva_audio_dma();
      return;
    }
  } while (((flag_blocco_input == '\0') && ((ciaa_pra_joystick & 0x40) != 0)) &&
          ((char)ciaa_pra_joystick < '\0'));
  _vettore_interrupt_sistema = uRam000132f6;
  _intena_registro = 0xc008;
  disattiva_audio_dma();
  return;
}

