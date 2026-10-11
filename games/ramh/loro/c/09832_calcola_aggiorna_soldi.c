/* $09832 calcola_aggiorna_soldi: Gestisce calcoli BCD per aggiornamento soldi con buffer temporanei e ritardo */

/* Gestisce calcoli BCD per aggiornamento soldi con buffer temporanei e ritardo */

void calcola_aggiorna_soldi(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  azzera_tre_buffer_8_byte();
  valore_bcd_tabella1 = (&DAT_00012161)[indice_tabella_bcd];
  somma_bcd_ripetuta();
  sVar1 = 7;
  puVar2 = &buffer_bcd_destinazione;
  puVar4 = &buffer_bcd_sorgente;
  do {
    puVar3 = puVar4 + 1;
    *puVar2 = *puVar4;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar4 = puVar3;
  } while (sVar1 != -1);
  pausa_ciclo_12895();
  sottrazione_bcd_8_cifre();
  if (riporto_sottrazione_bcd == '\0') {
    sVar1 = 7;
    puVar2 = &buffer_bcd_sorgente;
    do {
      *puVar2 = *puVar3;
      sVar1 = sVar1 + -1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (sVar1 != -1);
  }
  azzera_buffer_8_byte();
  valore_bcd_tabella1 = (&DAT_00012166)[(byte)(indice_tabella_bcd * '\x02')];
  valore_bcd_tabella2 = (&DAT_00012167)[(byte)(indice_tabella_bcd * '\x02')];
  somma_bcd_ripetuta();
  return;
}

