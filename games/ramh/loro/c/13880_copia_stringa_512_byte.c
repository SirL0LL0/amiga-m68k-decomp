/* $13880 copia_stringa_512_byte: Copia 512 byte nel buffer di testo e aggiunge il terminatore di riga 0x0D. */

/* Copia 512 byte nel buffer di testo e aggiunge il terminatore di riga 0x0D. */

void copia_stringa_512_byte(void)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *in_A0;
  undefined4 *puVar3;
  
  sVar2 = 0x7f;
  puVar1 = &buffer_testo_ingresso;
  do {
    puVar3 = puVar1;
    *puVar3 = *in_A0;
    sVar2 = sVar2 + -1;
    in_A0 = in_A0 + 1;
    puVar1 = puVar3 + 1;
  } while (sVar2 != -1);
  *(undefined1 *)((int)puVar3 + 2) = 0xd;
  return;
}

