/* $0c154 cancella_indicatori_schermo: Azzera bit specifici nei 4 bitplanes della memoria video per cancellare elementi o indicatori grafici. */

/* Azzera bit specifici nei 4 bitplanes della memoria video per cancellare elementi o indicatori
   grafici. */

void cancella_indicatori_schermo(void)

{
  byte bVar1;
  int iVar2;
  undefined3 uVar3;
  short sVar5;
  uint uVar4;
  char cVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  pbVar7 = &array_indicatori_grafici;
  iVar2 = 0x1721;
  valore_minimo_trovato = 0x80;
  cVar6 = '4';
  do {
    if (*pbVar7 == 0) {
      return;
    }
    uVar4 = CONCAT31((uint3)*pbVar7,3);
    pbVar8 = pbVar7;
    do {
      indirizzo_schermo(pbVar8,iVar2);
      bVar1 = valore_minimo_trovato ^ 0xff;
      *pbVar7 = bVar1 & *pbVar7;
      pbVar7[8000] = bVar1 & pbVar7[8000];
      pbVar7[16000] = bVar1 & pbVar7[16000];
      pbVar7[24000] = bVar1 & pbVar7[24000];
      uVar3 = (undefined3)(uVar4 >> 8);
      if ((char)uVar4 == '\0') {
        sVar5 = (short)CONCAT31(uVar3,7);
      }
      else {
        sVar5 = (short)CONCAT31(uVar3,(char)uVar4 + -1);
      }
      uVar4 = (uint)(ushort)(sVar5 - 0x100U);
    } while ((sVar5 - 0x100U & 0xff00) != 0);
    pbVar7 = pbVar8 + 1;
    valore_minimo_trovato = valore_minimo_trovato << 7 | valore_minimo_trovato >> 1;
    if (valore_minimo_trovato == 0x80) {
      valore_minimo_trovato = 0x80;
      iVar2 = iVar2 + 1;
    }
    cVar6 = cVar6 + -1;
  } while (cVar6 != '\0');
  return;
}

