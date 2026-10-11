/* $0c028 disegna_elementi_controllo_mascherati: Disegna grafica mascherata per tutti gli elementi di controllo attivi */

/* Disegna grafica mascherata per tutti gli elementi di controllo attivi */

void disegna_elementi_controllo_mascherati(void)

{
  char cVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  if ((flag_controllo_attivo != '\0') && (tipo_controllo != '\0')) {
    puVar2 = &DAT_00011a98;
    valore_minimo_trovato = '\0';
    cVar1 = tipo_controllo;
    do {
      trova_elemento_e_imposta_finestra();
      puVar3 = puVar2 + 1;
      puVar2 = puVar2 + 2;
      altezza_finestra_caratteri = (undefined1)*puVar3;
      disegna_grafica_mascherata();
      valore_minimo_trovato = indice_elemento_attivo + '\x01';
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
  }
  return;
}

