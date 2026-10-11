/* $0a9a8 carica_buffer_da_1201c: Copia due blocchi di 10 byte dall'indirizzo 1201c nei buffer 12442 e 12424. */

/* Copia due blocchi di 10 byte dall'indirizzo 1201c nei buffer 12442 e 12424. */

void carica_buffer_da_1201c(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  sVar1 = 9;
  puVar2 = &buffer_destinazione_12442;
  puVar4 = &buffer_sorgente_1201c;
  do {
    puVar3 = puVar4 + 1;
    *puVar2 = *puVar4;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar4 = puVar3;
  } while (sVar1 != -1);
  sVar1 = 9;
  puVar2 = &buffer_destinazione_12424;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}

