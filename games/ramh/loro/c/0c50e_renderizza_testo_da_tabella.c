/* $0c50e renderizza_testo_da_tabella: Analizza stringhe di controllo, per ciascuna legge valori da tabella 4 byte e cancella il resto riga. */

/* Analizza stringhe di controllo, per ciascuna legge valori da tabella 4 byte e cancella il resto
   riga. */

void renderizza_testo_da_tabella(void)

{
  char cVar1;
  char unaff_D6b;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = "[\x03\\";
  for (; pcVar3 = pcVar2, unaff_D6b != '\0'; unaff_D6b = unaff_D6b + -1) {
    do {
      pcVar2 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar2;
    } while (cVar1 != -1);
  }
  for (; *pcVar2 != -1; pcVar2 = pcVar2 + 2) {
    leggi_valore_tabella_4byte();
    cancella_resto_riga();
  }
  return;
}

