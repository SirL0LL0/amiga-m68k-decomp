/* $0ad1a gestisci_classifiche_e_transizione: Gestisce high-score, transizione schermo, input doppio buffer, confronto mastermind */

/* Gestisce high-score, transizione schermo, input doppio buffer, confronto mastermind */

void gestisci_classifiche_e_transizione(void)

{
  char cVar1;
  char cVar3;
  short sVar2;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  sfonda_colori_e_pulisci_schermo();
  larghezza_finestra_caratteri = 0x1a;
  altezza_finestra_caratteri = 0xe;
  disegna_rettangolo_grafico();
  aggiorna_animazioni_buffer_ciclico();
  cVar1 = '\0';
  cVar3 = '\x1e';
  puVar4 = &tabella_classifica_singoli;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &tabella_classifica_album;
  }
  do {
    valore_minimo_trovato = cVar1;
    inserisci_in_classifica(puVar4);
    cVar1 = cVar1 + '\x01';
    puVar4 = puVar4 + 5;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  aggiorna_scorrimento_buffer_dati();
  confronta_sequenza_mastermind();
  esegue_transizione_schermo_con_render();
  gestisci_input_doppio_buffer();
  sVar2 = 9;
  puVar4 = &buffer_destinazione_12424;
  puVar5 = &buffer_sorgente_confronto_1;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &buffer_destinazione_12442;
    puVar5 = &buffer_sorgente_confronto_2;
  }
  do {
    *puVar4 = *puVar5;
    sVar2 = sVar2 + -1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (sVar2 != -1);
  flag_seleziona_buffer_dati = 0;
  return;
}

