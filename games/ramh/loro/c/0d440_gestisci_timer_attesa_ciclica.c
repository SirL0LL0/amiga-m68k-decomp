/* $0d440 gestisci_timer_attesa_ciclica: Gestisce attesa temporizzata CIA con indice buffer circolare per sincronizzazione */

/* Gestisce attesa temporizzata CIA con indice buffer circolare per sincronizzazione */

void gestisci_timer_attesa_ciclica(void)

{
  uint uVar1;
  byte unaff_D6b;
  
  gestisci_tempo_attesa_ciaa();
  valore_attesa_timer = unaff_D6b;
  attendi_timer_ciaa();
  indice_buffer_timer = unaff_D6b & 0x7f;
  do {
    uVar1 = (uint)indice_buffer_timer;
    indice_buffer_timer = indice_buffer_timer + 1 & 0x3f;
  } while (valore_attesa_timer < (byte)(&tabella_intervalli_timer)[uVar1]);
  return;
}

