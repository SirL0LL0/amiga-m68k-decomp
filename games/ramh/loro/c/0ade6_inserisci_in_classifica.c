/* $0ade6 inserisci_in_classifica: Inserisce un valore nella classifica ordinata di 10 elementi se e inferiore ai valori presenti. */

/* Inserisce un valore nella classifica ordinata di 10 elementi se e inferiore ai valori presenti.
    */

void inserisci_in_classifica(void)

{
  char cVar1;
  byte unaff_D6b;
  byte *pbVar2;
  
  cVar1 = '\n';
  pbVar2 = &tabella_classifica_1;
  if (flag_seleziona_buffer_dati != '\0') {
    pbVar2 = &tabella_classifica_2;
  }
  do {
    if (unaff_D6b < *pbVar2) {
      scorri_elementi_buffer_dati();
      *pbVar2 = unaff_D6b;
      pbVar2[10] = valore_minimo_trovato;
      return;
    }
    pbVar2 = pbVar2 + 1;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

