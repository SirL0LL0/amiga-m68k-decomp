/* $13b7e pausa_cicli_d4: Esegue un breve ciclo di attesa a vuoto in base al valore del registro D4. */

/* Esegue un breve ciclo di attesa a vuoto in base al valore del registro D4. */

void pausa_cicli_d4(void)

{
  byte bVar1;
  byte unaff_D4b;
  
  for (bVar1 = unaff_D4b & 7; bVar1 != 0; bVar1 = bVar1 - 1) {
  }
  return;
}

