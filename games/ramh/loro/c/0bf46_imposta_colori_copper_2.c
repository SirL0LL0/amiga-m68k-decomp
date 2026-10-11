/* $0bf46 imposta_colori_copper_2: Copia 16 valori di colore dalla sorgente bfac nei registri colore della Copper list. */

/* Copia 16 valori di colore dalla sorgente bfac nei registri colore della Copper list. */

void imposta_colori_copper_2(void)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  
  puVar3 = &tavolozza_bfac;
  sVar1 = 0xf;
  puVar4 = &registri_colore_copper;
  do {
    puVar2 = puVar3 + 1;
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 2;
    puVar4[1] = *puVar2;
    puVar4 = puVar4 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

