/* $13784 copia_memoria_indietro: Copia a ritroso un blocco di memoria di 38912 byte dall'indirizzo sorgente al destinazione. */

/* Copia a ritroso un blocco di memoria di 38912 byte dall'indirizzo sorgente al destinazione. */

void copia_memoria_indietro(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&fine_buffer_sorgente;
  puVar3 = (undefined4 *)&fine_buffer_destinazione;
  iVar1 = 0x25ff;
  do {
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *puVar2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

