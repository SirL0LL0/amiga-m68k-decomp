/* $0d73e formatta_e_copia_stringa_in_buffer: Formatta e accoda caratteri nel buffer 122c8 convertendo cifre e gestendo la punteggiatura. */

/* Formatta e accoda caratteri nel buffer 122c8 convertendo cifre e gestendo la punteggiatura. */

void formatta_e_copia_stringa_in_buffer(void)

{
  byte *unaff_D5;
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (valore_minimo_trovato == 0xff) {
    return;
  }
  pbVar2 = &buffer_stringa_messa_in_pagine + valore_minimo_trovato;
  do {
    if (*unaff_D5 < 10) {
      bVar1 = (*unaff_D5 & 0x7f) + 0x30;
l_0d7b4:
      *pbVar2 = bVar1;
      valore_minimo_trovato = valore_minimo_trovato + 1;
      pbVar3 = pbVar2;
      if (valore_minimo_trovato == 0xff) {
l_0d7dc:
        *pbVar2 = 0xff;
        return;
      }
    }
    else {
      bVar1 = *unaff_D5 & 0x7f;
      if (((((bVar1 != 0x21) && (bVar1 != 0x2c)) && (bVar1 != 0x2e)) && (bVar1 != 0x3f)) ||
         (pbVar3 = pbVar2 + -1, *pbVar3 != 0x20)) {
        bVar1 = *unaff_D5 & 0x7f;
        goto l_0d7b4;
      }
      *pbVar3 = *unaff_D5;
    }
    pbVar2 = pbVar3 + 1;
    if ((*unaff_D5 & 0x80) == 0x80) goto l_0d7dc;
    unaff_D5 = unaff_D5 + 1;
  } while( true );
}

