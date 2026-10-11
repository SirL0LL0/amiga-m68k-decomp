/* $0c11c resetta_stato_audio: Azzera la variabile di stato 128aa e richiama la routine di sincronizzazione. */

/* Azzera la variabile di stato 128aa e richiama la routine di sincronizzazione. */

void resetta_stato_audio(void)

{
  flag_stato_audio = 0;
  routine_vuota();
  return;
}

