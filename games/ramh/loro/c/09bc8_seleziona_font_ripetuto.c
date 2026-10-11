/* $09bc8 seleziona_font_ripetuto: Chiama seleziona_font per D6 volte consecutive per impostare una sequenza di glifi. */

/* Chiama seleziona_font per D6 volte consecutive per impostare una sequenza di glifi. */

void seleziona_font_ripetuto(void)

{
  int unaff_D6;
  
  do {
    seleziona_font();
    unaff_D6 = unaff_D6 + -1;
  } while (unaff_D6 != 0);
  return;
}

