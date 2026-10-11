/* $0d5de avanza_puntatore_stringhe_bit7: Avanza il puntatore di memoria saltando stringhe terminate da un carattere con bit 7 attivo. */

/* Avanza il puntatore di memoria saltando stringhe terminate da un carattere con bit 7 attivo. */

void avanza_puntatore_stringhe_bit7(void)

{
  byte bVar1;
  short unaff_D4w;
  byte *unaff_A3;
  byte *pbVar2;
  
  for (; pbVar2 = unaff_A3, unaff_D4w != 0; unaff_D4w = unaff_D4w + -1) {
    do {
      unaff_A3 = pbVar2 + 1;
      bVar1 = *pbVar2;
      pbVar2 = unaff_A3;
    } while ((bVar1 & 0x80) == 0);
  }
  return;
}

