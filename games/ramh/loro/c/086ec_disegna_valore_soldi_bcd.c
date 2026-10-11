/* $086ec disegna_valore_soldi_bcd: Visualizza il valore dei soldi in BCD sullo schermo, saltando zeri iniziali e selezionando font per ogni cifra significativa */

/* Visualizza il valore dei soldi in BCD sullo schermo, saltando zeri iniziali e selezionando font
   per ogni cifra significativa */

void disegna_valore_soldi_bcd(void)

{
  short sVar1;
  char cVar2;
  char *pcVar3;
  
  flag_disabilita_sfondo = 1;
  stato_font_corrente = 0;
  processa_e_visualizza_testo_formattato();
  valore_minimo_trovato = '\x06';
  sVar1 = 6;
  pcVar3 = &buffer_bcd_soldi;
  do {
    if (*pcVar3 != '\0') break;
    valore_minimo_trovato = valore_minimo_trovato + '\x01';
    sVar1 = sVar1 + -1;
    pcVar3 = pcVar3 + 1;
  } while (sVar1 != -1);
  for (cVar2 = '\x06'; valore_minimo_trovato != cVar2; cVar2 = cVar2 + '\x01') {
    seleziona_font();
  }
  seleziona_font();
  cVar2 = cVar2 + '\x01';
  do {
    seleziona_font();
    cVar2 = cVar2 + '\x01';
  } while (cVar2 != '\x0f');
  stato_font_corrente = 1;
  flag_disabilita_sfondo = 0;
  return;
}

