/* $0dc62 copia_schermo_intero_in_buffer: Copia l'intero schermo di 4000 word per bitplane dalla memoria video al buffer. */

/* Copia l'intero schermo di 4000 word per bitplane dalla memoria video al buffer. */

void copia_schermo_intero_in_buffer(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 3999;
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

