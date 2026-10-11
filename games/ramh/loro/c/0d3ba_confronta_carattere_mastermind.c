/* $0d3ba confronta_carattere_mastermind: Confronta caratteri tra buffer e imposta il simbolo di corrispondenza esatta, parziale o assente. */

/* Confronta caratteri tra buffer e imposta il simbolo di corrispondenza esatta, parziale o assente.
    */

void confronta_carattere_mastermind(void)

{
  byte unaff_D6b;
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  
  puVar4 = &buffer_sorgente_confronto_1;
  puVar3 = &buffer_destinazione_12424;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &buffer_sorgente_confronto_2;
    puVar3 = &buffer_destinazione_12442;
  }
  if (puVar4[unaff_D6b] == puVar3[unaff_D6b]) {
    uVar2 = 0x2a;
  }
  else {
    if (unaff_D6b != 0) {
      pcVar5 = &buffer_destinazione_12424;
      bVar1 = unaff_D6b;
      if (flag_seleziona_buffer_dati != '\0') {
        pcVar5 = &buffer_destinazione_12442;
      }
      do {
        if (puVar4[unaff_D6b] == *pcVar5) {
          uVar2 = 0x2b;
          goto l_0d426;
        }
        pcVar5 = pcVar5 + 1;
        bVar1 = bVar1 - 1;
      } while (bVar1 != 0);
    }
    uVar2 = 0x3c;
  }
l_0d426:
  (&buffer_risultati_confronto)[unaff_D6b] = uVar2;
  return;
}

