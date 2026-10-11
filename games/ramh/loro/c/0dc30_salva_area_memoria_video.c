/* $0dc30 salva_area_memoria_video: Copia 960 word dai 4 bitplane della memoria video al buffer di destinazione. */

/* Copia 960 word dai 4 bitplane della memoria video al buffer di destinazione. */

void salva_area_memoria_video(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 0x3bf;
  puVar3 = parametro_dimensione_bf68;
  do {
    *puVar3 = *puVar2;
    puVar3[4000] = puVar2[4000];
    puVar3[8000] = puVar2[8000];
    puVar3[12000] = puVar2[12000];
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

