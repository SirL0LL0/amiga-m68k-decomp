/* $0d638 processa_e_visualizza_testo_formattato: Interpreta script con codici controllo (0x20/0x40/0x80), formatta valori BCD, gestisce timer, disegna sfondo e stampa testo finale */

/* Interpreta script con codici controllo (0x20/0x40/0x80), formatta valori BCD, gestisce timer,
   disegna sfondo e stampa testo finale */

void processa_e_visualizza_testo_formattato(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  
  valore_minimo_trovato = '\0';
  pbVar7 = &dati_script_testo;
  avanza_puntatore_stringhe_ff();
  do {
    bVar1 = *pbVar7;
    uVar3 = (ushort)bVar1;
    if (bVar1 == 0xff) break;
    pbVar6 = pbVar7 + 1;
    pbVar7 = pbVar7 + 2;
    bVar5 = *pbVar6;
    uVar3 = CONCAT11(bVar1,bVar5);
    if ((bVar1 & 0x20) == 0) {
      if ((bVar1 & 0x40) == 0) {
        if ((bVar1 & 0x80) != 0) {
          avanza_puntatore_stringhe_ff();
          bVar1 = contatore_stringhe_ff;
          valore_attesa_timer = contatore_stringhe_ff;
          gestisci_timer_attesa_ciclica(&contatore_stringhe_ff);
          uVar3 = (ushort)bVar1;
        }
        avanza_puntatore_stringhe_bit7();
        goto l_0d712;
      }
      pcVar8 = &buffer_stato_controlli;
      iVar4 = 0x20;
      if (0xb < bVar5) {
        bVar5 = bVar5 - 0xc;
        iVar4 = 0x14;
        pcVar8 = "";
      }
      for (; bVar5 != 0; bVar5 = bVar5 - 1) {
        pcVar8 = pcVar8 + iVar4;
      }
      if (*pcVar8 == '\0') goto l_0d712;
      processa_elenco_stringhe();
    }
    else {
      pcVar8 = &buffer_bcd_sorgente;
      for (; bVar5 != 0; bVar5 = bVar5 - 1) {
        pcVar8 = pcVar8 + 9;
      }
      sVar2 = 6;
      do {
        if (*pcVar8 != '\0') break;
        pcVar8 = pcVar8 + 1;
        sVar2 = sVar2 + -1;
      } while (sVar2 != -1);
l_0d712:
      formatta_e_copia_stringa_in_buffer();
    }
  } while (valore_minimo_trovato != -1);
  disegna_sfondo_area_testo();
  stampa_testo(uVar3);
  return;
}

