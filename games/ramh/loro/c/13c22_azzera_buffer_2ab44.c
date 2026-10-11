/* $13c22 azzera_buffer_2ab44: Azzera un buffer di memoria di 1024 byte situato all'indirizzo 2ab44. */

/* Azzera un buffer di memoria di 1024 byte situato all'indirizzo 2ab44. */

void azzera_buffer_2ab44(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = 0xff;
  puVar2 = &buffer_dati_ausiliario;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  return;
}

