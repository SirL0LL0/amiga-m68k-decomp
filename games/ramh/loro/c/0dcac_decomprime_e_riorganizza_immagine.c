/* $0dcac decomprime_e_riorganizza_immagine: Decomprime i dati RLE in memoria video e organizza i 4 bitplane nel buffer di destinazione. */

/* Decomprime i dati RLE in memoria video e organizza i 4 bitplane nel buffer di destinazione. */

void decomprime_e_riorganizza_immagine(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  char *in_A0;
  char *pcVar4;
  char *pcVar5;
  undefined2 *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  
  pcVar7 = (char *)&indirizzo_memoria_video;
  do {
    pcVar4 = in_A0 + 1;
    sVar2 = (short)*in_A0;
    pcVar8 = pcVar7;
    if (sVar2 < 0) {
      pcVar5 = pcVar4;
      if (*in_A0 != -0x80) {
        sVar2 = -sVar2;
        pcVar5 = in_A0 + 2;
        cVar1 = *pcVar4;
        pcVar4 = pcVar7;
        do {
          pcVar7 = pcVar4 + 1;
          *pcVar4 = cVar1;
          sVar2 = sVar2 + -1;
          pcVar4 = pcVar7;
        } while (sVar2 != -1);
      }
    }
    else {
      do {
        pcVar5 = pcVar4 + 1;
        pcVar7 = pcVar8 + 1;
        *pcVar8 = *pcVar4;
        sVar2 = sVar2 + -1;
        pcVar4 = pcVar5;
        pcVar8 = pcVar7;
      } while (sVar2 != -1);
    }
    in_A0 = pcVar5;
  } while ((int)pcVar7 < 0x76e47);
  puVar9 = &indirizzo_memoria_video;
  sVar2 = 199;
  puVar6 = parametro_dimensione_bf68;
  do {
    sVar3 = 0x13;
    puVar11 = puVar9 + 0x14;
    puVar12 = puVar9 + 0x28;
    puVar13 = puVar9 + 0x3c;
    do {
      puVar10 = puVar9;
      *puVar6 = *puVar10;
      puVar6[4000] = *puVar11;
      puVar6[8000] = *puVar12;
      puVar6[12000] = *puVar13;
      puVar6 = puVar6 + 1;
      sVar3 = sVar3 + -1;
      puVar9 = puVar10 + 1;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    } while (sVar3 != -1);
    puVar9 = puVar10 + 0x3d;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}

