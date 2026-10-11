/* $0a900 prepara_copia_stringhe_ff: Inizializza buffer destinazione, itera contatore saltando terminatori 0xFF su stringa vuota, poi invoca copia e processamento */

/* Inizializza buffer destinazione, itera contatore saltando terminatori 0xFF su stringa vuota, poi
   invoca copia e processamento */

void prepara_copia_stringhe_ff(void)

{
  char cVar1;
  char unaff_D6b;
  char *pcVar2;
  undefined1 *unaff_A3;
  char *pcVar3;
  
  *unaff_A3 = 1;
  pcVar3 = "";
  do {
    do {
      pcVar2 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar2;
    } while (cVar1 != -1);
    unaff_D6b = unaff_D6b + -1;
  } while (unaff_D6b != '\0');
  copia_e_processa_stringhe_ff();
  return;
}

