/* $0869a somma_bcd_8_cifre: Esegue la somma BCD a 8 cifre tra due buffer di byte con gestione del riporto. */

/* Esegue la somma BCD a 8 cifre tra due buffer di byte con gestione del riporto. */

void somma_bcd_8_cifre(void)

{
  short sVar1;
  char *unaff_D5;
  byte bVar2;
  byte *unaff_A3;
  bool bVar3;
  
  riporto_somma_bcd = 0;
  sVar1 = 7;
  bVar3 = false;
  do {
    bVar2 = bVar3 + *unaff_A3 + *unaff_D5;
    bVar3 = 9 < bVar2;
    if (bVar3) {
      bVar2 = bVar2 - 10;
    }
    *unaff_A3 = bVar2;
    unaff_A3 = unaff_A3 + -1;
    unaff_D5 = unaff_D5 + -1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  if (bVar3) {
    riporto_somma_bcd = 1;
  }
  return;
}

