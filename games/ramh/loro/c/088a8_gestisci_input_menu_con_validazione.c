/* $088a8 gestisci_input_menu_con_validazione: Gestisce input testo nel menu con validazione caratteri e aggiornamento interfaccia */

/* Gestisce input testo nel menu con validazione caratteri e aggiornamento interfaccia */

void gestisci_input_menu_con_validazione(void)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  undefined1 *unaff_A3;
  byte *pbVar4;
  undefined1 *puVar5;
  
  do {
    do {
      gestisci_input_testo_riquadro_menu();
      pbVar4 = &buffer_input_testo;
      cVar3 = '\x1e';
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + -1;
        if ((bVar1 & 0x80) != 0) break;
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
    } while ((cVar3 == '\0') || (cVar3 == '\x01'));
    do {
      if (*pbVar4 != 0x20) break;
      *pbVar4 = *pbVar4 | 0x80;
      pbVar4 = pbVar4 + -1;
      cVar3 = cVar3 + -1;
    } while (cVar3 != '\0');
    if ((cVar3 != '\0') && (cVar3 != '\x01')) {
      sVar2 = 0x1e;
      puVar5 = &buffer_testo_spazi;
      do {
        *unaff_A3 = *puVar5;
        sVar2 = sVar2 + -1;
        unaff_A3 = unaff_A3 + 1;
        puVar5 = puVar5 + 1;
      } while (sVar2 != -1);
      aggiorna_interfaccia_gioco_completa();
      copia_grafica_707c6_in_buffer_video();
      return;
    }
  } while( true );
}

