/* $13654 elabora_comando_canale_audio: Elabora la nota e i comandi del canale audio configurando i registri Paula. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Elabora la nota e i comandi del canale audio configurando i registri Paula. */

void elabora_comando_canale_audio(void)

{
  ushort uVar1;
  int iVar2;
  short in_D1w;
  byte bVar3;
  short sVar4;
  int in_A0;
  int unaff_A3;
  undefined4 *unaff_A5;
  short *unaff_A6;
  
  *(undefined4 *)unaff_A6 = *(undefined4 *)(in_A0 + in_D1w);
  bVar3 = *(byte *)(unaff_A6 + 1) >> 4;
  if (bVar3 != 0) {
    sVar4 = (ushort)bVar3 * 0x1e;
    *(undefined4 *)(unaff_A6 + 2) =
         *(undefined4 *)(&tabella_campioni_audio + (short)((ushort)bVar3 << 2));
    unaff_A6[4] = *(short *)(unaff_A3 + sVar4);
    unaff_A6[9] = *(short *)(unaff_A3 + 2 + (int)sVar4);
    uVar1 = *(ushort *)(unaff_A3 + 4 + (int)sVar4);
    if (uVar1 == 0) {
      *(undefined4 *)(unaff_A6 + 5) = *(undefined4 *)(unaff_A6 + 2);
      unaff_A6[7] = *(short *)(unaff_A3 + 6 + (int)sVar4);
      *(short *)(unaff_A5 + 2) = unaff_A6[9];
    }
    else {
      iVar2 = (uint)uVar1 + *(int *)(unaff_A6 + 2);
      *(int *)(unaff_A6 + 2) = iVar2;
      *(int *)(unaff_A6 + 5) = iVar2;
      unaff_A6[4] = *(short *)(unaff_A3 + 6 + (int)sVar4);
      unaff_A6[7] = *(short *)(unaff_A3 + 6 + (int)sVar4);
      *(short *)(unaff_A5 + 2) = unaff_A6[9];
    }
  }
  if (*unaff_A6 != 0) {
    unaff_A6[8] = *unaff_A6;
    _dmacon_registro = unaff_A6[10];
    *unaff_A5 = *(undefined4 *)(unaff_A6 + 2);
    *(short *)(unaff_A5 + 1) = unaff_A6[4];
    *(short *)((int)unaff_A5 + 6) = *unaff_A6;
    _maschera_dma_canali = unaff_A6[10] | _maschera_dma_canali;
  }
  if (*unaff_A6 != 0) {
    unaff_A6[0xb] = *unaff_A6;
  }
  bVar3 = *(byte *)(unaff_A6 + 1) & 0xf;
  if (bVar3 == 0xb) {
    flag_cambio_pattern = ~flag_cambio_pattern;
    stato_riproduzione_audio = (uint)(byte)(*(char *)((int)unaff_A6 + 3) - 1);
    return;
  }
  if (bVar3 == 0xc) {
    *(undefined1 *)(unaff_A5 + 2) = *(undefined1 *)((int)unaff_A6 + 3);
    return;
  }
  if (bVar3 != 0xd) {
    if (bVar3 == 0xe) {
      ciaa_pra_joystick = (*(byte *)((int)unaff_A6 + 3) & 1) << 1 | ciaa_pra_joystick & 0xfd;
      return;
    }
    if (bVar3 != 0xf) {
      return;
    }
    bVar3 = *(byte *)((int)unaff_A6 + 3) & 0xf;
    if (bVar3 != 0) {
      tipo_effetto_pitch = 0;
      bRam000133d1 = bVar3;
    }
    return;
  }
  flag_interruzione_pattern = 1;
  flag_cambio_pattern = ~flag_cambio_pattern;
  return;
}

