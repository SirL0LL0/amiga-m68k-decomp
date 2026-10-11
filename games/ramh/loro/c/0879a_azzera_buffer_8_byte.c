/* $0879a azzera_buffer_8_byte: Azzera 8 byte di memoria a partire dall'indirizzo specificato nel puntatore. */

/* Azzera 8 byte di memoria a partire dall'indirizzo specificato nel puntatore. */

void azzera_buffer_8_byte(void)

{
  char cVar1;
  undefined1 *unaff_A3;
  
  cVar1 = '\b';
  do {
    *unaff_A3 = 0;
    cVar1 = cVar1 + -1;
    unaff_A3 = unaff_A3 + 1;
  } while (cVar1 != '\0');
  return;
}

