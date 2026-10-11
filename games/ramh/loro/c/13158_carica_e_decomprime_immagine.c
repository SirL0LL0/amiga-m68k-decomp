/* $13158 carica_e_decomprime_immagine: Imposta i colori della palette Copper, decomprime l'immagine RLE in memoria video e aggiorna il ciclo di frame. */

/* Imposta i colori della palette Copper, decomprime l'immagine RLE in memoria video e aggiorna il
   ciclo di frame. */

void carica_e_decomprime_immagine(void)

{
  imposta_colori_copper_2();
  indice_frame_palette = indice_frame_palette + 1 & 3;
  decomprime_e_riorganizza_immagine();
  imposta_colori_copper_3();
  return;
}

