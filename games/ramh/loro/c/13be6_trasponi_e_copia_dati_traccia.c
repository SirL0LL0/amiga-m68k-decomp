/* $13be6 trasponi_e_copia_dati_traccia: Copia e traspone le note del buffer audio sottraendo l'offset D6, terminando con 0x0D. */

/* Copia e traspone le note del buffer audio sottraendo l'offset D6, terminando con 0x0D. */

void trasponi_e_copia_dati_traccia(void)

{
  short sVar1;
  short sVar2;
  short unaff_D6w;
  short *in_A1;
  short *psVar3;
  short *unaff_A3;
  
  sVar1 = 0x1f;
  do {
    psVar3 = in_A1;
    sVar2 = *unaff_A3;
    if ((char)sVar2 != '\0') {
      sVar2 = sVar2 - unaff_D6w;
    }
    *psVar3 = sVar2;
    psVar3[1] = unaff_A3[1];
    unaff_A3 = unaff_A3 + 8;
    sVar1 = sVar1 + -1;
    in_A1 = psVar3 + 8;
  } while (sVar1 != -1);
  *(undefined1 *)(psVar3 + 1) = 0xd;
  return;
}

