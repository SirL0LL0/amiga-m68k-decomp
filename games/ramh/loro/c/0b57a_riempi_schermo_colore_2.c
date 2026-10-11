/* $0b57a riempi_schermo_colore_2: Imposta i bitplane della memoria video per riempire lo schermo con il colore 2. */

/* Imposta i bitplane della memoria video per riempire lo schermo con il colore 2. */

void riempi_schermo_colore_2(void)

{
  short sVar1;
  undefined2 *puVar2;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 3999;
  do {
    *puVar2 = 0;
    puVar2[4000] = 0xffff;
    puVar2[8000] = 0;
    puVar2[12000] = 0;
    puVar2 = puVar2 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

