/* $0bec4 carica_tavolozza_schermo_2: Copia una tavolozza alternativa di 16 colori nella memoria Copper all'indirizzo $304. */

/* Copia una tavolozza alternativa di 16 colori nella memoria Copper all'indirizzo $304. */

void carica_tavolozza_schermo_2(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = 0xf;
  puVar2 = (undefined4 *)&tavolozza_copper_304;
  puVar3 = &tavolozza_predefinita_2;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}

