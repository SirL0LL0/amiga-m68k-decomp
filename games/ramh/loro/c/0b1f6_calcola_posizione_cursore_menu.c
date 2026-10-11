/* $0b1f6 calcola_posizione_cursore_menu: Confronta sommatore e cursore Y contro tabelle soglia, imposta indici e timer per navigazione menu. */

/* Confronta sommatore e cursore Y contro tabelle soglia, imposta indici e timer per navigazione
   menu. */

void calcola_posizione_cursore_menu(void)

{
  byte bVar1;
  byte *pbVar2;
  
  if (flag_seleziona_buffer_dati == '\0') {
    if ((&tabella_soglie_sommatore)[flag_primo_accesso_menu] == '\0') {
      (&tabella_soglie_sommatore)[flag_primo_accesso_menu] = '\x01';
    }
    else {
      sommatore_valori_tabella = 0;
    }
    indice_soglia_selezionata = 10;
    pbVar2 = &tabella_soglie_cursore_y;
    do {
      if (sommatore_valori_tabella == *pbVar2) goto l_0b250;
      if (sommatore_valori_tabella < *pbVar2) break;
      pbVar2 = pbVar2 + 1;
      indice_soglia_selezionata = indice_soglia_selezionata - 1;
    } while (indice_soglia_selezionata != 0);
    indice_soglia_selezionata = indice_soglia_selezionata + 1;
l_0b250:
    bVar1 = 10;
    pbVar2 = &soglie_classifica;
    do {
      if (qualita_esibizione_band == *pbVar2) goto l_0b274;
      if (qualita_esibizione_band < *pbVar2) break;
      pbVar2 = pbVar2 + 1;
      bVar1 = bVar1 - 1;
    } while (bVar1 != 0);
    bVar1 = bVar1 + 1;
l_0b274:
    if (indice_soglia_selezionata < bVar1) {
      indice_soglia_selezionata = bVar1;
    }
    gestisci_timer_attesa_ciclica();
    contatore_scorrimento_buffer = 0x14;
    gestisci_timer_attesa_ciclica();
    contatore_cicli_ritardo = 7;
  }
  return;
}

