/* $132ea irq_vblank: gestore interrupt livello 3 (vettore $6c), vertical blank */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* gestore interrupt livello 3 (vettore $6c), vertical blank */

undefined8 irq_vblank(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  aggiorna_pitch_audio_vblank();
  _DAT_00dff09c = 0x74;
  return CONCAT44(in_D0,in_D1);
}

