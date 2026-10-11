/* $0b5d0 indirizzo_schermo: calcola l'indirizzo nello schermo (40 byte/riga, 8000 byte/piano) */

/* calcola l'indirizzo nello schermo (40 byte/riga, 8000 byte/piano) */

ushort indirizzo_schermo(void)

{
  ushort unaff_D4w;
  
  return unaff_D4w & 0xff00;
}

