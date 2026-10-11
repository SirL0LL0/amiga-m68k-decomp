/* $08842 processa_elenco_stringhe: Scorre un elenco di stringhe formattate e le copia nel buffer di testo fino al terminatore 0xFF. */

/* Scorre un elenco di stringhe formattate e le copia nel buffer di testo fino al terminatore 0xFF.
    */

void processa_elenco_stringhe(void)

{
  byte *unaff_A3;
  byte *local_4;
  
  local_4 = unaff_A3;
  do {
    if (*local_4 == 0xff) {
      return;
    }
    if ((*local_4 & 0x80) != 0) {
      avanza_puntatore_stringhe_ff();
    }
    local_4 = local_4 + 3;
    avanza_puntatore_stringhe_bit7();
    formatta_e_copia_stringa_in_buffer();
  } while (valore_minimo_trovato != -1);
  return;
}

