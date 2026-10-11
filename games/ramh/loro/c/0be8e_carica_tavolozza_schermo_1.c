/* $0be8e carica_tavolozza_schermo_1: Configura i registri e copia una tavolozza di 16 colori nella memoria Copper a $300. */

/* Configura i registri e copia una tavolozza di 16 colori nella memoria Copper a $300. */

void carica_tavolozza_schermo_1(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  buffer_copper_300 = coordinata_x_schermo_d081 + ':';
  buffer_copper_302 = coordinata_x_schermo_d081 + 'H';
  buffer_copper_303 = 0;
  buffer_copper_301 = (coordinata_y_schermo_d080 >> 1) + 0x3e;
  sVar1 = 0xf;
  puVar2 = (undefined4 *)&tavolozza_copper_304;
  puVar3 = (undefined4 *)&tavolozza_predefinita_1;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}

