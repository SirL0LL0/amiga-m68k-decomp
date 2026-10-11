/* $0aa78 scorri_elementi_buffer_dati: Shifta a destra gli elementi nei buffer dati in base al flag 1289a e al valore D4. */

/* Shifta a destra gli elementi nei buffer dati in base al flag 1289a e al valore D4. */

void scorri_elementi_buffer_dati(void)

{
  char unaff_D4b;
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (unaff_D4b != '\x01') {
    cVar1 = unaff_D4b + -1;
    if (flag_seleziona_buffer_dati == '\0') {
      puVar4 = &DAT_00012422;
      puVar3 = &puntatore_dati_fade1;
      cVar2 = cVar1;
      do {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar3 = puVar3 + -1;
        cVar2 = cVar2 + -1;
      } while (cVar2 != '\0');
      puVar4 = &DAT_00012418;
      puVar3 = &DAT_00012419;
      do {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar3 = puVar3 + -1;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
    }
    else {
      puVar4 = &DAT_00012440;
      puVar3 = &puntatore_dati_fade2;
      cVar2 = cVar1;
      do {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar3 = puVar3 + -1;
        cVar2 = cVar2 + -1;
      } while (cVar2 != '\0');
      puVar4 = &DAT_00012436;
      puVar3 = &DAT_00012437;
      do {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + -1;
        puVar4 = puVar4 + -1;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
    }
  }
  return;
}

