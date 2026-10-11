/* $134fe aggiorna_riproduzione_audio: Elabora i 4 canali audio per il tick corrente, aggiorna i puntatori DMA Paula e gestisce il loop del pattern musicale. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Elabora i 4 canali audio per il tick corrente, aggiorna i puntatori DMA Paula e gestisce il loop
   del pattern musicale. */

void aggiorna_riproduzione_audio(void)

{
  short sVar1;
  
  _traccia_audio_corrente =
       tempo_musica +
       (uint)*(byte *)(struttura_dati_musica + 0x1d8 + (int)(short)stato_riproduzione_audio) * 0x400
  ;
  _maschera_dma_canali = 0;
  elabora_comando_canale_audio();
  elabora_comando_canale_audio();
  elabora_comando_canale_audio();
  elabora_comando_canale_audio();
  sVar1 = 500;
  do {
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  _dmacon_registro = _maschera_dma_canali | 0x8000;
  if (flag_dma_canale_0_attivo == 1) {
    _aud3lc_registro = ptr_dma_canale_0;
    _aud3len_registro = 1;
  }
  if (flag_dma_canale_1_attivo == 1) {
    _aud2lc_registro = ptr_dma_canale_1;
    _aud2len_registro = 1;
  }
  if (flag_dma_canale_2_attivo == 1) {
    _aud1lc_registro = ptr_dma_canale_2;
    _aud1len_registro = 1;
  }
  if (flag_dma_canale_3_attivo == 1) {
    _aud0lc_registro = ptr_dma_canale_3;
    _aud0len_registro = 1;
  }
  tempo_musica = tempo_musica + 0x10;
  if (tempo_musica != 0x400) goto l_13642;
  while( true ) {
    tempo_musica = 0;
    stato_riproduzione_audio = stato_riproduzione_audio + 1;
    flag_avanzamento_pattern = 1;
    if (stato_riproduzione_audio == frequenza_audio_corrente) {
      stato_riproduzione_audio = 0;
    }
l_13642:
    if (flag_cambio_pattern == 0) break;
    flag_cambio_pattern = 0;
  }
  return;
}

