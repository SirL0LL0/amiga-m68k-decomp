/* $096fe resetta_configurazione_input: Copia l'impostazione dei controlli da 129c5 a 129c4 e ripristina i blocchi di memoria associati. */

/* Copia l'impostazione dei controlli da 129c5 a 129c4 e ripristina i blocchi di memoria associati.
    */

void resetta_configurazione_input(void)

{
  riempi_memoria_byte_d6();
  tipo_controllo = tipo_controllo_predefinito;
  azzera_memoria_d4_byte();
  return;
}

