/* $0d084 gestisci_input_testo_riquadro_menu: Gestisce input tastiera in riquadro menu: inizializza buffer, stampa testo, attende tasti, gestisce backspace/invio e caratteri validi */

/* Gestisce input tastiera in riquadro menu: inizializza buffer, stampa testo, attende tasti,
   gestisce backspace/invio e caratteri validi */

void gestisci_input_testo_riquadro_menu(void)

{
  byte bVar1;
  undefined2 uVar2;
  byte *pbVar3;
  byte bVar4;
  
  do {
    inizializza_buffer_spazi();
    bVar1 = 5;
    aggiorna_riquadro_menu_e_grafica();
    stampa_testo();
    pbVar3 = &buffer_testo_spazi;
    bVar4 = 0;
    while( true ) {
      copia_grafica_707c6_in_buffer_video();
      routine_vuota();
      attendi_tasto();
      bVar4 = bVar4 & 0x7f;
      if (bVar4 == 0x1b) break;
      uVar2 = (undefined2)((uint)pbVar3 >> 0x10);
      if (bVar4 == 0x7f) {
        if (bVar1 != 1) {
          disegna_sfondo_carattere();
          bVar1 = bVar1 - 1;
          seleziona_font();
          pbVar3 = (byte *)CONCAT22(uVar2,(short)pbVar3 + -1);
          bVar4 = *pbVar3;
        }
      }
      else {
        if (bVar4 == 0xd) {
          *pbVar3 = 0xa0;
          routine_vuota();
          return;
        }
        if (((0x1e < bVar4) && (bVar4 < 0x5b)) && (bVar4 = bVar1, bVar1 != 0x1d)) {
          *pbVar3 = tasto_premuto;
          disegna_sfondo_carattere(tasto_premuto);
          pbVar3 = (byte *)CONCAT22(uVar2,(short)pbVar3 + 1);
          seleziona_font();
          bVar1 = bVar1 + 1;
          bVar4 = 0x40;
          seleziona_font();
        }
      }
    }
  } while( true );
}

