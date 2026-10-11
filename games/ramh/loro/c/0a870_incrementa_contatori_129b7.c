/* $0a870 incrementa_contatori_129b7: Incrementa di 1 i valori non nulli e diversi da 255 nei 4 byte dell'array 129b7. */

/* WARNING: Removing unreachable block (ram,0x0000a89c) */
/* Incrementa di 1 i valori non nulli e diversi da 255 nei 4 byte dell'array 129b7. */

void incrementa_contatori_129b7(void)

{
  short sVar1;
  char *pcVar2;
  char *pcVar3;
  
  sVar1 = 3;
  pcVar2 = &array_contatori_4_byte;
  do {
    pcVar3 = pcVar2;
    if ((*pcVar2 != '\0') && (*pcVar2 != -1)) {
      pcVar3 = pcVar2 + 1;
      *pcVar2 = *pcVar2 + '\x01';
    }
    sVar1 = sVar1 + -1;
    pcVar2 = pcVar3;
  } while (sVar1 != -1);
  return;
}

