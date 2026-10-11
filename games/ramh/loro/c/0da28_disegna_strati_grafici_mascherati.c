/* $0da28 disegna_strati_grafici_mascherati: Disegna elementi tabella (contatore=4) o controlli (contatore=2), poi sempre bitmap principale mascherata. */

/* Disegna elementi tabella (contatore=4) o controlli (contatore=2), poi sempre bitmap principale
   mascherata. */

void disegna_strati_grafici_mascherati(void)

{
  char cVar1;
  
  if (contatore_cicli_ritardo == '\x04') {
    disegna_elementi_tabella_mascherati();
    cVar1 = contatore_cicli_ritardo;
  }
  else {
    cVar1 = contatore_cicli_ritardo;
    if (contatore_cicli_ritardo == '\x02') {
      disegna_elementi_controllo_mascherati();
      cVar1 = contatore_cicli_ritardo;
    }
  }
  do {
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  disegna_bitmap_mascherata();
  return;
}

