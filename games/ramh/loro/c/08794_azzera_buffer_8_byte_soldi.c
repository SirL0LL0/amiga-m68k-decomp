/* $08794 azzera_buffer_8_byte_soldi: Azzera un buffer di 8 byte situato all'indirizzo 123ca. */

/* Azzera un buffer di 8 byte situato all'indirizzo 123ca. */

void azzera_buffer_8_byte_soldi(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  cVar1 = '\b';
  puVar2 = &buffer_bcd_soldi;
  do {
    *puVar2 = 0;
    cVar1 = cVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (cVar1 != '\0');
  return;
}

