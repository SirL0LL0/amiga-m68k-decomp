/* $0b534 pulisci_schermo_4_bitplane: Azzera i 32000 byte della memoria video dei 4 bitplane della schermata. */

/* Azzera i 32000 byte della memoria video dei 4 bitplane della schermata. */

void pulisci_schermo_4_bitplane(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&indirizzo_memoria_video;
  sVar1 = 1999;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar3 = puVar2 + 3;
    puVar2[2] = 0;
    puVar2 = puVar2 + 4;
    *puVar3 = 0;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

