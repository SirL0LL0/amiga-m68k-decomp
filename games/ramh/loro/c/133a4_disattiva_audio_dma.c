/* $133a4 disattiva_audio_dma: Azzera i volumi e disabilita i canali DMA audio del chip Paula. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Azzera i volumi e disabilita i canali DMA audio del chip Paula. */

void disattiva_audio_dma(void)

{
  _DAT_00dff0a8 = 0;
  _DAT_00dff0b8 = 0;
  _DAT_00dff0c8 = 0;
  _DAT_00dff0d8 = 0;
  _dmacon_registro = 0xf;
  return;
}

