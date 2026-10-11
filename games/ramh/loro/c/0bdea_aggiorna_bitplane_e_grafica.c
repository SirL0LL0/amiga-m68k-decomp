/* $0bdea aggiorna_bitplane_e_grafica: Duplica i dati del primo bitplane nel secondo per un'area verticale e aggiorna i buffer grafici. */

/* Duplica i dati del primo bitplane nel secondo per un'area verticale e aggiorna i buffer grafici.
    */

void aggiorna_bitplane_e_grafica(void)

{
  ushort uVar1;
  short sVar2;
  undefined1 *unaff_A3;
  ushort uVar3;
  
  DAT_0000bb90 = (ushort)indirizzo_tabella_dati * 0x100 + (ushort)coordinata_x_finestra * 0x100 |
                 (ushort)riga_inizio_finestra;
  altezza_finestra_caratteri = (riga_fine_finestra - riga_inizio_finestra) - 1;
  uVar1 = (ushort)altezza_finestra_caratteri;
  uVar3 = DAT_0000bb90;
  do {
    maschera_byte_superiore_d4(uVar3);
    sVar2 = 7;
    do {
      unaff_A3[8000] = *unaff_A3;
      unaff_A3 = unaff_A3 + 0x28;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    uVar3 = uVar3 + 1;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0xffff);
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}

