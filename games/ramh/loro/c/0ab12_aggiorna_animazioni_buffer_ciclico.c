/* $0ab12 aggiorna_animazioni_buffer_ciclico: Aggiorna 30 animazioni cicliche con doppio buffer e timer CIA per sincronizzazione frame */

/* Aggiorna 30 animazioni cicliche con doppio buffer e timer CIA per sincronizzazione frame */

void aggiorna_animazioni_buffer_ciclico(void)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  riempi_blocco_memoria();
  pbVar3 = &buffer_animazione_principale;
  if (flag_seleziona_buffer_dati != '\0') {
    pbVar3 = &buffer_animazione_secondario;
  }
  cVar2 = '\x1e';
  do {
    if ((*pbVar3 & 0x80) == 0) {
      gestisci_timer_attesa_ciclica();
      pbVar3[1] = pbVar3[1] + 4;
l_0ab80:
      bVar1 = *pbVar3 - 1;
      *pbVar3 = bVar1;
      if (bVar1 == 0) {
        *pbVar3 = pbVar3[3];
        contatore_animazione_ciclica = contatore_animazione_ciclica + 1;
        if (contatore_animazione_ciclica == 6) {
          contatore_animazione_ciclica = 0;
        }
        pbVar3[1] = (&tabella_offset_animazione)[contatore_animazione_ciclica];
        inizializza_buffer_ciclico_timer_cia();
      }
      else if ((bVar1 & 0x3f) == 0) goto l_0ab9e;
    }
    else {
      pbVar4 = pbVar3 + 1;
      gestisci_timer_attesa_ciclica();
      bVar1 = *pbVar4 - 4;
      if ((3 < *pbVar4) && (bVar1 != 0)) {
        *pbVar4 = bVar1;
        goto l_0ab80;
      }
      pbVar3[2] = pbVar3[2] - 1;
      pbVar3 = pbVar4;
l_0ab9e:
      *pbVar3 = pbVar3[4];
    }
    pbVar3 = pbVar3 + 5;
    cVar2 = cVar2 + -1;
    if (cVar2 == '\0') {
      return;
    }
  } while( true );
}

