/* $087ea sottrazione_bcd_8_cifre: Sottrae due numeri BCD a 8 cifre e imposta un flag se si verifica un prestito finale. */

/* Sottrae due numeri BCD a 8 cifre e imposta un flag se si verifica un prestito finale. */

void sottrazione_bcd_8_cifre(void)

{
  byte bVar1;
  bool bVar2;
  short sVar3;
  byte *unaff_D5;
  byte bVar4;
  byte *unaff_A3;
  
  bVar2 = false;
  riporto_sottrazione_bcd = 0;
  sVar3 = 7;
  do {
    bVar1 = *unaff_A3 - *unaff_D5;
    if (*unaff_A3 < *unaff_D5) {
      bVar4 = bVar1 - bVar2;
l_08814:
      bVar4 = bVar4 + 10;
      bVar2 = true;
    }
    else {
      bVar4 = bVar1 - bVar2;
      if (bVar1 < bVar2) goto l_08814;
      bVar2 = false;
    }
    *unaff_A3 = bVar4;
    unaff_A3 = unaff_A3 + -1;
    unaff_D5 = unaff_D5 + -1;
    sVar3 = sVar3 + -1;
    if (sVar3 == -1) {
      if (bVar2) {
        riporto_sottrazione_bcd = 1;
      }
      return;
    }
  } while( true );
}

