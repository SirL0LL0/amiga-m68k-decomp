/* $0bf52 imposta_colori_copper_4: Copia 16 valori di colore dalla sorgente bf6c nei registri colore della Copper list. */

/* Copia 16 valori di colore dalla sorgente bf6c nei registri colore della Copper list. */

void imposta_colori_copper_4(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar3 = &tavolozza_bf6c;
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

