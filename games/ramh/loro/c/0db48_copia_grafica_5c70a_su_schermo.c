/* $0db48 copia_grafica_5c70a_su_schermo: Copia blocchi di dati grafici da 5c70a nei 4 bitplane della memoria video. */

/* Copia blocchi di dati grafici da 5c70a nei 4 bitplane della memoria video. */

void copia_grafica_5c70a_su_schermo(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  puVar4 = &indirizzo_memoria_video;
  puVar2 = (undefined2 *)&sorgente_grafica_5c70a;
  sVar1 = 0x3bf;
  do {
    *puVar4 = *puVar2;
    puVar4[4000] = puVar2[1];
    puVar3 = puVar2 + 3;
    puVar4[8000] = puVar2[2];
    puVar2 = puVar2 + 4;
    puVar4[12000] = *puVar3;
    puVar4 = puVar4 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

