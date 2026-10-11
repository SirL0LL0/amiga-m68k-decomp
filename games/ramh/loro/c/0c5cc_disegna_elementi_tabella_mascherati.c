/* $0c5cc disegna_elementi_tabella_mascherati: Disegna grafica mascherata per elementi usando parametri da tabella lookup */

/* Disegna grafica mascherata per elementi usando parametri da tabella lookup */

void disegna_elementi_tabella_mascherati(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = (&tabella_parametri_controllo)[(byte)(tipo_controllo - 1)];
  valore_minimo_trovato = '\0';
  cVar1 = tipo_controllo;
  do {
    trova_elemento_e_imposta_finestra(cVar2);
    disegna_grafica_mascherata();
    cVar2 = cVar2 + '\x05';
    valore_minimo_trovato = indice_elemento_attivo + '\x01';
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

