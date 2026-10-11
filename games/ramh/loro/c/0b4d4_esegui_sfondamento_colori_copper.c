/* $0b4d4 esegui_sfondamento_colori_copper: Riduce progressivamente la luminosita' dei 16 registri colore Copper su 15 mezzi frame per effetto fade. */

/* Riduce progressivamente la luminosita' dei 16 registri colore Copper su 15 mezzi frame per
   effetto fade. */

void esegui_sfondamento_colori_copper(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  
  pbVar5 = &registri_colore_copper;
  sVar1 = 0xf;
  pbVar8 = &buffer_registri_copper;
  do {
    pbVar7 = pbVar8 + 1;
    *pbVar8 = *pbVar5;
    pbVar8 = pbVar8 + 2;
    *pbVar7 = pbVar5[1];
    pbVar5 = pbVar5 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = 0xe;
  do {
    sVar4 = 0x1f;
    pbVar5 = &buffer_registri_copper;
    do {
      bVar3 = *pbVar5 & 0x70;
      if (bVar3 != 0) {
        bVar3 = bVar3 - 0x10;
      }
      bVar2 = *pbVar5 & 7;
      if (bVar2 != 0) {
        bVar2 = bVar2 - 1;
      }
      *pbVar5 = bVar3 | bVar2;
      sVar4 = sVar4 + -1;
      pbVar5 = pbVar5 + 1;
    } while (sVar4 != -1);
    puVar10 = &buffer_registri_copper;
    puVar6 = &registri_colore_copper;
    sVar4 = 0xf;
    do {
      puVar9 = puVar10 + 1;
      *puVar6 = *puVar10;
      puVar10 = puVar10 + 2;
      puVar6[1] = *puVar9;
      puVar6 = puVar6 + 4;
      sVar4 = sVar4 + -1;
    } while (sVar4 != -1);
    attendi_mezzoframe();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

