/* $087c6 verifica_e_aggiorna_saldo_soldi: Sottrae importi BCD, imposta flag saldo negativo se serve e aggiorna interfaccia */

/* Sottrae importi BCD, imposta flag saldo negativo se serve e aggiorna interfaccia */

void verifica_e_aggiorna_saldo_soldi(void)

{
  sottrazione_bcd_8_cifre();
  if (riporto_sottrazione_bcd != '\0') {
    flag_saldo_negativo = 1;
    azzera_buffer_8_byte_soldi();
  }
  aggiorna_interfaccia_e_grafica_base();
  return;
}

