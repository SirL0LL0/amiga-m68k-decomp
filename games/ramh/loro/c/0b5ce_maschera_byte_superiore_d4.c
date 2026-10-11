/* $0b5ce maschera_byte_superiore_d4: Applica una maschera 0xFF00 al registro D4 ritornando il byte piu significativo. */

/* Applica una maschera 0xFF00 al registro D4 ritornando il byte piu significativo. */

ushort maschera_byte_superiore_d4(void)

{
  ushort unaff_D4w;
  
  return unaff_D4w & 0xff00;
}

