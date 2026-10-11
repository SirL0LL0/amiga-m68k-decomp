/* $0b024 disegna_simbolo_grafico: Disegna simbolo grafico selezionando sorgente in base al carattere input */

/* Disegna simbolo grafico selezionando sorgente in base al carattere input */

void disegna_simbolo_grafico(void)

{
  undefined4 unaff_D4;
  char unaff_D6b;
  undefined *puVar1;
  
  if (unaff_D6b == '<') {
    puVar1 = &DAT_0004d10a;
  }
  else if (unaff_D6b == '+') {
    puVar1 = &DAT_0004d08a;
  }
  else {
    puVar1 = &DAT_0004d68a;
  }
  larghezza_finestra_caratteri = 2;
  altezza_finestra_caratteri = 0x10;
  disegna_rettangolo_grafico(puVar1);
  disegna_rettangolo_grafico(unaff_D4);
  return;
}

