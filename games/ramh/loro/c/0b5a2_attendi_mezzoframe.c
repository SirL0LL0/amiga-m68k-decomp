/* $0b5a2 attendi_mezzoframe: Attende il passaggio del pennello video per sincronizzazione a mezzoframe */

/* Attende il passaggio del pennello video per sincronizzazione a mezzoframe */

undefined8 attendi_mezzoframe(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  attendi_passaggio_pennello();
  return CONCAT44(in_D0,in_D1);
}

