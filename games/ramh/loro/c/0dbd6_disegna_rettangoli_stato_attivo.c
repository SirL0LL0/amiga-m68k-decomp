/* $0dbd6 disegna_rettangoli_stato_attivo: Disegna rettangoli grafici per 4 slot se il flag corrispondente è attivo */

/* Disegna rettangoli grafici per 4 slot se il flag corrispondente è attivo */

void disegna_rettangoli_stato_attivo(void)

{
  char cVar1;
  char *pcVar2;
  
  larghezza_finestra_caratteri = 3;
  altezza_finestra_caratteri = 0x24;
  cVar1 = '\0';
  pcVar2 = &flag_slot_attivi;
  do {
    if (*pcVar2 != '\x01') {
      return;
    }
    disegna_rettangolo_grafico();
    cVar1 = cVar1 + '\x04';
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\x10');
  return;
}

