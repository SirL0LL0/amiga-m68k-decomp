/* $0d124 inizializza_buffer_spazi: Riempie un buffer di testo con 30 spazi e appone il terminatore 0xFF. */

/* Riempie un buffer di testo con 30 spazi e appone il terminatore 0xFF. */

void inizializza_buffer_spazi(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  sVar1 = 0x1d;
  puVar3 = &buffer_testo_spazi;
  do {
    puVar2 = puVar3 + 1;
    *puVar3 = 0x20;
    sVar1 = sVar1 + -1;
    puVar3 = puVar2;
  } while (sVar1 != -1);
  *puVar2 = 0xff;
  return;
}

