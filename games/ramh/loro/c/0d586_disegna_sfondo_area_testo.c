/* $0d586 disegna_sfondo_area_testo: Legge le coordinate da una tabella a 4 byte e ridisegna lo sfondo dei caratteri nell'area delimitata. */

/* Legge le coordinate da una tabella a 4 byte e ridisegna lo sfondo dei caratteri nell'area
   delimitata. */

void disegna_sfondo_area_testo(void)

{
  ushort uVar1;
  ushort unaff_D4w;
  ushort uVar2;
  ushort unaff_D5w;
  
  leggi_valore_tabella_4byte();
  uVar1 = unaff_D4w;
  if (flag_disabilita_sfondo == '\0') {
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
  return;
}

