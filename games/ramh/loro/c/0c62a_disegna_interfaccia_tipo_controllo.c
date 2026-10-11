/* $0c62a disegna_interfaccia_tipo_controllo: Disegna interfaccia grafica variando parametri in base al tipo di controllo */

/* Disegna interfaccia grafica variando parametri in base al tipo di controllo */

void disegna_interfaccia_tipo_controllo(void)

{
  undefined4 uVar1;
  char cVar2;
  char cVar3;
  
  if ((tipo_controllo != '\0') &&
     ((cVar2 = tipo_controllo, flag_tipo_controllo_1 == '\0' ||
      (cVar2 = flag_controllo_secondario, flag_controllo_secondario != '\0')))) {
    cVar3 = '\x14';
    uVar1 = 2;
    if (cVar2 == '\x04') {
      cVar3 = '\x15';
    }
    else {
      if (cVar2 == '\x01') {
        cVar3 = '\x12';
      }
      if (cVar2 == '\x02') {
        uVar1 = 5;
      }
    }
    valore_minimo_trovato = '\0';
    do {
      trova_elemento_e_imposta_finestra(uVar1,cVar3);
      disegna_grafica_mascherata();
      cVar3 = cVar3 - (char)uVar1;
      valore_minimo_trovato = indice_elemento_attivo + '\x01';
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    return;
  }
  disegna_immagine_4_bitplane();
  return;
}

