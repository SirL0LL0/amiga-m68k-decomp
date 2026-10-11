/* $0abfc inizializza_buffer_ciclico_timer_cia: Inizializza puntatori buffer schermo e timer CIA per sincronizzazione frame animazioni cicliche a doppio buffer */

/* Inizializza puntatori buffer schermo e timer CIA per sincronizzazione frame animazioni cicliche a
   doppio buffer */

void inizializza_buffer_ciclico_timer_cia(void)

{
  byte bVar1;
  byte bVar2;
  char unaff_D4b;
  undefined *puVar3;
  undefined *puVar4;
  
  if (flag_seleziona_buffer_dati == '\0') {
    bVar1 = 0x1e - unaff_D4b;
    (&tabella_buffer_schermo)[bVar1] = indice_buffer_timer & 0x1f;
    puVar3 = &tabella_buffer_schermo;
    for (bVar2 = bVar1; bVar2 != 0; bVar2 = bVar2 - 1) {
      puVar3 = puVar3 + 0x14;
    }
    puVar4 = &puntatore_dati_timer;
    for (; bVar1 != 0; bVar1 = bVar1 - 1) {
      puVar4 = puVar4 + 3;
    }
    gestisci_timer_attesa_ciclica(3,puVar4,0,puVar4,puVar3);
    prepara_copia_stringhe_ff();
  }
  return;
}

