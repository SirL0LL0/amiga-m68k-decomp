/* $0c310 decrementa_timer_attesa: Decrementa il contatore di timer se il suo valore e' maggiore di zero. */

/* Decrementa il contatore di timer se il suo valore e' maggiore di zero. */

void decrementa_timer_attesa(void)

{
  if (contatore_timer_attesa != '\0') {
    contatore_timer_attesa = contatore_timer_attesa + -1;
  }
  return;
}

