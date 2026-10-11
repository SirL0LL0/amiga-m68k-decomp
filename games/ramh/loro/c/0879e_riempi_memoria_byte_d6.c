/* $0879e riempi_memoria_byte_d6: Riempie un blocco di memoria di dimensione D4 con il valore byte D6. */

/* Riempie un blocco di memoria di dimensione D4 con il valore byte D6. */

void riempi_memoria_byte_d6(void)

{
  char unaff_D4b;
  undefined1 unaff_D6b;
  undefined1 *unaff_A3;
  
  do {
    *unaff_A3 = unaff_D6b;
    unaff_D4b = unaff_D4b + -1;
    unaff_A3 = unaff_A3 + 1;
  } while (unaff_D4b != '\0');
  return;
}

