/* $0b67e disegna_bitmap_mascherata: Disegna una bitmap con maschera di trasparenza su quattro bitplane dello schermo. */

/* Disegna una bitmap con maschera di trasparenza su quattro bitplane dello schermo. */

void disegna_bitmap_mascherata(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte *in_A0;
  byte *pbVar4;
  byte *pbVar5;
  byte *unaff_A3;
  
  larghezza_finestra_caratteri = *in_A0;
  pbVar4 = in_A0 + 2;
  altezza_finestra_caratteri = in_A0[1];
  sVar3 = altezza_finestra_caratteri - 1;
  do {
    sVar2 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      pbVar5 = pbVar4 + 3;
      bVar1 = *pbVar5 & pbVar4[2] & pbVar4[1] & *pbVar4;
      *unaff_A3 = bVar1 & *unaff_A3;
      unaff_A3[8000] = bVar1 & unaff_A3[8000];
      unaff_A3[16000] = bVar1 & unaff_A3[16000];
      unaff_A3[24000] = bVar1 & unaff_A3[24000];
      bVar1 = bVar1 ^ 0xff;
      *unaff_A3 = bVar1 & *pbVar4 | *unaff_A3;
      unaff_A3[8000] = bVar1 & pbVar4[1] | unaff_A3[8000];
      unaff_A3[16000] = bVar1 & pbVar4[2] | unaff_A3[16000];
      pbVar4 = pbVar4 + 4;
      unaff_A3[24000] = bVar1 & *pbVar5 | unaff_A3[24000];
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return;
}

