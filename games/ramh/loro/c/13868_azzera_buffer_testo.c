/* $13868 azzera_buffer_testo: Azzera un buffer di memoria di 1024 byte a partire dall'indirizzo 13fe6. */

/* Azzera un buffer di memoria di 1024 byte a partire dall'indirizzo 13fe6. */

void azzera_buffer_testo(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = 0xff;
  puVar2 = &buffer_testo_ingresso;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  return;
}

