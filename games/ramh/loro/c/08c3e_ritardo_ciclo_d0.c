/* $08c3e ritardo_ciclo_d0: Esegue un ciclo di attesa vuoto decrementando il registro D0. */

/* Esegue un ciclo di attesa vuoto decrementando il registro D0. */

void ritardo_ciclo_d0(void)

{
  short in_D0w;
  
  do {
    in_D0w = in_D0w + -1;
  } while (in_D0w != -1);
  return;
}

