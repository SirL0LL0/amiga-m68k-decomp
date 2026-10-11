/* $08d08 azzera_tre_buffer_8_byte: Azzera tre buffer consecutivi da 8 byte ciascuno richiamando tre volte la funzione di azzeramento. */

/* Azzera tre buffer consecutivi da 8 byte ciascuno richiamando tre volte la funzione di
   azzeramento. */

void azzera_tre_buffer_8_byte(void)

{
  azzera_buffer_8_byte();
  azzera_buffer_8_byte();
  azzera_buffer_8_byte();
  return;
}

