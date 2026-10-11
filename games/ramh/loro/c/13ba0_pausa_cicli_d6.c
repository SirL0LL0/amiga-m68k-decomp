/* $13ba0 pausa_cicli_d6: Esegue un breve ciclo di attesa a vuoto in base al valore del registro D6. */

/* Esegue un breve ciclo di attesa a vuoto in base al valore del registro D6. */

void pausa_cicli_d6(void)

{
  byte bVar1;
  byte unaff_D6b;
  
  for (bVar1 = unaff_D6b & 7; bVar1 != 0; bVar1 = bVar1 - 1) {
  }
  return;
}

