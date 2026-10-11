/* $0d598 cancella_resto_riga: pulisce la riga di testo dopo l'ultimo carattere */

/* pulisce la riga di testo dopo l'ultimo carattere */

void cancella_resto_riga(void)

{
  ushort uVar1;
  ushort unaff_D4w;
  ushort uVar2;
  ushort unaff_D5w;
  
  uVar1 = unaff_D4w;
  do {
    do {
      uVar2 = uVar1;
      disegna_sfondo_carattere();
      uVar1 = uVar2 + 1;
    } while ((char)uVar1 != (char)unaff_D5w);
    uVar2 = uVar2 + 0x101 & 0xff00;
    unaff_D4w = uVar2 | unaff_D4w & 0xff;
    uVar1 = unaff_D4w;
  } while (uVar2 != (unaff_D5w & 0xff00));
  return;
}

