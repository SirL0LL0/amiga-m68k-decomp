/* $0daa6 ritardo_ciclo_contatore: Esegue un ciclo di attesa software decrementando il contatore fino a 1. */

/* Esegue un ciclo di attesa software decrementando il contatore fino a 1. */

void ritardo_ciclo_contatore(void)

{
  char cVar1;
  
  for (cVar1 = contatore_cicli_ritardo; cVar1 != '\x01'; cVar1 = cVar1 + -1) {
  }
  return;
}

