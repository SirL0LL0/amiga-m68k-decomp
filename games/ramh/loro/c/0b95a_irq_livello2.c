/* $0b95a irq_livello2: gestore interrupt livello 2 (vettore $68): tastiera via CIA-A SDR, spazio = pausa ($bb64) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* gestore interrupt livello 2 (vettore $68): tastiera via CIA-A SDR, spazio = pausa ($bb64) */

undefined8 irq_livello2(void)

{
  ushort uVar1;
  byte bVar2;
  undefined4 in_D0;
  byte bVar3;
  undefined4 in_D1;
  ushort uVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  
  if (((_DAT_00dff01c & 0x4000) == 0) || ((_DAT_00dff01e & _DAT_00dff01c & 8) == 0)) goto l_0bb12;
  _DAT_00dff09c = 8;
  if ((DAT_00bfed01 & 0x88) != 0x88) goto l_0bb12;
  bVar2 = ~DAT_00bfec01 << 7;
  bVar3 = bVar2 | (byte)~DAT_00bfec01 >> 1;
  if (bVar3 == 0x40) {
    flag_blocco_input = 1;
  }
  else if (bVar3 == 0xc0) {
    flag_blocco_input = 0;
  }
  else if (bVar3 == 0x4c) {
    flag_scroll_attivo = 1;
  }
  else if (bVar3 == 0xcc) {
    flag_scroll_attivo = 0;
  }
  else if (bVar3 == 0x4d) {
    flag_scroll_direzione = 1;
  }
  else if (bVar3 == 0xcd) {
    flag_scroll_direzione = 0;
  }
  uVar4 = bVar3 & 0x7f;
  if (uVar4 < 0x68) {
    uVar1 = bVar3 & 7;
    uVar4 = uVar4 >> 3;
    (&DAT_0000bb66)[(short)uVar4] = (&DAT_0000bb66)[(short)uVar4] & ~('\x01' << uVar1);
    if (bVar2 == 0) {
      (&DAT_0000bb66)[(short)uVar4] = (&DAT_0000bb66)[(short)uVar4] | '\x01' << uVar1;
    }
  }
  if (bVar2 == 0) {
    if (((DAT_0000bb72 & 1) == 0) && ((DAT_0000bb72 & 2) == 0)) {
      puVar6 = &DAT_0000bb94;
    }
    else {
      puVar6 = &DAT_0000bc04;
    }
    tasto_premuto = puVar6[bVar3];
    if (trucco_tasti_giusti == 7) {
      if (bVar3 == 0x57) {
        puVar5 = &qualita_esibizione_band;
      }
      else {
        if (bVar3 != 0x58) {
          if (bVar3 == 0x56) {
            soldi_cifra_milioni = 1;
          }
          goto l_0bb0a;
        }
        puVar5 = &pubblico_band;
      }
      *puVar5 = 0xff;
    }
    else if (bVar3 == (&trucco_sequenza_colbops)[trucco_tasti_giusti]) {
      trucco_tasti_giusti = trucco_tasti_giusti + 1;
    }
    else {
      trucco_tasti_giusti = 0;
    }
  }
l_0bb0a:
  DAT_00bfee01 = DAT_00bfee01 & 0xbf;
l_0bb12:
  return CONCAT44(in_D0,in_D1);
}

