/* $0b532 sfonda_colori_e_pulisci_schermo: Esegue fade-out colori copper su 15 mezzi frame poi azzera tutta la memoria video (4 bitplane, 8000 byte) */

/* Esegue fade-out colori copper su 15 mezzi frame poi azzera tutta la memoria video (4 bitplane,
   8000 byte) */

void sfonda_colori_e_pulisci_schermo(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  esegui_sfondamento_colori_copper();
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

