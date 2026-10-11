/* $0c0a0 disegna_singolo_elemento_mascherato: Prepara e disegna grafica mascherata per un singolo elemento di controllo */

/* Prepara e disegna grafica mascherata per un singolo elemento di controllo */

void disegna_singolo_elemento_mascherato(void)

{
  if ((flag_controllo_attivo != '\0') && (tipo_controllo != '\0')) {
    indice_elemento_attivo = 0;
    prepara_finestra_elemento(tipo_controllo);
    larghezza_finestra_caratteri = 5;
    altezza_finestra_caratteri = 0x10;
    disegna_grafica_mascherata();
  }
  return;
}

