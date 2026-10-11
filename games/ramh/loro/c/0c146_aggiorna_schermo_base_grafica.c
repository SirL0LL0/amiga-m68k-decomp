/* $0c146 aggiorna_schermo_base_grafica: Disabilita flag stato, renderizza scena condizionale con ritardo e copia grafica di base (0x6f8c6) nel buffer video */

/* Disabilita flag stato, renderizza scena condizionale con ritardo e copia grafica di base
   (0x6f8c6) nel buffer video */

void aggiorna_schermo_base_grafica(void)

{
  disattiva_flag_128b1();
  renderizza_scena_condizionale();
  copia_grafica_6f8c6_in_buffer_video();
  return;
}

