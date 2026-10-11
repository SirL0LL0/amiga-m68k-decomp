/* $08918 elabora_input_e_stringhe_ff: Imposta stato controlli, scorre tabella stringhe saltando terminatori 0xFF in base a tasto premuto, poi copia e processa stringhe */

/* Imposta stato controlli, scorre tabella stringhe saltando terminatori 0xFF in base a tasto
   premuto, poi copia e processa stringhe */

void elabora_input_e_stringhe_ff(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  buffer_stato_controlli = 1;
  pcVar3 = &tabella_stringhe_ff;
  for (cVar2 = tasto_giu; cVar2 != '\0'; cVar2 = cVar2 + -1) {
    do {
      pcVar4 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar4;
    } while (cVar1 != -1);
  }
  copia_e_processa_stringhe_ff();
  return;
}

