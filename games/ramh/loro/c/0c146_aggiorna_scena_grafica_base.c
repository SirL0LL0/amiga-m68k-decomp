/* $0c146 aggiorna_scena_grafica_base: Disabilita flag, renderizza scena condizionale e copia grafica di base nel buffer video */

/* Disabilita flag, renderizza scena condizionale e copia grafica di base nel buffer video */

void aggiorna_scena_grafica_base(void)

{
  disattiva_flag_128b1();
  renderizza_scena_condizionale();
  copia_grafica_6f8c6_in_buffer_video();
  return;
}

