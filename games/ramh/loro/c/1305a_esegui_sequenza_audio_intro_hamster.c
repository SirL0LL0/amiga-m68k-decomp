/* $1305a esegui_sequenza_audio_intro_hamster: Esegue driver audio con interrupt, pattern, caricamento immagini, sfumature colori */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Esegue driver audio con interrupt, pattern, caricamento immagini, sfumature colori */

void esegui_sequenza_audio_intro_hamster(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  char *pcVar4;
  
  puVar2 = &buffer_dati_audio;
  sVar1 = 0x1f;
  puVar3 = &UNK_0002e315;
  do {
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  inizializza_driver_audio();
  stato_riproduzione_audio = 1;
  _vettore_interrupt_salvato = _vettore_interrupt_sistema;
  _vettore_interrupt_sistema = 0x132ea;
  _intena_registro = 0x8020;
  do {
    while( true ) {
      do {
        while( true ) {
          if (flag_interruzione_pattern != '\0') {
            _vettore_interrupt_sistema = uRam000132f6;
            _intena_registro = 0xc008;
            disattiva_audio_dma();
            return;
          }
          if (flag_avanzamento_pattern != '\0') break;
          if (((flag_blocco_input != '\0') || ((ciaa_pra_joystick & 0x40) == 0)) ||
             (-1 < (char)ciaa_pra_joystick)) {
            _vettore_interrupt_sistema = uRam000132f6;
            _intena_registro = 0xc008;
            disattiva_audio_dma();
            return;
          }
        }
        flag_avanzamento_pattern = '\0';
        contatore_pattern_audio = contatore_pattern_audio + 1;
        pcVar4 = (char *)((int)&PTR_DAT_00013200 + (uint)contatore_pattern_audio);
      } while (*pcVar4 == '\0');
      if (*pcVar4 != '\x01') break;
      carica_e_decomprime_immagine();
l_13142:
      gestisce_sfumatura_colori_testo_bitplane();
    }
    if (*pcVar4 == '\x02') goto l_13142;
    if (*pcVar4 == '\x03') {
      effetto_sfumatura_colori_su();
    }
    else if (*pcVar4 == '\x04') {
      effetto_sfumatura_colori_su();
      effetto_sfumatura_colori_giu();
    }
  } while( true );
}

