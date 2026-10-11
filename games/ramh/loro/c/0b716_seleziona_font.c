/* $0b716 seleziona_font: sceglie il font (piccolo a $c7c5, 6 byte/carattere) e il glifo */

/* sceglie il font (piccolo a $c7c5, 6 byte/carattere) e il glifo */

void seleziona_font(void)

{
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  int unaff_D6;
  uint uVar1;
  undefined4 unaff_A3;
  ushort uVar2;
  
  if (stato_font_corrente != '\0') {
    disegna_sfondo_carattere();
  }
  uVar1 = unaff_D6 - 1;
  if (flag_selezione_font != '\0') {
    do {
      uVar2 = (short)uVar1 - 1;
      uVar1 = (uint)uVar2;
    } while (uVar2 != 0xffff);
    larghezza_finestra_caratteri = 2;
    altezza_finestra_caratteri = 0xe;
    disegna_glifo(unaff_D4,unaff_D5,unaff_D6,unaff_A3);
    return;
  }
  do {
    uVar2 = (short)uVar1 - 1;
    uVar1 = (uint)uVar2;
  } while (uVar2 != 0xffff);
  larghezza_finestra_caratteri = 1;
  altezza_finestra_caratteri = 6;
  disegna_glifo(unaff_D4,unaff_D5,unaff_D6,unaff_A3);
  return;
}

