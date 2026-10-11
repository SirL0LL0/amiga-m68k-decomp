/* $0d3a6 confronta_sequenza_mastermind: Esegue il confronto su 10 caratteri consecutivi invocando la routine mastermind per ciascuna posizione. */

/* Esegue il confronto su 10 caratteri consecutivi invocando la routine mastermind per ciascuna
   posizione. */

void confronta_sequenza_mastermind(void)

{
  char cVar1;
  
  cVar1 = '\0';
  do {
    confronta_carattere_mastermind();
    cVar1 = cVar1 + '\x01';
  } while (cVar1 != '\n');
  return;
}

