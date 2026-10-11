/* $09dfa aggiorna_contatori_fine_turno: Calcola valori da contatori scorrimento, aggiorna indicatori membri band, esegue somme BCD */

/* Calcola valori da contatori scorrimento, aggiorna indicatori membri band, esegue somme BCD */

void aggiorna_contatori_fine_turno(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  cVar1 = '\0';
  valore_cursore_x_salvato = '\0';
  if (((sotto_contatore_scorrimento < 0xb) && (sotto_contatore_scorrimento != 0)) &&
     (cVar1 = '\f' - sotto_contatore_scorrimento, valore_cursore_x_salvato = cVar1,
     flag_scrolling_attivo == '\0')) {
    valore_cursore_x_salvato = cVar1 * '\x02';
  }
  if ((contatore_scorrimento_buffer < 0xb) && (contatore_scorrimento_buffer != 0)) {
    cVar1 = cVar1 + ('\f' - contatore_scorrimento_buffer);
    valore_cursore_x_salvato = ('\f' - contatore_scorrimento_buffer) + valore_cursore_x_salvato;
  }
  (&array_indicatori_grafici)[indice_array_indicatori] = cVar1 + '\x01';
  indice_array_indicatori = indice_array_indicatori + 1;
  cancella_indicatori_schermo();
  azzera_tre_buffer_8_byte();
  if (valore_cursore_x_salvato != '\0') {
    DAT_0001287a = 1;
    valore_bcd_tabella1 = 2;
    somma_bcd_ripetuta();
    azzera_buffer_8_byte();
    somma_bcd_ripetuta();
    somma_bcd_8_cifre();
    aggiorna_interfaccia_e_grafica_base();
  }
  if ((sotto_contatore_scorrimento != 0) && (sotto_contatore_scorrimento < 10)) {
    accumulaore_scorrimento = ('\n' - sotto_contatore_scorrimento) + accumulaore_scorrimento;
    if (accumulaore_scorrimento < 0xf6) {
      if (accumulaore_scorrimento < 0xa7) {
        if (accumulaore_scorrimento < 0x61) {
          if (accumulaore_scorrimento < 0x26) {
            return;
          }
          puVar2 = &flag_slot_attivi;
        }
        else {
          puVar2 = &flag_slot_2_attivo;
        }
      }
      else {
        puVar2 = &flag_slot_3_attivo;
      }
    }
    else {
      puVar2 = &flag_slot_4_attivo;
    }
    *puVar2 = 1;
  }
  return;
}

