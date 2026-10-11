/* $0be5a copia_bitplane_2_in_1: Copia i dati dal terzo bitplane (offset 16000) nel secondo bitplane (offset 8000) per le righe specificate. */

/* Copia i dati dal terzo bitplane (offset 16000) nel secondo bitplane (offset 8000) per le righe
   specificate. */

void copia_bitplane_2_in_1(void)

{
  ushort uVar1;
  short sVar2;
  int unaff_A3;
  short sVar3;
  
  uVar1 = (ushort)altezza_finestra_caratteri;
  sVar3 = DAT_0000bb90;
  do {
    maschera_byte_superiore_d4(sVar3);
    sVar2 = 7;
    do {
      *(undefined1 *)(unaff_A3 + 8000) = *(undefined1 *)(unaff_A3 + 16000);
      unaff_A3 = unaff_A3 + 0x28;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    sVar3 = sVar3 + 1;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0xffff);
  return;
}

