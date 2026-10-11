/* $0af8a disegna_carattere_grafico: Disegna carattere grafico con sfondo testo e rettangoli per i 4 bitplane */

/* Disegna carattere grafico con sfondo testo e rettangoli per i 4 bitplane */

void disegna_carattere_grafico(void)

{
  undefined4 unaff_D4;
  char unaff_D6b;
  undefined *puVar1;
  
  larghezza_finestra_caratteri = 2;
  altezza_finestra_caratteri = 0x10;
  disegna_sfondo_area_testo();
  if (unaff_D6b == 'J') {
    disegna_rettangolo_grafico();
    disegna_rettangolo_grafico(unaff_D4);
    disegna_rettangolo_grafico(unaff_D4);
    disegna_rettangolo_grafico(unaff_D4);
    return;
  }
  puVar1 = &DAT_0004d58a;
  for (unaff_D6b = unaff_D6b + -0x4b; unaff_D6b != '\0'; unaff_D6b = unaff_D6b + -1) {
    puVar1 = puVar1 + -0x80;
  }
  disegna_rettangolo_grafico(puVar1);
  disegna_rettangolo_grafico(unaff_D4);
  return;
}

