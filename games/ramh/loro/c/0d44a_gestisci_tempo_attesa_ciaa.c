/* $0d44a gestisci_tempo_attesa_ciaa: Imposta il contatore di attesa e attende il completamento dell'intervallo temporale tramite il timer CIAA. */

/* Imposta il contatore di attesa e attende il completamento dell'intervallo temporale tramite il
   timer CIAA. */

void gestisci_tempo_attesa_ciaa(void)

{
  uint uVar1;
  byte unaff_D6b;
  
  valore_attesa_timer = unaff_D6b;
  attendi_timer_ciaa();
  indice_buffer_timer = unaff_D6b & 0x7f;
  do {
    uVar1 = (uint)indice_buffer_timer;
    indice_buffer_timer = indice_buffer_timer + 1 & 0x3f;
  } while (valore_attesa_timer < (byte)(&tabella_intervalli_timer)[uVar1]);
  return;
}

