/* $0db70 copia_grafica_6f8c6_in_buffer_video: Copia 1920 word di dati grafici da 6f8c6 nel buffer video con offset 0x780. */

/* Copia 1920 word di dati grafici da 6f8c6 nel buffer video con offset 0x780. */

void copia_grafica_6f8c6_in_buffer_video(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = (undefined2 *)&sorgente_grafica_6f8c6;
  puVar3 = (undefined2 *)(parametro_dimensione_bf68 + 0x780);
  sVar1 = 0x77f;
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

