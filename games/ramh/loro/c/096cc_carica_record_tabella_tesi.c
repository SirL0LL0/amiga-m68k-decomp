/* $096cc carica_record_tabella_tesi: Copia un elemento di 30 byte dalla tabella tesi nel buffer di lavoro 1283e. */

/* Copia un elemento di 30 byte dalla tabella tesi nel buffer di lavoro 1283e. */

void carica_record_tabella_tesi(void)

{
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &tabella_tesi_fine;
  for (cVar1 = indice_elemento_tabella; cVar1 != '\0'; cVar1 = cVar1 + -1) {
    puVar4 = puVar4 + 0x1e;
  }
  sVar2 = 0x1d;
  puVar3 = &buffer_record_30_byte;
  do {
    *puVar3 = *puVar4;
    sVar2 = sVar2 + -1;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (sVar2 != -1);
  return;
}

