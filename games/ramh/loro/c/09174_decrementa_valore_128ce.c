/* $09174 decrementa_valore_128ce: Decrementa la variabile 128ce fino a 10 volte fermandosi se arriva a 1. */

/* Decrementa la variabile 128ce fino a 10 volte fermandosi se arriva a 1. */

void decrementa_valore_128ce(void)

{
  short sVar1;
  
  sVar1 = 9;
  do {
    if (qualita_esibizione_band == '\x01') {
      return;
    }
    qualita_esibizione_band = qualita_esibizione_band + -1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

