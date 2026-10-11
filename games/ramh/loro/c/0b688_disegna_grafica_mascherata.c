/* $0b688 disegna_grafica_mascherata: Disegna un'immagine grafica mascherata sui 4 bitplanes per sovrapporre elementi visivi allo sfondo. */

/* Disegna un'immagine grafica mascherata sui 4 bitplanes per sovrapporre elementi visivi allo
   sfondo. */

void disegna_grafica_mascherata(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte *in_A0;
  byte *pbVar4;
  byte *unaff_A3;
  
  sVar3 = altezza_finestra_caratteri - 1;
  do {
    sVar2 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      pbVar4 = in_A0 + 3;
      bVar1 = *pbVar4 & in_A0[2] & in_A0[1] & *in_A0;
      *unaff_A3 = bVar1 & *unaff_A3;
      unaff_A3[8000] = bVar1 & unaff_A3[8000];
      unaff_A3[16000] = bVar1 & unaff_A3[16000];
      unaff_A3[24000] = bVar1 & unaff_A3[24000];
      bVar1 = bVar1 ^ 0xff;
      *unaff_A3 = bVar1 & *in_A0 | *unaff_A3;
      unaff_A3[8000] = bVar1 & in_A0[1] | unaff_A3[8000];
      unaff_A3[16000] = bVar1 & in_A0[2] | unaff_A3[16000];
      in_A0 = in_A0 + 4;
      unaff_A3[24000] = bVar1 & *pbVar4 | unaff_A3[24000];
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return;
}

