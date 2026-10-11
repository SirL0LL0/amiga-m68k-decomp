/* $0915c incrementa_valore_128ce: Incrementa la variabile 128ce fino a 10 volte se diversa da 255. */

/* Incrementa la variabile 128ce fino a 10 volte se diversa da 255. */

void incrementa_valore_128ce(void)

{
  short sVar1;
  
  sVar1 = 9;
  do {
    if (qualita_esibizione_band == -1) {
      return;
    }
    qualita_esibizione_band = qualita_esibizione_band + '\x01';
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

