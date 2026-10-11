/* $0b552 riempi_schermo_colore_7: Imposta i bitplane della memoria video per riempire lo schermo con il colore 7. */

/* Imposta i bitplane della memoria video per riempire lo schermo con il colore 7. */

void riempi_schermo_colore_7(void)

{
  short sVar1;
  undefined2 *puVar2;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 3999;
  do {
    *puVar2 = 0xffff;
    puVar2[4000] = 0xffff;
    puVar2[8000] = 0xffff;
    puVar2[12000] = 0;
    puVar2 = puVar2 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

