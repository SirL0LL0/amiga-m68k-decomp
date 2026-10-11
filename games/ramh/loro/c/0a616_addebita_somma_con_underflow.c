/* $0a616 addebita_somma_con_underflow: Azzera il buffer temporaneo, attiva il flag e sottrae una somma in BCD gestendo l'eventuale underflow. */

/* Azzera il buffer temporaneo, attiva il flag e sottrae una somma in BCD gestendo l'eventuale
   underflow. */

void addebita_somma_con_underflow(void)

{
  azzera_buffer_8_byte();
  flag_addebito_soldi = 1;
  sottrai_soldi_gestisci_underflow();
  return;
}

