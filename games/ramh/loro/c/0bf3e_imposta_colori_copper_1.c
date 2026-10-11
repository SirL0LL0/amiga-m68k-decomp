/* $0bf3e imposta_colori_copper_1: Copia 16 valori di colore dalla sorgente bfcc nei registri colore della Copper list. */

/* Copia 16 valori di colore dalla sorgente bfcc nei registri colore della Copper list. */

void imposta_colori_copper_1(void)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  
  puVar2 = &tavolozza_bfcc;
  sVar1 = 0xf;
  puVar4 = &registri_colore_copper;
  do {
    puVar3 = puVar2 + 1;
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 2;
    puVar4[1] = *puVar3;
    puVar4 = puVar4 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

