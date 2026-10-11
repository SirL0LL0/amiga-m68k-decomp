/* $13306 inizializza_driver_audio: Inizializza le tabelle dei canali audio e azzera i volumi dei registri Paula. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Inizializza le tabelle dei canali audio e azzera i volumi dei registri Paula. */

void inizializza_driver_audio(void)

{
  char cVar1;
  short sVar3;
  int iVar2;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  
  pcVar5 = (char *)(struttura_dati_musica + 0x1d8);
  sVar3 = 0x80;
  cVar1 = '\0';
  do {
    cVar4 = cVar1;
    sVar3 = sVar3 + -1;
    pcVar6 = pcVar5;
    while( true ) {
      pcVar5 = pcVar6 + 1;
      cVar1 = *pcVar6;
      if (cVar4 < *pcVar6) break;
      sVar3 = sVar3 + -1;
      pcVar6 = pcVar5;
      if (sVar3 == -1) {
        iVar2 = struttura_dati_musica + (uint)(byte)(cVar4 + 1) * 0x400 + 600;
        sVar3 = 0xe;
        iVar7 = struttura_dati_musica;
        piVar8 = &tabella_canali_audio;
        do {
          *piVar8 = iVar2;
          iVar2 = (uint)*(ushort *)(iVar7 + 0x2a) * 2 + iVar2;
          iVar7 = iVar7 + 0x1e;
          sVar3 = sVar3 + -1;
          piVar8 = piVar8 + 1;
        } while (sVar3 != -1);
        iVar2 = 0;
        do {
          **(undefined4 **)((int)&tabella_canali_audio + (int)(short)iVar2) = 0;
          iVar2 = iVar2 + 4;
        } while (iVar2 != 0x3c);
        _DAT_00dff0a8 = 0;
        _DAT_00dff0b8 = 0;
        _DAT_00dff0c8 = 0;
        _DAT_00dff0d8 = 0;
        stato_riproduzione_audio = 0;
        tempo_musica = 0;
        _traccia_audio_corrente = 0;
        frequenza_audio_corrente._1_1_ = tempo_musica_predefinito;
        return;
      }
    }
  } while( true );
}

