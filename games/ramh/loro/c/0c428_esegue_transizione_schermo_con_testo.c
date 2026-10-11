/* $0c428 esegue_transizione_schermo_con_testo: Esegue fade-out colori, pulisce schermo, disegna bitmap mascherata, renderizza testo da tabella e glifi in loop */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Esegue fade-out colori, pulisce schermo, disegna bitmap mascherata, renderizza testo da tabella e
   glifi in loop */

void esegue_transizione_schermo_con_testo(void)

{
  short sVar2;
  uint uVar1;
  char cVar3;
  undefined1 *puVar4;
  
  sfonda_colori_e_pulisci_schermo();
  riempi_schermo_colore_2();
  flag_disabilita_sfondo = 1;
  stato_font_corrente = 0;
  flag_render_testo_tabella = 1;
  renderizza_testo_da_tabella();
  flag_render_testo_tabella = 0;
  renderizza_testo_da_tabella();
  routine_vuota();
  puVar4 = &LAB_0000ca62;
  sVar2 = 0x1100;
  do {
    uVar1 = CONCAT31((uint3)(byte)((ushort)sVar2 >> 8),2);
    do {
      while( true ) {
        sVar2 = (short)uVar1;
        _larghezza_finestra_caratteri = 0x208;
        disegna_glifo(uVar1,puVar4);
        uVar1 = (uint)(ushort)(sVar2 + 2U);
        cVar3 = (char)(sVar2 + 2U);
        if (cVar3 != '\f') break;
        uVar1 = (uint)(ushort)(sVar2 + 4);
      }
    } while (cVar3 != '\x18');
    sVar2 = sVar2 + 0x102;
  } while ((char)((ushort)sVar2 >> 8) != '\x18');
  disegna_bitmap_mascherata();
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  return;
}

