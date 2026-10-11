/* $08c64 somma_bcd_ripetuta: Esegue ripetutamente la somma BCD a 8 cifre per un numero di volte specificato nel registro D4. */

/* Esegue ripetutamente la somma BCD a 8 cifre per un numero di volte specificato nel registro D4.
    */

void somma_bcd_ripetuta(void)

{
  ushort uVar1;
  ushort unaff_D4w;
  undefined4 unaff_D5;
  undefined4 unaff_A3;
  
  do {
    somma_bcd_8_cifre(unaff_A3,unaff_D5);
    uVar1 = unaff_D4w - 0x100;
    unaff_D4w = uVar1 & 0xff00;
  } while ((uVar1 & 0xff00) != 0);
  return;
}

