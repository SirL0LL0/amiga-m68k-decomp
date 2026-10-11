/* $09c92 aggiorna_stato_gioco_principale: Gestisce contatori font e audio, aggiorna interfaccia; a step 4 processa soldi e messaggi, a step 6 chiama gestione classifiche */

/* Gestisce contatori font e audio, aggiorna interfaccia; a step 4 processa soldi e messaggi, a step
   6 chiama gestione classifiche */

void aggiorna_stato_gioco_principale(void)

{
  undefined1 uVar1;
  short sVar2;
  char cVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  if ((((flag_saldo_negativo == '\0') && (tipo_controllo != '\0')) && (flag_slot_4_attivo == '\0'))
     && (flag_sequenza_completata == '\0')) {
    contatore_font_primario = contatore_font_primario + '\x01';
    if (contatore_font_primario == '\a') {
      contatore_font_primario = '\0';
    }
    if ((indice_sequenza_audio == (&tabella_sequenze_audio)[(byte)(contatore_font_secondario << 1)])
       && (flag_audio_attivo ==
           *(char *)((int)&PTR_DAT_000120cb + (uint)(byte)(contatore_font_secondario << 1)))) {
      contatore_font_secondario = contatore_font_secondario + '\x01';
      if (contatore_font_secondario == '\f') {
        flag_sequenza_completata = 1;
        return;
      }
      indice_sequenza_audio = '\0';
      flag_audio_attivo = '\x01';
    }
    else {
      flag_audio_attivo = flag_audio_attivo + '\x01';
      if (flag_audio_attivo == '\n') {
        flag_audio_attivo = '\0';
        indice_sequenza_audio = indice_sequenza_audio + '\x01';
      }
    }
    aggiorna_interfaccia_e_grafica_base_2();
    uVar1 = flag_stato_audio;
    if (contatore_font_primario == '\x04') {
      resetta_stato_audio();
      inizializza_schermo_gioco_completo();
      azzera_buffer_8_byte();
      puVar5 = &dati_calcolo_soldi_turno;
      cVar3 = tipo_controllo;
      do {
        azzera_tre_buffer_8_byte();
        sVar2 = 3;
        puVar4 = &buffer_temporaneo_2byte;
        puVar6 = puVar5;
        do {
          *puVar4 = *puVar6;
          sVar2 = sVar2 + -1;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
        } while (sVar2 != -1);
        somma_bcd_8_cifre();
        puVar5 = puVar5 + 4;
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
      sottrai_soldi_gestisci_underflow();
      pausa_messaggio();
      flag_stato_audio = uVar1;
      routine_vuota();
    }
    else if (contatore_font_primario == '\x06') {
      processa_fine_turno_classifiche();
      routine_vuota();
      return;
    }
    return;
  }
  stato_font_corrente = 1;
  return;
}

