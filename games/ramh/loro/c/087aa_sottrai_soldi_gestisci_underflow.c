/* $087aa sottrai_soldi_gestisci_underflow: Sottrae una quantita BCD e se il saldo diventa negativo attiva il flag e azzera. */

/* Sottrae una quantita BCD e se il saldo diventa negativo attiva il flag e azzera. */

void sottrai_soldi_gestisci_underflow(void)

{
  if (flag_saldo_negativo == '\0') {
    sottrazione_bcd_8_cifre();
    if (riporto_sottrazione_bcd != '\0') {
      flag_saldo_negativo = '\x01';
      azzera_buffer_8_byte_soldi();
    }
    aggiorna_interfaccia_e_grafica_base();
  }
  return;
}

