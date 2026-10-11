/* $1342c aggiorna_pitch_canale_audio: Calcola e aggiorna il periodo di intonazione (pitch) per un canale audio Paula. */

/* Calcola e aggiorna il periodo di intonazione (pitch) per un canale audio Paula. */

void aggiorna_pitch_canale_audio(void)

{
  byte bVar1;
  undefined2 uVar2;
  short *psVar3;
  int unaff_A5;
  int unaff_A6;
  
  bVar1 = *(byte *)(unaff_A6 + 2) & 0xf;
  if (bVar1 != 0) {
    if (bVar1 == 1) {
      *(short *)(unaff_A6 + 0x16) = *(short *)(unaff_A6 + 0x16) - (ushort)*(byte *)(unaff_A6 + 3);
      if ((short)(*(short *)(unaff_A6 + 0x16) + -0x71) < 0) {
        *(undefined2 *)(unaff_A6 + 0x16) = 0x71;
      }
      *(undefined2 *)(unaff_A5 + 6) = *(undefined2 *)(unaff_A6 + 0x16);
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    *(short *)(unaff_A6 + 0x16) = (ushort)*(byte *)(unaff_A6 + 3) + *(short *)(unaff_A6 + 0x16);
    if (-1 < (short)(*(short *)(unaff_A6 + 0x16) + -0x358)) {
      *(undefined2 *)(unaff_A6 + 0x16) = 0x358;
    }
    *(undefined2 *)(unaff_A5 + 6) = *(undefined2 *)(unaff_A6 + 0x16);
    return;
  }
  if (tipo_effetto_pitch == 1) {
l_134c4:
    bVar1 = *(byte *)(unaff_A6 + 3) >> 4;
  }
  else {
    if (tipo_effetto_pitch != 2) {
      if (tipo_effetto_pitch == 3) {
        uVar2 = *(undefined2 *)(unaff_A6 + 0x10);
        goto l_134f8;
      }
      if (tipo_effetto_pitch == 4) goto l_134c4;
      if (tipo_effetto_pitch != 5) {
        return;
      }
    }
    bVar1 = *(byte *)(unaff_A6 + 3) & 0xf;
  }
  for (psVar3 = &tabella_note_periodi;
      uVar2 = *(undefined2 *)((int)psVar3 + (int)(short)((ushort)bVar1 << 1)),
      *(short *)(unaff_A6 + 0x10) != *psVar3; psVar3 = psVar3 + 1) {
  }
l_134f8:
  *(undefined2 *)(unaff_A5 + 6) = uVar2;
  return;
}

