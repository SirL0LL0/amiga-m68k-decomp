/* $0dad2 renderizza_scena_condizionale: Ritardo e copia bitplane, poi disegna strati mascherati; in base a flag schermo e contatore sceglie immagine o bitmap mascherata, e a contatore=4 elementi tabel */

/* Ritardo e copia bitplane, poi disegna strati mascherati; in base a flag schermo e contatore
   sceglie immagine o bitmap mascherata, e a contatore=4 elementi tabel */

void renderizza_scena_condizionale(void)

{
  ritardo_ciclo_contatore();
  copia_interleaved_bitplane_custom();
  disegna_strati_grafici_mascherati();
  if (flag_abilitazione_schermo != '\0') {
    if ((contatore_cicli_ritardo == '\x01') || (contatore_cicli_ritardo == '\x02')) {
      disegna_immagine_4_bitplane();
    }
    else {
      disegna_bitmap_mascherata();
    }
  }
  if (contatore_cicli_ritardo == '\x04') {
    disegna_elementi_tabella_mascherati();
  }
  return;
}

