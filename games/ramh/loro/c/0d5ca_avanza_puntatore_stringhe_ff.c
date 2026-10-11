/* $0d5ca avanza_puntatore_stringhe_ff: Avanza il puntatore di memoria saltando un numero di stringhe terminate da 0xFF. */

/* Avanza il puntatore di memoria saltando un numero di stringhe terminate da 0xFF. */

void avanza_puntatore_stringhe_ff(void)

{
  char cVar1;
  short unaff_D4w;
  char *unaff_A3;
  char *pcVar2;
  
  for (; pcVar2 = unaff_A3, unaff_D4w != 0; unaff_D4w = unaff_D4w + -1) {
    do {
      unaff_A3 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = unaff_A3;
    } while (cVar1 != -1);
  }
  return;
}

