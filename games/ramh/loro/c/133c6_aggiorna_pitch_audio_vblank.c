/* $133c6 aggiorna_pitch_audio_vblank: Aggiorna pitch dei 4 canali audio durante VBlank ciclando effetti pitch */

/* Aggiorna pitch dei 4 canali audio durante VBlank ciclando effetti pitch */

void aggiorna_pitch_audio_vblank(void)

{
  tipo_effetto_pitch = tipo_effetto_pitch + 1;
  if (tipo_effetto_pitch == 6) {
    tipo_effetto_pitch = 0;
    aggiorna_riproduzione_audio();
    return;
  }
  if (flag_pitch_canale_0 != '\0') {
    aggiorna_pitch_canale_audio();
  }
  if (flag_pitch_canale_1 != '\0') {
    aggiorna_pitch_canale_audio();
  }
  if (flag_pitch_canale_2 != '\0') {
    aggiorna_pitch_canale_audio();
  }
  if (flag_pitch_canale_3 != '\0') {
    aggiorna_pitch_canale_audio();
    return;
  }
  return;
}

