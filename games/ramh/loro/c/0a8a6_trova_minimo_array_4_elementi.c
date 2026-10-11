/* $0a8a6 trova_minimo_array_4_elementi: Trova l'elemento attivo con valore minimo nell'array 129b7 e ne salva l'indice. */

/* Trova l'elemento attivo con valore minimo nell'array 129b7 e ne salva l'indice. */

void trova_minimo_array_4_elementi(void)

{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = &array_stato_attivo_4_elementi;
  pbVar3 = &array_contatori_4_byte;
  valore_minimo_trovato = 0xff;
  cVar1 = '\0';
  do {
    if (((*pbVar2 & 0x80) == 0) && (*pbVar3 <= valore_minimo_trovato)) {
      valore_minimo_trovato = *pbVar3;
      indice_minimo_trovato = cVar1;
    }
    cVar1 = cVar1 + '\x01';
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
  } while (cVar1 != '\x04');
  indice_elemento_selezionato = indice_minimo_trovato;
  return;
}

