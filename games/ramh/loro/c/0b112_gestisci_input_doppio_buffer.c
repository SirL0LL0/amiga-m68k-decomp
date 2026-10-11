/* $0b112 gestisci_input_doppio_buffer: Polling input joystick su due buffer alternati con attese temporizzate e gestione bit 0x80 per sincronizzazione. */

/* Polling input joystick su due buffer alternati con attese temporizzate e gestione bit 0x80 per
   sincronizzazione. */

void gestisci_input_doppio_buffer(void)

{
  int unaff_A3;
  byte *pbVar1;
  
  if (flag_seleziona_buffer_dati != '\0') {
    pausa_attesa_d6_1();
    if (buffer_sorgente_confronto_2 != -2) {
      pausa_attesa_d6_2(*(undefined1 *)(unaff_A3 + 1));
      pbVar1 = (byte *)(unaff_A3 + 1);
      if ((*pbVar1 & 0x80) != 0) {
        gestisci_timer_attesa_ciclica();
        *pbVar1 = 8;
        return;
      }
    }
    return;
  }
  pausa_attesa_d6_1();
  if (buffer_sorgente_confronto_1 != -2) {
    pausa_attesa_d6_1(*(undefined1 *)(unaff_A3 + 1));
    pbVar1 = (byte *)(unaff_A3 + 1);
    if ((*pbVar1 & 0x80) != 0) {
      gestisci_timer_attesa_ciclica();
      *pbVar1 = 8;
      return;
    }
  }
  return;
}

