/* $099bc esegui_flusso_principale_gioco: Esegue flusso completo del gioco: intro, ciclo 10 turni con menu band, concerti, soldi BCD, classifiche, e finale */

/* Esegue flusso completo del gioco: intro, ciclo 10 turni con menu band, concerti, soldi BCD,
   classifiche, e finale */

void esegui_flusso_principale_gioco(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *unaff_A3;
  undefined1 *puVar3;
  
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  contatore_ritardo_12895 = 6;
  pausa_ciclo_12895();
  sVar1 = 7;
  puVar2 = &buffer_bcd_sorgente;
  do {
    puVar3 = unaff_A3 + 1;
    *puVar2 = *unaff_A3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    unaff_A3 = puVar3;
  } while (sVar1 != -1);
  attesa_temporizzata_12895();
  sVar1 = 7;
  puVar2 = &buffer_bcd_destinazione;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  flag_stato_iniziale = 0x59;
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  indice_tabella_bcd = 7;
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  contatore_turni_gioco = '\n';
  azzera_buffer_8_byte();
  attesa_temporizzata_12895();
  somma_bcd_ripetuta();
  sottrai_soldi_gestisci_underflow();
  if (flag_saldo_negativo == '\0') {
    contatore_cicli_ritardo = 2;
    contatore_ritardo_cicli = 2;
    flag_controllo_attivo = 1;
    sequenza_intro_gioco_completa();
    renderizza_schermo_completo_con_colori();
    while ((((aggiorna_stato_ciclo_gioco_principale(), flag_sequenza_completata == '\0' &&
             (flag_saldo_negativo == '\0')) && (flag_slot_4_attivo == '\0')) &&
           (tipo_controllo != '\0'))) {
      flag_controllo_attivo = 1;
      renderizza_scena_condizionale();
      copia_grafica_6f8c6_in_buffer_video();
      gestisci_menu_membri_band();
      if ((tipo_controllo == '\0') || (flag_saldo_negativo != '\0')) break;
      attiva_stato_audio();
      attendi_input_gioco_con_timeout_59_frame();
      flag_controllo_attivo = 0;
      renderizza_scena_condizionale();
      copia_grafica_6f8c6_in_buffer_video();
      attendi_input_gioco_con_timeout_59_frame();
      calcola_aggiorna_soldi();
      somma_bcd_8_cifre();
      aggiorna_interfaccia_e_grafica_base();
      resetta_stato_audio();
      inizializza_schermo_principale_completo();
      avvia_sequenza_audio_buffer_ausiliario();
      incrementa_valore_128cd();
      incrementa_livello_129c3();
      if (pubblico_band < 0x46) {
        decrementa_valore_128ce();
      }
      else {
        incrementa_valore_128ce();
      }
      contatore_turni_gioco = contatore_turni_gioco + -1;
      if (contatore_turni_gioco == '\0') break;
    }
    contatore_cicli_ritardo = 1;
    sfonda_colori_e_pulisci_schermo();
    resetta_stato_audio();
    renderizza_schermo_completo_con_colori();
  }
  return;
}

