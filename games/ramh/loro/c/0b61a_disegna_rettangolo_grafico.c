/* $0b61a disegna_rettangolo_grafico: Copia una regione di memoria grafica nei 4 bitplanes dello schermo per la larghezza e altezza specificate. */

/* Copia una regione di memoria grafica nei 4 bitplanes dello schermo per la larghezza e altezza
   specificate. */

void disegna_rettangolo_grafico(void)

{
  short sVar1;
  short sVar2;
  undefined1 *in_A0;
  undefined1 *puVar3;
  undefined1 *unaff_A3;
  
  sVar2 = altezza_finestra_caratteri - 1;
  do {
    sVar1 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      *unaff_A3 = *in_A0;
      unaff_A3[8000] = in_A0[1];
      puVar3 = in_A0 + 3;
      unaff_A3[16000] = in_A0[2];
      in_A0 = in_A0 + 4;
      unaff_A3[24000] = *puVar3;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}

