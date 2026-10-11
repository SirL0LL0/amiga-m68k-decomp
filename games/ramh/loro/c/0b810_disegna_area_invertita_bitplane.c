/* $0b810 disegna_area_invertita_bitplane: Disegna area rettangolare invertendo i pixel sui 4 bitplane dello schermo */

/* Disegna area rettangolare invertendo i pixel sui 4 bitplane dello schermo */

void disegna_area_invertita_bitplane(void)

{
  byte *pbVar1;
  byte bVar2;
  uint unaff_D4;
  byte *unaff_D5;
  int unaff_D6;
  int iVar3;
  byte *unaff_A3;
  char cVar4;
  
  cVar4 = larghezza_finestra_caratteri;
  iVar3 = unaff_D6;
  do {
    do {
      calcola_indirizzo_video(unaff_D6,cVar4,unaff_D4);
      pbVar1 = unaff_D5 + 1;
      bVar2 = *unaff_D5 ^ 0xff;
      *unaff_A3 = bVar2 & *unaff_A3;
      unaff_A3[8000] = bVar2 & unaff_A3[8000];
      unaff_A3[16000] = bVar2 & unaff_A3[16000];
      unaff_A3 = unaff_A3 + 24000;
      *unaff_A3 = bVar2 & *unaff_A3;
      cVar4 = cVar4 + -1;
      unaff_D5 = pbVar1;
    } while (cVar4 != '\0');
    unaff_D6 = iVar3 + 1;
    if ((char)unaff_D6 == '\b') {
      unaff_D6 = 0;
      unaff_D4 = (uint)(ushort)((short)unaff_D4 + 0x100);
    }
    altezza_finestra_caratteri = altezza_finestra_caratteri + -1;
    cVar4 = larghezza_finestra_caratteri;
    iVar3 = unaff_D6;
  } while (altezza_finestra_caratteri != '\0');
  return;
}

