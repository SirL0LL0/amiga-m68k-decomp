/* $0db5a copia_interleaved_bitplane_custom: Copia una quantita' di word specificata distribuendo i dati nei 4 bitplane. */

/* Copia una quantita' di word specificata distribuendo i dati nei 4 bitplane. */

void copia_interleaved_bitplane_custom(void)

{
  short in_D0w;
  undefined2 *in_A0;
  undefined2 *puVar1;
  undefined2 *in_A1;
  
  do {
    *in_A1 = *in_A0;
    in_A1[4000] = in_A0[1];
    puVar1 = in_A0 + 3;
    in_A1[8000] = in_A0[2];
    in_A0 = in_A0 + 4;
    in_A1[12000] = *puVar1;
    in_A1 = in_A1 + 1;
    in_D0w = in_D0w + -1;
  } while (in_D0w != -1);
  return;
}

