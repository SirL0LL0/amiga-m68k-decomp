/* $0918c incrementa_valore_128cd: Incrementa la variabile 128cd fino a 10 volte se diversa da 255. */

/* Incrementa la variabile 128cd fino a 10 volte se diversa da 255. */

void incrementa_valore_128cd(void)

{
  short sVar1;
  
  sVar1 = 9;
  do {
    if (pubblico_band == -1) {
      return;
    }
    pubblico_band = pubblico_band + '\x01';
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

