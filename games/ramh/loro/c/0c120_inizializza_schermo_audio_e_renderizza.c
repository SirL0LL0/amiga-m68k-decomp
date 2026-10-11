/* $0c120 inizializza_schermo_audio_e_renderizza: Inizializza schermo, avvia due sequenze audio buffer ausiliario, attiva flag, renderizza scena e copia grafica */

/* Inizializza schermo, avvia due sequenze audio buffer ausiliario, attiva flag, renderizza scena e
   copia grafica */

void inizializza_schermo_audio_e_renderizza(void)

{
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_buffer_ausiliario();
  avvia_sequenza_audio_buffer_ausiliario();
  attiva_flag_128b1();
  renderizza_scena_condizionale();
  copia_grafica_6f8c6_in_buffer_video();
  return;
}

