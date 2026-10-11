/* $09be4 inizializza_seleziona_font: Configura sequenza di selezione font ripetuta con parametri variabili, alterna flag di stato e chiama selezione glifi */

/* Configura sequenza di selezione font ripetuta con parametri variabili, alterna flag di stato e
   chiama selezione glifi */

void inizializza_seleziona_font(void)

{
  char cVar1;
  short sVar2;
  
  stato_font_corrente = 0;
  for (cVar1 = contatore_font_primario; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  sVar2 = 0x141a;
  seleziona_font_ripetuto(0x141a);
  flag_selezione_font = 1;
  seleziona_font(sVar2 + 0x100);
  seleziona_font();
  flag_selezione_font = 0;
  for (cVar1 = contatore_font_secondario; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  seleziona_font_ripetuto();
  stato_font_corrente = 1;
  return;
}

