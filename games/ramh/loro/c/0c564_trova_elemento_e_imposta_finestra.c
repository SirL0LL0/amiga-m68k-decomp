/* $0c564 trova_elemento_e_imposta_finestra: Trova il primo elemento attivo nell'array e imposta le dimensioni della finestra. */

/* Trova il primo elemento attivo nell'array e imposta le dimensioni della finestra. */

void trova_elemento_e_imposta_finestra(void)

{
  char cVar1;
  byte unaff_D6b;
  
  while (((&array_stato_attivo_4_elementi)[unaff_D6b] & 0x80) != 0) {
    unaff_D6b = unaff_D6b + 1;
  }
  indice_elemento_attivo = unaff_D6b;
  for (cVar1 = (&array_durata_elementi)[unaff_D6b]; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  larghezza_finestra_caratteri = 5;
  altezza_finestra_caratteri = 0x30;
  return;
}

