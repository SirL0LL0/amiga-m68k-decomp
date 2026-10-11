/* $0a926 elabora_animazioni_timer_30_frame: Elabora 30 frame animazioni con timer CIA, copia stringhe FF, aggiorna buffer ciclico */

/* Elabora 30 frame animazioni con timer CIA, copia stringhe FF, aggiorna buffer ciclico */

void elabora_animazioni_timer_30_frame(void)

{
  char cVar2;
  byte bVar3;
  short sVar1;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  puVar4 = &puntatore_dati_timer;
  puVar6 = &tabella_buffer_schermo;
  cVar2 = '\x1e';
  do {
    gestisci_timer_attesa_ciclica(puVar4,puVar6);
    prepara_copia_stringhe_ff();
    puVar6 = puVar6 + 0x14;
    puVar4 = puVar4 + 3;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  cVar2 = '\x1e';
  do {
    prepara_copia_stringhe_ff();
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  bVar3 = indice_buffer_timer & 7 | 1;
  do {
    aggiorna_animazioni_buffer_ciclico();
    bVar3 = bVar3 - 1;
  } while (bVar3 != 0);
  sVar1 = 9;
  puVar5 = &buffer_destinazione_12442;
  puVar8 = &buffer_sorgente_1201c;
  do {
    puVar7 = puVar8 + 1;
    *puVar5 = *puVar8;
    sVar1 = sVar1 + -1;
    puVar5 = puVar5 + 1;
    puVar8 = puVar7;
  } while (sVar1 != -1);
  sVar1 = 9;
  puVar5 = &buffer_destinazione_12424;
  do {
    *puVar5 = *puVar7;
    sVar1 = sVar1 + -1;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  } while (sVar1 != -1);
  return;
}

