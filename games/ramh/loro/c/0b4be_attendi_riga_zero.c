/* $0b4be attendi_riga_zero: aspetta finche' il byte basso di VHPOSR e' 0 (riga 0 o 256) */

/* aspetta finche' il byte basso di VHPOSR e' 0 (riga 0 o 256) */

void attendi_riga_zero(void)

{
  do {
  } while (DAT_00dff006 != '\0');
  return;
}

