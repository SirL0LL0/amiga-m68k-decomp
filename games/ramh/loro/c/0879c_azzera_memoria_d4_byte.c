/* $0879c azzera_memoria_d4_byte: Azzera un numero di byte specificato dal registro D4 a partire dal puntatore A3. */

/* Azzera un numero di byte specificato dal registro D4 a partire dal puntatore A3. */

void azzera_memoria_d4_byte(void)

{
  char unaff_D4b;
  undefined1 *unaff_A3;
  
  do {
    *unaff_A3 = 0;
    unaff_D4b = unaff_D4b + -1;
    unaff_A3 = unaff_A3 + 1;
  } while (unaff_D4b != '\0');
  return;
}

