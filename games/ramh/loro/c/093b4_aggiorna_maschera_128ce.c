/* $093b4 aggiorna_maschera_128ce: Esegue uno scorrimento a destra di 128ce e imposta il bit meno significativo. */

/* Esegue uno scorrimento a destra di 128ce e imposta il bit meno significativo. */

void aggiorna_maschera_128ce(void)

{
  qualita_esibizione_band = qualita_esibizione_band >> 1 | 1;
  return;
}

