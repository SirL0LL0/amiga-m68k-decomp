/* $089e6 configura_controlli_input: Configura la mappatura dei tasti direzionali e la posizione del cursore in base alla modalita di input selezionata. */

/* Configura la mappatura dei tasti direzionali e la posizione del cursore in base alla modalita di
   input selezionata. */

void configura_controlli_input(void)

{
  short sVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  buffer_stato_controlli = 1;
  livello_selezionato_129c3 = 0;
  if (tipo_controllo == '\x01') {
    sVar1 = 0x13;
    puVar3 = &buffer_stato_controlli;
    puVar4 = &dati_controlli_predefiniti;
    do {
      *puVar3 = *puVar4;
      sVar1 = sVar1 + -1;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (sVar1 != -1);
    riempi_memoria_byte_d6();
    riempi_memoria_byte_d6();
    valore_minimo_trovato = '\0';
    riempi_memoria_byte_d6();
    bVar2 = DAT_000129bf;
    riempi_memoria_byte_d6();
  }
  else if (tipo_controllo == '\x02') {
    DAT_000129a5 = variabili_stato_gioco_1;
    tipo_controllo_predefinito = DAT_000129a4;
    valore_minimo_trovato = '(';
    DAT_000129ad = DAT_000129ab;
    array_contatori_4_byte = DAT_000129ac;
    DAT_000129c1 = DAT_000129bf;
    DAT_000129c2 = DAT_000129c0;
    bVar2 = 0;
  }
  else {
    bVar2 = tipo_controllo - 3;
    if (bVar2 == 0) {
      valore_minimo_trovato = '<';
      tipo_controllo_predefinito = variabili_stato_gioco_1;
      DAT_000129b2 = DAT_000129b1;
      array_contatori_4_byte = DAT_000129ad;
      DAT_000129c2 = DAT_000129c1;
    }
    else {
      valore_minimo_trovato = 'P';
    }
  }
  ritardo_ciclo_d0();
  pubblico_band = bVar2 >> 2;
  ritardo_ciclo_d0();
  qualita_esibizione_band = (byte)((bVar2 >> 2) + valore_minimo_trovato) >> 2;
  if ((DAT_000129bf & 0x80) == 0) {
    tasto_giu = DAT_000129ab;
    if ((DAT_000129c0 & 0x80) == 0) {
      tasto_destra = DAT_000129ac;
      tasto_su = DAT_000129ad;
      tasto_sinistra = array_contatori_4_byte;
      return;
    }
    tasto_su = DAT_000129ac;
    tasto_destra = DAT_000129ad;
    tasto_sinistra = array_contatori_4_byte;
    return;
  }
  tasto_su = DAT_000129ab;
  tasto_destra = DAT_000129ac;
  tasto_giu = DAT_000129ad;
  tasto_sinistra = array_contatori_4_byte;
  return;
}

