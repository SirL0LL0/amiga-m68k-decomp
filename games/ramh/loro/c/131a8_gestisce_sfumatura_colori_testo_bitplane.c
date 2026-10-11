/* $131a8 gestisce_sfumatura_colori_testo_bitplane: Applica sfumatura colori copper su/giù, imposta palette, converte bitplane schermo, incrementa contatore e visualizza testo */

/* Applica sfumatura colori copper su/giù, imposta palette, converte bitplane schermo, incrementa
   contatore e visualizza testo */

void gestisce_sfumatura_colori_testo_bitplane(void)

{
  if (valore_colore_copper == '\"') {
    effetto_sfumatura_colori_su();
  }
  imposta_colori_copper_1();
  converti_bitplane_schermo();
  contatore_sfumatura_colori = contatore_sfumatura_colori + '\x01';
  flag_render_testo_tabella = 1;
  visualizza_testo_con_font_attivo();
  flag_render_testo_tabella = 0;
  effetto_sfumatura_colori_giu();
  return;
}

