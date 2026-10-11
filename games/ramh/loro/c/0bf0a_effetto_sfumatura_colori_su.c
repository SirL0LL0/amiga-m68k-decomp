/* $0bf0a effetto_sfumatura_colori_su: Esegue sfumatura verso l'alto dei colori Copper attendendo il pennello */

/* Esegue sfumatura verso l'alto dei colori Copper attendendo il pennello */

void effetto_sfumatura_colori_su(void)

{
  short sVar1;
  
  valore_colore_copper = '\"';
  do {
    imposta_colori_copper_1();
    sVar1 = 1;
    do {
      attendi_passaggio_pennello();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    valore_colore_copper = valore_colore_copper + '\x11';
  } while (valore_colore_copper != -0x45);
  valore_colore_copper = 0xaa;
  return;
}

