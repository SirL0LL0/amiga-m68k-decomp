/* $0dbac aggiorna_interfaccia_gioco_completa: Aggiorna interfaccia completa: copia bitplane, cancella indicatori, disegna rettangoli stato, inizializza font, mostra soldi e interfaccia controllo */

/* Aggiorna interfaccia completa: copia bitplane, cancella indicatori, disegna rettangoli stato,
   inizializza font, mostra soldi e interfaccia controllo */

void aggiorna_interfaccia_gioco_completa(void)

{
  copia_interleaved_bitplane_custom();
  cancella_indicatori_schermo();
  disegna_rettangoli_stato_attivo();
  inizializza_seleziona_font();
  visualizza_valore_soldi_formattato();
  disegna_interfaccia_tipo_controllo();
  return;
}

