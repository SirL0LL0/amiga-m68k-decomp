/* $09fa4 ciclo_principale_input_menu_sequenza: Gestisce timer, input mouse, caricamento risorse, stringhe FF e validazione menu in loop */

/* WARNING: Removing unreachable block (ram,0x00009fdc) */
/* WARNING: Removing unreachable block (ram,0x0000a008) */
/* WARNING: Removing unreachable block (ram,0x00009fea) */
/* Gestisce timer, input mouse, caricamento risorse, stringhe FF e validazione menu in loop */

void ciclo_principale_input_menu_sequenza(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  uVar2 = (uint)indice_sequenza_corrente;
  gestisci_input_e_carica_rock();
  if ((char)uVar2 != '\0') {
    gestisci_timer_attesa_ciclica(uVar2);
  }
  do {
    gestisci_timer_attesa_ciclica(uVar2);
  } while (flag_attesa_timer_completata != '\0');
  flag_attesa_timer_completata = 1;
  cVar1 = '\x10';
  pcVar3 = "";
  do {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != -1);
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  pausa_ciclo_d6(pcVar3);
  *pcVar3 = '\x01';
  copia_e_processa_stringhe_ff();
  cVar1 = indice_sequenza_corrente + 1;
  stato_sequenza_1 = cVar1;
  stato_sequenza_2 = cVar1;
  inizializza_schermo_gioco_completo();
  attendi_rilascio_pulsante_mouse();
  if (cVar1 != '\0') {
    inizializza_schermo_gioco_completo();
    pausa_ciclo_d6();
    pcVar4[2] = '\0';
    gestisci_input_menu_con_validazione();
  }
  indice_sequenza_corrente = indice_sequenza_corrente + 1;
  return;
}

