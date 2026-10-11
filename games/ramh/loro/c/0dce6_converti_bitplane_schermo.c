/* $0dce6 converti_bitplane_schermo: Copia e separa i 4 bitplane dalla memoria video al buffer grafico per 200 righe. */

/* Copia e separa i 4 bitplane dalla memoria video al buffer grafico per 200 righe. */

void converti_bitplane_schermo(void)

{
  short sVar1;
  short sVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  
  puVar4 = &indirizzo_memoria_video;
  sVar1 = 199;
  puVar3 = parametro_dimensione_bf68;
  do {
    sVar2 = 0x13;
    puVar6 = puVar4 + 0x14;
    puVar7 = puVar4 + 0x28;
    puVar8 = puVar4 + 0x3c;
    do {
      puVar5 = puVar4;
      *puVar3 = *puVar5;
      puVar3[4000] = *puVar6;
      puVar3[8000] = *puVar7;
      puVar3[12000] = *puVar8;
      puVar3 = puVar3 + 1;
      sVar2 = sVar2 + -1;
      puVar4 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    } while (sVar2 != -1);
    puVar4 = puVar5 + 0x3d;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

