/* $08ecc inizializza_schermo_attendi_mouse: Inizializza schermo gioco completo e attende rilascio pulsante mouse impostando flag */

/* Inizializza schermo gioco completo e attende rilascio pulsante mouse impostando flag */

void inizializza_schermo_attendi_mouse(void)

{
  char unaff_D6b;
  
  inizializza_schermo_principale_completo();
  attendi_rilascio_pulsante_mouse();
  if (unaff_D6b == '\0') {
    flag_rilascio_mouse = 1;
  }
  return;
}

