/* $0c10e attiva_stato_audio: Imposta a 1 il flag dello stato audio ed esegue una routine neutra di completamento. */

/* Imposta a 1 il flag dello stato audio ed esegue una routine neutra di completamento. */

void attiva_stato_audio(void)

{
  flag_stato_audio = 1;
  routine_vuota();
  return;
}

