/* $08954 copia_e_processa_stringhe_ff: Copia stringhe terminate da 0xFF da D5 a A3, gestendo byte con bit 0x80 che attivano timer e salto stringhe. */

/* Copia stringhe terminate da 0xFF da D5 a A3, gestendo byte con bit 0x80 che attivano timer e
   salto stringhe. */

void copia_e_processa_stringhe_ff(void)

{
  byte *unaff_D5;
  byte bVar1;
  byte *unaff_A3;
  byte *pbVar2;
  
  while( true ) {
    *unaff_A3 = *unaff_D5;
    bVar1 = *unaff_D5;
    if (bVar1 == 0xff) break;
    unaff_A3[1] = unaff_D5[1];
    pbVar2 = unaff_A3 + 2;
    unaff_D5 = unaff_D5 + 2;
    if ((bVar1 & 0x80) == 0) {
      bVar1 = 0;
    }
    else {
      avanza_puntatore_stringhe_ff();
      bVar1 = contatore_stringhe_ff;
      gestisci_timer_attesa_ciclica();
    }
    unaff_A3 = unaff_A3 + 3;
    *pbVar2 = bVar1;
  }
  return;
}

