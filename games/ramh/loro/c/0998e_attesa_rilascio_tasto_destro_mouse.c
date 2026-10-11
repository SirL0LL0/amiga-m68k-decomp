/* $0998e attesa_rilascio_tasto_destro_mouse: Se il tasto destro del mouse e' premuto, attende 9 mezzi frame e poi resetta il flag. */

/* Se il tasto destro del mouse e' premuto, attende 9 mezzi frame e poi resetta il flag. */

void attesa_rilascio_tasto_destro_mouse(void)

{
  char cVar1;
  
  if (flag_stato_mouse_destro != '\0') {
    cVar1 = '\t';
    do {
      pausa_breve();
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
    flag_stato_mouse_destro = '\0';
  }
  return;
}

