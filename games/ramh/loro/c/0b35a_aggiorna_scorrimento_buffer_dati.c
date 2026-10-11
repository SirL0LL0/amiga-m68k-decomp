/* $0b35a aggiorna_scorrimento_buffer_dati: Gestisce scorrimento elementi nei buffer dati in base a contatori, livello e flag, con timer CIA. */

/* Gestisce scorrimento elementi nei buffer dati in base a contatori, livello e flag, con timer CIA.
    */

void aggiorna_scorrimento_buffer_dati(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  
  bVar2 = contatore_scorrimento_buffer;
  if (flag_seleziona_buffer_dati != '\0') {
    if (((contatore_scorrimento_buffer < 9) && (contatore_scorrimento_buffer != 0)) &&
       (((sotto_contatore_scorrimento == 0 || (5 < sotto_contatore_scorrimento)) ||
        ((contatore_scorrimento_buffer != 0 && (contatore_scorrimento_buffer < 6)))))) {
      bVar2 = (byte)(9 - contatore_scorrimento_buffer | 4) >> 2;
      do {
        if (sotto_contatore_scorrimento == 1) break;
        sotto_contatore_scorrimento = sotto_contatore_scorrimento - 1;
        bVar2 = bVar2 - 1;
      } while (bVar2 != 0);
    }
    else {
      if (sotto_contatore_scorrimento == 0x14) {
        return;
      }
      sotto_contatore_scorrimento = sotto_contatore_scorrimento + 1;
    }
    if (sotto_contatore_scorrimento < 0xb) {
      bVar2 = sotto_contatore_scorrimento - 1;
      scorri_elementi_buffer_dati();
      (&buffer_sorgente_confronto_2)[bVar2] = 0xfe;
    }
    return;
  }
  if ((contatore_cicli_ritardo & 0x80) != 0) {
    if (10 < contatore_scorrimento_buffer) {
      return;
    }
    gestisci_timer_attesa_ciclica();
    contatore_scorrimento_buffer = bVar2 + 3;
    goto l_0b40e;
  }
  if (livello_selezionato_129c3 < 5) {
    bVar2 = 2;
  }
  else if (livello_selezionato_129c3 < 10) {
    bVar2 = 4;
  }
  else {
    bVar2 = 6;
  }
  gestisci_timer_attesa_ciclica();
  bVar3 = bVar2 <= contatore_scorrimento_buffer;
  bVar1 = contatore_scorrimento_buffer - bVar2;
  contatore_scorrimento_buffer = indice_soglia_selezionata;
  if (bVar1 == 0) {
    bVar1 = bVar2 + 1;
l_0b3ae:
    if (indice_soglia_selezionata < bVar1) {
      contatore_scorrimento_buffer = bVar1;
    }
  }
  else if (bVar3) goto l_0b3ae;
  contatore_cicli_ritardo = contatore_cicli_ritardo - 1;
  if (contatore_cicli_ritardo == 0) {
    contatore_cicli_ritardo = 0x80;
  }
l_0b40e:
  if (contatore_scorrimento_buffer < 0xb) {
    bVar2 = contatore_scorrimento_buffer - 1;
    scorri_elementi_buffer_dati();
    (&buffer_sorgente_confronto_1)[bVar2] = 0xfe;
  }
  return;
}

