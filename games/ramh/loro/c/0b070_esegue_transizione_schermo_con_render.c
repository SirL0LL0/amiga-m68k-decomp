/* $0b070 esegue_transizione_schermo_con_render: Esegue fade-out, pulisce schermo, disegna rettangolo, copia dati e renderizza ciclo principale due volte */

/* Esegue fade-out, pulisce schermo, disegna rettangolo, copia dati e renderizza ciclo principale
   due volte */

void esegue_transizione_schermo_con_render(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  contatore_frame_globale = 0x4a;
  puVar2 = &puntatore_dati_fade1;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar2 = &puntatore_dati_fade2;
  }
  flag_alternanza_render = 1;
  ciclo_principale_rendering_gioco();
  sfonda_colori_e_pulisci_schermo(puVar2);
  larghezza_finestra_caratteri = 0x1a;
  altezza_finestra_caratteri = 0xe;
  disegna_rettangolo_grafico();
  sVar1 = 4;
  puVar2 = &buffer_risultati_confronto;
  puVar3 = &buffer_risultati_confronto;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  contatore_frame_globale = 0x4f;
  flag_alternanza_render = 1;
  ciclo_principale_rendering_gioco();
  return;
}

