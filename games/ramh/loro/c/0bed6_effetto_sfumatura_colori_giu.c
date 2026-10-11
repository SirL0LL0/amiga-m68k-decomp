/* $0bed6 effetto_sfumatura_colori_giu: Esegue sfumatura verso il basso dei colori Copper attendendo il pennello */

/* Esegue sfumatura verso il basso dei colori Copper attendendo il pennello */

void effetto_sfumatura_colori_giu(void)

{
  short sVar1;
  
  valore_colore_copper = -0x56;
  do {
    imposta_colori_copper_1();
    sVar1 = 1;
    do {
      attendi_passaggio_pennello();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    valore_colore_copper = valore_colore_copper + -0x11;
  } while (valore_colore_copper != '\x11');
  valore_colore_copper = 0x22;
  return;
}

