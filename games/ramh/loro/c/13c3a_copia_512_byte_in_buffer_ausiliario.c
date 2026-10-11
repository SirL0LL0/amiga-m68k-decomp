/* $13c3a copia_512_byte_in_buffer_ausiliario: Copia 512 byte dal puntatore A0 nel buffer ausiliario e aggiunge un ritorno a capo. */

/* Copia 512 byte dal puntatore A0 nel buffer ausiliario e aggiunge un ritorno a capo. */

void copia_512_byte_in_buffer_ausiliario(void)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *in_A0;
  undefined4 *puVar3;
  
  sVar2 = 0x7f;
  puVar1 = &buffer_dati_ausiliario;
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

