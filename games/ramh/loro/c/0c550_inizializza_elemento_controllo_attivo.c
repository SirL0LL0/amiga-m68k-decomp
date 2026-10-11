/* $0c550 inizializza_elemento_controllo_attivo: Seleziona l'elemento UI attivo in base a tipo_controllo, imposta dimensioni finestra 5x48 caratteri. */

/* Seleziona l'elemento UI attivo in base a tipo_controllo, imposta dimensioni finestra 5x48
   caratteri. */

void inizializza_elemento_controllo_attivo(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = tipo_controllo - 1;
  if (bVar2 != 0) {
    gestisci_timer_attesa_ciclica();
  }
  while (((&array_stato_attivo_4_elementi)[bVar2] & 0x80) != 0) {
    bVar2 = bVar2 + 1;
  }
  indice_elemento_attivo = bVar2;
  for (cVar1 = (&array_durata_elementi)[bVar2]; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  larghezza_finestra_caratteri = 5;
  altezza_finestra_caratteri = 0x30;
  return;
}

