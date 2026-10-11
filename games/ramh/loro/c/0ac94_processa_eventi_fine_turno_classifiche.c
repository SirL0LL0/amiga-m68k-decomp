/* $0ac94 processa_eventi_fine_turno_classifiche: Se flag eventi attivo: resetta audio, mostra messaggi, gestisce high-score e classifica, esegue fade-out schermo e ricarica stato gioco */

/* Se flag eventi attivo: resetta audio, mostra messaggi, gestisce high-score e classifica, esegue
   fade-out schermo e ricarica stato gioco */

void processa_eventi_fine_turno_classifiche(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  if (flag_eventi_classifiche_pending != 0) {
    resetta_stato_audio();
    inizializza_schermo_principale_completo();
    pausa_messaggio();
    attiva_stato_audio();
    inizializza_schermo_principale_completo();
    pausa_messaggio();
    if ((flag_eventi_classifiche_pending & 0x40) != 0) {
      gestisci_classifiche_e_transizione();
    }
    if ((flag_eventi_classifiche_pending & 0x80) != 0) {
      mostra_schermata_classifica();
    }
    sfonda_colori_e_pulisci_schermo();
    flag_stato_audio = uVar1;
    aggiorna_contatori_fine_turno();
    renderizza_schermo_completo_con_colori();
    aggiorna_stato_ciclo_gioco_principale();
    return;
  }
  aggiorna_contatori_fine_turno();
  renderizza_schermo_completo_con_colori();
  return;
}

