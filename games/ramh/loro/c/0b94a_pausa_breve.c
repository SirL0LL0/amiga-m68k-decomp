/* $0b94a pausa_breve: 5 x attendi_passaggio_pennello */

/* 5 x attendi_passaggio_pennello */

void pausa_breve(void)

{
  short sVar1;
  
  sVar1 = 4;
  do {
    attendi_passaggio_pennello();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}

