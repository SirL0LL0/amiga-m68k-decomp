/* $0dc78 esegui_sequenza_intro_hamster: Imposta palette copper, decomprime immagine intro, riproduce sequenza audio hamster attendendo pressione tasto fuoco */

/* Imposta palette copper, decomprime immagine intro, riproduce sequenza audio hamster attendendo
   pressione tasto fuoco */

void esegui_sequenza_intro_hamster(void)

{
  imposta_colori_copper_2();
  flag_intro_in_corso = 1;
  decomprime_e_riorganizza_immagine();
  imposta_colori_copper_3();
  esegui_intro_hamster_attendi_fuoco();
  imposta_colori_copper_4();
  flag_intro_in_corso = 0;
  return;
}

