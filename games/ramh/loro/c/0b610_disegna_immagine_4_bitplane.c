/* $0b610 disegna_immagine_4_bitplane: Disegna un'immagine rettangolare dai dati in A0 sui 4 bitplane dello schermo. */

/* Disegna un'immagine rettangolare dai dati in A0 sui 4 bitplane dello schermo. */

void disegna_immagine_4_bitplane(void)

{
  short sVar1;
  short sVar2;
  byte *in_A0;
  byte *pbVar3;
  byte *pbVar4;
  byte *unaff_A3;
  
  larghezza_finestra_caratteri = *in_A0;
  pbVar3 = in_A0 + 2;
  altezza_finestra_caratteri = in_A0[1];
  sVar2 = altezza_finestra_caratteri - 1;
  do {
    sVar1 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      *unaff_A3 = *pbVar3;
      unaff_A3[8000] = pbVar3[1];
      pbVar4 = pbVar3 + 3;
      unaff_A3[16000] = pbVar3[2];
      pbVar3 = pbVar3 + 4;
      unaff_A3[24000] = *pbVar4;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}

