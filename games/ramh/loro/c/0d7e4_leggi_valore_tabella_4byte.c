/* $0d7e4 leggi_valore_tabella_4byte: Cerca un record di 4 byte in una tabella e ne restituisce il terzo byte traslato di 8 bit. */

/* Cerca un record di 4 byte in una tabella e ne restituisce il terzo byte traslato di 8 bit. */

short leggi_valore_tabella_4byte(void)

{
  char unaff_D6b;
  char *pcVar1;
  
  for (pcVar1 = "\x16\x01\x17\x1f"; (unaff_D6b != '\0' && (*pcVar1 != -1)); pcVar1 = pcVar1 + 4) {
    unaff_D6b = unaff_D6b + -1;
  }
  return (ushort)(byte)pcVar1[2] << 8;
}

