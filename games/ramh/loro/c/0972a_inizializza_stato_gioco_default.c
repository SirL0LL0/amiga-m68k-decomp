/* $0972a inizializza_stato_gioco_default: Copia valori predefiniti in variabili stato gioco e aggiorna interfaccia */

/* Copia valori predefiniti in variabili stato gioco e aggiorna interfaccia */

void inizializza_stato_gioco_default(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  sVar1 = 3;
  puVar2 = &variabili_stato_gioco_1;
  puVar3 = &valori_predefiniti_1;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  sVar1 = 3;
  puVar2 = &variabili_stato_gioco_2;
  puVar3 = &valori_predefiniti_2;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  sVar1 = 3;
  puVar2 = &array_contatori_4_byte;
  puVar3 = &valori_predefiniti_contatori;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  tipo_controllo = tipo_controllo_predefinito;
  renderizza_interfaccia_gioco_completa();
  return;
}

