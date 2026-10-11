/* $13bbc copia_blocco_dati_512: Copia 512 byte da A3 ad A1 a blocchi di 16 byte e aggiunge il terminatore 0x0D. */

/* Copia 512 byte da A3 ad A1 a blocchi di 16 byte e aggiunge il terminatore 0x0D. */

void copia_blocco_dati_512(void)

{
  short sVar1;
  undefined4 *in_A1;
  undefined4 *puVar2;
  undefined4 *unaff_A3;
  
  sVar1 = 0x1f;
  do {
    puVar2 = in_A1;
    *puVar2 = *unaff_A3;
    unaff_A3 = unaff_A3 + 4;
    sVar1 = sVar1 + -1;
    in_A1 = puVar2 + 4;
  } while (sVar1 != -1);
  *(undefined1 *)((int)puVar2 + 2) = 0xd;
  return;
}

