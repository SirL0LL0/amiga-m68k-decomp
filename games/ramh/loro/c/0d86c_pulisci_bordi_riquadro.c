/* $0d86c pulisci_bordi_riquadro: Pulisce i bordi esterni e i margini di un riquadro nei 4 bitplanes della memoria video. */

/* Pulisce i bordi esterni e i margini di un riquadro nei 4 bitplanes della memoria video. */

void pulisci_bordi_riquadro(void)

{
  short sVar1;
  uint unaff_D4;
  uint uVar2;
  ushort uVar3;
  ushort unaff_D5w;
  char cVar4;
  byte *unaff_A3;
  byte *pbVar5;
  
  uVar2 = unaff_D4;
  do {
    maschera_byte_superiore_d4();
    sVar1 = 7;
    do {
      *unaff_A3 = *unaff_A3 & 0x7f;
      unaff_A3[8000] = unaff_A3[8000] & 0x7f;
      unaff_A3[16000] = unaff_A3[16000] & 0x7f;
      unaff_A3[24000] = unaff_A3[24000] & 0x7f;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    uVar3 = (short)uVar2 + 0x100;
    uVar2 = (uint)uVar3;
  } while ((uVar3 & 0xff00) != (unaff_D5w & 0xff00));
  cVar4 = (char)unaff_D5w;
  uVar3 = (short)CONCAT31((int3)(unaff_D4 >> 8),cVar4) - 1;
  do {
    maschera_byte_superiore_d4();
    sVar1 = 7;
    do {
      pbVar5 = unaff_A3;
      *pbVar5 = *pbVar5 & 0xfe;
      pbVar5[8000] = pbVar5[8000] & 0xfe;
      pbVar5[16000] = pbVar5[16000] & 0xfe;
      pbVar5[24000] = pbVar5[24000] & 0xfe;
      unaff_A3 = pbVar5 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    uVar3 = uVar3 + 0x100;
  } while ((uVar3 & 0xff00) != (unaff_D5w & 0xff00));
  maschera_byte_superiore_d4();
  uVar2 = unaff_D4;
  do {
    *unaff_A3 = 0;
    pbVar5[0x1f68] = 0;
    pbVar5[0x3ea8] = 0;
    pbVar5[0x5de8] = 0;
    uVar3 = (short)uVar2 + 1;
    uVar2 = (uint)uVar3;
    maschera_byte_superiore_d4();
  } while (cVar4 != (char)uVar3);
  sVar1 = ((ushort)unaff_D4 & 0xff) - 0x100;
  indirizzo_schermo();
  do {
    *unaff_A3 = 0;
    pbVar5[0x1f68] = 0;
    pbVar5[0x3ea8] = 0;
    pbVar5[0x5de8] = 0;
    sVar1 = sVar1 + 1;
    indirizzo_schermo();
  } while (cVar4 != (char)sVar1);
  return;
}

