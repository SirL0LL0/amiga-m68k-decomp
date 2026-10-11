/* $0b88a disegna_sfondo_carattere: riempie lo sfondo della cella di un carattere */

/* riempie lo sfondo della cella di un carattere */

void disegna_sfondo_carattere(void)

{
  short sVar1;
  undefined1 *unaff_A3;
  
  maschera_byte_superiore_d4();
  sVar1 = 7;
  if ((flag_render_testo_tabella == '\0') && (flag_alternanza_render == '\0')) {
    do {
      *unaff_A3 = 0xff;
      unaff_A3[8000] = 0;
      unaff_A3[16000] = 0;
      unaff_A3[24000] = 0;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    return;
  }
  if (flag_alternanza_render == '\0') {
    do {
      *unaff_A3 = 0;
      unaff_A3[8000] = 0;
      unaff_A3[16000] = 0;
      unaff_A3[24000] = 0;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    return;
  }
  if (flag_alternanza_render == '\x01') {
    do {
      *unaff_A3 = 0xff;
      unaff_A3[8000] = 0xff;
      unaff_A3[16000] = 0;
      unaff_A3[24000] = 0xff;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    return;
  }
  do {
    *unaff_A3 = 0xff;
    unaff_A3[8000] = 0;
    unaff_A3[16000] = 0xff;
    unaff_A3[24000] = 0xff;
    unaff_A3 = unaff_A3 + 0x28;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

