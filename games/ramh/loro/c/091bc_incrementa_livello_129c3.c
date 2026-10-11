/* $091bc incrementa_livello_129c3: Incrementa la variabile 129c3 fino a un valore massimo di 15. */

/* Incrementa la variabile 129c3 fino a un valore massimo di 15. */

void incrementa_livello_129c3(void)

{
  if (livello_selezionato_129c3 != '\x0f') {
    livello_selezionato_129c3 = livello_selezionato_129c3 + '\x01';
  }
  return;
}

