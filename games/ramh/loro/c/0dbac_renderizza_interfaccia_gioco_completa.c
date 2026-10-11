/* $0dbac renderizza_interfaccia_gioco_completa: Renderizza interfaccia completa: copia bitplane interleaved, cancella indicatori, disegna rettangoli stato, font, soldi e controllo */

/* Renderizza interfaccia completa: copia bitplane interleaved, cancella indicatori, disegna
   rettangoli stato, font, soldi e controllo */

void renderizza_interfaccia_gioco_completa(void)

{
  copia_interleaved_bitplane_custom();
  cancella_indicatori_schermo();
  disegna_rettangoli_stato_attivo();
  inizializza_seleziona_font();
  disegna_valore_soldi_bcd();
  disegna_interfaccia_tipo_controllo();
  return;
}

