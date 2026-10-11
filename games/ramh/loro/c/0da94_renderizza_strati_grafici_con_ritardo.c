/* $0da94 renderizza_strati_grafici_con_ritardo: Esegue ritardo software, copia bitplane intercalati e disegna strati grafici mascherati (tabella/controlli + bitmap principale) */

/* Esegue ritardo software, copia bitplane intercalati e disegna strati grafici mascherati
   (tabella/controlli + bitmap principale) */

void renderizza_strati_grafici_con_ritardo(void)

{
  ritardo_ciclo_contatore();
  copia_interleaved_bitplane_custom();
  disegna_strati_grafici_mascherati();
  return;
}

