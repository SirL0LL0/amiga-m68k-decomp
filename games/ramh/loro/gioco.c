/* Rock Star Ate My Hamster - decompilato da Ghidra, nomi da decomp/nomi.json */

/* $08100 avvio: ingresso del gioco: prende la macchina (trap #0), spegne il sistema, imposta vettori, copper e DMA, entra nel ciclo principale */

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* ingresso del gioco: prende la macchina (trap #0), spegne il sistema, imposta vettori, copper e
   DMA, entra nel ciclo principale */

void avvio(void)

{
  undefined4 unaff_D6;
  undefined4 in_A1;
  undefined4 unaff_A2;
  
  _DAT_00000080 = 0x810a;
  __m68k_trap(0);
  _DAT_0007fffa = (undefined2)((uint)unaff_A2 >> 0x10);
  _DAT_0007fff6 = (undefined2)((uint)in_A1 >> 0x10);
  _DAT_0007fff8 = (undefined2)in_A1;
  _DAT_0007fff2 = 0x810a;
  _DAT_00000142 = 0x7fff0;
  _DAT_00dff180 = 0xeaa;
  DAT_00bfe301 = 0;
  DAT_00bfd000 = DAT_00bfd000 | 3;
  DAT_00bfd200 = 0xc2;
  _DAT_00000104 = 0;
  _DAT_00000068 = irq_livello2;
  _intena_registro = 0xc008;
  DAT_00bfed01 = 0x88;
  _DAT_00dff080 = &copper_ini;
  _DAT_00dff088 = 0;
  _DAT_00dff08e = 0x3981;
  _DAT_00dff090 = 0x1c1;
  _DAT_00dff092 = 0x38;
  _DAT_00dff094 = 0xd0;
  _DAT_00dff100 = 0x4200;
  _DAT_00dff102 = 0;
  _DAT_00dff104 = 0x67;
  _DAT_00dff108 = 0;
  _DAT_00dff10a = 0;
  _dmacon_registro = 0x83a0;
  _DAT_00000004 = 3;
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x81f8;
  imposta_parametro_bf68();
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x81fe;
  copia_memoria_indietro();
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x8202;
  routine_vuota();
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x8206;
  routine_vuota();
  DAT_000123c7 = 0xff;
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x8214;
  elabora_animazioni_timer_30_frame();
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x8218;
  esegui_sequenza_intro_hamster();
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x821c;
  sfonda_colori_e_pulisci_schermo();
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x8220;
  inizializza_stato_gioco();
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x8224;
  inizializza_gioco_e_attendi_input();
l_08224:
  _DAT_0007fffc = 0;
  _DAT_0007fffe = 0x8228;
  ciclo_principale_gioco();
  do {
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x822c;
    resetta_configurazione_input();
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x8230;
    inizializza_menu_principale();
    do {
      _DAT_0007fffc = 0;
      _DAT_0007fffe = 0x8234;
      gestisci_menu_principale_2();
      if (flag_rilascio_mouse != '\0') {
        flag_rilascio_mouse = '\0';
        _DAT_0007fffc = 0;
        _DAT_0007fffe = 0x82d4;
        inizializza_schermo_e_attendi_fuoco();
        goto l_08298;
      }
      _DAT_0007fffc = 0;
      _DAT_0007fffe = 0x8246;
      aggiorna_ciclo_principale_gioco();
      if (flag_slot_4_attivo != '\0') {
        _DAT_0007fffc = 0;
        _DAT_0007fffe = 0x8258;
        avvia_sequenza_intro_con_audio_iniziale();
        goto l_08298;
      }
      if (flag_saldo_negativo != '\0') {
        _DAT_0007fffc = 0;
        _DAT_0007fffe = 0x826e;
        avvia_sequenza_intro_completa();
        goto l_08298;
      }
      if (flag_sequenza_completata != '\0') {
        _DAT_0007fffc = 0;
        _DAT_0007fffe = 0x8284;
        avvia_sequenza_intro_senza_audio_iniziale();
        goto l_08298;
      }
    } while (tipo_controllo != '\0');
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x8298;
    inizializza_schermata_e_audio();
l_08298:
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x829c;
    resetta_stato_audio();
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x82a2;
    inizializza_schermo_principale_completo();
    tipo_controllo = '\0';
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x82b0;
    renderizza_interfaccia_gioco_completa();
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x82b4;
    attendi_rilascio_pulsante_mouse();
    _DAT_0007fffc = (undefined2)((uint)unaff_D6 >> 0x10);
    _DAT_0007fffe = (undefined2)unaff_D6;
    _DAT_0007fff8 = 0;
    _DAT_0007fffa = 0x82ba;
    inizializza_stato_gioco_completo();
    unaff_D6 = CONCAT22(_DAT_0007fffc,_DAT_0007fffe);
    if ((char)_DAT_0007fffe != '\0') goto l_08224;
    _DAT_0007fffc = 0;
    _DAT_0007fffe = 0x82c8;
    inizializza_stato_gioco_default();
  } while( true );
}


/* $08466 inizializza_gioco_e_attendi_input: Inizializza schermo, audio e attende input fuoco giocatore in sequenza per avviare la partita */

/* Inizializza schermo, audio e attende input fuoco giocatore in sequenza per avviare la partita */

void inizializza_gioco_e_attendi_input(void)

{
  int iVar1;
  
  flag_stato_audio = 1;
  renderizza_schermo_completo_con_colori();
  iVar1 = 0;
  aggiorna_riquadro_menu_con_grafica(0);
  salva_area_memoria_video();
  pausa_messaggio();
  routine_vuota();
  attiva_stato_audio();
  iVar1 = iVar1 + 1;
  attendi_input_gioco_con_timeout_59_frame(iVar1);
  iVar1 = iVar1 + 1;
  attendi_input_gioco_con_timeout_59_frame(iVar1);
  resetta_stato_audio();
  attendi_input_gioco_con_timeout_59_frame(iVar1 + 1);
  attiva_stato_audio();
  attendi_input_gioco_con_timeout_59_frame();
  resetta_stato_audio();
  return;
}


/* $084c4 inizializza_stato_gioco: Inizializza le variabili di stato del gioco, la memoria, il buffer video e i parametri predefiniti. */

/* Inizializza le variabili di stato del gioco, la memoria, il buffer video e i parametri
   predefiniti. */

void inizializza_stato_gioco(void)

{
  short sVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  pulisci_schermo_4_bitplane();
  azzera_memoria_d4_byte();
  azzera_buffer_8_byte_soldi();
  routine_vuota();
  sVar1 = 0x147;
  puVar3 = &valore_minimo_trovato;
  do {
    *puVar3 = 0;
    sVar1 = sVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != 0);
  riempi_memoria_byte_d6();
  contatore_modalita_testo = 0x14;
  contatore_iniziale = 5;
  flag_primo_avvio = 1;
  flag_finestra_aperta = 1;
  flag_audio_attivo = 1;
  flag_interfaccia_attiva = 1;
  contatore_cicli_ritardo = 1;
  modalita_video_corrente = 2;
  coordinata_x_finestra = 0x15;
  coordinata_y_finestra = 0xd;
  valore_default_a0 = 0xa0;
  valore_default_a0_2 = 0xa0;
  valore_default_a0_3 = 0xa0;
  numero_colori_attivi = 0xf;
  carica_buffer_da_1201c();
  aggiorna_interfaccia_e_grafica_base();
  aggiorna_interfaccia_e_grafica_base_2();
  valore_timer_ciclico = 0x38;
  cVar2 = '\x04';
  gestisci_timer_attesa_ciclica();
  sVar1 = 9;
  pcVar4 = &array_inizializzazione_9byte;
  do {
    *pcVar4 = cVar2;
    cVar2 = cVar2 + '\x01';
    sVar1 = sVar1 + -1;
    pcVar4 = pcVar4 + 1;
  } while (sVar1 != -1);
  return;
}


/* $084c8 inizializza_stato_gioco_completo: Azzera buffer, imposta variabili globali iniziali, carica dati e prepara interfaccia grafica */

/* Azzera buffer, imposta variabili globali iniziali, carica dati e prepara interfaccia grafica */

void inizializza_stato_gioco_completo(void)

{
  short sVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  azzera_memoria_d4_byte();
  azzera_buffer_8_byte_soldi();
  routine_vuota();
  sVar1 = 0x147;
  puVar3 = &valore_minimo_trovato;
  do {
    *puVar3 = 0;
    sVar1 = sVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != 0);
  riempi_memoria_byte_d6();
  contatore_modalita_testo = 0x14;
  contatore_iniziale = 5;
  flag_primo_avvio = 1;
  flag_finestra_aperta = 1;
  flag_audio_attivo = 1;
  flag_interfaccia_attiva = 1;
  contatore_cicli_ritardo = 1;
  modalita_video_corrente = 2;
  coordinata_x_finestra = 0x15;
  coordinata_y_finestra = 0xd;
  valore_default_a0 = 0xa0;
  valore_default_a0_2 = 0xa0;
  valore_default_a0_3 = 0xa0;
  numero_colori_attivi = 0xf;
  carica_buffer_da_1201c();
  aggiorna_interfaccia_e_grafica_base();
  aggiorna_interfaccia_e_grafica_base_2();
  valore_timer_ciclico = 0x38;
  cVar2 = '\x04';
  gestisci_timer_attesa_ciclica();
  sVar1 = 9;
  pcVar4 = &array_inizializzazione_9byte;
  do {
    *pcVar4 = cVar2;
    cVar2 = cVar2 + '\x01';
    sVar1 = sVar1 + -1;
    pcVar4 = pcVar4 + 1;
  } while (sVar1 != -1);
  return;
}


/* $085c6 avvia_partita_livello_avanzato: Inizializza schermo, audio e variabili per nuova partita a livello avanzato (livello > 9) */

/* WARNING: Removing unreachable block (ram,0x0000860a) */
/* WARNING: Removing unreachable block (ram,0x00008646) */
/* WARNING: Removing unreachable block (ram,0x00008618) */
/* Inizializza schermo, audio e variabili per nuova partita a livello avanzato (livello > 9) */

void avvia_partita_livello_avanzato(void)

{
  if ((9 < livello_selezionato_129c3) && (99 < qualita_esibizione_band)) {
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    gestisci_timer_attesa_ciclica();
    if (indirizzo_tabella_dati == '\0') {
      inizializza_schermo_principale_completo();
      incrementa_livello_129c3();
      incrementa_valore_128ce();
      avvia_sequenza_audio_testo_lungo();
    }
    else {
      inizializza_schermo_principale_completo();
      aggiorna_maschera_128ce();
      decrementa_timer_attesa();
      avvia_sequenza_audio_testo_lungo();
      schermata_menu_controllo_testo();
    }
    aggiorna_schermo_base_grafica();
    aggiorna_stato_ciclo_gioco_principale();
  }
  return;
}


/* $0869a somma_bcd_8_cifre: Esegue la somma BCD a 8 cifre tra due buffer di byte con gestione del riporto. */

/* Esegue la somma BCD a 8 cifre tra due buffer di byte con gestione del riporto. */

void somma_bcd_8_cifre(void)

{
  short sVar1;
  char *unaff_D5;
  byte bVar2;
  byte *unaff_A3;
  bool bVar3;
  
  riporto_somma_bcd = 0;
  sVar1 = 7;
  bVar3 = false;
  do {
    bVar2 = bVar3 + *unaff_A3 + *unaff_D5;
    bVar3 = 9 < bVar2;
    if (bVar3) {
      bVar2 = bVar2 - 10;
    }
    *unaff_A3 = bVar2;
    unaff_A3 = unaff_A3 + -1;
    unaff_D5 = unaff_D5 + -1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  if (bVar3) {
    riporto_somma_bcd = 1;
  }
  return;
}


/* $086e2 aggiorna_interfaccia_e_grafica_base: Aggiorna interfaccia completa e copia grafica base (707c6) nel buffer video */

/* Aggiorna interfaccia completa e copia grafica base (707c6) nel buffer video */

void aggiorna_interfaccia_e_grafica_base(void)

{
  renderizza_interfaccia_gioco_completa();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $086ec disegna_valore_soldi_bcd: Visualizza il valore dei soldi in BCD sullo schermo, saltando zeri iniziali e selezionando font per ogni cifra significativa */

/* Visualizza il valore dei soldi in BCD sullo schermo, saltando zeri iniziali e selezionando font
   per ogni cifra significativa */

void disegna_valore_soldi_bcd(void)

{
  short sVar1;
  char cVar2;
  char *pcVar3;
  
  flag_disabilita_sfondo = 1;
  stato_font_corrente = 0;
  processa_e_visualizza_testo_formattato();
  valore_minimo_trovato = '\x06';
  sVar1 = 6;
  pcVar3 = &buffer_bcd_soldi;
  do {
    if (*pcVar3 != '\0') break;
    valore_minimo_trovato = valore_minimo_trovato + '\x01';
    sVar1 = sVar1 + -1;
    pcVar3 = pcVar3 + 1;
  } while (sVar1 != -1);
  for (cVar2 = '\x06'; valore_minimo_trovato != cVar2; cVar2 = cVar2 + '\x01') {
    seleziona_font();
  }
  seleziona_font();
  cVar2 = cVar2 + '\x01';
  do {
    seleziona_font();
    cVar2 = cVar2 + '\x01';
  } while (cVar2 != '\x0f');
  stato_font_corrente = 1;
  flag_disabilita_sfondo = 0;
  return;
}


/* $08794 azzera_buffer_8_byte_soldi: Azzera un buffer di 8 byte situato all'indirizzo 123ca. */

/* Azzera un buffer di 8 byte situato all'indirizzo 123ca. */

void azzera_buffer_8_byte_soldi(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  cVar1 = '\b';
  puVar2 = &buffer_bcd_soldi;
  do {
    *puVar2 = 0;
    cVar1 = cVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (cVar1 != '\0');
  return;
}


/* $0879a azzera_buffer_8_byte: Azzera 8 byte di memoria a partire dall'indirizzo specificato nel puntatore. */

/* Azzera 8 byte di memoria a partire dall'indirizzo specificato nel puntatore. */

void azzera_buffer_8_byte(void)

{
  char cVar1;
  undefined1 *unaff_A3;
  
  cVar1 = '\b';
  do {
    *unaff_A3 = 0;
    cVar1 = cVar1 + -1;
    unaff_A3 = unaff_A3 + 1;
  } while (cVar1 != '\0');
  return;
}


/* $0879c azzera_memoria_d4_byte: Azzera un numero di byte specificato dal registro D4 a partire dal puntatore A3. */

/* Azzera un numero di byte specificato dal registro D4 a partire dal puntatore A3. */

void azzera_memoria_d4_byte(void)

{
  char unaff_D4b;
  undefined1 *unaff_A3;
  
  do {
    *unaff_A3 = 0;
    unaff_D4b = unaff_D4b + -1;
    unaff_A3 = unaff_A3 + 1;
  } while (unaff_D4b != '\0');
  return;
}


/* $0879e riempi_memoria_byte_d6: Riempie un blocco di memoria di dimensione D4 con il valore byte D6. */

/* Riempie un blocco di memoria di dimensione D4 con il valore byte D6. */

void riempi_memoria_byte_d6(void)

{
  char unaff_D4b;
  undefined1 unaff_D6b;
  undefined1 *unaff_A3;
  
  do {
    *unaff_A3 = unaff_D6b;
    unaff_D4b = unaff_D4b + -1;
    unaff_A3 = unaff_A3 + 1;
  } while (unaff_D4b != '\0');
  return;
}


/* $087aa sottrai_soldi_gestisci_underflow: Sottrae una quantita BCD e se il saldo diventa negativo attiva il flag e azzera. */

/* Sottrae una quantita BCD e se il saldo diventa negativo attiva il flag e azzera. */

void sottrai_soldi_gestisci_underflow(void)

{
  if (flag_saldo_negativo == '\0') {
    sottrazione_bcd_8_cifre();
    if (riporto_sottrazione_bcd != '\0') {
      flag_saldo_negativo = '\x01';
      azzera_buffer_8_byte_soldi();
    }
    aggiorna_interfaccia_e_grafica_base();
  }
  return;
}


/* $087c6 verifica_e_aggiorna_saldo_soldi: Sottrae importi BCD, imposta flag saldo negativo se serve e aggiorna interfaccia */

/* Sottrae importi BCD, imposta flag saldo negativo se serve e aggiorna interfaccia */

void verifica_e_aggiorna_saldo_soldi(void)

{
  sottrazione_bcd_8_cifre();
  if (riporto_sottrazione_bcd != '\0') {
    flag_saldo_negativo = 1;
    azzera_buffer_8_byte_soldi();
  }
  aggiorna_interfaccia_e_grafica_base();
  return;
}


/* $087ea sottrazione_bcd_8_cifre: Sottrae due numeri BCD a 8 cifre e imposta un flag se si verifica un prestito finale. */

/* Sottrae due numeri BCD a 8 cifre e imposta un flag se si verifica un prestito finale. */

void sottrazione_bcd_8_cifre(void)

{
  byte bVar1;
  bool bVar2;
  short sVar3;
  byte *unaff_D5;
  byte bVar4;
  byte *unaff_A3;
  
  bVar2 = false;
  riporto_sottrazione_bcd = 0;
  sVar3 = 7;
  do {
    bVar1 = *unaff_A3 - *unaff_D5;
    if (*unaff_A3 < *unaff_D5) {
      bVar4 = bVar1 - bVar2;
l_08814:
      bVar4 = bVar4 + 10;
      bVar2 = true;
    }
    else {
      bVar4 = bVar1 - bVar2;
      if (bVar1 < bVar2) goto l_08814;
      bVar2 = false;
    }
    *unaff_A3 = bVar4;
    unaff_A3 = unaff_A3 + -1;
    unaff_D5 = unaff_D5 + -1;
    sVar3 = sVar3 + -1;
    if (sVar3 == -1) {
      if (bVar2) {
        riporto_sottrazione_bcd = 1;
      }
      return;
    }
  } while( true );
}


/* $08842 processa_elenco_stringhe: Scorre un elenco di stringhe formattate e le copia nel buffer di testo fino al terminatore 0xFF. */

/* Scorre un elenco di stringhe formattate e le copia nel buffer di testo fino al terminatore 0xFF.
    */

void processa_elenco_stringhe(void)

{
  byte *unaff_A3;
  byte *local_4;
  
  local_4 = unaff_A3;
  do {
    if (*local_4 == 0xff) {
      return;
    }
    if ((*local_4 & 0x80) != 0) {
      avanza_puntatore_stringhe_ff();
    }
    local_4 = local_4 + 3;
    avanza_puntatore_stringhe_bit7();
    formatta_e_copia_stringa_in_buffer();
  } while (valore_minimo_trovato != -1);
  return;
}


/* $088a8 gestisci_input_testo_menu_validato: Gestisce input testo in riquadro menu con validazione caratteri e refresh schermo */

/* Gestisce input testo in riquadro menu con validazione caratteri e refresh schermo */

void gestisci_input_testo_menu_validato(void)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  undefined1 *unaff_A3;
  byte *pbVar4;
  undefined1 *puVar5;
  
  do {
    do {
      processa_input_testo_riquadro_menu();
      pbVar4 = &buffer_input_testo;
      cVar3 = '\x1e';
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + -1;
        if ((bVar1 & 0x80) != 0) break;
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
    } while ((cVar3 == '\0') || (cVar3 == '\x01'));
    do {
      if (*pbVar4 != 0x20) break;
      *pbVar4 = *pbVar4 | 0x80;
      pbVar4 = pbVar4 + -1;
      cVar3 = cVar3 + -1;
    } while (cVar3 != '\0');
    if ((cVar3 != '\0') && (cVar3 != '\x01')) {
      sVar2 = 0x1e;
      puVar5 = &buffer_testo_spazi;
      do {
        *unaff_A3 = *puVar5;
        sVar2 = sVar2 + -1;
        unaff_A3 = unaff_A3 + 1;
        puVar5 = puVar5 + 1;
      } while (sVar2 != -1);
      renderizza_interfaccia_gioco_completa();
      copia_grafica_707c6_in_buffer_video();
      return;
    }
  } while( true );
}


/* $08918 elabora_input_e_stringhe_ff: Imposta stato controlli, scorre tabella stringhe saltando terminatori 0xFF in base a tasto premuto, poi copia e processa stringhe */

/* Imposta stato controlli, scorre tabella stringhe saltando terminatori 0xFF in base a tasto
   premuto, poi copia e processa stringhe */

void elabora_input_e_stringhe_ff(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  buffer_stato_controlli = 1;
  pcVar3 = &tabella_stringhe_ff;
  for (cVar2 = tasto_giu; cVar2 != '\0'; cVar2 = cVar2 + -1) {
    do {
      pcVar4 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar4;
    } while (cVar1 != -1);
  }
  copia_e_processa_stringhe_ff();
  return;
}


/* $08954 copia_e_processa_stringhe_ff: Copia stringhe terminate da 0xFF da D5 a A3, gestendo byte con bit 0x80 che attivano timer e salto stringhe. */

/* Copia stringhe terminate da 0xFF da D5 a A3, gestendo byte con bit 0x80 che attivano timer e
   salto stringhe. */

void copia_e_processa_stringhe_ff(void)

{
  byte *unaff_D5;
  byte bVar1;
  byte *unaff_A3;
  byte *pbVar2;
  
  while( true ) {
    *unaff_A3 = *unaff_D5;
    bVar1 = *unaff_D5;
    if (bVar1 == 0xff) break;
    unaff_A3[1] = unaff_D5[1];
    pbVar2 = unaff_A3 + 2;
    unaff_D5 = unaff_D5 + 2;
    if ((bVar1 & 0x80) == 0) {
      bVar1 = 0;
    }
    else {
      avanza_puntatore_stringhe_ff();
      bVar1 = contatore_stringhe_ff;
      gestisci_timer_attesa_ciclica();
    }
    unaff_A3 = unaff_A3 + 3;
    *pbVar2 = bVar1;
  }
  return;
}


/* $089aa elabora_scelta_menu_principale: Elabora input menu, inizializza schermo, attende rilascio mouse e gestisce validazione selezione */

/* Elabora input menu, inizializza schermo, attende rilascio mouse e gestisce validazione selezione
    */

void elabora_scelta_menu_principale(void)

{
  char unaff_D6b;
  
  elabora_input_e_stringhe_ff();
  inizializza_schermo_principale_completo();
  attendi_rilascio_pulsante_mouse();
  if (unaff_D6b != '\0') {
    inizializza_schermo_principale_completo();
    buffer_stato_controlli = 0;
    gestisci_input_testo_menu_validato();
    return;
  }
  buffer_stato_controlli = 1;
  return;
}


/* $089e6 configura_controlli_input: Configura la mappatura dei tasti direzionali e la posizione del cursore in base alla modalita di input selezionata. */

/* Configura la mappatura dei tasti direzionali e la posizione del cursore in base alla modalita di
   input selezionata. */

void configura_controlli_input(void)

{
  short sVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  buffer_stato_controlli = 1;
  livello_selezionato_129c3 = 0;
  if (tipo_controllo == '\x01') {
    sVar1 = 0x13;
    puVar3 = &buffer_stato_controlli;
    puVar4 = &dati_controlli_predefiniti;
    do {
      *puVar3 = *puVar4;
      sVar1 = sVar1 + -1;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (sVar1 != -1);
    riempi_memoria_byte_d6();
    riempi_memoria_byte_d6();
    valore_minimo_trovato = '\0';
    riempi_memoria_byte_d6();
    bVar2 = DAT_000129bf;
    riempi_memoria_byte_d6();
  }
  else if (tipo_controllo == '\x02') {
    DAT_000129a5 = variabili_stato_gioco_1;
    tipo_controllo_predefinito = DAT_000129a4;
    valore_minimo_trovato = '(';
    DAT_000129ad = DAT_000129ab;
    array_contatori_4_byte = DAT_000129ac;
    DAT_000129c1 = DAT_000129bf;
    DAT_000129c2 = DAT_000129c0;
    bVar2 = 0;
  }
  else {
    bVar2 = tipo_controllo - 3;
    if (bVar2 == 0) {
      valore_minimo_trovato = '<';
      tipo_controllo_predefinito = variabili_stato_gioco_1;
      DAT_000129b2 = DAT_000129b1;
      array_contatori_4_byte = DAT_000129ad;
      DAT_000129c2 = DAT_000129c1;
    }
    else {
      valore_minimo_trovato = 'P';
    }
  }
  ritardo_ciclo_d0();
  pubblico_band = bVar2 >> 2;
  ritardo_ciclo_d0();
  qualita_esibizione_band = (byte)((bVar2 >> 2) + valore_minimo_trovato) >> 2;
  if ((DAT_000129bf & 0x80) == 0) {
    tasto_giu = DAT_000129ab;
    if ((DAT_000129c0 & 0x80) == 0) {
      tasto_destra = DAT_000129ac;
      tasto_su = DAT_000129ad;
      tasto_sinistra = array_contatori_4_byte;
      return;
    }
    tasto_su = DAT_000129ac;
    tasto_destra = DAT_000129ad;
    tasto_sinistra = array_contatori_4_byte;
    return;
  }
  tasto_su = DAT_000129ab;
  tasto_destra = DAT_000129ac;
  tasto_giu = DAT_000129ad;
  tasto_sinistra = array_contatori_4_byte;
  return;
}


/* $08c3e ritardo_ciclo_d0: Esegue un ciclo di attesa vuoto decrementando il registro D0. */

/* Esegue un ciclo di attesa vuoto decrementando il registro D0. */

void ritardo_ciclo_d0(void)

{
  short in_D0w;
  
  do {
    in_D0w = in_D0w + -1;
  } while (in_D0w != -1);
  return;
}


/* $08c48 inizializza_menu_principale: Configura controlli input e avvia gestione menu principale con selezione tipo controllo */

/* Configura controlli input e avvia gestione menu principale con selezione tipo controllo */

void inizializza_menu_principale(void)

{
  configura_controlli_input();
  if (tipo_controllo != '\x01') {
    elabora_scelta_menu_principale();
  }
  gestisci_menu_principale_soldi();
  return;
}


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


/* $08c84 esegui_tre_somme_bcd: Esegue tre volte la somma BCD ripetuta per calcoli monetari a precisione fissa. */

/* Esegue tre volte la somma BCD ripetuta per calcoli monetari a precisione fissa. */

void esegui_tre_somme_bcd(void)

{
  esegui_somma_bcd_ripetuta();
  esegui_somma_bcd_ripetuta();
  esegui_somma_bcd_ripetuta();
  return;
}


/* $08cf0 esegui_somma_bcd_ripetuta: Wrapper che esegue la somma BCD ripetuta per calcoli monetari */

/* Wrapper che esegue la somma BCD ripetuta per calcoli monetari */

void esegui_somma_bcd_ripetuta(void)

{
  somma_bcd_ripetuta();
  return;
}


/* $08d08 azzera_tre_buffer_8_byte: Azzera tre buffer consecutivi da 8 byte ciascuno richiamando tre volte la funzione di azzeramento. */

/* Azzera tre buffer consecutivi da 8 byte ciascuno richiamando tre volte la funzione di
   azzeramento. */

void azzera_tre_buffer_8_byte(void)

{
  azzera_buffer_8_byte();
  azzera_buffer_8_byte();
  azzera_buffer_8_byte();
  return;
}


/* $08d28 gestisci_menu_principale_soldi: Azzera buffer, calcola somme BCD per tipo controllo, inizializza schermo, attende scelta menu e verifica saldo soldi */

/* WARNING: Removing unreachable block (ram,0x00008dd8) */
/* WARNING: Removing unreachable block (ram,0x00008dce) */
/* Azzera buffer, calcola somme BCD per tipo controllo, inizializza schermo, attende scelta menu e
   verifica saldo soldi */

void gestisci_menu_principale_soldi(void)

{
  azzera_tre_buffer_8_byte();
  esegui_tre_somme_bcd();
  if (((tipo_controllo != '\x01') && (esegui_tre_somme_bcd(), tipo_controllo != '\x02')) &&
     (esegui_tre_somme_bcd(), tipo_controllo != '\x03')) {
    esegui_tre_somme_bcd();
  }
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  stato_schermata_corrente = 3;
  verifica_e_aggiorna_saldo_soldi();
  return;
}


/* $08dec gestisci_menu_principale_2: Gestisce il flusso del menu principale: rileva click, inizializza schermo, attende scelta giocatore e aggiorna interfaccia */

/* WARNING: Removing unreachable block (ram,0x00008e3c) */
/* WARNING: Removing unreachable block (ram,0x00008e22) */
/* WARNING: Removing unreachable block (ram,0x00008e88) */
/* WARNING: Removing unreachable block (ram,0x00008e14) */
/* WARNING: Removing unreachable block (ram,0x00008e30) */
/* WARNING: Removing unreachable block (ram,0x00008ec6) */
/* Gestisce il flusso del menu principale: rileva click, inizializza schermo, attende scelta
   giocatore e aggiorna interfaccia */

void gestisci_menu_principale_2(void)

{
  gestisci_click_menu_principale();
  inizializza_schermo_principale_completo();
  if (area_menu_selezionata == '\0') {
    menu_attendi_scelta();
    aggiorna_schermo_menu_con_animazione();
    return;
  }
  if (flag_sequenza_audio == '\0') {
    menu_attendi_scelta();
  }
  else {
    menu_attendi_scelta();
  }
  inizializza_schermo_attendi_mouse();
  return;
}


/* $08ecc inizializza_schermo_attendi_mouse: Inizializza schermo gioco completo e attende rilascio pulsante mouse impostando flag */

/* Inizializza schermo gioco completo e attende rilascio pulsante mouse impostando flag */

void inizializza_schermo_attendi_mouse(void)

{
  char unaff_D6b;
  
  inizializza_schermo_principale_completo();
  attendi_rilascio_pulsante_mouse();
  if (unaff_D6b == '\0') {
    flag_rilascio_mouse = 1;
  }
  return;
}


/* $08eea aggiorna_schermo_menu_con_animazione: Inizializza schermo, attende input menu, se flag animazione attivo copia dati animazione e buffer soldi poi aggiorna interfaccia e grafica */

/* WARNING: Removing unreachable block (ram,0x00008f50) */
/* WARNING: Removing unreachable block (ram,0x00008f6c) */
/* WARNING: Removing unreachable block (ram,0x00008f6e) */
/* WARNING: Removing unreachable block (ram,0x00008f72) */
/* WARNING: Removing unreachable block (ram,0x00008f7e) */
/* WARNING: Removing unreachable block (ram,0x00008f80) */
/* WARNING: Removing unreachable block (ram,0x00008f84) */
/* Inizializza schermo, attende input menu, se flag animazione attivo copia dati animazione e buffer
   soldi poi aggiorna interfaccia e grafica */

void aggiorna_schermo_menu_con_animazione(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar4;
  undefined1 *puVar3;
  
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  if (flag_animazione_attiva != '\0') {
    sVar1 = 299;
    puVar3 = &DAT_00076e56;
    puVar4 = &buffer_animazione_principale;
    do {
      puVar2 = puVar3 + 1;
      *puVar4 = *puVar3;
      sVar1 = sVar1 + -1;
      puVar3 = puVar2;
      puVar4 = puVar4 + 1;
    } while (sVar1 != -1);
    sVar1 = 0xc90;
    puVar3 = &buffer_bcd_soldi;
    do {
      *puVar3 = *puVar2;
      sVar1 = sVar1 + -1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (sVar1 != -1);
    renderizza_interfaccia_gioco_completa();
    copia_grafica_707c6_in_buffer_video();
  }
  return;
}


/* $08f88 gestisci_click_menu_principale: Rileva click su 5 aree menu (coordinate Y), carica dati corrispondenti, avvia audio e aggiorna schermo */

/* WARNING: Removing unreachable block (ram,0x00009054) */
/* Rileva click su 5 aree menu (coordinate Y), carica dati corrispondenti, avvia audio e aggiorna
   schermo */

void gestisci_click_menu_principale(void)

{
  undefined4 uVar1;
  short sVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  azzera_tre_buffer_8_byte();
  if (((area_menu_selezionata == '\0') && (0x3b < pubblico_band)) &&
     (0x27 < qualita_esibizione_band)) {
    if (qualita_esibizione_band < 0x46) {
      if (flag_area_1_usata != '\0') {
        return;
      }
      flag_area_1_usata = '\x01';
      area_menu_selezionata = 1;
      puVar5 = &DAT_00012125;
      puVar3 = &DAT_00012127;
      uVar1 = 0x13;
    }
    else {
      if (qualita_esibizione_band < 0x6e) {
        if (flag_area_2_usata != '\0') {
          return;
        }
        flag_area_2_usata = '\x02';
        area_menu_selezionata = 2;
        puVar5 = &DAT_00012129;
        puVar3 = &DAT_0001212b;
        codice_risorsa_audio_corrente = 0x34;
      }
      else if (qualita_esibizione_band < 0xa0) {
        if (flag_area_3_usata != '\0') {
          return;
        }
        flag_area_3_usata = '\x03';
        area_menu_selezionata = 3;
        puVar5 = &DAT_0001212d;
        puVar3 = &DAT_0001212f;
        codice_risorsa_audio_corrente = 0x35;
      }
      else if (qualita_esibizione_band < 0xfa) {
        if (flag_area_4_usata != '\0') {
          return;
        }
        flag_area_4_usata = '\x04';
        area_menu_selezionata = 4;
        puVar5 = &DAT_00012131;
        puVar3 = &DAT_00012133;
        codice_risorsa_audio_corrente = 0x36;
      }
      else {
        if (flag_area_5_usata != '\0') {
          return;
        }
        flag_area_5_usata = '\x05';
        area_menu_selezionata = 5;
        puVar5 = &DAT_00012135;
        puVar3 = &DAT_00012137;
        codice_risorsa_audio_corrente = 0x37;
      }
      uVar1 = 0x14;
    }
    sVar2 = 1;
    puVar4 = &buffer_temporaneo_2byte;
    do {
      *puVar4 = *puVar5;
      sVar2 = sVar2 + -1;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (sVar2 != -1);
    sVar2 = 1;
    puVar5 = &valore_bcd_tabella1;
    do {
      *puVar5 = *puVar3;
      sVar2 = sVar2 + -1;
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + 1;
    } while (sVar2 != -1);
    inizializza_schermo_audio_e_renderizza(uVar1);
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    flag_abilitazione_schermo = 0;
    area_menu_selezionata = 0;
    inizializza_schermo_principale_completo();
    pausa_messaggio();
    pausa_messaggio();
    aggiorna_schermo_base_grafica();
    return;
  }
  return;
}


/* $0915c incrementa_valore_128ce: Incrementa la variabile 128ce fino a 10 volte se diversa da 255. */

/* Incrementa la variabile 128ce fino a 10 volte se diversa da 255. */

void incrementa_valore_128ce(void)

{
  short sVar1;
  
  sVar1 = 9;
  do {
    if (qualita_esibizione_band == -1) {
      return;
    }
    qualita_esibizione_band = qualita_esibizione_band + '\x01';
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $09174 decrementa_valore_128ce: Decrementa la variabile 128ce fino a 10 volte fermandosi se arriva a 1. */

/* Decrementa la variabile 128ce fino a 10 volte fermandosi se arriva a 1. */

void decrementa_valore_128ce(void)

{
  short sVar1;
  
  sVar1 = 9;
  do {
    if (qualita_esibizione_band == '\x01') {
      return;
    }
    qualita_esibizione_band = qualita_esibizione_band + -1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0918c incrementa_valore_128cd: Incrementa la variabile 128cd fino a 10 volte se diversa da 255. */

/* Incrementa la variabile 128cd fino a 10 volte se diversa da 255. */

void incrementa_valore_128cd(void)

{
  short sVar1;
  
  sVar1 = 9;
  do {
    if (pubblico_band == -1) {
      return;
    }
    pubblico_band = pubblico_band + '\x01';
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $091bc incrementa_livello_129c3: Incrementa la variabile 129c3 fino a un valore massimo di 15. */

/* Incrementa la variabile 129c3 fino a un valore massimo di 15. */

void incrementa_livello_129c3(void)

{
  if (livello_selezionato_129c3 != '\x0f') {
    livello_selezionato_129c3 = livello_selezionato_129c3 + '\x01';
  }
  return;
}


/* $091ce decrementa_livello_129c3: Decrementa la variabile 129c3 fino a un valore minimo di 0. */

/* Decrementa la variabile 129c3 fino a un valore minimo di 0. */

void decrementa_livello_129c3(void)

{
  if (livello_selezionato_129c3 != '\0') {
    livello_selezionato_129c3 = livello_selezionato_129c3 + -1;
  }
  return;
}


/* $091e0 esegui_ciclo_concerti_registrazioni: Esegue 6 turni di concerti/registrazioni: inizializza schermo, gestisce soldi BCD, input, audio e aggiorna stato gioco per ogni turno */

/* Esegue 6 turni di concerti/registrazioni: inizializza schermo, gestisce soldi BCD, input, audio e
   aggiorna stato gioco per ogni turno */

void esegui_ciclo_concerti_registrazioni(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  uVar2 = 6;
  azzera_buffer_8_byte();
  somma_bcd_ripetuta();
  sottrai_soldi_gestisci_underflow();
  if (flag_saldo_negativo != '\0') {
    return;
  }
  attendi_input_gioco_con_timeout_59_frame();
  attiva_stato_audio();
  uVar3 = uVar2;
  while( true ) {
    cVar1 = (char)uVar2;
    inizializza_schermo_principale_completo(uVar2,uVar3);
    incrementa_valore_128cd();
    decrementa_livello_129c3();
    gestisci_input_e_carica_rock();
    gestisci_eventi_audio_slot_band();
    if (flag_saldo_negativo != '\0') break;
    aggiorna_stato_ciclo_gioco_principale();
    if ((((flag_saldo_negativo != '\0') || (flag_sequenza_completata != '\0')) ||
        (flag_slot_4_attivo != '\0')) || (tipo_controllo == '\0')) break;
    uVar2 = (uint)(byte)(cVar1 - 1U);
    if ((byte)(cVar1 - 1U) == 0) {
      resetta_stato_audio();
      attendi_input_gioco_con_timeout_59_frame();
      return;
    }
  }
  resetta_stato_audio();
  return;
}


/* $092ce avvia_sequenza_intro_completa: Esegue sequenza intro completa: reset audio, 3 inizializzazioni schermo, 2 sequenze audio-testo, attesa fuoco */

/* Esegue sequenza intro completa: reset audio, 3 inizializzazioni schermo, 2 sequenze audio-testo,
   attesa fuoco */

void avvia_sequenza_intro_completa(void)

{
  resetta_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  inizializza_schermo_principale_completo();
  aggiorna_riquadro_menu_con_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $092f6 inizializza_schermo_e_attendi_fuoco: Inizializza schermo gioco, attende pressione fuoco, renderizza scena iniziale */

/* Inizializza schermo gioco, attende pressione fuoco, renderizza scena iniziale */

void inizializza_schermo_e_attendi_fuoco(void)

{
  inizializza_schermo_principale_completo();
  aggiorna_riquadro_menu_con_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $0931e avvia_sequenza_intro_senza_audio_iniziale: Esegue sequenza intro senza attivazione audio iniziale: reset audio, 3 schermi, 2 audio-testo, attesa fuoco */

/* Esegue sequenza intro senza attivazione audio iniziale: reset audio, 3 schermi, 2 audio-testo,
   attesa fuoco */

void avvia_sequenza_intro_senza_audio_iniziale(void)

{
  resetta_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  inizializza_schermo_principale_completo();
  aggiorna_riquadro_menu_con_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $0932e inizializza_schermata_e_audio: Resetta lo stato audio, aggiorna gli elementi grafici e carica le immagini di sfondo nel buffer video. */

/* Resetta lo stato audio, aggiorna gli elementi grafici e carica le immagini di sfondo nel buffer
   video. */

void inizializza_schermata_e_audio(void)

{
  resetta_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  inizializza_schermo_principale_completo();
  aggiorna_riquadro_menu_con_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $09338 avvia_sequenza_intro_con_audio_iniziale: Esegue sequenza intro con attivazione audio iniziale: attiva audio, reset, 3 schermi, 2 audio-testo, attesa fuoco */

/* Esegue sequenza intro con attivazione audio iniziale: attiva audio, reset, 3 schermi, 2
   audio-testo, attesa fuoco */

void avvia_sequenza_intro_con_audio_iniziale(void)

{
  resetta_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  inizializza_schermo_principale_completo();
  aggiorna_riquadro_menu_con_grafica();
  attendi_pressione_fuoco();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $09356 gestisci_transizione_testo_modale: Se modalita testo attiva, esegue transizione con fade, audio lungo e ricarica schermo completo */

/* Se modalita testo attiva, esegue transizione con fade, audio lungo e ricarica schermo completo */

void gestisci_transizione_testo_modale(void)

{
  if ((flag_modalita_testo != '\0') &&
     (contatore_modalita_testo = contatore_modalita_testo + -1, contatore_modalita_testo == '\0')) {
    attendi_input_gioco_con_timeout_59_frame();
    schermata_testo_con_transizione_e_timer();
    flag_disabilita_sfondo = 0;
    stato_font_corrente = 1;
    avvia_sequenza_audio_testo_lungo();
    aggiorna_maschera_128ce();
    sfonda_colori_e_pulisci_schermo();
    renderizza_schermo_completo_con_colori();
  }
  return;
}


/* $093b4 aggiorna_maschera_128ce: Esegue uno scorrimento a destra di 128ce e imposta il bit meno significativo. */

/* Esegue uno scorrimento a destra di 128ce e imposta il bit meno significativo. */

void aggiorna_maschera_128ce(void)

{
  qualita_esibizione_band = qualita_esibizione_band >> 1 | 1;
  return;
}


/* $093c8 aggiorna_ciclo_principale_gioco: Ciclo principale di gioco: ogni 16 frame gestisce acquisti modalita testo, avvio partita alto livello, classifiche e transizioni testo modale */

/* Ciclo principale di gioco: ogni 16 frame gestisce acquisti modalita testo, avvio partita alto
   livello, classifiche e transizioni testo modale */

void aggiorna_ciclo_principale_gioco(void)

{
  if ((((flag_saldo_negativo == '\0') && (tipo_controllo != '\0')) &&
      (flag_sequenza_completata == '\0')) && (flag_slot_4_attivo == '\0')) {
    processa_acquisto_testo_soldi();
    contatore_cicli_principale = contatore_cicli_principale - 1 & 0xf;
    if (contatore_cicli_principale == 0) {
      contatore_cicli_principale = 0xc;
      avvia_partita_livello_avanzato();
    }
    else if (contatore_cicli_principale == 3) {
      gestisci_classifica_punteggi_attiva();
    }
    gestisci_transizione_testo_modale();
  }
  return;
}


/* $09440 ciclo_principale_gioco: Loop principale di gioco: gestisce menu, record tesi, interfaccia e transizioni schermo */

/* WARNING: Removing unreachable block (ram,0x0000958a) */
/* WARNING: Removing unreachable block (ram,0x000096a4) */
/* WARNING: Removing unreachable block (ram,0x000096ae) */
/* WARNING: Removing unreachable block (ram,0x000096b8) */
/* WARNING: Removing unreachable block (ram,0x000096c8) */
/* WARNING: Removing unreachable block (ram,0x000095bc) */
/* WARNING: Removing unreachable block (ram,0x000095c2) */
/* WARNING: Removing unreachable block (ram,0x000095ce) */
/* WARNING: Removing unreachable block (ram,0x000095d4) */
/* WARNING: Removing unreachable block (ram,0x000095e6) */
/* WARNING: Removing unreachable block (ram,0x000095e8) */
/* WARNING: Removing unreachable block (ram,0x000095f2) */
/* WARNING: Removing unreachable block (ram,0x000095fe) */
/* WARNING: Removing unreachable block (ram,0x00009604) */
/* WARNING: Removing unreachable block (ram,0x0000964e) */
/* WARNING: Removing unreachable block (ram,0x00009650) */
/* WARNING: Removing unreachable block (ram,0x0000965a) */
/* WARNING: Removing unreachable block (ram,0x00009664) */
/* WARNING: Removing unreachable block (ram,0x0000966a) */
/* WARNING: Removing unreachable block (ram,0x00009682) */
/* WARNING: Removing unreachable block (ram,0x00009552) */
/* WARNING: Removing unreachable block (ram,0x0000955c) */
/* WARNING: Removing unreachable block (ram,0x0000956c) */
/* Loop principale di gioco: gestisce menu, record tesi, interfaccia e transizioni schermo */

void ciclo_principale_gioco(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  contatore_cicli_ritardo = 3;
  flag_stato_audio = 0;
  flag_inizializzazione_schermo = 0;
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  tipo_controllo = 0x73;
  tipo_controllo_predefinito = 0x73;
  flag_controllo_secondario = 0;
  flag_tipo_controllo_1 = 1;
  inizializza_schermo_principale_completo();
  do {
    while( true ) {
      do {
        renderizza_interfaccia_gioco_completa();
        carica_record_tabella_tesi();
      } while ((flag_dati_record & 0x7f) != 0x55);
      indice_elemento_corrente = indice_elemento_tabella;
      trova_elemento_e_imposta_finestra();
      indice_elemento_corrente = 0;
      flag_stato_menu = 0;
      disegna_grafica_mascherata();
      sVar1 = 0x12;
      puVar2 = &buffer_destinazione_copia;
      puVar3 = &buffer_record_30_byte;
      do {
        *puVar2 = *puVar3;
        sVar1 = sVar1 + -1;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (sVar1 != -1);
      azzera_tre_buffer_8_byte();
      sVar1 = 3;
      puVar2 = &buffer_temporaneo_2byte;
      puVar3 = &buffer_sorgente_copia;
      do {
        *puVar2 = *puVar3;
        sVar1 = sVar1 + -1;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (sVar1 != -1);
      inizializza_schermo_principale_completo();
      menu_attendi_scelta();
      inizializza_schermo_principale_completo();
      flag_modalita_schermo = 1;
      if (indice_elemento_tabella != '\0') break;
      indice_elemento_tabella = '3';
    }
    indice_elemento_tabella = indice_elemento_tabella + -1;
  } while( true );
}


/* $096cc carica_record_tabella_tesi: Copia un elemento di 30 byte dalla tabella tesi nel buffer di lavoro 1283e. */

/* Copia un elemento di 30 byte dalla tabella tesi nel buffer di lavoro 1283e. */

void carica_record_tabella_tesi(void)

{
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &tabella_tesi_fine;
  for (cVar1 = indice_elemento_tabella; cVar1 != '\0'; cVar1 = cVar1 + -1) {
    puVar4 = puVar4 + 0x1e;
  }
  sVar2 = 0x1d;
  puVar3 = &buffer_record_30_byte;
  do {
    *puVar3 = *puVar4;
    sVar2 = sVar2 + -1;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (sVar2 != -1);
  return;
}


/* $096fe resetta_configurazione_input: Copia l'impostazione dei controlli da 129c5 a 129c4 e ripristina i blocchi di memoria associati. */

/* Copia l'impostazione dei controlli da 129c5 a 129c4 e ripristina i blocchi di memoria associati.
    */

void resetta_configurazione_input(void)

{
  riempi_memoria_byte_d6();
  tipo_controllo = tipo_controllo_predefinito;
  azzera_memoria_d4_byte();
  return;
}


/* $0972a inizializza_stato_gioco_default: Copia valori predefiniti in variabili stato gioco e aggiorna interfaccia */

/* Copia valori predefiniti in variabili stato gioco e aggiorna interfaccia */

void inizializza_stato_gioco_default(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  sVar1 = 3;
  puVar2 = &variabili_stato_gioco_1;
  puVar3 = &valori_predefiniti_1;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  sVar1 = 3;
  puVar2 = &variabili_stato_gioco_2;
  puVar3 = &valori_predefiniti_2;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  sVar1 = 3;
  puVar2 = &array_contatori_4_byte;
  puVar3 = &valori_predefiniti_contatori;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  tipo_controllo = tipo_controllo_predefinito;
  renderizza_interfaccia_gioco_completa();
  return;
}


/* $0977a gestisci_turno_giocatore_acquisto: Gestisce turno giocatore: input menu, transazioni BCD soldi, verifica saldo e aggiorna stato */

/* Gestisce turno giocatore: input menu, transazioni BCD soldi, verifica saldo e aggiorna stato */

void gestisci_turno_giocatore_acquisto(void)

{
  char cVar1;
  
  if (tipo_controllo == '\x01') {
    mappatura_controlli_attiva = 0x73;
  }
  else {
    mappatura_controlli_attiva = 0x87;
  }
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  azzera_tre_buffer_8_byte();
  (&buffer_bcd_destinazione)[(byte)(&tabella_indirizzi_bcd_dest)[(uint)indirizzo_tabella_dati * 2]]
       = (&tabella_valori_bcd_sorgente)[(uint)indirizzo_tabella_dati * 2];
  somma_bcd_ripetuta();
  attendi_input_gioco_con_timeout_59_frame();
  cVar1 = '\f' - indirizzo_tabella_dati;
  do {
    incrementa_contatori_129b7();
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  verifica_e_aggiorna_saldo_soldi();
  aggiorna_stato_ciclo_gioco_principale();
  return;
}


/* $09832 calcola_aggiorna_soldi: Gestisce calcoli BCD per aggiornamento soldi con buffer temporanei e ritardo */

/* Gestisce calcoli BCD per aggiornamento soldi con buffer temporanei e ritardo */

void calcola_aggiorna_soldi(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  azzera_tre_buffer_8_byte();
  valore_bcd_tabella1 = (&DAT_00012161)[indice_tabella_bcd];
  somma_bcd_ripetuta();
  sVar1 = 7;
  puVar2 = &buffer_bcd_destinazione;
  puVar4 = &buffer_bcd_sorgente;
  do {
    puVar3 = puVar4 + 1;
    *puVar2 = *puVar4;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar4 = puVar3;
  } while (sVar1 != -1);
  pausa_ciclo_12895();
  sottrazione_bcd_8_cifre();
  if (riporto_sottrazione_bcd == '\0') {
    sVar1 = 7;
    puVar2 = &buffer_bcd_sorgente;
    do {
      *puVar2 = *puVar3;
      sVar1 = sVar1 + -1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (sVar1 != -1);
  }
  azzera_buffer_8_byte();
  valore_bcd_tabella1 = (&DAT_00012166)[(byte)(indice_tabella_bcd * '\x02')];
  valore_bcd_tabella2 = (&DAT_00012167)[(byte)(indice_tabella_bcd * '\x02')];
  somma_bcd_ripetuta();
  return;
}


/* $09910 pausa_ciclo_12895: Esegue un ciclo di ritardo in base al valore della variabile 12895. */

/* Esegue un ciclo di ritardo in base al valore della variabile 12895. */

void pausa_ciclo_12895(void)

{
  char cVar1;
  
  for (cVar1 = contatore_ritardo_12895; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  return;
}


/* $09934 attesa_temporizzata_12895: Esegue un attesa a vuoto decrementando la variabile 12895 fino a zero. */

/* Esegue un attesa a vuoto decrementando la variabile 12895 fino a zero. */

void attesa_temporizzata_12895(void)

{
  char cVar1;
  
  for (cVar1 = contatore_ritardo_12895; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  return;
}


/* $0993c attendi_rilascio_pulsante_mouse: Attende il rilascio dei pulsanti del mouse e aggiorna lo stato degli input. */

/* Attende il rilascio dei pulsanti del mouse e aggiorna lo stato degli input. */

void attendi_rilascio_pulsante_mouse(void)

{
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  flag_stato_mouse_sinistro = 1;
  aggiorna_riquadro_menu_con_grafica();
  flag_stato_mouse_destro = 1;
  ciclo_principale_menu_joystick();
  return;
}


/* $09944 menu_attendi_scelta: aspetta il rilascio del fuoco e la fine della pausa, poi gestisce il menu; restituisce la scelta in d6 */

/* aspetta il rilascio del fuoco e la fine della pausa, poi gestisce il menu; restituisce la scelta
   in d6 */

void menu_attendi_scelta(void)

{
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  flag_stato_mouse_sinistro = 1;
  aggiorna_riquadro_menu_con_grafica();
  flag_stato_mouse_destro = 1;
  ciclo_principale_menu_joystick();
  return;
}


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


/* $09bda aggiorna_interfaccia_e_grafica_base_2: Aggiorna interfaccia completa e copia grafica base (707c6) nel buffer video */

/* Aggiorna interfaccia completa e copia grafica base (707c6) nel buffer video */

void aggiorna_interfaccia_e_grafica_base_2(void)

{
  renderizza_interfaccia_gioco_completa();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $09be4 inizializza_seleziona_font: Configura sequenza di selezione font ripetuta con parametri variabili, alterna flag di stato e chiama selezione glifi */

/* Configura sequenza di selezione font ripetuta con parametri variabili, alterna flag di stato e
   chiama selezione glifi */

void inizializza_seleziona_font(void)

{
  char cVar1;
  short sVar2;
  
  stato_font_corrente = 0;
  for (cVar1 = contatore_font_primario; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  sVar2 = 0x141a;
  seleziona_font_ripetuto(0x141a);
  flag_selezione_font = 1;
  seleziona_font(sVar2 + 0x100);
  seleziona_font();
  flag_selezione_font = 0;
  for (cVar1 = contatore_font_secondario; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  seleziona_font_ripetuto();
  stato_font_corrente = 1;
  return;
}


/* $09c92 aggiorna_stato_ciclo_gioco_principale: Gestisce contatori font e sequenze audio; allo step 4 processa soldi BCD e messaggi, allo step 6 avvia gestione fine turno e classifiche */

/* Gestisce contatori font e sequenze audio; allo step 4 processa soldi BCD e messaggi, allo step 6
   avvia gestione fine turno e classifiche */

void aggiorna_stato_ciclo_gioco_principale(void)

{
  undefined1 uVar1;
  short sVar2;
  char cVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  if ((((flag_saldo_negativo == '\0') && (tipo_controllo != '\0')) && (flag_slot_4_attivo == '\0'))
     && (flag_sequenza_completata == '\0')) {
    contatore_font_primario = contatore_font_primario + '\x01';
    if (contatore_font_primario == '\a') {
      contatore_font_primario = '\0';
    }
    if ((indice_sequenza_audio == (&tabella_sequenze_audio)[(byte)(contatore_font_secondario << 1)])
       && (flag_audio_attivo ==
           *(char *)((int)&PTR_DAT_000120cb + (uint)(byte)(contatore_font_secondario << 1)))) {
      contatore_font_secondario = contatore_font_secondario + '\x01';
      if (contatore_font_secondario == '\f') {
        flag_sequenza_completata = 1;
        return;
      }
      indice_sequenza_audio = '\0';
      flag_audio_attivo = '\x01';
    }
    else {
      flag_audio_attivo = flag_audio_attivo + '\x01';
      if (flag_audio_attivo == '\n') {
        flag_audio_attivo = '\0';
        indice_sequenza_audio = indice_sequenza_audio + '\x01';
      }
    }
    aggiorna_interfaccia_e_grafica_base_2();
    uVar1 = flag_stato_audio;
    if (contatore_font_primario == '\x04') {
      resetta_stato_audio();
      inizializza_schermo_principale_completo();
      azzera_buffer_8_byte();
      puVar5 = &dati_calcolo_soldi_turno;
      cVar3 = tipo_controllo;
      do {
        azzera_tre_buffer_8_byte();
        sVar2 = 3;
        puVar4 = &buffer_temporaneo_2byte;
        puVar6 = puVar5;
        do {
          *puVar4 = *puVar6;
          sVar2 = sVar2 + -1;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
        } while (sVar2 != -1);
        somma_bcd_8_cifre();
        puVar5 = puVar5 + 4;
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
      sottrai_soldi_gestisci_underflow();
      pausa_messaggio();
      flag_stato_audio = uVar1;
      routine_vuota();
    }
    else if (contatore_font_primario == '\x06') {
      processa_eventi_fine_turno_classifiche();
      routine_vuota();
      return;
    }
    return;
  }
  stato_font_corrente = 1;
  return;
}


/* $09dfa aggiorna_contatori_fine_turno: Calcola valori da contatori scorrimento, aggiorna indicatori membri band, esegue somme BCD */

/* Calcola valori da contatori scorrimento, aggiorna indicatori membri band, esegue somme BCD */

void aggiorna_contatori_fine_turno(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  cVar1 = '\0';
  valore_cursore_x_salvato = '\0';
  if (((sotto_contatore_scorrimento < 0xb) && (sotto_contatore_scorrimento != 0)) &&
     (cVar1 = '\f' - sotto_contatore_scorrimento, valore_cursore_x_salvato = cVar1,
     flag_scrolling_attivo == '\0')) {
    valore_cursore_x_salvato = cVar1 * '\x02';
  }
  if ((contatore_scorrimento_buffer < 0xb) && (contatore_scorrimento_buffer != 0)) {
    cVar1 = cVar1 + ('\f' - contatore_scorrimento_buffer);
    valore_cursore_x_salvato = ('\f' - contatore_scorrimento_buffer) + valore_cursore_x_salvato;
  }
  (&array_indicatori_grafici)[indice_array_indicatori] = cVar1 + '\x01';
  indice_array_indicatori = indice_array_indicatori + 1;
  cancella_indicatori_schermo();
  azzera_tre_buffer_8_byte();
  if (valore_cursore_x_salvato != '\0') {
    DAT_0001287a = 1;
    valore_bcd_tabella1 = 2;
    somma_bcd_ripetuta();
    azzera_buffer_8_byte();
    somma_bcd_ripetuta();
    somma_bcd_8_cifre();
    aggiorna_interfaccia_e_grafica_base();
  }
  if ((sotto_contatore_scorrimento != 0) && (sotto_contatore_scorrimento < 10)) {
    accumulaore_scorrimento = ('\n' - sotto_contatore_scorrimento) + accumulaore_scorrimento;
    if (accumulaore_scorrimento < 0xf6) {
      if (accumulaore_scorrimento < 0xa7) {
        if (accumulaore_scorrimento < 0x61) {
          if (accumulaore_scorrimento < 0x26) {
            return;
          }
          puVar2 = &flag_slot_attivi;
        }
        else {
          puVar2 = &flag_slot_2_attivo;
        }
      }
      else {
        puVar2 = &flag_slot_3_attivo;
      }
    }
    else {
      puVar2 = &flag_slot_4_attivo;
    }
    *puVar2 = 1;
  }
  return;
}


/* $09fa4 ciclo_input_menu_nuova_partita: Gestisce timer, input mouse, caricamento risorse, stringhe FF e validazione menu in loop */

/* WARNING: Removing unreachable block (ram,0x00009fdc) */
/* WARNING: Removing unreachable block (ram,0x0000a008) */
/* WARNING: Removing unreachable block (ram,0x00009fea) */
/* Gestisce timer, input mouse, caricamento risorse, stringhe FF e validazione menu in loop */

void ciclo_input_menu_nuova_partita(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  uVar2 = (uint)indice_sequenza_corrente;
  gestisci_input_e_carica_rock();
  if ((char)uVar2 != '\0') {
    gestisci_timer_attesa_ciclica(uVar2);
  }
  do {
    gestisci_timer_attesa_ciclica(uVar2);
  } while (flag_attesa_timer_completata != '\0');
  flag_attesa_timer_completata = 1;
  cVar1 = '\x10';
  pcVar3 = "";
  do {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != -1);
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  pausa_ciclo_d6(pcVar3);
  *pcVar3 = '\x01';
  copia_e_processa_stringhe_ff();
  cVar1 = indice_sequenza_corrente + 1;
  stato_sequenza_1 = cVar1;
  stato_sequenza_2 = cVar1;
  inizializza_schermo_principale_completo();
  attendi_rilascio_pulsante_mouse();
  if (cVar1 != '\0') {
    inizializza_schermo_principale_completo();
    pausa_ciclo_d6();
    pcVar4[2] = '\0';
    gestisci_input_testo_menu_validato();
  }
  indice_sequenza_corrente = indice_sequenza_corrente + 1;
  return;
}


/* $0a0cc pausa_ciclo_d6: Esegue un breve ciclo di ritardo decrementando il registro D6. */

/* Esegue un breve ciclo di ritardo decrementando il registro D6. */

void pausa_ciclo_d6(void)

{
  char unaff_D6b;
  
  for (; unaff_D6b != '\0'; unaff_D6b = unaff_D6b + -1) {
  }
  return;
}


/* $0a0ea avvia_nuova_partita_da_menu: Avvia nuova partita dal menu: inizializza schermo, attende scelta, processa acquisto, esegue loop render/input/audio fino a fine partita */

/* Avvia nuova partita dal menu: inizializza schermo, attende scelta, processa acquisto, esegue loop
   render/input/audio fino a fine partita */

void avvia_nuova_partita_da_menu(void)

{
  char cVar1;
  
  indice_sequenza_corrente = '\0';
  riempi_memoria_byte_d6();
  flag_schermo_inizializzato = 1;
  flag_audio_attivo = 1;
  inizializza_schermo_principale_completo();
  menu_attendi_scelta();
  azzera_buffer_8_byte();
  if (indirizzo_tabella_dati != 6) {
    pubblico_band_salvato = pubblico_band;
    contatore_cicli_gioco = (&tabella_indirizzi_dati)[indirizzo_tabella_dati];
    dato_tabella_indice_basso = (&tabella_byte_basso)[(byte)(indirizzo_tabella_dati << 1)];
    dato_tabella_indice_alto = (&tabella_byte_alto)[(byte)(indirizzo_tabella_dati << 1)];
    sottrai_soldi_gestisci_underflow();
    aggiorna_stato_ciclo_gioco_principale();
    if ((flag_saldo_negativo == '\0') && (flag_sequenza_completata == '\0')) {
      sfonda_colori_e_pulisci_schermo();
      contatore_cicli_ritardo = 4;
      renderizza_schermo_completo_con_colori();
      attendi_input_gioco_con_timeout_59_frame();
      cVar1 = contatore_cicli_gioco;
      do {
        do {
          aggiorna_stato_ciclo_gioco_principale();
          if ((flag_saldo_negativo != '\0') || (flag_sequenza_completata != '\0')) goto l_0a234;
          cVar1 = cVar1 + -1;
        } while (cVar1 != '\0');
        inizializza_schermo_principale_completo();
        ciclo_input_menu_nuova_partita();
        cVar1 = contatore_cicli_gioco;
      } while (indice_sequenza_corrente != '\n');
      decrementa_livello_129c3();
      decrementa_livello_129c3();
      incrementa_valore_128cd();
      incrementa_valore_128cd();
      flag_sequenza_audio = 1;
      attendi_input_gioco_con_timeout_59_frame();
      esegue_sequenza_avvio_partita();
    }
  }
l_0a234:
  contatore_cicli_ritardo = 1;
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  return;
}


/* $0a248 gestisci_eventi_audio_slot_band: Gestisce eventi audio per slot musicisti: verifica slot attivi, soldi BCD e flag stato per attivare timer, menu ritorno o sequenza audio flag2 */

/* WARNING: Removing unreachable block (ram,0x0000a288) */
/* WARNING: Removing unreachable block (ram,0x0000a296) */
/* Gestisce eventi audio per slot musicisti: verifica slot attivi, soldi BCD e flag stato per
   attivare timer, menu ritorno o sequenza audio flag2 */

void gestisci_eventi_audio_slot_band(void)

{
  if ((flag_slot_attivi != '\0') && ((buffer_bcd_soldi != '\0' || (soldi_cifra_milioni != '\0')))) {
    if ((flag_stato_gioco & 1) == 0) {
      gestisci_timer_attesa_ciclica();
    }
    if (((flag_stato_gioco & 2) != 0) ||
       (gestisci_timer_attesa_ciclica(), flag_slot_3_attivo == '\0')) {
      if ((flag_stato_gioco & 4) == 0) {
        gestisci_ritorno_menu_audio();
      }
      return;
    }
    gestisci_evento_audio_flag_2();
  }
  return;
}


/* $0a2e0 gestisci_evento_audio_con_addebito: Gestisce evento audio con addebito BCD: schermi, audio, addebito, pausa, ripristina grafica */

/* Gestisce evento audio con addebito BCD: schermi, audio, addebito, pausa, ripristina grafica */

void gestisci_evento_audio_con_addebito(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 1;
  flag_stato_audio = 0;
  inizializza_schermo_audio_e_renderizza();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_buffer_ausiliario();
  addebita_somma_con_underflow();
  pausa_messaggio();
  flag_stato_audio = uVar1;
  aggiorna_schermo_base_grafica();
  return;
}


/* $0a324 gestisci_evento_audio_flag_2: Gestisce evento audio flag 2: schermi, audio, addebito BCD, pausa, ripristina grafica */

/* Gestisce evento audio flag 2: schermi, audio, addebito BCD, pausa, ripristina grafica */

void gestisci_evento_audio_flag_2(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 2;
  flag_stato_audio = 0;
  inizializza_schermo_audio_e_renderizza();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_buffer_ausiliario();
  addebita_somma_con_underflow();
  pausa_messaggio();
  flag_stato_audio = uVar1;
  aggiorna_schermo_base_grafica();
  return;
}


/* $0a346 gestisci_ritorno_menu_audio: Salva stato audio, gestisce menu principale e ripristina audio per ritorno da slot band */

/* Salva stato audio, gestisce menu principale e ripristina audio per ritorno da slot band */

void gestisci_ritorno_menu_audio(void)

{
  undefined1 uVar1;
  
  uVar1 = flag_stato_audio;
  flag_stato_gioco = flag_stato_gioco | 4;
  resetta_stato_audio();
  attendi_input_gioco_con_timeout_59_frame();
  gestisci_menu_principale_soldi();
  flag_stato_audio = uVar1;
  routine_vuota();
  return;
}


/* $0a396 visualizza_menu_formattato_joystick: Renderizza menu con testo formattato multiplo, input joystick e transizioni schermo */

/* WARNING: Removing unreachable block (ram,0x0000a3b4) */
/* WARNING: Removing unreachable block (ram,0x0000a46a) */
/* WARNING: Removing unreachable block (ram,0x0000a496) */
/* WARNING: Removing unreachable block (ram,0x0000a4a0) */
/* WARNING: Removing unreachable block (ram,0x0000a4aa) */
/* WARNING: Removing unreachable block (ram,0x0000a4b0) */
/* WARNING: Removing unreachable block (ram,0x0000a4d8) */
/* WARNING: Removing unreachable block (ram,0x0000a4e2) */
/* WARNING: Removing unreachable block (ram,0x0000a4ec) */
/* WARNING: Removing unreachable block (ram,0x0000a4f2) */
/* WARNING: Removing unreachable block (ram,0x0000a50e) */
/* WARNING: Removing unreachable block (ram,0x0000a524) */
/* Renderizza menu con testo formattato multiplo, input joystick e transizioni schermo */

void visualizza_menu_formattato_joystick(void)

{
  char cVar1;
  short sVar2;
  
  if ((flag_eventi_classifiche_pending & 0x80) == 0) {
    menu_attendi_scelta();
  }
  inizializza_schermo_principale_completo();
  contatore_righe_testo = 0xc;
  flag_stato_mouse_sinistro = 1;
  aggiorna_riquadro_menu_con_grafica();
  cVar1 = '\r';
  sVar2 = 0x38;
  do {
    processa_e_visualizza_testo_formattato(cVar1,sVar2);
    sVar2 = sVar2 + 1;
    cVar1 = cVar1 + '\x01';
  } while (cVar1 != '\x17');
  ciclo_principale_menu_joystick();
  sommatore_valori_tabella = 0;
  flag_primo_accesso_menu = indirizzo_tabella_dati;
  inizializza_schermo_principale_completo();
  attendi_rilascio_pulsante_mouse();
  decrementa_livello_129c3();
  decrementa_livello_129c3();
  calcola_posizione_cursore_menu();
  flag_eventi_classifiche_pending = flag_eventi_classifiche_pending | 0x40;
  contatore_righe_testo = 0;
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  aggiorna_stato_ciclo_gioco_principale();
  return;
}


/* $0a586 somma_valore_tabella_128ba: Somma alla variabile 128be un valore letto dalla tabella 128ba all'offset A3. */

/* Somma alla variabile 128be un valore letto dalla tabella 128ba all'offset A3. */

void somma_valore_tabella_128ba(void)

{
  int unaff_A3;
  
  sommatore_valori_tabella =
       *(char *)((uint)indirizzo_tabella_dati + unaff_A3) + sommatore_valori_tabella;
  return;
}


/* $0a5a2 esegue_sequenza_avvio_partita: Esegue sequenza inizializzazione schermo/audio per nuova partita in modalita speciale */

/* WARNING: Removing unreachable block (ram,0x0000a60e) */
/* Esegue sequenza inizializzazione schermo/audio per nuova partita in modalita speciale */

void esegue_sequenza_avvio_partita(void)

{
  if ((soldi_cifra_milioni != '\0') && ((flag_stato_gioco & 8) == 0)) {
    flag_stato_gioco = flag_stato_gioco | 8;
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    flag_sequenza_audio = 0;
    attendi_input_gioco_con_timeout_59_frame();
    attiva_stato_audio();
    attendi_input_gioco_con_timeout_59_frame();
    flag_stato_audio = 0;
    aggiorna_schermo_base_grafica();
    aggiorna_stato_ciclo_gioco_principale();
  }
  return;
}


/* $0a616 addebita_somma_con_underflow: Azzera il buffer temporaneo, attiva il flag e sottrae una somma in BCD gestendo l'eventuale underflow. */

/* Azzera il buffer temporaneo, attiva il flag e sottrae una somma in BCD gestendo l'eventuale
   underflow. */

void addebita_somma_con_underflow(void)

{
  azzera_buffer_8_byte();
  flag_addebito_soldi = 1;
  sottrai_soldi_gestisci_underflow();
  return;
}


/* $0a630 gestisci_menu_membri_band: Menu gestione 4 slot musicisti: assunzione/licenziamento con costi BCD, stati slot attivi, transizioni schermo e aggiornamento interfaccia */

/* WARNING: Removing unreachable block (ram,0x0000a862) */
/* WARNING: Removing unreachable block (ram,0x0000a7e2) */
/* WARNING: Removing unreachable block (ram,0x0000a7f0) */
/* WARNING: Removing unreachable block (ram,0x0000a84e) */
/* WARNING: Removing unreachable block (ram,0x0000a85a) */
/* WARNING: Removing unreachable block (ram,0x0000a7dc) */
/* Menu gestione 4 slot musicisti: assunzione/licenziamento con costi BCD, stati slot attivi,
   transizioni schermo e aggiornamento interfaccia */

void gestisci_menu_membri_band(void)

{
  char cVar1;
  byte bVar2;
  byte unaff_D6b;
  uint uVar3;
  
  trova_minimo_array_4_elementi();
  indice_elemento_attivo = indice_elemento_selezionato;
  indice_elemento_attivo_salvato = indice_elemento_selezionato;
  if (8 < unaff_D6b) {
    decrementa_contatori_129b7();
    contatore_ritardo_cicli = 0;
    gestisci_timer_attesa_ciclica();
    return;
  }
  azzera_tre_buffer_8_byte();
  gestisci_timer_attesa_ciclica();
  bVar2 = indice_elemento_selezionato;
  buffer_temporaneo_2byte = 9;
  if (unaff_D6b < 4) {
    gestisci_timer_attesa_ciclica();
    contatore_ritardo_cicli = 0;
    uVar3 = (uint)indice_elemento_selezionato;
    cVar1 = indice_elemento_selezionato + 0x48;
    indirizzo_testo_slot2 = cVar1;
    indirizzo_testo_condiviso = cVar1;
    if (flag_slot_2_attivo == '\0') {
      inizializza_schermo_principale_completo();
      attendi_rilascio_pulsante_mouse();
      if (cVar1 == '\0') {
        verifica_e_aggiorna_saldo_soldi();
        decrementa_contatori_129b7();
        (&array_valori_slot)[uVar3] = 0x14;
        return;
      }
      goto l_0a78a;
    }
  }
  else {
    contatore_ritardo_cicli = 0;
    uVar3 = (uint)indice_elemento_selezionato;
    cVar1 = indice_elemento_selezionato + 0x48;
    indirizzo_testo_slot3 = cVar1;
    indirizzo_testo_condiviso = cVar1;
    if (flag_slot_3_attivo == '\0') {
      inizializza_schermo_principale_completo();
      attendi_rilascio_pulsante_mouse();
      if (cVar1 == '\0') {
        verifica_e_aggiorna_saldo_soldi();
        decrementa_contatori_129b7();
        (&array_valori_slot)[bVar2] = 0xf;
        return;
      }
      attiva_stato_audio();
      attendi_input_gioco_con_timeout_59_frame();
      (&array_contatori_4_byte)[bVar2] = 2;
      return;
    }
  }
  contatore_ritardo_cicli = 0;
  attendi_input_gioco_con_timeout_59_frame();
l_0a78a:
  attiva_stato_audio();
  attendi_input_gioco_con_timeout_59_frame();
  (&array_stato_attivo_4_elementi)[uVar3] = 0x80;
  tipo_controllo = tipo_controllo + -1;
  aggiorna_maschera_128ce();
  routine_vuota();
  disegna_elementi_controllo_mascherati();
  renderizza_schermo_completo_con_colori();
  return;
}


/* $0a870 incrementa_contatori_129b7: Incrementa di 1 i valori non nulli e diversi da 255 nei 4 byte dell'array 129b7. */

/* WARNING: Removing unreachable block (ram,0x0000a89c) */
/* Incrementa di 1 i valori non nulli e diversi da 255 nei 4 byte dell'array 129b7. */

void incrementa_contatori_129b7(void)

{
  short sVar1;
  char *pcVar2;
  char *pcVar3;
  
  sVar1 = 3;
  pcVar2 = &array_contatori_4_byte;
  do {
    pcVar3 = pcVar2;
    if ((*pcVar2 != '\0') && (*pcVar2 != -1)) {
      pcVar3 = pcVar2 + 1;
      *pcVar2 = *pcVar2 + '\x01';
    }
    sVar1 = sVar1 + -1;
    pcVar2 = pcVar3;
  } while (sVar1 != -1);
  return;
}


/* $0a874 decrementa_contatori_129b7: Decrementa di 1 i valori non nulli e diversi da 255 nei 4 byte dell'array 129b7. */

/* WARNING: Removing unreachable block (ram,0x0000a898) */
/* Decrementa di 1 i valori non nulli e diversi da 255 nei 4 byte dell'array 129b7. */

void decrementa_contatori_129b7(void)

{
  short sVar1;
  char *pcVar2;
  char *pcVar3;
  
  sVar1 = 3;
  pcVar2 = &array_contatori_4_byte;
  do {
    pcVar3 = pcVar2;
    if ((*pcVar2 != '\0') && (*pcVar2 != -1)) {
      pcVar3 = pcVar2 + 1;
      *pcVar2 = *pcVar2 + -1;
    }
    sVar1 = sVar1 + -1;
    pcVar2 = pcVar3;
  } while (sVar1 != -1);
  return;
}


/* $0a8a6 trova_minimo_array_4_elementi: Trova l'elemento attivo con valore minimo nell'array 129b7 e ne salva l'indice. */

/* Trova l'elemento attivo con valore minimo nell'array 129b7 e ne salva l'indice. */

void trova_minimo_array_4_elementi(void)

{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = &array_stato_attivo_4_elementi;
  pbVar3 = &array_contatori_4_byte;
  valore_minimo_trovato = 0xff;
  cVar1 = '\0';
  do {
    if (((*pbVar2 & 0x80) == 0) && (*pbVar3 <= valore_minimo_trovato)) {
      valore_minimo_trovato = *pbVar3;
      indice_minimo_trovato = cVar1;
    }
    cVar1 = cVar1 + '\x01';
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
  } while (cVar1 != '\x04');
  indice_elemento_selezionato = indice_minimo_trovato;
  return;
}


/* $0a900 prepara_copia_stringhe_ff: Inizializza buffer destinazione, itera contatore saltando terminatori 0xFF su stringa vuota, poi invoca copia e processamento */

/* Inizializza buffer destinazione, itera contatore saltando terminatori 0xFF su stringa vuota, poi
   invoca copia e processamento */

void prepara_copia_stringhe_ff(void)

{
  char cVar1;
  char unaff_D6b;
  char *pcVar2;
  undefined1 *unaff_A3;
  char *pcVar3;
  
  *unaff_A3 = 1;
  pcVar3 = "";
  do {
    do {
      pcVar2 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar2;
    } while (cVar1 != -1);
    unaff_D6b = unaff_D6b + -1;
  } while (unaff_D6b != '\0');
  copia_e_processa_stringhe_ff();
  return;
}


/* $0a926 elabora_animazioni_timer_30_frame: Elabora 30 frame animazioni con timer CIA, copia stringhe FF, aggiorna buffer ciclico */

/* Elabora 30 frame animazioni con timer CIA, copia stringhe FF, aggiorna buffer ciclico */

void elabora_animazioni_timer_30_frame(void)

{
  char cVar2;
  byte bVar3;
  short sVar1;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  puVar4 = &puntatore_dati_timer;
  puVar6 = &tabella_buffer_schermo;
  cVar2 = '\x1e';
  do {
    gestisci_timer_attesa_ciclica(puVar4,puVar6);
    prepara_copia_stringhe_ff();
    puVar6 = puVar6 + 0x14;
    puVar4 = puVar4 + 3;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  cVar2 = '\x1e';
  do {
    prepara_copia_stringhe_ff();
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  bVar3 = indice_buffer_timer & 7 | 1;
  do {
    aggiorna_animazioni_buffer_ciclico();
    bVar3 = bVar3 - 1;
  } while (bVar3 != 0);
  sVar1 = 9;
  puVar5 = &buffer_destinazione_12442;
  puVar8 = &buffer_sorgente_1201c;
  do {
    puVar7 = puVar8 + 1;
    *puVar5 = *puVar8;
    sVar1 = sVar1 + -1;
    puVar5 = puVar5 + 1;
    puVar8 = puVar7;
  } while (sVar1 != -1);
  sVar1 = 9;
  puVar5 = &buffer_destinazione_12424;
  do {
    *puVar5 = *puVar7;
    sVar1 = sVar1 + -1;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  } while (sVar1 != -1);
  return;
}


/* $0a9a8 carica_buffer_da_1201c: Copia due blocchi di 10 byte dall'indirizzo 1201c nei buffer 12442 e 12424. */

/* Copia due blocchi di 10 byte dall'indirizzo 1201c nei buffer 12442 e 12424. */

void carica_buffer_da_1201c(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  sVar1 = 9;
  puVar2 = &buffer_destinazione_12442;
  puVar4 = &buffer_sorgente_1201c;
  do {
    puVar3 = puVar4 + 1;
    *puVar2 = *puVar4;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar4 = puVar3;
  } while (sVar1 != -1);
  sVar1 = 9;
  puVar2 = &buffer_destinazione_12424;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}


/* $0a9cc renderizza_messaggio_completo: Processa elenco stringhe, disegna sfondo area testo, stampa testo, copia schermo in buffer, imposta colori copper e avvia brano musicale */

/* Processa elenco stringhe, disegna sfondo area testo, stampa testo, copia schermo in buffer,
   imposta colori copper e avvia brano musicale */

void renderizza_messaggio_completo(void)

{
  byte bVar1;
  byte unaff_D4b;
  undefined4 unaff_D6;
  
  valore_minimo_trovato = 0;
  for (bVar1 = unaff_D4b; bVar1 != 0; bVar1 = bVar1 - 1) {
  }
  flag_controllo_secondario = unaff_D4b;
  processa_elenco_stringhe(unaff_D6);
  disegna_sfondo_area_testo();
  stampa_testo();
  copia_schermo_intero_in_buffer
            ((&tabella_buffer_schermo)[flag_controllo_secondario],(uint)flag_controllo_secondario);
  imposta_colori_copper_4();
  avvia_sequenza_musicale_rock5();
  return;
}


/* $0aa52 riempi_blocco_memoria: Invoqua la routine per riempire un blocco di memoria con il valore byte specificato. */

/* Invoqua la routine per riempire un blocco di memoria con il valore byte specificato. */

void riempi_blocco_memoria(void)

{
  riempi_memoria_byte_d6();
  return;
}


/* $0aa78 scorri_elementi_buffer_dati: Shifta a destra gli elementi nei buffer dati in base al flag 1289a e al valore D4. */

/* Shifta a destra gli elementi nei buffer dati in base al flag 1289a e al valore D4. */

void scorri_elementi_buffer_dati(void)

{
  char unaff_D4b;
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (unaff_D4b != '\x01') {
    cVar1 = unaff_D4b + -1;
    if (flag_seleziona_buffer_dati == '\0') {
      puVar4 = &DAT_00012422;
      puVar3 = &puntatore_dati_fade1;
      cVar2 = cVar1;
      do {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar3 = puVar3 + -1;
        cVar2 = cVar2 + -1;
      } while (cVar2 != '\0');
      puVar4 = &DAT_00012418;
      puVar3 = &DAT_00012419;
      do {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar3 = puVar3 + -1;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
    }
    else {
      puVar4 = &DAT_00012440;
      puVar3 = &puntatore_dati_fade2;
      cVar2 = cVar1;
      do {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar3 = puVar3 + -1;
        cVar2 = cVar2 + -1;
      } while (cVar2 != '\0');
      puVar4 = &DAT_00012436;
      puVar3 = &DAT_00012437;
      do {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + -1;
        puVar4 = puVar4 + -1;
        cVar1 = cVar1 + -1;
      } while (cVar1 != '\0');
    }
  }
  return;
}


/* $0ab12 aggiorna_animazioni_buffer_ciclico: Aggiorna 30 animazioni cicliche con doppio buffer e timer CIA per sincronizzazione frame */

/* Aggiorna 30 animazioni cicliche con doppio buffer e timer CIA per sincronizzazione frame */

void aggiorna_animazioni_buffer_ciclico(void)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  riempi_blocco_memoria();
  pbVar3 = &buffer_animazione_principale;
  if (flag_seleziona_buffer_dati != '\0') {
    pbVar3 = &buffer_animazione_secondario;
  }
  cVar2 = '\x1e';
  do {
    if ((*pbVar3 & 0x80) == 0) {
      gestisci_timer_attesa_ciclica();
      pbVar3[1] = pbVar3[1] + 4;
l_0ab80:
      bVar1 = *pbVar3 - 1;
      *pbVar3 = bVar1;
      if (bVar1 == 0) {
        *pbVar3 = pbVar3[3];
        contatore_animazione_ciclica = contatore_animazione_ciclica + 1;
        if (contatore_animazione_ciclica == 6) {
          contatore_animazione_ciclica = 0;
        }
        pbVar3[1] = (&tabella_offset_animazione)[contatore_animazione_ciclica];
        inizializza_buffer_ciclico_timer_cia();
      }
      else if ((bVar1 & 0x3f) == 0) goto l_0ab9e;
    }
    else {
      pbVar4 = pbVar3 + 1;
      gestisci_timer_attesa_ciclica();
      bVar1 = *pbVar4 - 4;
      if ((3 < *pbVar4) && (bVar1 != 0)) {
        *pbVar4 = bVar1;
        goto l_0ab80;
      }
      pbVar3[2] = pbVar3[2] - 1;
      pbVar3 = pbVar4;
l_0ab9e:
      *pbVar3 = pbVar3[4];
    }
    pbVar3 = pbVar3 + 5;
    cVar2 = cVar2 + -1;
    if (cVar2 == '\0') {
      return;
    }
  } while( true );
}


/* $0abfc inizializza_buffer_ciclico_timer_cia: Inizializza puntatori buffer schermo e timer CIA per sincronizzazione frame animazioni cicliche a doppio buffer */

/* Inizializza puntatori buffer schermo e timer CIA per sincronizzazione frame animazioni cicliche a
   doppio buffer */

void inizializza_buffer_ciclico_timer_cia(void)

{
  byte bVar1;
  byte bVar2;
  char unaff_D4b;
  undefined *puVar3;
  undefined *puVar4;
  
  if (flag_seleziona_buffer_dati == '\0') {
    bVar1 = 0x1e - unaff_D4b;
    (&tabella_buffer_schermo)[bVar1] = indice_buffer_timer & 0x1f;
    puVar3 = &tabella_buffer_schermo;
    for (bVar2 = bVar1; bVar2 != 0; bVar2 = bVar2 - 1) {
      puVar3 = puVar3 + 0x14;
    }
    puVar4 = &puntatore_dati_timer;
    for (; bVar1 != 0; bVar1 = bVar1 - 1) {
      puVar4 = puVar4 + 3;
    }
    gestisci_timer_attesa_ciclica(3,puVar4,0,puVar4,puVar3);
    prepara_copia_stringhe_ff();
  }
  return;
}


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


/* $0ad10 mostra_schermata_classifica: Inizializza, disegna e gestisce la visualizzazione della classifica musicale. */

/* Inizializza, disegna e gestisce la visualizzazione della classifica musicale. */

void mostra_schermata_classifica(void)

{
  char cVar1;
  char cVar3;
  short sVar2;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  flag_seleziona_buffer_dati = '\x01';
  sfonda_colori_e_pulisci_schermo();
  larghezza_finestra_caratteri = 0x1a;
  altezza_finestra_caratteri = 0xe;
  disegna_rettangolo_grafico();
  aggiorna_animazioni_buffer_ciclico();
  cVar1 = '\0';
  cVar3 = '\x1e';
  puVar4 = &tabella_classifica_singoli;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &tabella_classifica_album;
  }
  do {
    valore_minimo_trovato = cVar1;
    inserisci_in_classifica(puVar4);
    cVar1 = cVar1 + '\x01';
    puVar4 = puVar4 + 5;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  aggiorna_scorrimento_buffer_dati();
  confronta_sequenza_mastermind();
  esegue_transizione_schermo_con_render();
  gestisci_input_doppio_buffer();
  sVar2 = 9;
  puVar4 = &buffer_destinazione_12424;
  puVar5 = &buffer_sorgente_confronto_1;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &buffer_destinazione_12442;
    puVar5 = &buffer_sorgente_confronto_2;
  }
  do {
    *puVar4 = *puVar5;
    sVar2 = sVar2 + -1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (sVar2 != -1);
  flag_seleziona_buffer_dati = 0;
  return;
}


/* $0ad1a gestisci_classifiche_e_transizione: Gestisce high-score, transizione schermo, input doppio buffer, confronto mastermind */

/* Gestisce high-score, transizione schermo, input doppio buffer, confronto mastermind */

void gestisci_classifiche_e_transizione(void)

{
  char cVar1;
  char cVar3;
  short sVar2;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  sfonda_colori_e_pulisci_schermo();
  larghezza_finestra_caratteri = 0x1a;
  altezza_finestra_caratteri = 0xe;
  disegna_rettangolo_grafico();
  aggiorna_animazioni_buffer_ciclico();
  cVar1 = '\0';
  cVar3 = '\x1e';
  puVar4 = &tabella_classifica_singoli;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &tabella_classifica_album;
  }
  do {
    valore_minimo_trovato = cVar1;
    inserisci_in_classifica(puVar4);
    cVar1 = cVar1 + '\x01';
    puVar4 = puVar4 + 5;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  aggiorna_scorrimento_buffer_dati();
  confronta_sequenza_mastermind();
  esegue_transizione_schermo_con_render();
  gestisci_input_doppio_buffer();
  sVar2 = 9;
  puVar4 = &buffer_destinazione_12424;
  puVar5 = &buffer_sorgente_confronto_1;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &buffer_destinazione_12442;
    puVar5 = &buffer_sorgente_confronto_2;
  }
  do {
    *puVar4 = *puVar5;
    sVar2 = sVar2 + -1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (sVar2 != -1);
  flag_seleziona_buffer_dati = 0;
  return;
}


/* $0ade6 inserisci_in_classifica: Inserisce un valore nella classifica ordinata di 10 elementi se e inferiore ai valori presenti. */

/* Inserisce un valore nella classifica ordinata di 10 elementi se e inferiore ai valori presenti.
    */

void inserisci_in_classifica(void)

{
  char cVar1;
  byte unaff_D6b;
  byte *pbVar2;
  
  cVar1 = '\n';
  pbVar2 = &tabella_classifica_1;
  if (flag_seleziona_buffer_dati != '\0') {
    pbVar2 = &tabella_classifica_2;
  }
  do {
    if (unaff_D6b < *pbVar2) {
      scorri_elementi_buffer_dati();
      *pbVar2 = unaff_D6b;
      pbVar2[10] = valore_minimo_trovato;
      return;
    }
    pbVar2 = pbVar2 + 1;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}


/* $0ae30 ciclo_principale_rendering_gioco: Ciclo rendering principale: disegna caratteri, simboli, testo formattato, copia schermo in buffer, imposta colori copper, gestisce input fuoco */

/* Ciclo rendering principale: disegna caratteri, simboli, testo formattato, copia schermo in
   buffer, imposta colori copper, gestisce input fuoco */

void ciclo_principale_rendering_gioco(void)

{
  char unaff_D4b;
  char unaff_D6b;
  char *unaff_A3;
  undefined1 uVar1;
  
  do {
    flag_alternanza_render = flag_alternanza_render ^ 3;
    contatore_frame_globale = contatore_frame_globale + '\x01';
    disegna_carattere_grafico(unaff_A3,unaff_D4b,unaff_D6b);
    flag_selezione_font = 1;
    disegna_simbolo_grafico();
    flag_selezione_font = 0;
    processa_e_visualizza_testo_formattato();
    leggi_valore_tabella_4byte();
    if (*unaff_A3 == -2) {
      processa_e_visualizza_testo_formattato(unaff_D6b + '\x05');
      leggi_valore_tabella_4byte();
      uVar1 = pubblico_band;
      pubblico_band = pubblico_band_salvato;
      copia_schermo_intero_in_buffer((&array_inizializzazione_9byte)[flag_primo_accesso_menu]);
      imposta_colori_copper_4();
      gestisci_input_e_carica_rock();
      pubblico_band = uVar1;
    }
    else {
      leggi_valore_tabella_4byte(*unaff_A3,unaff_D6b + '\x05');
      renderizza_messaggio_completo();
    }
    unaff_D6b = unaff_D6b + '\x01';
    unaff_A3 = unaff_A3 + -1;
    unaff_D4b = unaff_D4b + -1;
  } while (unaff_D4b != '\0');
  flag_alternanza_render = 0;
  return;
}


/* $0af8a disegna_carattere_grafico: Disegna carattere grafico con sfondo testo e rettangoli per i 4 bitplane */

/* Disegna carattere grafico con sfondo testo e rettangoli per i 4 bitplane */

void disegna_carattere_grafico(void)

{
  undefined4 unaff_D4;
  char unaff_D6b;
  undefined *puVar1;
  
  larghezza_finestra_caratteri = 2;
  altezza_finestra_caratteri = 0x10;
  disegna_sfondo_area_testo();
  if (unaff_D6b == 'J') {
    disegna_rettangolo_grafico();
    disegna_rettangolo_grafico(unaff_D4);
    disegna_rettangolo_grafico(unaff_D4);
    disegna_rettangolo_grafico(unaff_D4);
    return;
  }
  puVar1 = &DAT_0004d58a;
  for (unaff_D6b = unaff_D6b + -0x4b; unaff_D6b != '\0'; unaff_D6b = unaff_D6b + -1) {
    puVar1 = puVar1 + -0x80;
  }
  disegna_rettangolo_grafico(puVar1);
  disegna_rettangolo_grafico(unaff_D4);
  return;
}


/* $0b024 disegna_simbolo_grafico: Disegna simbolo grafico selezionando sorgente in base al carattere input */

/* Disegna simbolo grafico selezionando sorgente in base al carattere input */

void disegna_simbolo_grafico(void)

{
  undefined4 unaff_D4;
  char unaff_D6b;
  undefined *puVar1;
  
  if (unaff_D6b == '<') {
    puVar1 = &DAT_0004d10a;
  }
  else if (unaff_D6b == '+') {
    puVar1 = &DAT_0004d08a;
  }
  else {
    puVar1 = &DAT_0004d68a;
  }
  larghezza_finestra_caratteri = 2;
  altezza_finestra_caratteri = 0x10;
  disegna_rettangolo_grafico(puVar1);
  disegna_rettangolo_grafico(unaff_D4);
  return;
}


/* $0b070 esegue_transizione_schermo_con_render: Esegue fade-out, pulisce schermo, disegna rettangolo, copia dati e renderizza ciclo principale due volte */

/* Esegue fade-out, pulisce schermo, disegna rettangolo, copia dati e renderizza ciclo principale
   due volte */

void esegue_transizione_schermo_con_render(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  contatore_frame_globale = 0x4a;
  puVar2 = &puntatore_dati_fade1;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar2 = &puntatore_dati_fade2;
  }
  flag_alternanza_render = 1;
  ciclo_principale_rendering_gioco();
  sfonda_colori_e_pulisci_schermo(puVar2);
  larghezza_finestra_caratteri = 0x1a;
  altezza_finestra_caratteri = 0xe;
  disegna_rettangolo_grafico();
  sVar1 = 4;
  puVar2 = &buffer_risultati_confronto;
  puVar3 = &buffer_risultati_confronto;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  contatore_frame_globale = 0x4f;
  flag_alternanza_render = 1;
  ciclo_principale_rendering_gioco();
  return;
}


/* $0b112 gestisci_input_doppio_buffer: Polling input joystick su due buffer alternati con attese temporizzate e gestione bit 0x80 per sincronizzazione. */

/* Polling input joystick su due buffer alternati con attese temporizzate e gestione bit 0x80 per
   sincronizzazione. */

void gestisci_input_doppio_buffer(void)

{
  int unaff_A3;
  byte *pbVar1;
  
  if (flag_seleziona_buffer_dati != '\0') {
    pausa_attesa_d6_1();
    if (buffer_sorgente_confronto_2 != -2) {
      pausa_attesa_d6_2(*(undefined1 *)(unaff_A3 + 1));
      pbVar1 = (byte *)(unaff_A3 + 1);
      if ((*pbVar1 & 0x80) != 0) {
        gestisci_timer_attesa_ciclica();
        *pbVar1 = 8;
        return;
      }
    }
    return;
  }
  pausa_attesa_d6_1();
  if (buffer_sorgente_confronto_1 != -2) {
    pausa_attesa_d6_1(*(undefined1 *)(unaff_A3 + 1));
    pbVar1 = (byte *)(unaff_A3 + 1);
    if ((*pbVar1 & 0x80) != 0) {
      gestisci_timer_attesa_ciclica();
      *pbVar1 = 8;
      return;
    }
  }
  return;
}


/* $0b16e pausa_attesa_d6_1: Esegue un ciclo vuoto di attesa basato sul contatore D6. */

/* Esegue un ciclo vuoto di attesa basato sul contatore D6. */

void pausa_attesa_d6_1(void)

{
  char unaff_D6b;
  
  for (; unaff_D6b != '\0'; unaff_D6b = unaff_D6b + -1) {
  }
  return;
}


/* $0b1d8 pausa_attesa_d6_2: Esegue un ciclo vuoto di attesa decrementando il registro D6. */

/* Esegue un ciclo vuoto di attesa decrementando il registro D6. */

void pausa_attesa_d6_2(void)

{
  char unaff_D6b;
  
  for (; unaff_D6b != '\0'; unaff_D6b = unaff_D6b + -1) {
  }
  return;
}


/* $0b1f6 calcola_posizione_cursore_menu: Confronta sommatore e cursore Y contro tabelle soglia, imposta indici e timer per navigazione menu. */

/* Confronta sommatore e cursore Y contro tabelle soglia, imposta indici e timer per navigazione
   menu. */

void calcola_posizione_cursore_menu(void)

{
  byte bVar1;
  byte *pbVar2;
  
  if (flag_seleziona_buffer_dati == '\0') {
    if ((&tabella_soglie_sommatore)[flag_primo_accesso_menu] == '\0') {
      (&tabella_soglie_sommatore)[flag_primo_accesso_menu] = '\x01';
    }
    else {
      sommatore_valori_tabella = 0;
    }
    indice_soglia_selezionata = 10;
    pbVar2 = &tabella_soglie_cursore_y;
    do {
      if (sommatore_valori_tabella == *pbVar2) goto l_0b250;
      if (sommatore_valori_tabella < *pbVar2) break;
      pbVar2 = pbVar2 + 1;
      indice_soglia_selezionata = indice_soglia_selezionata - 1;
    } while (indice_soglia_selezionata != 0);
    indice_soglia_selezionata = indice_soglia_selezionata + 1;
l_0b250:
    bVar1 = 10;
    pbVar2 = &soglie_classifica;
    do {
      if (qualita_esibizione_band == *pbVar2) goto l_0b274;
      if (qualita_esibizione_band < *pbVar2) break;
      pbVar2 = pbVar2 + 1;
      bVar1 = bVar1 - 1;
    } while (bVar1 != 0);
    bVar1 = bVar1 + 1;
l_0b274:
    if (indice_soglia_selezionata < bVar1) {
      indice_soglia_selezionata = bVar1;
    }
    gestisci_timer_attesa_ciclica();
    contatore_scorrimento_buffer = 0x14;
    gestisci_timer_attesa_ciclica();
    contatore_cicli_ritardo = 7;
  }
  return;
}


/* $0b35a aggiorna_scorrimento_buffer_dati: Gestisce scorrimento elementi nei buffer dati in base a contatori, livello e flag, con timer CIA. */

/* Gestisce scorrimento elementi nei buffer dati in base a contatori, livello e flag, con timer CIA.
    */

void aggiorna_scorrimento_buffer_dati(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  
  bVar2 = contatore_scorrimento_buffer;
  if (flag_seleziona_buffer_dati != '\0') {
    if (((contatore_scorrimento_buffer < 9) && (contatore_scorrimento_buffer != 0)) &&
       (((sotto_contatore_scorrimento == 0 || (5 < sotto_contatore_scorrimento)) ||
        ((contatore_scorrimento_buffer != 0 && (contatore_scorrimento_buffer < 6)))))) {
      bVar2 = (byte)(9 - contatore_scorrimento_buffer | 4) >> 2;
      do {
        if (sotto_contatore_scorrimento == 1) break;
        sotto_contatore_scorrimento = sotto_contatore_scorrimento - 1;
        bVar2 = bVar2 - 1;
      } while (bVar2 != 0);
    }
    else {
      if (sotto_contatore_scorrimento == 0x14) {
        return;
      }
      sotto_contatore_scorrimento = sotto_contatore_scorrimento + 1;
    }
    if (sotto_contatore_scorrimento < 0xb) {
      bVar2 = sotto_contatore_scorrimento - 1;
      scorri_elementi_buffer_dati();
      (&buffer_sorgente_confronto_2)[bVar2] = 0xfe;
    }
    return;
  }
  if ((contatore_cicli_ritardo & 0x80) != 0) {
    if (10 < contatore_scorrimento_buffer) {
      return;
    }
    gestisci_timer_attesa_ciclica();
    contatore_scorrimento_buffer = bVar2 + 3;
    goto l_0b40e;
  }
  if (livello_selezionato_129c3 < 5) {
    bVar2 = 2;
  }
  else if (livello_selezionato_129c3 < 10) {
    bVar2 = 4;
  }
  else {
    bVar2 = 6;
  }
  gestisci_timer_attesa_ciclica();
  bVar3 = bVar2 <= contatore_scorrimento_buffer;
  bVar1 = contatore_scorrimento_buffer - bVar2;
  contatore_scorrimento_buffer = indice_soglia_selezionata;
  if (bVar1 == 0) {
    bVar1 = bVar2 + 1;
l_0b3ae:
    if (indice_soglia_selezionata < bVar1) {
      contatore_scorrimento_buffer = bVar1;
    }
  }
  else if (bVar3) goto l_0b3ae;
  contatore_cicli_ritardo = contatore_cicli_ritardo - 1;
  if (contatore_cicli_ritardo == 0) {
    contatore_cicli_ritardo = 0x80;
  }
l_0b40e:
  if (contatore_scorrimento_buffer < 0xb) {
    bVar2 = contatore_scorrimento_buffer - 1;
    scorri_elementi_buffer_dati();
    (&buffer_sorgente_confronto_1)[bVar2] = 0xfe;
  }
  return;
}


/* $0b498 imposta_parametro_bf68: Imposta la variabile globale 00bf68 al valore predefinito 0x400. */

/* Imposta la variabile globale 00bf68 al valore predefinito 0x400. */

void imposta_parametro_bf68(void)

{
  parametro_dimensione_bf68 = 0x400;
  return;
}


/* $0b4a4 attendi_passaggio_pennello: attesa base del gioco: aspetta che il pennello passi per la riga 0/256 (circa mezzo quadro); corretta da patch_velocita.py */

/* attesa base del gioco: aspetta che il pennello passi per la riga 0/256 (circa mezzo quadro);
   corretta da patch_velocita.py */

void attendi_passaggio_pennello(void)

{
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  return;
}


/* $0b4be attendi_riga_zero: aspetta finche' il byte basso di VHPOSR e' 0 (riga 0 o 256) */

/* aspetta finche' il byte basso di VHPOSR e' 0 (riga 0 o 256) */

void attendi_riga_zero(void)

{
  do {
  } while (DAT_00dff006 != '\0');
  return;
}


/* $0b4d4 esegui_sfondamento_colori_copper: Riduce progressivamente la luminosita' dei 16 registri colore Copper su 15 mezzi frame per effetto fade. */

/* Riduce progressivamente la luminosita' dei 16 registri colore Copper su 15 mezzi frame per
   effetto fade. */

void esegui_sfondamento_colori_copper(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  
  pbVar5 = &registri_colore_copper;
  sVar1 = 0xf;
  pbVar8 = &buffer_registri_copper;
  do {
    pbVar7 = pbVar8 + 1;
    *pbVar8 = *pbVar5;
    pbVar8 = pbVar8 + 2;
    *pbVar7 = pbVar5[1];
    pbVar5 = pbVar5 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = 0xe;
  do {
    sVar4 = 0x1f;
    pbVar5 = &buffer_registri_copper;
    do {
      bVar3 = *pbVar5 & 0x70;
      if (bVar3 != 0) {
        bVar3 = bVar3 - 0x10;
      }
      bVar2 = *pbVar5 & 7;
      if (bVar2 != 0) {
        bVar2 = bVar2 - 1;
      }
      *pbVar5 = bVar3 | bVar2;
      sVar4 = sVar4 + -1;
      pbVar5 = pbVar5 + 1;
    } while (sVar4 != -1);
    puVar10 = &buffer_registri_copper;
    puVar6 = &registri_colore_copper;
    sVar4 = 0xf;
    do {
      puVar9 = puVar10 + 1;
      *puVar6 = *puVar10;
      puVar10 = puVar10 + 2;
      puVar6[1] = *puVar9;
      puVar6 = puVar6 + 4;
      sVar4 = sVar4 + -1;
    } while (sVar4 != -1);
    attendi_mezzoframe();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0b532 sfonda_colori_e_pulisci_schermo: Esegue fade-out colori copper su 15 mezzi frame poi azzera tutta la memoria video (4 bitplane, 8000 byte) */

/* Esegue fade-out colori copper su 15 mezzi frame poi azzera tutta la memoria video (4 bitplane,
   8000 byte) */

void sfonda_colori_e_pulisci_schermo(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  esegui_sfondamento_colori_copper();
  puVar2 = (undefined4 *)&indirizzo_memoria_video;
  sVar1 = 1999;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar3 = puVar2 + 3;
    puVar2[2] = 0;
    puVar2 = puVar2 + 4;
    *puVar3 = 0;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0b534 pulisci_schermo_4_bitplane: Azzera i 32000 byte della memoria video dei 4 bitplane della schermata. */

/* Azzera i 32000 byte della memoria video dei 4 bitplane della schermata. */

void pulisci_schermo_4_bitplane(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&indirizzo_memoria_video;
  sVar1 = 1999;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar3 = puVar2 + 3;
    puVar2[2] = 0;
    puVar2 = puVar2 + 4;
    *puVar3 = 0;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0b552 riempi_schermo_colore_7: Imposta i bitplane della memoria video per riempire lo schermo con il colore 7. */

/* Imposta i bitplane della memoria video per riempire lo schermo con il colore 7. */

void riempi_schermo_colore_7(void)

{
  short sVar1;
  undefined2 *puVar2;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 3999;
  do {
    *puVar2 = 0xffff;
    puVar2[4000] = 0xffff;
    puVar2[8000] = 0xffff;
    puVar2[12000] = 0;
    puVar2 = puVar2 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0b57a riempi_schermo_colore_2: Imposta i bitplane della memoria video per riempire lo schermo con il colore 2. */

/* Imposta i bitplane della memoria video per riempire lo schermo con il colore 2. */

void riempi_schermo_colore_2(void)

{
  short sVar1;
  undefined2 *puVar2;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 3999;
  do {
    *puVar2 = 0;
    puVar2[4000] = 0xffff;
    puVar2[8000] = 0;
    puVar2[12000] = 0;
    puVar2 = puVar2 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0b5a2 attendi_mezzoframe: Attende il passaggio del pennello video per sincronizzazione a mezzoframe */

/* Attende il passaggio del pennello video per sincronizzazione a mezzoframe */

undefined8 attendi_mezzoframe(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  attendi_passaggio_pennello();
  return CONCAT44(in_D0,in_D1);
}


/* $0b5b0 calcola_indirizzo_video: Funzione wrapper che calcola l'indirizzo di memoria video corrispondente alle coordinate sullo schermo. */

/* Funzione wrapper che calcola l'indirizzo di memoria video corrispondente alle coordinate sullo
   schermo. */

void calcola_indirizzo_video(void)

{
  indirizzo_schermo();
  return;
}


/* $0b5ce maschera_byte_superiore_d4: Applica una maschera 0xFF00 al registro D4 ritornando il byte piu significativo. */

/* Applica una maschera 0xFF00 al registro D4 ritornando il byte piu significativo. */

ushort maschera_byte_superiore_d4(void)

{
  ushort unaff_D4w;
  
  return unaff_D4w & 0xff00;
}


/* $0b5d0 indirizzo_schermo: calcola l'indirizzo nello schermo (40 byte/riga, 8000 byte/piano) */

/* calcola l'indirizzo nello schermo (40 byte/riga, 8000 byte/piano) */

ushort indirizzo_schermo(void)

{
  ushort unaff_D4w;
  
  return unaff_D4w & 0xff00;
}


/* $0b610 disegna_immagine_4_bitplane: Disegna un'immagine rettangolare dai dati in A0 sui 4 bitplane dello schermo. */

/* Disegna un'immagine rettangolare dai dati in A0 sui 4 bitplane dello schermo. */

void disegna_immagine_4_bitplane(void)

{
  short sVar1;
  short sVar2;
  byte *in_A0;
  byte *pbVar3;
  byte *pbVar4;
  byte *unaff_A3;
  
  larghezza_finestra_caratteri = *in_A0;
  pbVar3 = in_A0 + 2;
  altezza_finestra_caratteri = in_A0[1];
  sVar2 = altezza_finestra_caratteri - 1;
  do {
    sVar1 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      *unaff_A3 = *pbVar3;
      unaff_A3[8000] = pbVar3[1];
      pbVar4 = pbVar3 + 3;
      unaff_A3[16000] = pbVar3[2];
      pbVar3 = pbVar3 + 4;
      unaff_A3[24000] = *pbVar4;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}


/* $0b61a disegna_rettangolo_grafico: Copia una regione di memoria grafica nei 4 bitplanes dello schermo per la larghezza e altezza specificate. */

/* Copia una regione di memoria grafica nei 4 bitplanes dello schermo per la larghezza e altezza
   specificate. */

void disegna_rettangolo_grafico(void)

{
  short sVar1;
  short sVar2;
  undefined1 *in_A0;
  undefined1 *puVar3;
  undefined1 *unaff_A3;
  
  sVar2 = altezza_finestra_caratteri - 1;
  do {
    sVar1 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      *unaff_A3 = *in_A0;
      unaff_A3[8000] = in_A0[1];
      puVar3 = in_A0 + 3;
      unaff_A3[16000] = in_A0[2];
      in_A0 = in_A0 + 4;
      unaff_A3[24000] = *puVar3;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}


/* $0b67e disegna_bitmap_mascherata: Disegna una bitmap con maschera di trasparenza su quattro bitplane dello schermo. */

/* Disegna una bitmap con maschera di trasparenza su quattro bitplane dello schermo. */

void disegna_bitmap_mascherata(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte *in_A0;
  byte *pbVar4;
  byte *pbVar5;
  byte *unaff_A3;
  
  larghezza_finestra_caratteri = *in_A0;
  pbVar4 = in_A0 + 2;
  altezza_finestra_caratteri = in_A0[1];
  sVar3 = altezza_finestra_caratteri - 1;
  do {
    sVar2 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      pbVar5 = pbVar4 + 3;
      bVar1 = *pbVar5 & pbVar4[2] & pbVar4[1] & *pbVar4;
      *unaff_A3 = bVar1 & *unaff_A3;
      unaff_A3[8000] = bVar1 & unaff_A3[8000];
      unaff_A3[16000] = bVar1 & unaff_A3[16000];
      unaff_A3[24000] = bVar1 & unaff_A3[24000];
      bVar1 = bVar1 ^ 0xff;
      *unaff_A3 = bVar1 & *pbVar4 | *unaff_A3;
      unaff_A3[8000] = bVar1 & pbVar4[1] | unaff_A3[8000];
      unaff_A3[16000] = bVar1 & pbVar4[2] | unaff_A3[16000];
      pbVar4 = pbVar4 + 4;
      unaff_A3[24000] = bVar1 & *pbVar5 | unaff_A3[24000];
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return;
}


/* $0b688 disegna_grafica_mascherata: Disegna un'immagine grafica mascherata sui 4 bitplanes per sovrapporre elementi visivi allo sfondo. */

/* Disegna un'immagine grafica mascherata sui 4 bitplanes per sovrapporre elementi visivi allo
   sfondo. */

void disegna_grafica_mascherata(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte *in_A0;
  byte *pbVar4;
  byte *unaff_A3;
  
  sVar3 = altezza_finestra_caratteri - 1;
  do {
    sVar2 = larghezza_finestra_caratteri - 1;
    do {
      indirizzo_schermo();
      pbVar4 = in_A0 + 3;
      bVar1 = *pbVar4 & in_A0[2] & in_A0[1] & *in_A0;
      *unaff_A3 = bVar1 & *unaff_A3;
      unaff_A3[8000] = bVar1 & unaff_A3[8000];
      unaff_A3[16000] = bVar1 & unaff_A3[16000];
      unaff_A3[24000] = bVar1 & unaff_A3[24000];
      bVar1 = bVar1 ^ 0xff;
      *unaff_A3 = bVar1 & *in_A0 | *unaff_A3;
      unaff_A3[8000] = bVar1 & in_A0[1] | unaff_A3[8000];
      unaff_A3[16000] = bVar1 & in_A0[2] | unaff_A3[16000];
      in_A0 = in_A0 + 4;
      unaff_A3[24000] = bVar1 & *pbVar4 | unaff_A3[24000];
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return;
}


/* $0b716 seleziona_font: sceglie il font (piccolo a $c7c5, 6 byte/carattere) e il glifo */

/* sceglie il font (piccolo a $c7c5, 6 byte/carattere) e il glifo */

void seleziona_font(void)

{
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  int unaff_D6;
  uint uVar1;
  undefined4 unaff_A3;
  ushort uVar2;
  
  if (stato_font_corrente != '\0') {
    disegna_sfondo_carattere();
  }
  uVar1 = unaff_D6 - 1;
  if (flag_selezione_font != '\0') {
    do {
      uVar2 = (short)uVar1 - 1;
      uVar1 = (uint)uVar2;
    } while (uVar2 != 0xffff);
    larghezza_finestra_caratteri = 2;
    altezza_finestra_caratteri = 0xe;
    disegna_glifo(unaff_D4,unaff_D5,unaff_D6,unaff_A3);
    return;
  }
  do {
    uVar2 = (short)uVar1 - 1;
    uVar1 = (uint)uVar2;
  } while (uVar2 != 0xffff);
  larghezza_finestra_caratteri = 1;
  altezza_finestra_caratteri = 6;
  disegna_glifo(unaff_D4,unaff_D5,unaff_D6,unaff_A3);
  return;
}


/* $0b78e disegna_glifo: disegna un carattere nei 4 bitplane */

/* disegna un carattere nei 4 bitplane */

void disegna_glifo(void)

{
  byte *pbVar1;
  byte bVar2;
  uint unaff_D4;
  byte *unaff_D5;
  int unaff_D6;
  int iVar3;
  byte *unaff_A3;
  char cVar4;
  
  cVar4 = larghezza_finestra_caratteri;
  iVar3 = unaff_D6;
  do {
    do {
      indirizzo_schermo(unaff_D6,cVar4,unaff_D4);
      pbVar1 = unaff_D5 + 1;
      bVar2 = *unaff_D5;
      if (flag_render_testo_tabella == '\0') {
        bVar2 = bVar2 ^ 0xff;
        *unaff_A3 = bVar2 & *unaff_A3;
      }
      else {
        *unaff_A3 = bVar2;
      }
      unaff_A3[8000] = bVar2 & unaff_A3[8000];
      unaff_A3[16000] = bVar2 & unaff_A3[16000];
      unaff_A3 = unaff_A3 + 24000;
      *unaff_A3 = bVar2 & *unaff_A3;
      cVar4 = cVar4 + -1;
      unaff_D5 = pbVar1;
    } while (cVar4 != '\0');
    unaff_D6 = iVar3 + 1;
    if ((char)unaff_D6 == '\b') {
      unaff_D6 = 0;
      unaff_D4 = (uint)(ushort)((short)unaff_D4 + 0x100);
    }
    altezza_finestra_caratteri = altezza_finestra_caratteri + -1;
    cVar4 = larghezza_finestra_caratteri;
    iVar3 = unaff_D6;
  } while (altezza_finestra_caratteri != '\0');
  return;
}


/* $0b810 disegna_area_invertita_bitplane: Disegna area rettangolare invertendo i pixel sui 4 bitplane dello schermo */

/* Disegna area rettangolare invertendo i pixel sui 4 bitplane dello schermo */

void disegna_area_invertita_bitplane(void)

{
  byte *pbVar1;
  byte bVar2;
  uint unaff_D4;
  byte *unaff_D5;
  int unaff_D6;
  int iVar3;
  byte *unaff_A3;
  char cVar4;
  
  cVar4 = larghezza_finestra_caratteri;
  iVar3 = unaff_D6;
  do {
    do {
      calcola_indirizzo_video(unaff_D6,cVar4,unaff_D4);
      pbVar1 = unaff_D5 + 1;
      bVar2 = *unaff_D5 ^ 0xff;
      *unaff_A3 = bVar2 & *unaff_A3;
      unaff_A3[8000] = bVar2 & unaff_A3[8000];
      unaff_A3[16000] = bVar2 & unaff_A3[16000];
      unaff_A3 = unaff_A3 + 24000;
      *unaff_A3 = bVar2 & *unaff_A3;
      cVar4 = cVar4 + -1;
      unaff_D5 = pbVar1;
    } while (cVar4 != '\0');
    unaff_D6 = iVar3 + 1;
    if ((char)unaff_D6 == '\b') {
      unaff_D6 = 0;
      unaff_D4 = (uint)(ushort)((short)unaff_D4 + 0x100);
    }
    altezza_finestra_caratteri = altezza_finestra_caratteri + -1;
    cVar4 = larghezza_finestra_caratteri;
    iVar3 = unaff_D6;
  } while (altezza_finestra_caratteri != '\0');
  return;
}


/* $0b882 attendi_timer_ciaa: Funzione vuota usata come segnaposto per la gestione del timer CIAA TODLO. */

/* Funzione vuota usata come segnaposto per la gestione del timer CIAA TODLO. */

void attendi_timer_ciaa(void)

{
  return;
}


/* $0b88a disegna_sfondo_carattere: riempie lo sfondo della cella di un carattere */

/* riempie lo sfondo della cella di un carattere */

void disegna_sfondo_carattere(void)

{
  short sVar1;
  undefined1 *unaff_A3;
  
  maschera_byte_superiore_d4();
  sVar1 = 7;
  if ((flag_render_testo_tabella == '\0') && (flag_alternanza_render == '\0')) {
    do {
      *unaff_A3 = 0xff;
      unaff_A3[8000] = 0;
      unaff_A3[16000] = 0;
      unaff_A3[24000] = 0;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    return;
  }
  if (flag_alternanza_render == '\0') {
    do {
      *unaff_A3 = 0;
      unaff_A3[8000] = 0;
      unaff_A3[16000] = 0;
      unaff_A3[24000] = 0;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    return;
  }
  if (flag_alternanza_render == '\x01') {
    do {
      *unaff_A3 = 0xff;
      unaff_A3[8000] = 0xff;
      unaff_A3[16000] = 0;
      unaff_A3[24000] = 0xff;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    return;
  }
  do {
    *unaff_A3 = 0xff;
    unaff_A3[8000] = 0;
    unaff_A3[16000] = 0xff;
    unaff_A3[24000] = 0xff;
    unaff_A3 = unaff_A3 + 0x28;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


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


/* $0b95a irq_livello2: gestore interrupt livello 2 (vettore $68): tastiera via CIA-A SDR, spazio = pausa ($bb64) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* gestore interrupt livello 2 (vettore $68): tastiera via CIA-A SDR, spazio = pausa ($bb64) */

undefined8 irq_livello2(void)

{
  ushort uVar1;
  byte bVar2;
  undefined4 in_D0;
  byte bVar3;
  undefined4 in_D1;
  ushort uVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  
  if (((_DAT_00dff01c & 0x4000) == 0) || ((_DAT_00dff01e & _DAT_00dff01c & 8) == 0)) goto l_0bb12;
  _DAT_00dff09c = 8;
  if ((DAT_00bfed01 & 0x88) != 0x88) goto l_0bb12;
  bVar2 = ~DAT_00bfec01 << 7;
  bVar3 = bVar2 | (byte)~DAT_00bfec01 >> 1;
  if (bVar3 == 0x40) {
    flag_blocco_input = 1;
  }
  else if (bVar3 == 0xc0) {
    flag_blocco_input = 0;
  }
  else if (bVar3 == 0x4c) {
    flag_scroll_attivo = 1;
  }
  else if (bVar3 == 0xcc) {
    flag_scroll_attivo = 0;
  }
  else if (bVar3 == 0x4d) {
    flag_scroll_direzione = 1;
  }
  else if (bVar3 == 0xcd) {
    flag_scroll_direzione = 0;
  }
  uVar4 = bVar3 & 0x7f;
  if (uVar4 < 0x68) {
    uVar1 = bVar3 & 7;
    uVar4 = uVar4 >> 3;
    (&DAT_0000bb66)[(short)uVar4] = (&DAT_0000bb66)[(short)uVar4] & ~('\x01' << uVar1);
    if (bVar2 == 0) {
      (&DAT_0000bb66)[(short)uVar4] = (&DAT_0000bb66)[(short)uVar4] | '\x01' << uVar1;
    }
  }
  if (bVar2 == 0) {
    if (((DAT_0000bb72 & 1) == 0) && ((DAT_0000bb72 & 2) == 0)) {
      puVar6 = &DAT_0000bb94;
    }
    else {
      puVar6 = &DAT_0000bc04;
    }
    tasto_premuto = puVar6[bVar3];
    if (trucco_tasti_giusti == 7) {
      if (bVar3 == 0x57) {
        puVar5 = &qualita_esibizione_band;
      }
      else {
        if (bVar3 != 0x58) {
          if (bVar3 == 0x56) {
            soldi_cifra_milioni = 1;
          }
          goto l_0bb0a;
        }
        puVar5 = &pubblico_band;
      }
      *puVar5 = 0xff;
    }
    else if (bVar3 == (&trucco_sequenza_colbops)[trucco_tasti_giusti]) {
      trucco_tasti_giusti = trucco_tasti_giusti + 1;
    }
    else {
      trucco_tasti_giusti = 0;
    }
  }
l_0bb0a:
  DAT_00bfee01 = DAT_00bfee01 & 0xbf;
l_0bb12:
  return CONCAT44(in_D0,in_D1);
}


/* $0bc76 leggi_input_joystick_fuoco: Legge stato joystick e tasto fuoco, imposta codice azione in base a input */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Legge stato joystick e tasto fuoco, imposta codice azione in base a input */

void leggi_input_joystick_fuoco(void)

{
  ushort uVar1;
  char cVar2;
  
  cVar2 = stato_precedente_joystick;
  codice_azione_input = 0;
  if ((ciaa_pra_joystick & 0x40) == 0) {
    codice_azione_input = 1;
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
    return;
  }
  if (-1 < (char)ciaa_pra_joystick) {
    codice_azione_input = 1;
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x80) == 0);
    return;
  }
  if (flag_blocco_input != '\0') {
    codice_azione_input = 1;
    do {
    } while (flag_blocco_input != '\0');
    return;
  }
  if (flag_scroll_direzione != '\0') {
    codice_azione_input = 3;
    return;
  }
  if (flag_scroll_attivo == '\0') {
    stato_precedente_joystick = DAT_00dff00a;
    if (cVar2 == DAT_00dff00a) {
      if (((_DAT_00dff00c & 2) == 0) && ((_DAT_00dff00c & 0x200) == 0)) {
        uVar1 = _DAT_00dff00c ^ _DAT_00dff00c >> 1;
        if ((uVar1 & 1) != 0) {
          codice_azione_input = 3;
          return;
        }
        if ((uVar1 & 0x100) != 0) {
          codice_azione_input = 2;
          return;
        }
      }
      return;
    }
    if ((char)(cVar2 - DAT_00dff00a) < '\0') {
      codice_azione_input = 3;
      return;
    }
  }
  codice_azione_input = 2;
  return;
}


/* $0bd3e attendi_pressione_fuoco: Cicla in lettura joystick fino a rilevare pressione tasto fuoco, poi azzera il codice azione. */

/* Cicla in lettura joystick fino a rilevare pressione tasto fuoco, poi azzera il codice azione. */

void attendi_pressione_fuoco(void)

{
  do {
    leggi_input_joystick_fuoco();
  } while (codice_azione_input != '\x01');
  codice_azione_input = 0;
  return;
}


/* $0bd54 aggiorna_scorrimento_tavolozza: Aggiorna coordinata schermo e ricarica tavolozza per scorrimento fluido */

/* Aggiorna coordinata schermo e ricarica tavolozza per scorrimento fluido */

void aggiorna_scorrimento_tavolozza(void)

{
  if (flag_blocco_input != '\0') {
    return;
  }
  if (flag_scroll_attivo == '\0') {
    if (flag_scroll_direzione == '\0') {
      if (codice_azione_input == '\0') {
        return;
      }
      if (codice_azione_input == '\x01') {
        return;
      }
      if (codice_azione_input == '\x02') goto l_0bdbe;
      codice_azione_input = '\0';
    }
    if (coordinata_x_schermo_d081 != coordinata_x_schermo_max) {
      attendi_passaggio_pennello();
      coordinata_x_schermo_d081 = coordinata_x_schermo_d081 + '\x01';
      carica_tavolozza_schermo_1();
    }
  }
  else {
l_0bdbe:
    codice_azione_input = '\0';
    if (coordinata_x_schermo_d081 != coordinata_x_schermo_min) {
      attendi_passaggio_pennello();
      coordinata_x_schermo_d081 = coordinata_x_schermo_d081 + -1;
      carica_tavolozza_schermo_1();
      return;
    }
  }
  return;
}


/* $0bdea aggiorna_bitplane_e_grafica: Duplica i dati del primo bitplane nel secondo per un'area verticale e aggiorna i buffer grafici. */

/* Duplica i dati del primo bitplane nel secondo per un'area verticale e aggiorna i buffer grafici.
    */

void aggiorna_bitplane_e_grafica(void)

{
  ushort uVar1;
  short sVar2;
  undefined1 *unaff_A3;
  ushort uVar3;
  
  DAT_0000bb90 = (ushort)indirizzo_tabella_dati * 0x100 + (ushort)coordinata_x_finestra * 0x100 |
                 (ushort)riga_inizio_finestra;
  altezza_finestra_caratteri = (riga_fine_finestra - riga_inizio_finestra) - 1;
  uVar1 = (ushort)altezza_finestra_caratteri;
  uVar3 = DAT_0000bb90;
  do {
    maschera_byte_superiore_d4(uVar3);
    sVar2 = 7;
    do {
      unaff_A3[8000] = *unaff_A3;
      unaff_A3 = unaff_A3 + 0x28;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    uVar3 = uVar3 + 1;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0xffff);
  copia_grafica_6f8c6_in_buffer_video();
  copia_grafica_707c6_in_buffer_video();
  return;
}


/* $0be5a copia_bitplane_2_in_1: Copia i dati dal terzo bitplane (offset 16000) nel secondo bitplane (offset 8000) per le righe specificate. */

/* Copia i dati dal terzo bitplane (offset 16000) nel secondo bitplane (offset 8000) per le righe
   specificate. */

void copia_bitplane_2_in_1(void)

{
  ushort uVar1;
  short sVar2;
  int unaff_A3;
  short sVar3;
  
  uVar1 = (ushort)altezza_finestra_caratteri;
  sVar3 = DAT_0000bb90;
  do {
    maschera_byte_superiore_d4(sVar3);
    sVar2 = 7;
    do {
      *(undefined1 *)(unaff_A3 + 8000) = *(undefined1 *)(unaff_A3 + 16000);
      unaff_A3 = unaff_A3 + 0x28;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    sVar3 = sVar3 + 1;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0xffff);
  return;
}


/* $0be8e carica_tavolozza_schermo_1: Configura i registri e copia una tavolozza di 16 colori nella memoria Copper a $300. */

/* Configura i registri e copia una tavolozza di 16 colori nella memoria Copper a $300. */

void carica_tavolozza_schermo_1(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  buffer_copper_300 = coordinata_x_schermo_d081 + ':';
  buffer_copper_302 = coordinata_x_schermo_d081 + 'H';
  buffer_copper_303 = 0;
  buffer_copper_301 = (coordinata_y_schermo_d080 >> 1) + 0x3e;
  sVar1 = 0xf;
  puVar2 = (undefined4 *)&tavolozza_copper_304;
  puVar3 = (undefined4 *)&tavolozza_predefinita_1;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}


/* $0bec4 carica_tavolozza_schermo_2: Copia una tavolozza alternativa di 16 colori nella memoria Copper all'indirizzo $304. */

/* Copia una tavolozza alternativa di 16 colori nella memoria Copper all'indirizzo $304. */

void carica_tavolozza_schermo_2(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = 0xf;
  puVar2 = (undefined4 *)&tavolozza_copper_304;
  puVar3 = &tavolozza_predefinita_2;
  do {
    *puVar2 = *puVar3;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}


/* $0bed6 effetto_sfumatura_colori_giu: Esegue sfumatura verso il basso dei colori Copper attendendo il pennello */

/* Esegue sfumatura verso il basso dei colori Copper attendendo il pennello */

void effetto_sfumatura_colori_giu(void)

{
  short sVar1;
  
  valore_colore_copper = -0x56;
  do {
    imposta_colori_copper_1();
    sVar1 = 1;
    do {
      attendi_passaggio_pennello();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    valore_colore_copper = valore_colore_copper + -0x11;
  } while (valore_colore_copper != '\x11');
  valore_colore_copper = 0x22;
  return;
}


/* $0bf0a effetto_sfumatura_colori_su: Esegue sfumatura verso l'alto dei colori Copper attendendo il pennello */

/* Esegue sfumatura verso l'alto dei colori Copper attendendo il pennello */

void effetto_sfumatura_colori_su(void)

{
  short sVar1;
  
  valore_colore_copper = '\"';
  do {
    imposta_colori_copper_1();
    sVar1 = 1;
    do {
      attendi_passaggio_pennello();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    valore_colore_copper = valore_colore_copper + '\x11';
  } while (valore_colore_copper != -0x45);
  valore_colore_copper = 0xaa;
  return;
}


/* $0bf3e imposta_colori_copper_1: Copia 16 valori di colore dalla sorgente bfcc nei registri colore della Copper list. */

/* Copia 16 valori di colore dalla sorgente bfcc nei registri colore della Copper list. */

void imposta_colori_copper_1(void)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  
  puVar2 = &tavolozza_bfcc;
  sVar1 = 0xf;
  puVar4 = &registri_colore_copper;
  do {
    puVar3 = puVar2 + 1;
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 2;
    puVar4[1] = *puVar3;
    puVar4 = puVar4 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0bf46 imposta_colori_copper_2: Copia 16 valori di colore dalla sorgente bfac nei registri colore della Copper list. */

/* Copia 16 valori di colore dalla sorgente bfac nei registri colore della Copper list. */

void imposta_colori_copper_2(void)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  
  puVar3 = &tavolozza_bfac;
  sVar1 = 0xf;
  puVar4 = &registri_colore_copper;
  do {
    puVar2 = puVar3 + 1;
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 2;
    puVar4[1] = *puVar2;
    puVar4 = puVar4 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0bf4c imposta_colori_copper_3: Copia 16 valori di colore dalla sorgente bf8c nei registri colore della Copper list. */

/* Copia 16 valori di colore dalla sorgente bf8c nei registri colore della Copper list. */

void imposta_colori_copper_3(void)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  
  puVar3 = &tavolozza_bf8c;
  sVar1 = 0xf;
  puVar4 = &registri_colore_copper;
  do {
    puVar2 = puVar3 + 1;
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 2;
    puVar4[1] = *puVar2;
    puVar4 = puVar4 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0bf52 imposta_colori_copper_4: Copia 16 valori di colore dalla sorgente bf6c nei registri colore della Copper list. */

/* Copia 16 valori di colore dalla sorgente bf6c nei registri colore della Copper list. */

void imposta_colori_copper_4(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar3 = &tavolozza_bf6c;
  sVar1 = 0xf;
  puVar4 = &registri_colore_copper;
  do {
    puVar2 = puVar3 + 1;
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 2;
    puVar4[1] = *puVar2;
    puVar4 = puVar4 + 4;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0c00c renderizza_schermo_completo_con_colori: Renderizza schermo completo: copia grafica, scena, interfaccia, buffer, colori copper */

/* Renderizza schermo completo: copia grafica, scena, interfaccia, buffer, colori copper */

void renderizza_schermo_completo_con_colori(void)

{
  copia_grafica_5c70a_su_schermo();
  renderizza_scena_condizionale();
  renderizza_interfaccia_gioco_completa();
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  return;
}


/* $0c028 disegna_elementi_controllo_mascherati: Disegna grafica mascherata per tutti gli elementi di controllo attivi */

/* Disegna grafica mascherata per tutti gli elementi di controllo attivi */

void disegna_elementi_controllo_mascherati(void)

{
  char cVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  if ((flag_controllo_attivo != '\0') && (tipo_controllo != '\0')) {
    puVar2 = &DAT_00011a98;
    valore_minimo_trovato = '\0';
    cVar1 = tipo_controllo;
    do {
      trova_elemento_e_imposta_finestra();
      puVar3 = puVar2 + 1;
      puVar2 = puVar2 + 2;
      altezza_finestra_caratteri = (undefined1)*puVar3;
      disegna_grafica_mascherata();
      valore_minimo_trovato = indice_elemento_attivo + '\x01';
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
  }
  return;
}


/* $0c0a0 disegna_singolo_elemento_mascherato: Prepara e disegna grafica mascherata per un singolo elemento di controllo */

/* Prepara e disegna grafica mascherata per un singolo elemento di controllo */

void disegna_singolo_elemento_mascherato(void)

{
  if ((flag_controllo_attivo != '\0') && (tipo_controllo != '\0')) {
    indice_elemento_attivo = 0;
    prepara_finestra_elemento(tipo_controllo);
    larghezza_finestra_caratteri = 5;
    altezza_finestra_caratteri = 0x10;
    disegna_grafica_mascherata();
  }
  return;
}


/* $0c0f4 prepara_finestra_elemento: Invoqua la routine per individuare l'elemento attivo e impostare le dimensioni della relativa finestra. */

/* Invoqua la routine per individuare l'elemento attivo e impostare le dimensioni della relativa
   finestra. */

void prepara_finestra_elemento(void)

{
  trova_elemento_e_imposta_finestra();
  return;
}


/* $0c10e attiva_stato_audio: Imposta a 1 il flag dello stato audio ed esegue una routine neutra di completamento. */

/* Imposta a 1 il flag dello stato audio ed esegue una routine neutra di completamento. */

void attiva_stato_audio(void)

{
  flag_stato_audio = 1;
  routine_vuota();
  return;
}


/* $0c11c resetta_stato_audio: Azzera la variabile di stato 128aa e richiama la routine di sincronizzazione. */

/* Azzera la variabile di stato 128aa e richiama la routine di sincronizzazione. */

void resetta_stato_audio(void)

{
  flag_stato_audio = 0;
  routine_vuota();
  return;
}


/* $0c120 inizializza_schermo_audio_e_renderizza: Inizializza schermo, avvia due sequenze audio buffer ausiliario, attiva flag, renderizza scena e copia grafica */

/* Inizializza schermo, avvia due sequenze audio buffer ausiliario, attiva flag, renderizza scena e
   copia grafica */

void inizializza_schermo_audio_e_renderizza(void)

{
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_buffer_ausiliario();
  avvia_sequenza_audio_buffer_ausiliario();
  attiva_flag_128b1();
  renderizza_scena_condizionale();
  copia_grafica_6f8c6_in_buffer_video();
  return;
}


/* $0c146 aggiorna_schermo_base_grafica: Disabilita flag stato, renderizza scena condizionale con ritardo e copia grafica di base (0x6f8c6) nel buffer video */

/* Disabilita flag stato, renderizza scena condizionale con ritardo e copia grafica di base
   (0x6f8c6) nel buffer video */

void aggiorna_schermo_base_grafica(void)

{
  disattiva_flag_128b1();
  renderizza_scena_condizionale();
  copia_grafica_6f8c6_in_buffer_video();
  return;
}


/* $0c154 cancella_indicatori_schermo: Azzera bit specifici nei 4 bitplanes della memoria video per cancellare elementi o indicatori grafici. */

/* Azzera bit specifici nei 4 bitplanes della memoria video per cancellare elementi o indicatori
   grafici. */

void cancella_indicatori_schermo(void)

{
  byte bVar1;
  int iVar2;
  undefined3 uVar3;
  short sVar5;
  uint uVar4;
  char cVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  pbVar7 = &array_indicatori_grafici;
  iVar2 = 0x1721;
  valore_minimo_trovato = 0x80;
  cVar6 = '4';
  do {
    if (*pbVar7 == 0) {
      return;
    }
    uVar4 = CONCAT31((uint3)*pbVar7,3);
    pbVar8 = pbVar7;
    do {
      indirizzo_schermo(pbVar8,iVar2);
      bVar1 = valore_minimo_trovato ^ 0xff;
      *pbVar7 = bVar1 & *pbVar7;
      pbVar7[8000] = bVar1 & pbVar7[8000];
      pbVar7[16000] = bVar1 & pbVar7[16000];
      pbVar7[24000] = bVar1 & pbVar7[24000];
      uVar3 = (undefined3)(uVar4 >> 8);
      if ((char)uVar4 == '\0') {
        sVar5 = (short)CONCAT31(uVar3,7);
      }
      else {
        sVar5 = (short)CONCAT31(uVar3,(char)uVar4 + -1);
      }
      uVar4 = (uint)(ushort)(sVar5 - 0x100U);
    } while ((sVar5 - 0x100U & 0xff00) != 0);
    pbVar7 = pbVar8 + 1;
    valore_minimo_trovato = valore_minimo_trovato << 7 | valore_minimo_trovato >> 1;
    if (valore_minimo_trovato == 0x80) {
      valore_minimo_trovato = 0x80;
      iVar2 = iVar2 + 1;
    }
    cVar6 = cVar6 + -1;
  } while (cVar6 != '\0');
  return;
}


/* $0c202 esegui_transizione_testo_audio: Gestisce transizioni schermo con fade, renderizza bitmap/testo, sincronizza timer e audio */

/* WARNING: Removing unreachable block (ram,0x0000c292) */
/* WARNING: Removing unreachable block (ram,0x0000c298) */
/* WARNING: Removing unreachable block (ram,0x0000c2a6) */
/* WARNING: Removing unreachable block (ram,0x0000c2b4) */
/* WARNING: Removing unreachable block (ram,0x0000c2bc) */
/* WARNING: Removing unreachable block (ram,0x0000c2fa) */
/* WARNING: Removing unreachable block (ram,0x0000c2cc) */
/* WARNING: Removing unreachable block (ram,0x0000c2fe) */
/* Gestisce transizioni schermo con fade, renderizza bitmap/testo, sincronizza timer e audio */

void esegui_transizione_testo_audio(void)

{
  char cVar1;
  
  attendi_input_gioco_con_timeout_59_frame();
  esegue_transizione_schermo_testo_bitmap();
  gestisci_timer_attesa_ciclica();
  cVar1 = stato_transizione_schermo;
  do {
    gestisci_timer_attesa_ciclica();
  } while (cVar1 == -0x79);
  stato_transizione_schermo = 0x87;
  renderizza_bitmap_testo_e_copia_schermo();
  flag_disabilita_sfondo = 0;
  stato_font_corrente = 1;
  avvia_sequenza_audio_testo_lungo();
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  attiva_stato_audio();
  inizializza_schermo_principale_completo();
  avvia_sequenza_audio_testo_lungo();
  resetta_stato_audio();
  aggiorna_stato_ciclo_gioco_principale();
  return;
}


/* $0c310 decrementa_timer_attesa: Decrementa il contatore di timer se il suo valore e' maggiore di zero. */

/* Decrementa il contatore di timer se il suo valore e' maggiore di zero. */

void decrementa_timer_attesa(void)

{
  if (contatore_timer_attesa != '\0') {
    contatore_timer_attesa = contatore_timer_attesa + -1;
  }
  return;
}


/* $0c31e schermata_testo_con_transizione_e_timer: Esegue transizione con fade, disegna bitmap mascherata, visualizza testo, gestisce timer e copia schermo */

/* Esegue transizione con fade, disegna bitmap mascherata, visualizza testo, gestisce timer e copia
   schermo */

void schermata_testo_con_transizione_e_timer(void)

{
  undefined4 unaff_D6;
  
  esegue_transizione_schermo_testo_bitmap();
  disegna_bitmap_mascherata(unaff_D6);
  visualizza_testo_con_font_attivo();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  return;
}


/* $0c326 renderizza_bitmap_testo_e_copia_schermo: Disegna bitmap mascherata, visualizza testo con font, processa testo formattato, copia schermo e imposta colori copper */

/* Disegna bitmap mascherata, visualizza testo con font, processa testo formattato, copia schermo e
   imposta colori copper */

void renderizza_bitmap_testo_e_copia_schermo(void)

{
  disegna_bitmap_mascherata();
  visualizza_testo_con_font_attivo();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  return;
}


/* $0c376 schermata_menu_controllo_testo: Gestisce menu controllo con transizione, doppio testo formattato, inizializzazione elemento, audio e transizione finale */

/* Gestisce menu controllo con transizione, doppio testo formattato, inizializzazione elemento,
   audio e transizione finale */

void schermata_menu_controllo_testo(void)

{
  esegue_transizione_schermo_testo_bitmap();
  visualizza_testo_con_font_attivo();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  if (flag_elemento_controllo == '\0') {
    inizializza_elemento_controllo_attivo();
  }
  else {
    trova_elemento_e_imposta_finestra();
  }
  disegna_grafica_mascherata();
  indice_elemento_attivo_salvato = indice_elemento_attivo;
  flag_elemento_controllo = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  flag_disabilita_sfondo = 0;
  stato_font_corrente = 1;
  avvia_sequenza_audio_testo_lungo();
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  return;
}


/* $0c37e visualizza_schermata_testo_con_grafica: Renderizza testo formattato con font, disegna grafica mascherata, imposta colori copper e avvia audio */

/* Renderizza testo formattato con font, disegna grafica mascherata, imposta colori copper e avvia
   audio */

void visualizza_schermata_testo_con_grafica(void)

{
  visualizza_testo_con_font_attivo();
  gestisci_timer_attesa_ciclica();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  if (flag_elemento_controllo == '\0') {
    inizializza_elemento_controllo_attivo();
  }
  else {
    trova_elemento_e_imposta_finestra();
  }
  disegna_grafica_mascherata();
  indice_elemento_attivo_salvato = indice_elemento_attivo;
  flag_elemento_controllo = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  flag_disabilita_sfondo = 0;
  stato_font_corrente = 1;
  avvia_sequenza_audio_testo_lungo();
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  return;
}


/* $0c428 esegue_transizione_schermo_testo_bitmap: Esegue transizione schermo: fade-out colori, pulizia, bitmap mascherata, rendering testo da tabella, griglia glifi, testo formattato finale */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Esegue transizione schermo: fade-out colori, pulizia, bitmap mascherata, rendering testo da
   tabella, griglia glifi, testo formattato finale */

void esegue_transizione_schermo_testo_bitmap(void)

{
  short sVar2;
  uint uVar1;
  char cVar3;
  undefined1 *puVar4;
  
  sfonda_colori_e_pulisci_schermo();
  riempi_schermo_colore_2();
  flag_disabilita_sfondo = 1;
  stato_font_corrente = 0;
  flag_render_testo_tabella = 1;
  renderizza_testo_da_tabella();
  flag_render_testo_tabella = 0;
  renderizza_testo_da_tabella();
  routine_vuota();
  puVar4 = &LAB_0000ca62;
  sVar2 = 0x1100;
  do {
    uVar1 = CONCAT31((uint3)(byte)((ushort)sVar2 >> 8),2);
    do {
      while( true ) {
        sVar2 = (short)uVar1;
        _larghezza_finestra_caratteri = 0x208;
        disegna_glifo(uVar1,puVar4);
        uVar1 = (uint)(ushort)(sVar2 + 2U);
        cVar3 = (char)(sVar2 + 2U);
        if (cVar3 != '\f') break;
        uVar1 = (uint)(ushort)(sVar2 + 4);
      }
    } while (cVar3 != '\x18');
    sVar2 = sVar2 + 0x102;
  } while ((char)((ushort)sVar2 >> 8) != '\x18');
  disegna_bitmap_mascherata();
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 1;
  processa_e_visualizza_testo_formattato();
  flag_render_testo_tabella = 0;
  return;
}


/* $0c4f4 visualizza_testo_con_font_attivo: Attiva flag selezione font, processa e visualizza testo formattato con codici controllo, poi disattiva flag */

/* Attiva flag selezione font, processa e visualizza testo formattato con codici controllo, poi
   disattiva flag */

void visualizza_testo_con_font_attivo(void)

{
  flag_selezione_font = 1;
  processa_e_visualizza_testo_formattato();
  flag_selezione_font = 0;
  return;
}


/* $0c50e renderizza_testo_da_tabella: Analizza stringhe di controllo, per ciascuna legge valori da tabella 4 byte e cancella il resto riga. */

/* Analizza stringhe di controllo, per ciascuna legge valori da tabella 4 byte e cancella il resto
   riga. */

void renderizza_testo_da_tabella(void)

{
  char cVar1;
  char unaff_D6b;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = "[\x03\\";
  for (; pcVar3 = pcVar2, unaff_D6b != '\0'; unaff_D6b = unaff_D6b + -1) {
    do {
      pcVar2 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar2;
    } while (cVar1 != -1);
  }
  for (; *pcVar2 != -1; pcVar2 = pcVar2 + 2) {
    leggi_valore_tabella_4byte();
    cancella_resto_riga();
  }
  return;
}


/* $0c550 inizializza_elemento_controllo_attivo: Seleziona l'elemento UI attivo in base a tipo_controllo, imposta dimensioni finestra 5x48 caratteri. */

/* Seleziona l'elemento UI attivo in base a tipo_controllo, imposta dimensioni finestra 5x48
   caratteri. */

void inizializza_elemento_controllo_attivo(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = tipo_controllo - 1;
  if (bVar2 != 0) {
    gestisci_timer_attesa_ciclica();
  }
  while (((&array_stato_attivo_4_elementi)[bVar2] & 0x80) != 0) {
    bVar2 = bVar2 + 1;
  }
  indice_elemento_attivo = bVar2;
  for (cVar1 = (&array_durata_elementi)[bVar2]; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  larghezza_finestra_caratteri = 5;
  altezza_finestra_caratteri = 0x30;
  return;
}


/* $0c564 trova_elemento_e_imposta_finestra: Trova il primo elemento attivo nell'array e imposta le dimensioni della finestra. */

/* Trova il primo elemento attivo nell'array e imposta le dimensioni della finestra. */

void trova_elemento_e_imposta_finestra(void)

{
  char cVar1;
  byte unaff_D6b;
  
  while (((&array_stato_attivo_4_elementi)[unaff_D6b] & 0x80) != 0) {
    unaff_D6b = unaff_D6b + 1;
  }
  indice_elemento_attivo = unaff_D6b;
  for (cVar1 = (&array_durata_elementi)[unaff_D6b]; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  larghezza_finestra_caratteri = 5;
  altezza_finestra_caratteri = 0x30;
  return;
}


/* $0c5cc disegna_elementi_tabella_mascherati: Disegna grafica mascherata per elementi usando parametri da tabella lookup */

/* Disegna grafica mascherata per elementi usando parametri da tabella lookup */

void disegna_elementi_tabella_mascherati(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = (&tabella_parametri_controllo)[(byte)(tipo_controllo - 1)];
  valore_minimo_trovato = '\0';
  cVar1 = tipo_controllo;
  do {
    trova_elemento_e_imposta_finestra(cVar2);
    disegna_grafica_mascherata();
    cVar2 = cVar2 + '\x05';
    valore_minimo_trovato = indice_elemento_attivo + '\x01';
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}


/* $0c62a disegna_interfaccia_tipo_controllo: Disegna interfaccia grafica variando parametri in base al tipo di controllo */

/* Disegna interfaccia grafica variando parametri in base al tipo di controllo */

void disegna_interfaccia_tipo_controllo(void)

{
  undefined4 uVar1;
  char cVar2;
  char cVar3;
  
  if ((tipo_controllo != '\0') &&
     ((cVar2 = tipo_controllo, flag_tipo_controllo_1 == '\0' ||
      (cVar2 = flag_controllo_secondario, flag_controllo_secondario != '\0')))) {
    cVar3 = '\x14';
    uVar1 = 2;
    if (cVar2 == '\x04') {
      cVar3 = '\x15';
    }
    else {
      if (cVar2 == '\x01') {
        cVar3 = '\x12';
      }
      if (cVar2 == '\x02') {
        uVar1 = 5;
      }
    }
    valore_minimo_trovato = '\0';
    do {
      trova_elemento_e_imposta_finestra(uVar1,cVar3);
      disegna_grafica_mascherata();
      cVar3 = cVar3 - (char)uVar1;
      valore_minimo_trovato = indice_elemento_attivo + '\x01';
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    return;
  }
  disegna_immagine_4_bitplane();
  return;
}


/* $0c6d8 disegna_sequenza_elementi_mascherati: Disegna sequenza di elementi mascherati incrementando offset finestra */

/* Disegna sequenza di elementi mascherati incrementando offset finestra */

void disegna_sequenza_elementi_mascherati(void)

{
  char unaff_D4b;
  char unaff_D6b;
  
  valore_minimo_trovato = '\0';
  do {
    trova_elemento_e_imposta_finestra(unaff_D4b);
    disegna_grafica_mascherata();
    unaff_D4b = unaff_D4b + '\a';
    valore_minimo_trovato = indice_elemento_attivo + '\x01';
    unaff_D6b = unaff_D6b + -1;
  } while (unaff_D6b != '\0');
  return;
}


/* $0c71c sequenza_intro_gioco_completa: Sequenza intro completa con ramificazione modalità testo: fade, riempimento, testi, immagini, 4 bitmap, audio finale */

/* Sequenza intro completa con ramificazione modalità testo: fade, riempimento, testi, immagini, 4
   bitmap, audio finale */

void sequenza_intro_gioco_completa(void)

{
  undefined *puVar1;
  
  sfonda_colori_e_pulisci_schermo();
  riempi_schermo_colore_7();
  stato_font_corrente = 0;
  flag_disabilita_sfondo = 1;
  if (flag_modalita_testo == '\0') {
    processa_e_visualizza_testo_formattato();
    disegna_immagine_4_bitplane();
  }
  else {
    processa_e_visualizza_testo_formattato();
    processa_e_visualizza_testo_formattato();
    visualizza_testo_con_font_attivo(flag_modalita_testo);
    visualizza_testo_con_font_attivo();
    decrementa_valore_128ce();
    decrementa_valore_128ce();
  }
  visualizza_testo_con_font_attivo();
  flag_selezione_font = 1;
  puVar1 = &puntatore_bitmap_mascherata;
  disegna_bitmap_mascherata(&puntatore_bitmap_mascherata);
  disegna_bitmap_mascherata(puVar1);
  disegna_bitmap_mascherata(puVar1);
  disegna_bitmap_mascherata();
  flag_selezione_font = 0;
  renderizza_testo_da_tabella(tipo_controllo);
  disegna_sequenza_elementi_mascherati();
  stato_font_corrente = 1;
  flag_disabilita_sfondo = 0;
  copia_schermo_intero_in_buffer();
  imposta_colori_copper_4();
  avvia_sequenza_audio_testo_lungo();
  sfonda_colori_e_pulisci_schermo();
  return;
}


/* $0d084 processa_input_testo_riquadro_menu: Processa input tastiera in riquadro menu: buffer 30 char, backspace, invio, caratteri validi, refresh grafico */

/* Processa input tastiera in riquadro menu: buffer 30 char, backspace, invio, caratteri validi,
   refresh grafico */

void processa_input_testo_riquadro_menu(void)

{
  byte bVar1;
  undefined2 uVar2;
  byte *pbVar3;
  byte bVar4;
  
  do {
    inizializza_buffer_spazi();
    bVar1 = 5;
    aggiorna_riquadro_menu_con_grafica();
    stampa_testo();
    pbVar3 = &buffer_testo_spazi;
    bVar4 = 0;
    while( true ) {
      copia_grafica_707c6_in_buffer_video();
      routine_vuota();
      attendi_tasto();
      bVar4 = bVar4 & 0x7f;
      if (bVar4 == 0x1b) break;
      uVar2 = (undefined2)((uint)pbVar3 >> 0x10);
      if (bVar4 == 0x7f) {
        if (bVar1 != 1) {
          disegna_sfondo_carattere();
          bVar1 = bVar1 - 1;
          seleziona_font();
          pbVar3 = (byte *)CONCAT22(uVar2,(short)pbVar3 + -1);
          bVar4 = *pbVar3;
        }
      }
      else {
        if (bVar4 == 0xd) {
          *pbVar3 = 0xa0;
          routine_vuota();
          return;
        }
        if (((0x1e < bVar4) && (bVar4 < 0x5b)) && (bVar4 = bVar1, bVar1 != 0x1d)) {
          *pbVar3 = tasto_premuto;
          disegna_sfondo_carattere(tasto_premuto);
          pbVar3 = (byte *)CONCAT22(uVar2,(short)pbVar3 + 1);
          seleziona_font();
          bVar1 = bVar1 + 1;
          bVar4 = 0x40;
          seleziona_font();
        }
      }
    }
  } while( true );
}


/* $0d124 inizializza_buffer_spazi: Riempie un buffer di testo con 30 spazi e appone il terminatore 0xFF. */

/* Riempie un buffer di testo con 30 spazi e appone il terminatore 0xFF. */

void inizializza_buffer_spazi(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  sVar1 = 0x1d;
  puVar3 = &buffer_testo_spazi;
  do {
    puVar2 = puVar3 + 1;
    *puVar3 = 0x20;
    sVar1 = sVar1 + -1;
    puVar3 = puVar2;
  } while (sVar1 != -1);
  *puVar2 = 0xff;
  return;
}


/* $0d138 processa_acquisto_testo_soldi: In modalita testo azzera timer, sottrae soldi BCD, mostra messaggio e aggiorna interfaccia */

/* WARNING: Removing unreachable block (ram,0x0000d15e) */
/* WARNING: Removing unreachable block (ram,0x0000d176) */
/* WARNING: Removing unreachable block (ram,0x0000d1ec) */
/* WARNING: Removing unreachable block (ram,0x0000d1ae) */
/* In modalita testo azzera timer, sottrae soldi BCD, mostra messaggio e aggiorna interfaccia */

void processa_acquisto_testo_soldi(void)

{
  if (flag_modalita_testo == '\0') {
    if (0x95 < qualita_esibizione_band) {
      gestisci_timer_attesa_ciclica();
    }
  }
  else if (contatore_timer_attesa == '\0') {
    inizializza_schermo_audio_e_renderizza();
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    azzera_buffer_8_byte();
    flag_sottratto_soldi = 1;
    sottrai_soldi_gestisci_underflow();
    pausa_messaggio();
    aggiorna_schermo_base_grafica();
    aggiorna_stato_ciclo_gioco_principale();
    flag_modalita_testo = 0;
    return;
  }
  return;
}


/* $0d24c gestisci_classifica_punteggi_attiva: Se classifiche attive e cursore basso, avvia audio, verifica soldi e aggiorna stato gioco */

/* WARNING: Removing unreachable block (ram,0x0000d326) */
/* WARNING: Removing unreachable block (ram,0x0000d336) */
/* WARNING: Removing unreachable block (ram,0x0000d306) */
/* WARNING: Removing unreachable block (ram,0x0000d308) */
/* WARNING: Removing unreachable block (ram,0x0000d310) */
/* WARNING: Removing unreachable block (ram,0x0000d2f6) */
/* WARNING: Removing unreachable block (ram,0x0000d2f0) */
/* Se classifiche attive e cursore basso, avvia audio, verifica soldi e aggiorna stato gioco */

void gestisci_classifica_punteggi_attiva(void)

{
  if (((flag_classifiche_attive == '\0') && (flag_eventi_classifiche_pending != '\0')) &&
     (199 < qualita_esibizione_band)) {
    inizializza_schermo_audio_e_renderizza();
    flag_classifiche_attive = '\x01';
    flag_scrolling_attivo = 0xf;
    inizializza_schermo_principale_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    menu_attendi_scelta();
    azzera_tre_buffer_8_byte(0xac);
    gestisci_timer_attesa_ciclica();
    contatore_verifica_soldi = 4;
    verifica_e_aggiorna_saldo_soldi();
    attendi_input_gioco_con_timeout_59_frame();
    aggiorna_schermo_base_grafica();
    aggiorna_stato_ciclo_gioco_principale();
  }
  return;
}


/* $0d33a attiva_flag_128b1: Imposta a 1 il flag di stato DAT_000128b1. */

/* Imposta a 1 il flag di stato DAT_000128b1. */

void attiva_flag_128b1(void)

{
  flag_abilitazione_schermo = 1;
  return;
}


/* $0d344 disattiva_flag_128b1: Azzera il flag di stato DAT_000128b1. */

/* Azzera il flag di stato DAT_000128b1. */

void disattiva_flag_128b1(void)

{
  flag_abilitazione_schermo = 0;
  return;
}


/* $0d348 attendi_input_gioco_con_timeout_59_frame: Inizializza schermo e attende input joystick/fuoco per 59 frame (circa 1 sec) o fino a pressione tasto */

/* Inizializza schermo e attende input joystick/fuoco per 59 frame (circa 1 sec) o fino a pressione
   tasto */

void attendi_input_gioco_con_timeout_59_frame(void)

{
  short sVar1;
  undefined1 *extraout_A0;
  undefined1 *puVar2;
  
  inizializza_schermo_principale_completo();
  codice_azione_input = '\0';
  sVar1 = 4;
  do {
    pausa_breve();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = 0x3b;
  while( true ) {
    pausa_breve();
    leggi_input_joystick_fuoco();
    if (flag_blocco_input != '\0') break;
    puVar2 = &codice_azione_input;
    if (codice_azione_input == '\x01') goto l_0d390;
    sVar1 = sVar1 + -1;
    if (sVar1 == -1) {
      return;
    }
  }
  do {
    puVar2 = extraout_A0;
  } while (flag_blocco_input != '\0');
l_0d390:
  *puVar2 = 0;
  return;
}


/* $0d34c pausa_messaggio: pausa dopo un messaggio (65 pause brevi), interrompibile; con spazio premuto aspetta il rilascio */

/* pausa dopo un messaggio (65 pause brevi), interrompibile; con spazio premuto aspetta il rilascio
    */

void pausa_messaggio(void)

{
  short sVar1;
  undefined1 *extraout_A0;
  undefined1 *puVar2;
  
  codice_azione_input = '\0';
  sVar1 = 4;
  do {
    pausa_breve();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = 0x3b;
  while( true ) {
    pausa_breve();
    leggi_input_joystick_fuoco();
    if (flag_blocco_input != '\0') break;
    puVar2 = &codice_azione_input;
    if (codice_azione_input == '\x01') goto l_0d390;
    sVar1 = sVar1 + -1;
    if (sVar1 == -1) {
      return;
    }
  }
  do {
    puVar2 = extraout_A0;
  } while (flag_blocco_input != '\0');
l_0d390:
  *puVar2 = 0;
  return;
}


/* $0d3a6 confronta_sequenza_mastermind: Esegue il confronto su 10 caratteri consecutivi invocando la routine mastermind per ciascuna posizione. */

/* Esegue il confronto su 10 caratteri consecutivi invocando la routine mastermind per ciascuna
   posizione. */

void confronta_sequenza_mastermind(void)

{
  char cVar1;
  
  cVar1 = '\0';
  do {
    confronta_carattere_mastermind();
    cVar1 = cVar1 + '\x01';
  } while (cVar1 != '\n');
  return;
}


/* $0d3ba confronta_carattere_mastermind: Confronta caratteri tra buffer e imposta il simbolo di corrispondenza esatta, parziale o assente. */

/* Confronta caratteri tra buffer e imposta il simbolo di corrispondenza esatta, parziale o assente.
    */

void confronta_carattere_mastermind(void)

{
  byte unaff_D6b;
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  
  puVar4 = &buffer_sorgente_confronto_1;
  puVar3 = &buffer_destinazione_12424;
  if (flag_seleziona_buffer_dati != '\0') {
    puVar4 = &buffer_sorgente_confronto_2;
    puVar3 = &buffer_destinazione_12442;
  }
  if (puVar4[unaff_D6b] == puVar3[unaff_D6b]) {
    uVar2 = 0x2a;
  }
  else {
    if (unaff_D6b != 0) {
      pcVar5 = &buffer_destinazione_12424;
      bVar1 = unaff_D6b;
      if (flag_seleziona_buffer_dati != '\0') {
        pcVar5 = &buffer_destinazione_12442;
      }
      do {
        if (puVar4[unaff_D6b] == *pcVar5) {
          uVar2 = 0x2b;
          goto l_0d426;
        }
        pcVar5 = pcVar5 + 1;
        bVar1 = bVar1 - 1;
      } while (bVar1 != 0);
    }
    uVar2 = 0x3c;
  }
l_0d426:
  (&buffer_risultati_confronto)[unaff_D6b] = uVar2;
  return;
}


/* $0d440 gestisci_timer_attesa_ciclica: Gestisce attesa temporizzata CIA con indice buffer circolare per sincronizzazione */

/* Gestisce attesa temporizzata CIA con indice buffer circolare per sincronizzazione */

void gestisci_timer_attesa_ciclica(void)

{
  uint uVar1;
  byte unaff_D6b;
  
  gestisci_tempo_attesa_ciaa();
  valore_attesa_timer = unaff_D6b;
  attendi_timer_ciaa();
  indice_buffer_timer = unaff_D6b & 0x7f;
  do {
    uVar1 = (uint)indice_buffer_timer;
    indice_buffer_timer = indice_buffer_timer + 1 & 0x3f;
  } while (valore_attesa_timer < (byte)(&tabella_intervalli_timer)[uVar1]);
  return;
}


/* $0d44a gestisci_tempo_attesa_ciaa: Imposta il contatore di attesa e attende il completamento dell'intervallo temporale tramite il timer CIAA. */

/* Imposta il contatore di attesa e attende il completamento dell'intervallo temporale tramite il
   timer CIAA. */

void gestisci_tempo_attesa_ciaa(void)

{
  uint uVar1;
  byte unaff_D6b;
  
  valore_attesa_timer = unaff_D6b;
  attendi_timer_ciaa();
  indice_buffer_timer = unaff_D6b & 0x7f;
  do {
    uVar1 = (uint)indice_buffer_timer;
    indice_buffer_timer = indice_buffer_timer + 1 & 0x3f;
  } while (valore_attesa_timer < (byte)(&tabella_intervalli_timer)[uVar1]);
  return;
}


/* $0d48e stampa_testo: impagina e disegna un testo nel riquadro dei messaggi */

/* impagina e disegna un testo nel riquadro dei messaggi */

void stampa_testo(void)

{
  undefined4 uVar1;
  ushort uVar2;
  char cVar3;
  uint unaff_D4;
  undefined4 uVar4;
  ushort unaff_D5w;
  uint unaff_D6;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  pcVar6 = "";
  uVar5 = unaff_D6 & 0xffff0000;
  indice_minimo_trovato = (byte)(unaff_D4 >> 8);
  puVar7 = (undefined4 *)register0x0000003c;
  do {
    *(uint *)((int)puVar7 + -4) = unaff_D4;
    *(char **)((int)puVar7 + -8) = pcVar6;
    valore_minimo_trovato = '\x01';
    DAT_0001286b = '\x01';
    do {
      if (*pcVar6 == -1) {
        DAT_0001286b = valore_minimo_trovato;
        break;
      }
      if (*pcVar6 == ' ') {
        DAT_0001286b = valore_minimo_trovato;
      }
      uVar2 = (short)unaff_D4 + 1;
      unaff_D4 = (uint)uVar2;
      valore_minimo_trovato = valore_minimo_trovato + '\x01';
      pcVar6 = pcVar6 + 1;
    } while ((char)uVar2 != (char)unaff_D5w);
    pcVar6 = *(char **)((int)puVar7 + -8);
    uVar4 = *(undefined4 *)((int)puVar7 + -4);
    puVar8 = (undefined4 *)((int)puVar7 + -4);
    *(undefined4 *)((int)puVar7 + -4) = uVar4;
    uVar5 = CONCAT31((int3)(uVar5 >> 8),DAT_0001286b);
    if (DAT_0001286b == '\x01') {
      uVar5 = (uint)(byte)((char)unaff_D5w - (char)uVar4);
    }
    puVar9 = (undefined4 *)((int)puVar7 + -8);
    *(uint *)((int)puVar7 + -8) = uVar5;
    if (*pcVar6 == -1) {
      return;
    }
    if (*pcVar6 != ' ') goto l_0d500;
    pcVar6 = pcVar6 + 1;
    uVar4 = *(undefined4 *)((int)puVar7 + -8);
    do {
      puVar9 = (undefined4 *)((int)puVar8 + -4);
      *(undefined4 *)((int)puVar8 + -4) = uVar4;
l_0d500:
      if (*pcVar6 == -1) {
        return;
      }
      puVar9[-1] = 0xd510;
      seleziona_font();
      pcVar6 = pcVar6 + 1;
      puVar8 = puVar9 + 1;
      uVar1 = *puVar9;
      cVar3 = (char)uVar1 + -1;
      uVar4 = CONCAT31((int3)((uint)uVar1 >> 8),cVar3);
    } while (cVar3 != '\0');
    uVar4 = puVar9[1];
    if (flag_selezione_font != '\0') {
      uVar4 = CONCAT22((short)((uint)uVar4 >> 0x10),(short)uVar4 + 0x100);
    }
    uVar2 = (short)uVar4 + 0x100;
    unaff_D4 = CONCAT22((short)((uint)uVar4 >> 0x10),uVar2);
    uVar5 = CONCAT22((short)((uint)uVar1 >> 0x10),uVar2) & 0xffffff00;
    puVar7 = puVar9 + 2;
    if ((uVar2 & 0xff00) == (unaff_D5w & 0xff00)) {
      unaff_D4 = (uint)(ushort)((ushort)indice_minimo_trovato << 8 | uVar2 & 0xff);
      puVar9[1] = 0xd560;
      cancella_resto_riga();
      puVar7 = puVar9 + 2;
    }
  } while( true );
}


/* $0d586 disegna_sfondo_area_testo: Legge le coordinate da una tabella a 4 byte e ridisegna lo sfondo dei caratteri nell'area delimitata. */

/* Legge le coordinate da una tabella a 4 byte e ridisegna lo sfondo dei caratteri nell'area
   delimitata. */

void disegna_sfondo_area_testo(void)

{
  ushort uVar1;
  ushort unaff_D4w;
  ushort uVar2;
  ushort unaff_D5w;
  
  leggi_valore_tabella_4byte();
  uVar1 = unaff_D4w;
  if (flag_disabilita_sfondo == '\0') {
    do {
      do {
        uVar2 = uVar1;
        disegna_sfondo_carattere();
        uVar1 = uVar2 + 1;
      } while ((char)uVar1 != (char)unaff_D5w);
      uVar2 = uVar2 + 0x101 & 0xff00;
      unaff_D4w = uVar2 | unaff_D4w & 0xff;
      uVar1 = unaff_D4w;
    } while (uVar2 != (unaff_D5w & 0xff00));
    return;
  }
  return;
}


/* $0d598 cancella_resto_riga: pulisce la riga di testo dopo l'ultimo carattere */

/* pulisce la riga di testo dopo l'ultimo carattere */

void cancella_resto_riga(void)

{
  ushort uVar1;
  ushort unaff_D4w;
  ushort uVar2;
  ushort unaff_D5w;
  
  uVar1 = unaff_D4w;
  do {
    do {
      uVar2 = uVar1;
      disegna_sfondo_carattere();
      uVar1 = uVar2 + 1;
    } while ((char)uVar1 != (char)unaff_D5w);
    uVar2 = uVar2 + 0x101 & 0xff00;
    unaff_D4w = uVar2 | unaff_D4w & 0xff;
    uVar1 = unaff_D4w;
  } while (uVar2 != (unaff_D5w & 0xff00));
  return;
}


/* $0d5ca avanza_puntatore_stringhe_ff: Avanza il puntatore di memoria saltando un numero di stringhe terminate da 0xFF. */

/* Avanza il puntatore di memoria saltando un numero di stringhe terminate da 0xFF. */

void avanza_puntatore_stringhe_ff(void)

{
  char cVar1;
  short unaff_D4w;
  char *unaff_A3;
  char *pcVar2;
  
  for (; pcVar2 = unaff_A3, unaff_D4w != 0; unaff_D4w = unaff_D4w + -1) {
    do {
      unaff_A3 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = unaff_A3;
    } while (cVar1 != -1);
  }
  return;
}


/* $0d5de avanza_puntatore_stringhe_bit7: Avanza il puntatore di memoria saltando stringhe terminate da un carattere con bit 7 attivo. */

/* Avanza il puntatore di memoria saltando stringhe terminate da un carattere con bit 7 attivo. */

void avanza_puntatore_stringhe_bit7(void)

{
  byte bVar1;
  short unaff_D4w;
  byte *unaff_A3;
  byte *pbVar2;
  
  for (; pbVar2 = unaff_A3, unaff_D4w != 0; unaff_D4w = unaff_D4w + -1) {
    do {
      unaff_A3 = pbVar2 + 1;
      bVar1 = *pbVar2;
      pbVar2 = unaff_A3;
    } while ((bVar1 & 0x80) == 0);
  }
  return;
}


/* $0d5f4 inizializza_schermo_principale_completo: Inizializzazione completa schermo gioco: copia grafica base, renderizza strati con ritardo, testo senza sfondo, salva area video, copia grafica parziale */

/* Inizializzazione completa schermo gioco: copia grafica base, renderizza strati con ritardo, testo
   senza sfondo, salva area video, copia grafica parziale */

void inizializza_schermo_principale_completo(void)

{
  copia_grafica_5c70a_su_schermo();
  renderizza_strati_grafici_con_ritardo();
  flag_disabilita_sfondo = 1;
  stato_font_corrente = 0;
  processa_e_visualizza_testo_formattato();
  stato_font_corrente = 1;
  flag_disabilita_sfondo = 0;
  salva_area_memoria_video();
  copia_parziale_grafica_6f8c6();
  return;
}


/* $0d638 processa_e_visualizza_testo_formattato: Interpreta script con codici controllo (0x20/0x40/0x80), formatta valori BCD, gestisce timer, disegna sfondo e stampa testo finale */

/* Interpreta script con codici controllo (0x20/0x40/0x80), formatta valori BCD, gestisce timer,
   disegna sfondo e stampa testo finale */

void processa_e_visualizza_testo_formattato(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  
  valore_minimo_trovato = '\0';
  pbVar7 = &dati_script_testo;
  avanza_puntatore_stringhe_ff();
  do {
    bVar1 = *pbVar7;
    uVar3 = (ushort)bVar1;
    if (bVar1 == 0xff) break;
    pbVar6 = pbVar7 + 1;
    pbVar7 = pbVar7 + 2;
    bVar5 = *pbVar6;
    uVar3 = CONCAT11(bVar1,bVar5);
    if ((bVar1 & 0x20) == 0) {
      if ((bVar1 & 0x40) == 0) {
        if ((bVar1 & 0x80) != 0) {
          avanza_puntatore_stringhe_ff();
          bVar1 = contatore_stringhe_ff;
          valore_attesa_timer = contatore_stringhe_ff;
          gestisci_timer_attesa_ciclica(&contatore_stringhe_ff);
          uVar3 = (ushort)bVar1;
        }
        avanza_puntatore_stringhe_bit7();
        goto l_0d712;
      }
      pcVar8 = &buffer_stato_controlli;
      iVar4 = 0x20;
      if (0xb < bVar5) {
        bVar5 = bVar5 - 0xc;
        iVar4 = 0x14;
        pcVar8 = "";
      }
      for (; bVar5 != 0; bVar5 = bVar5 - 1) {
        pcVar8 = pcVar8 + iVar4;
      }
      if (*pcVar8 == '\0') goto l_0d712;
      processa_elenco_stringhe();
    }
    else {
      pcVar8 = &buffer_bcd_sorgente;
      for (; bVar5 != 0; bVar5 = bVar5 - 1) {
        pcVar8 = pcVar8 + 9;
      }
      sVar2 = 6;
      do {
        if (*pcVar8 != '\0') break;
        pcVar8 = pcVar8 + 1;
        sVar2 = sVar2 + -1;
      } while (sVar2 != -1);
l_0d712:
      formatta_e_copia_stringa_in_buffer();
    }
  } while (valore_minimo_trovato != -1);
  disegna_sfondo_area_testo();
  stampa_testo(uVar3);
  return;
}


/* $0d73e formatta_e_copia_stringa_in_buffer: Formatta e accoda caratteri nel buffer 122c8 convertendo cifre e gestendo la punteggiatura. */

/* Formatta e accoda caratteri nel buffer 122c8 convertendo cifre e gestendo la punteggiatura. */

void formatta_e_copia_stringa_in_buffer(void)

{
  byte *unaff_D5;
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (valore_minimo_trovato == 0xff) {
    return;
  }
  pbVar2 = &buffer_stringa_messa_in_pagine + valore_minimo_trovato;
  do {
    if (*unaff_D5 < 10) {
      bVar1 = (*unaff_D5 & 0x7f) + 0x30;
l_0d7b4:
      *pbVar2 = bVar1;
      valore_minimo_trovato = valore_minimo_trovato + 1;
      pbVar3 = pbVar2;
      if (valore_minimo_trovato == 0xff) {
l_0d7dc:
        *pbVar2 = 0xff;
        return;
      }
    }
    else {
      bVar1 = *unaff_D5 & 0x7f;
      if (((((bVar1 != 0x21) && (bVar1 != 0x2c)) && (bVar1 != 0x2e)) && (bVar1 != 0x3f)) ||
         (pbVar3 = pbVar2 + -1, *pbVar3 != 0x20)) {
        bVar1 = *unaff_D5 & 0x7f;
        goto l_0d7b4;
      }
      *pbVar3 = *unaff_D5;
    }
    pbVar2 = pbVar3 + 1;
    if ((*unaff_D5 & 0x80) == 0x80) goto l_0d7dc;
    unaff_D5 = unaff_D5 + 1;
  } while( true );
}


/* $0d7e4 leggi_valore_tabella_4byte: Cerca un record di 4 byte in una tabella e ne restituisce il terzo byte traslato di 8 bit. */

/* Cerca un record di 4 byte in una tabella e ne restituisce il terzo byte traslato di 8 bit. */

short leggi_valore_tabella_4byte(void)

{
  char unaff_D6b;
  char *pcVar1;
  
  for (pcVar1 = "\x16\x01\x17\x1f"; (unaff_D6b != '\0' && (*pcVar1 != -1)); pcVar1 = pcVar1 + 4) {
    unaff_D6b = unaff_D6b + -1;
  }
  return (ushort)(byte)pcVar1[2] << 8;
}


/* $0d814 routine_vuota: Funzione vuota usata come punto di ritorno neutro o segnaposto. */

/* Funzione vuota usata come punto di ritorno neutro o segnaposto. */

void routine_vuota(void)

{
  return;
}


/* $0d816 aggiorna_riquadro_menu_con_grafica: Aggiorna riquadro menu: legge coordinate da tabella, pulisce bordi e riga, visualizza testo formattato, copia grafica condizionale nel buffer video */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Aggiorna riquadro menu: legge coordinate da tabella, pulisce bordi e riga, visualizza testo
   formattato, copia grafica condizionale nel buffer video */

void aggiorna_riquadro_menu_con_grafica(void)

{
  short unaff_D4w;
  short unaff_D5w;
  
  leggi_valore_tabella_4byte();
  _coordinata_y_finestra = unaff_D5w + 1;
  _coordinata_x_finestra = unaff_D4w + -1;
  cancella_resto_riga();
  pulisci_bordi_riquadro();
  processa_e_visualizza_testo_formattato();
  indirizzo_tabella_dati = 0;
  if (flag_stato_mouse_sinistro == '\0') {
    copia_grafica_6f8c6_in_buffer_video();
    copia_grafica_707c6_in_buffer_video();
  }
  flag_stato_mouse_sinistro = 0;
  return;
}


/* $0d86c pulisci_bordi_riquadro: Pulisce i bordi esterni e i margini di un riquadro nei 4 bitplanes della memoria video. */

/* Pulisce i bordi esterni e i margini di un riquadro nei 4 bitplanes della memoria video. */

void pulisci_bordi_riquadro(void)

{
  short sVar1;
  uint unaff_D4;
  uint uVar2;
  ushort uVar3;
  ushort unaff_D5w;
  char cVar4;
  byte *unaff_A3;
  byte *pbVar5;
  
  uVar2 = unaff_D4;
  do {
    maschera_byte_superiore_d4();
    sVar1 = 7;
    do {
      *unaff_A3 = *unaff_A3 & 0x7f;
      unaff_A3[8000] = unaff_A3[8000] & 0x7f;
      unaff_A3[16000] = unaff_A3[16000] & 0x7f;
      unaff_A3[24000] = unaff_A3[24000] & 0x7f;
      unaff_A3 = unaff_A3 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    uVar3 = (short)uVar2 + 0x100;
    uVar2 = (uint)uVar3;
  } while ((uVar3 & 0xff00) != (unaff_D5w & 0xff00));
  cVar4 = (char)unaff_D5w;
  uVar3 = (short)CONCAT31((int3)(unaff_D4 >> 8),cVar4) - 1;
  do {
    maschera_byte_superiore_d4();
    sVar1 = 7;
    do {
      pbVar5 = unaff_A3;
      *pbVar5 = *pbVar5 & 0xfe;
      pbVar5[8000] = pbVar5[8000] & 0xfe;
      pbVar5[16000] = pbVar5[16000] & 0xfe;
      pbVar5[24000] = pbVar5[24000] & 0xfe;
      unaff_A3 = pbVar5 + 0x28;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    uVar3 = uVar3 + 0x100;
  } while ((uVar3 & 0xff00) != (unaff_D5w & 0xff00));
  maschera_byte_superiore_d4();
  uVar2 = unaff_D4;
  do {
    *unaff_A3 = 0;
    pbVar5[0x1f68] = 0;
    pbVar5[0x3ea8] = 0;
    pbVar5[0x5de8] = 0;
    uVar3 = (short)uVar2 + 1;
    uVar2 = (uint)uVar3;
    maschera_byte_superiore_d4();
  } while (cVar4 != (char)uVar3);
  sVar1 = ((ushort)unaff_D4 & 0xff) - 0x100;
  indirizzo_schermo();
  do {
    *unaff_A3 = 0;
    pbVar5[0x1f68] = 0;
    pbVar5[0x3ea8] = 0;
    pbVar5[0x5de8] = 0;
    sVar1 = sVar1 + 1;
    indirizzo_schermo();
  } while (cVar4 != (char)sVar1);
  return;
}


/* $0d94a ciclo_principale_menu_joystick: Ciclo menu principale: aggiorna bitplane, tavolozza, input joystick, renderizza scena */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Ciclo menu principale: aggiorna bitplane, tavolozza, input joystick, renderizza scena */

void ciclo_principale_menu_joystick(void)

{
  char cVar1;
  undefined4 unaff_D4;
  undefined2 unaff_D5w;
  undefined4 local_4;
  
  if (flag_modalita_schermo == '\0') {
    local_4 = CONCAT22((short)((uint)unaff_D4 >> 0x10),_coordinata_x_finestra);
    coordinata_y_schermo_d080 = (char)_coordinata_x_finestra * '\b' + -6;
    coordinata_x_schermo_d081 = (char)(_coordinata_x_finestra >> 5) - 4;
    coordinata_x_schermo_max =
         (char)(CONCAT11((char)((ushort)unaff_D5w >> 8),coordinata_y_finestra) >> 5) + -0xc;
    register0x0000003c = (BADSPACEBASE *)&local_4;
    coordinata_x_schermo_min = coordinata_x_schermo_d081;
  }
  indirizzo_tabella_dati = flag_modalita_schermo != '\0';
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9a4;
  aggiorna_bitplane_e_grafica();
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9a8;
  attendi_passaggio_pennello();
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9ac;
  carica_tavolozza_schermo_1();
  *(undefined4 *)((int)register0x0000003c + -4) = 0xd9b0;
  attesa_rilascio_tasto_destro_mouse();
  while( true ) {
    *(undefined4 *)register0x0000003c = 0xd9b6;
    leggi_input_joystick_fuoco();
    *(undefined4 *)register0x0000003c = 0xd9ba;
    aggiorna_scorrimento_tavolozza();
    if (codice_azione_input == '\x01') break;
    if (((coordinata_x_schermo_d081 & 7) == 0) || ((coordinata_x_schermo_d081 & 7) == 7)) {
      cVar1 = ((coordinata_x_schermo_d081 >> 3) - coordinata_x_finestra) + '\x01';
      if (indirizzo_tabella_dati != cVar1) {
        *(undefined4 *)register0x0000003c = 0xda22;
        indirizzo_tabella_dati = cVar1;
        copia_bitplane_2_in_1();
        *(undefined4 *)register0x0000003c = 0xda26;
        aggiorna_bitplane_e_grafica();
      }
    }
  }
  codice_azione_input = 0;
  *(undefined4 *)register0x0000003c = 0xd9ce;
  renderizza_scena_condizionale();
  *(undefined4 *)register0x0000003c = 0xd9d2;
  renderizza_interfaccia_gioco_completa();
  *(undefined4 *)register0x0000003c = 0xd9d6;
  copia_grafica_6f8c6_in_buffer_video();
  *(undefined4 *)register0x0000003c = 0xd9da;
  copia_grafica_707c6_in_buffer_video();
  *(undefined4 *)register0x0000003c = 0xd9de;
  carica_tavolozza_schermo_2();
  return;
}


/* $0da28 disegna_strati_grafici_mascherati: Disegna elementi tabella (contatore=4) o controlli (contatore=2), poi sempre bitmap principale mascherata. */

/* Disegna elementi tabella (contatore=4) o controlli (contatore=2), poi sempre bitmap principale
   mascherata. */

void disegna_strati_grafici_mascherati(void)

{
  char cVar1;
  
  if (contatore_cicli_ritardo == '\x04') {
    disegna_elementi_tabella_mascherati();
    cVar1 = contatore_cicli_ritardo;
  }
  else {
    cVar1 = contatore_cicli_ritardo;
    if (contatore_cicli_ritardo == '\x02') {
      disegna_elementi_controllo_mascherati();
      cVar1 = contatore_cicli_ritardo;
    }
  }
  do {
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  disegna_bitmap_mascherata();
  return;
}


/* $0da94 renderizza_strati_grafici_con_ritardo: Esegue ritardo software, copia bitplane intercalati e disegna strati grafici mascherati (tabella/controlli + bitmap principale) */

/* Esegue ritardo software, copia bitplane intercalati e disegna strati grafici mascherati
   (tabella/controlli + bitmap principale) */

void renderizza_strati_grafici_con_ritardo(void)

{
  ritardo_ciclo_contatore();
  copia_interleaved_bitplane_custom();
  disegna_strati_grafici_mascherati();
  return;
}


/* $0daa6 ritardo_ciclo_contatore: Esegue un ciclo di attesa software decrementando il contatore fino a 1. */

/* Esegue un ciclo di attesa software decrementando il contatore fino a 1. */

void ritardo_ciclo_contatore(void)

{
  char cVar1;
  
  for (cVar1 = contatore_cicli_ritardo; cVar1 != '\x01'; cVar1 = cVar1 + -1) {
  }
  return;
}


/* $0dad2 renderizza_scena_condizionale: Ritardo e copia bitplane, poi disegna strati mascherati; in base a flag schermo e contatore sceglie immagine o bitmap mascherata, e a contatore=4 elementi tabel */

/* Ritardo e copia bitplane, poi disegna strati mascherati; in base a flag schermo e contatore
   sceglie immagine o bitmap mascherata, e a contatore=4 elementi tabel */

void renderizza_scena_condizionale(void)

{
  ritardo_ciclo_contatore();
  copia_interleaved_bitplane_custom();
  disegna_strati_grafici_mascherati();
  if (flag_abilitazione_schermo != '\0') {
    if ((contatore_cicli_ritardo == '\x01') || (contatore_cicli_ritardo == '\x02')) {
      disegna_immagine_4_bitplane();
    }
    else {
      disegna_bitmap_mascherata();
    }
  }
  if (contatore_cicli_ritardo == '\x04') {
    disegna_elementi_tabella_mascherati();
  }
  return;
}


/* $0db48 copia_grafica_5c70a_su_schermo: Copia blocchi di dati grafici da 5c70a nei 4 bitplane della memoria video. */

/* Copia blocchi di dati grafici da 5c70a nei 4 bitplane della memoria video. */

void copia_grafica_5c70a_su_schermo(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  puVar4 = &indirizzo_memoria_video;
  puVar2 = (undefined2 *)&sorgente_grafica_5c70a;
  sVar1 = 0x3bf;
  do {
    *puVar4 = *puVar2;
    puVar4[4000] = puVar2[1];
    puVar3 = puVar2 + 3;
    puVar4[8000] = puVar2[2];
    puVar2 = puVar2 + 4;
    puVar4[12000] = *puVar3;
    puVar4 = puVar4 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0db5a copia_interleaved_bitplane_custom: Copia una quantita' di word specificata distribuendo i dati nei 4 bitplane. */

/* Copia una quantita' di word specificata distribuendo i dati nei 4 bitplane. */

void copia_interleaved_bitplane_custom(void)

{
  short in_D0w;
  undefined2 *in_A0;
  undefined2 *puVar1;
  undefined2 *in_A1;
  
  do {
    *in_A1 = *in_A0;
    in_A1[4000] = in_A0[1];
    puVar1 = in_A0 + 3;
    in_A1[8000] = in_A0[2];
    in_A0 = in_A0 + 4;
    in_A1[12000] = *puVar1;
    in_A1 = in_A1 + 1;
    in_D0w = in_D0w + -1;
  } while (in_D0w != -1);
  return;
}


/* $0db70 copia_grafica_6f8c6_in_buffer_video: Copia 1920 word di dati grafici da 6f8c6 nel buffer video con offset 0x780. */

/* Copia 1920 word di dati grafici da 6f8c6 nel buffer video con offset 0x780. */

void copia_grafica_6f8c6_in_buffer_video(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = (undefined2 *)&sorgente_grafica_6f8c6;
  puVar3 = (undefined2 *)(parametro_dimensione_bf68 + 0x780);
  sVar1 = 0x77f;
  do {
    *puVar3 = *puVar2;
    puVar3[4000] = puVar2[4000];
    puVar3[8000] = puVar2[8000];
    puVar3[12000] = puVar2[12000];
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0db8e copia_parziale_grafica_6f8c6: Copia 320 word di dati grafici da 6f8c6 nel buffer video con offset 0x780. */

/* Copia 320 word di dati grafici da 6f8c6 nel buffer video con offset 0x780. */

void copia_parziale_grafica_6f8c6(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = (undefined2 *)&sorgente_grafica_6f8c6;
  puVar3 = (undefined2 *)(parametro_dimensione_bf68 + 0x780);
  sVar1 = 0x13f;
  do {
    *puVar3 = *puVar2;
    puVar3[4000] = puVar2[4000];
    puVar3[8000] = puVar2[8000];
    puVar3[12000] = puVar2[12000];
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0dbac renderizza_interfaccia_gioco_completa: Renderizza interfaccia completa: copia bitplane interleaved, cancella indicatori, disegna rettangoli stato, font, soldi e controllo */

/* Renderizza interfaccia completa: copia bitplane interleaved, cancella indicatori, disegna
   rettangoli stato, font, soldi e controllo */

void renderizza_interfaccia_gioco_completa(void)

{
  copia_interleaved_bitplane_custom();
  cancella_indicatori_schermo();
  disegna_rettangoli_stato_attivo();
  inizializza_seleziona_font();
  disegna_valore_soldi_bcd();
  disegna_interfaccia_tipo_controllo();
  return;
}


/* $0dbd6 disegna_rettangoli_stato_attivo: Disegna rettangoli grafici per 4 slot se il flag corrispondente è attivo */

/* Disegna rettangoli grafici per 4 slot se il flag corrispondente è attivo */

void disegna_rettangoli_stato_attivo(void)

{
  char cVar1;
  char *pcVar2;
  
  larghezza_finestra_caratteri = 3;
  altezza_finestra_caratteri = 0x24;
  cVar1 = '\0';
  pcVar2 = &flag_slot_attivi;
  do {
    if (*pcVar2 != '\x01') {
      return;
    }
    disegna_rettangolo_grafico();
    cVar1 = cVar1 + '\x04';
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\x10');
  return;
}


/* $0dc12 copia_grafica_707c6_in_buffer_video: Copia 1120 word di dati grafici da 707c6 nel buffer video con offset 0x1680. */

/* Copia 1120 word di dati grafici da 707c6 nel buffer video con offset 0x1680. */

void copia_grafica_707c6_in_buffer_video(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = (undefined2 *)&sorgente_grafica_707c6;
  puVar3 = (undefined2 *)(parametro_dimensione_bf68 + 0x1680);
  sVar1 = 0x45f;
  do {
    *puVar3 = *puVar2;
    puVar3[4000] = puVar2[4000];
    puVar3[8000] = puVar2[8000];
    puVar3[12000] = puVar2[12000];
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0dc30 salva_area_memoria_video: Copia 960 word dai 4 bitplane della memoria video al buffer di destinazione. */

/* Copia 960 word dai 4 bitplane della memoria video al buffer di destinazione. */

void salva_area_memoria_video(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 0x3bf;
  puVar3 = parametro_dimensione_bf68;
  do {
    *puVar3 = *puVar2;
    puVar3[4000] = puVar2[4000];
    puVar3[8000] = puVar2[8000];
    puVar3[12000] = puVar2[12000];
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0dc62 copia_schermo_intero_in_buffer: Copia l'intero schermo di 4000 word per bitplane dalla memoria video al buffer. */

/* Copia l'intero schermo di 4000 word per bitplane dalla memoria video al buffer. */

void copia_schermo_intero_in_buffer(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar2 = &indirizzo_memoria_video;
  sVar1 = 3999;
  puVar3 = parametro_dimensione_bf68;
  do {
    *puVar3 = *puVar2;
    puVar3[4000] = puVar2[4000];
    puVar3[8000] = puVar2[8000];
    puVar3[12000] = puVar2[12000];
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0dc78 esegui_sequenza_intro_hamster: Imposta palette copper, decomprime immagine intro, riproduce sequenza audio hamster attendendo pressione tasto fuoco */

/* Imposta palette copper, decomprime immagine intro, riproduce sequenza audio hamster attendendo
   pressione tasto fuoco */

void esegui_sequenza_intro_hamster(void)

{
  imposta_colori_copper_2();
  flag_intro_in_corso = 1;
  decomprime_e_riorganizza_immagine();
  imposta_colori_copper_3();
  esegui_intro_hamster_attendi_fuoco();
  imposta_colori_copper_4();
  flag_intro_in_corso = 0;
  return;
}


/* $0dcac decomprime_e_riorganizza_immagine: Decomprime i dati RLE in memoria video e organizza i 4 bitplane nel buffer di destinazione. */

/* Decomprime i dati RLE in memoria video e organizza i 4 bitplane nel buffer di destinazione. */

void decomprime_e_riorganizza_immagine(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  char *in_A0;
  char *pcVar4;
  char *pcVar5;
  undefined2 *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  
  pcVar7 = (char *)&indirizzo_memoria_video;
  do {
    pcVar4 = in_A0 + 1;
    sVar2 = (short)*in_A0;
    pcVar8 = pcVar7;
    if (sVar2 < 0) {
      pcVar5 = pcVar4;
      if (*in_A0 != -0x80) {
        sVar2 = -sVar2;
        pcVar5 = in_A0 + 2;
        cVar1 = *pcVar4;
        pcVar4 = pcVar7;
        do {
          pcVar7 = pcVar4 + 1;
          *pcVar4 = cVar1;
          sVar2 = sVar2 + -1;
          pcVar4 = pcVar7;
        } while (sVar2 != -1);
      }
    }
    else {
      do {
        pcVar5 = pcVar4 + 1;
        pcVar7 = pcVar8 + 1;
        *pcVar8 = *pcVar4;
        sVar2 = sVar2 + -1;
        pcVar4 = pcVar5;
        pcVar8 = pcVar7;
      } while (sVar2 != -1);
    }
    in_A0 = pcVar5;
  } while ((int)pcVar7 < 0x76e47);
  puVar9 = &indirizzo_memoria_video;
  sVar2 = 199;
  puVar6 = parametro_dimensione_bf68;
  do {
    sVar3 = 0x13;
    puVar11 = puVar9 + 0x14;
    puVar12 = puVar9 + 0x28;
    puVar13 = puVar9 + 0x3c;
    do {
      puVar10 = puVar9;
      *puVar6 = *puVar10;
      puVar6[4000] = *puVar11;
      puVar6[8000] = *puVar12;
      puVar6[12000] = *puVar13;
      puVar6 = puVar6 + 1;
      sVar3 = sVar3 + -1;
      puVar9 = puVar10 + 1;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    } while (sVar3 != -1);
    puVar9 = puVar10 + 0x3d;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}


/* $0dce6 converti_bitplane_schermo: Copia e separa i 4 bitplane dalla memoria video al buffer grafico per 200 righe. */

/* Copia e separa i 4 bitplane dalla memoria video al buffer grafico per 200 righe. */

void converti_bitplane_schermo(void)

{
  short sVar1;
  short sVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  
  puVar4 = &indirizzo_memoria_video;
  sVar1 = 199;
  puVar3 = parametro_dimensione_bf68;
  do {
    sVar2 = 0x13;
    puVar6 = puVar4 + 0x14;
    puVar7 = puVar4 + 0x28;
    puVar8 = puVar4 + 0x3c;
    do {
      puVar5 = puVar4;
      *puVar3 = *puVar5;
      puVar3[4000] = *puVar6;
      puVar3[8000] = *puVar7;
      puVar3[12000] = *puVar8;
      puVar3 = puVar3 + 1;
      sVar2 = sVar2 + -1;
      puVar4 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    } while (sVar2 != -1);
    puVar4 = puVar5 + 0x3d;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


/* $0dd2a attendi_tasto: azzera $12866 e aspetta che il gestore della tastiera ci scriva un tasto; lo restituisce in d6 */

/* WARNING: Removing unreachable block (ram,0x0000dd38) */
/* azzera $12866 e aspetta che il gestore della tastiera ci scriva un tasto; lo restituisce in d6 */

void attendi_tasto(void)

{
                    /* WARNING: Do nothing block with infinite loop */
  do {
  } while( true );
}


/* $1305a esegui_sequenza_audio_intro_hamster: Esegue driver audio con interrupt, pattern, caricamento immagini, sfumature colori */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Esegue driver audio con interrupt, pattern, caricamento immagini, sfumature colori */

void esegui_sequenza_audio_intro_hamster(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  char *pcVar4;
  
  puVar2 = &buffer_dati_audio;
  sVar1 = 0x1f;
  puVar3 = &UNK_0002e315;
  do {
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  inizializza_driver_audio();
  stato_riproduzione_audio = 1;
  _vettore_interrupt_salvato = _vettore_interrupt_sistema;
  _vettore_interrupt_sistema = 0x132ea;
  _intena_registro = 0x8020;
  do {
    while( true ) {
      do {
        while( true ) {
          if (flag_interruzione_pattern != '\0') {
            _vettore_interrupt_sistema = uRam000132f6;
            _intena_registro = 0xc008;
            disattiva_audio_dma();
            return;
          }
          if (flag_avanzamento_pattern != '\0') break;
          if (((flag_blocco_input != '\0') || ((ciaa_pra_joystick & 0x40) == 0)) ||
             (-1 < (char)ciaa_pra_joystick)) {
            _vettore_interrupt_sistema = uRam000132f6;
            _intena_registro = 0xc008;
            disattiva_audio_dma();
            return;
          }
        }
        flag_avanzamento_pattern = '\0';
        contatore_pattern_audio = contatore_pattern_audio + 1;
        pcVar4 = (char *)((int)&PTR_DAT_00013200 + (uint)contatore_pattern_audio);
      } while (*pcVar4 == '\0');
      if (*pcVar4 != '\x01') break;
      carica_e_decomprime_immagine();
l_13142:
      gestisce_sfumatura_colori_testo_bitplane();
    }
    if (*pcVar4 == '\x02') goto l_13142;
    if (*pcVar4 == '\x03') {
      effetto_sfumatura_colori_su();
    }
    else if (*pcVar4 == '\x04') {
      effetto_sfumatura_colori_su();
      effetto_sfumatura_colori_giu();
    }
  } while( true );
}


/* $13158 carica_e_decomprime_immagine: Imposta i colori della palette Copper, decomprime l'immagine RLE in memoria video e aggiorna il ciclo di frame. */

/* Imposta i colori della palette Copper, decomprime l'immagine RLE in memoria video e aggiorna il
   ciclo di frame. */

void carica_e_decomprime_immagine(void)

{
  imposta_colori_copper_2();
  indice_frame_palette = indice_frame_palette + 1 & 3;
  decomprime_e_riorganizza_immagine();
  imposta_colori_copper_3();
  return;
}


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


/* $1323c inizializza_e_avvia_audio: Inizializza il driver audio, avvia la riproduzione e attende interruzione pattern o pressione tasto fuoco per fermarsi. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Inizializza il driver audio, avvia la riproduzione e attende interruzione pattern o pressione
   tasto fuoco per fermarsi. */

void inizializza_e_avvia_audio(void)

{
  tempo_musica_predefinito = 2;
  tempo_musica_predefinito = 2;
  ptr_stato_audio._0_1_ = 0;
  inizializza_driver_audio();
  stato_riproduzione_audio = 1;
  _vettore_interrupt_salvato = _vettore_interrupt_sistema;
  do {
    if (flag_interruzione_pattern != '\0') {
      _vettore_interrupt_sistema = uRam000132f6;
      _intena_registro = 0xc008;
      disattiva_audio_dma();
      return;
    }
  } while (((flag_blocco_input == '\0') && ((ciaa_pra_joystick & 0x40) != 0)) &&
          ((char)ciaa_pra_joystick < '\0'));
  _vettore_interrupt_sistema = uRam000132f6;
  _intena_registro = 0xc008;
  disattiva_audio_dma();
  return;
}


/* $132ea irq_vblank: gestore interrupt livello 3 (vettore $6c), vertical blank */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* gestore interrupt livello 3 (vettore $6c), vertical blank */

undefined8 irq_vblank(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  aggiorna_pitch_audio_vblank();
  _DAT_00dff09c = 0x74;
  return CONCAT44(in_D0,in_D1);
}


/* $13306 inizializza_driver_audio: Inizializza le tabelle dei canali audio e azzera i volumi dei registri Paula. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Inizializza le tabelle dei canali audio e azzera i volumi dei registri Paula. */

void inizializza_driver_audio(void)

{
  char cVar1;
  short sVar3;
  int iVar2;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  
  pcVar5 = (char *)(struttura_dati_musica + 0x1d8);
  sVar3 = 0x80;
  cVar1 = '\0';
  do {
    cVar4 = cVar1;
    sVar3 = sVar3 + -1;
    pcVar6 = pcVar5;
    while( true ) {
      pcVar5 = pcVar6 + 1;
      cVar1 = *pcVar6;
      if (cVar4 < *pcVar6) break;
      sVar3 = sVar3 + -1;
      pcVar6 = pcVar5;
      if (sVar3 == -1) {
        iVar2 = struttura_dati_musica + (uint)(byte)(cVar4 + 1) * 0x400 + 600;
        sVar3 = 0xe;
        iVar7 = struttura_dati_musica;
        piVar8 = &tabella_canali_audio;
        do {
          *piVar8 = iVar2;
          iVar2 = (uint)*(ushort *)(iVar7 + 0x2a) * 2 + iVar2;
          iVar7 = iVar7 + 0x1e;
          sVar3 = sVar3 + -1;
          piVar8 = piVar8 + 1;
        } while (sVar3 != -1);
        iVar2 = 0;
        do {
          **(undefined4 **)((int)&tabella_canali_audio + (int)(short)iVar2) = 0;
          iVar2 = iVar2 + 4;
        } while (iVar2 != 0x3c);
        _DAT_00dff0a8 = 0;
        _DAT_00dff0b8 = 0;
        _DAT_00dff0c8 = 0;
        _DAT_00dff0d8 = 0;
        stato_riproduzione_audio = 0;
        tempo_musica = 0;
        _traccia_audio_corrente = 0;
        frequenza_audio_corrente._1_1_ = tempo_musica_predefinito;
        return;
      }
    }
  } while( true );
}


/* $133a4 disattiva_audio_dma: Azzera i volumi e disabilita i canali DMA audio del chip Paula. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Azzera i volumi e disabilita i canali DMA audio del chip Paula. */

void disattiva_audio_dma(void)

{
  _DAT_00dff0a8 = 0;
  _DAT_00dff0b8 = 0;
  _DAT_00dff0c8 = 0;
  _DAT_00dff0d8 = 0;
  _dmacon_registro = 0xf;
  return;
}


/* $133c6 aggiorna_pitch_audio_vblank: Aggiorna pitch dei 4 canali audio durante VBlank ciclando effetti pitch */

/* Aggiorna pitch dei 4 canali audio durante VBlank ciclando effetti pitch */

void aggiorna_pitch_audio_vblank(void)

{
  tipo_effetto_pitch = tipo_effetto_pitch + 1;
  if (tipo_effetto_pitch == 6) {
    tipo_effetto_pitch = 0;
    aggiorna_riproduzione_audio();
    return;
  }
  if (flag_pitch_canale_0 != '\0') {
    aggiorna_pitch_canale_audio();
  }
  if (flag_pitch_canale_1 != '\0') {
    aggiorna_pitch_canale_audio();
  }
  if (flag_pitch_canale_2 != '\0') {
    aggiorna_pitch_canale_audio();
  }
  if (flag_pitch_canale_3 != '\0') {
    aggiorna_pitch_canale_audio();
    return;
  }
  return;
}


/* $1342c aggiorna_pitch_canale_audio: Calcola e aggiorna il periodo di intonazione (pitch) per un canale audio Paula. */

/* Calcola e aggiorna il periodo di intonazione (pitch) per un canale audio Paula. */

void aggiorna_pitch_canale_audio(void)

{
  byte bVar1;
  undefined2 uVar2;
  short *psVar3;
  int unaff_A5;
  int unaff_A6;
  
  bVar1 = *(byte *)(unaff_A6 + 2) & 0xf;
  if (bVar1 != 0) {
    if (bVar1 == 1) {
      *(short *)(unaff_A6 + 0x16) = *(short *)(unaff_A6 + 0x16) - (ushort)*(byte *)(unaff_A6 + 3);
      if ((short)(*(short *)(unaff_A6 + 0x16) + -0x71) < 0) {
        *(undefined2 *)(unaff_A6 + 0x16) = 0x71;
      }
      *(undefined2 *)(unaff_A5 + 6) = *(undefined2 *)(unaff_A6 + 0x16);
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    *(short *)(unaff_A6 + 0x16) = (ushort)*(byte *)(unaff_A6 + 3) + *(short *)(unaff_A6 + 0x16);
    if (-1 < (short)(*(short *)(unaff_A6 + 0x16) + -0x358)) {
      *(undefined2 *)(unaff_A6 + 0x16) = 0x358;
    }
    *(undefined2 *)(unaff_A5 + 6) = *(undefined2 *)(unaff_A6 + 0x16);
    return;
  }
  if (tipo_effetto_pitch == 1) {
l_134c4:
    bVar1 = *(byte *)(unaff_A6 + 3) >> 4;
  }
  else {
    if (tipo_effetto_pitch != 2) {
      if (tipo_effetto_pitch == 3) {
        uVar2 = *(undefined2 *)(unaff_A6 + 0x10);
        goto l_134f8;
      }
      if (tipo_effetto_pitch == 4) goto l_134c4;
      if (tipo_effetto_pitch != 5) {
        return;
      }
    }
    bVar1 = *(byte *)(unaff_A6 + 3) & 0xf;
  }
  for (psVar3 = &tabella_note_periodi;
      uVar2 = *(undefined2 *)((int)psVar3 + (int)(short)((ushort)bVar1 << 1)),
      *(short *)(unaff_A6 + 0x10) != *psVar3; psVar3 = psVar3 + 1) {
  }
l_134f8:
  *(undefined2 *)(unaff_A5 + 6) = uVar2;
  return;
}


/* $134fe aggiorna_riproduzione_audio: Elabora i 4 canali audio per il tick corrente, aggiorna i puntatori DMA Paula e gestisce il loop del pattern musicale. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Elabora i 4 canali audio per il tick corrente, aggiorna i puntatori DMA Paula e gestisce il loop
   del pattern musicale. */

void aggiorna_riproduzione_audio(void)

{
  short sVar1;
  
  _traccia_audio_corrente =
       tempo_musica +
       (uint)*(byte *)(struttura_dati_musica + 0x1d8 + (int)(short)stato_riproduzione_audio) * 0x400
  ;
  _maschera_dma_canali = 0;
  elabora_comando_canale_audio();
  elabora_comando_canale_audio();
  elabora_comando_canale_audio();
  elabora_comando_canale_audio();
  sVar1 = 500;
  do {
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  _dmacon_registro = _maschera_dma_canali | 0x8000;
  if (flag_dma_canale_0_attivo == 1) {
    _aud3lc_registro = ptr_dma_canale_0;
    _aud3len_registro = 1;
  }
  if (flag_dma_canale_1_attivo == 1) {
    _aud2lc_registro = ptr_dma_canale_1;
    _aud2len_registro = 1;
  }
  if (flag_dma_canale_2_attivo == 1) {
    _aud1lc_registro = ptr_dma_canale_2;
    _aud1len_registro = 1;
  }
  if (flag_dma_canale_3_attivo == 1) {
    _aud0lc_registro = ptr_dma_canale_3;
    _aud0len_registro = 1;
  }
  tempo_musica = tempo_musica + 0x10;
  if (tempo_musica != 0x400) goto l_13642;
  while( true ) {
    tempo_musica = 0;
    stato_riproduzione_audio = stato_riproduzione_audio + 1;
    flag_avanzamento_pattern = 1;
    if (stato_riproduzione_audio == frequenza_audio_corrente) {
      stato_riproduzione_audio = 0;
    }
l_13642:
    if (flag_cambio_pattern == 0) break;
    flag_cambio_pattern = 0;
  }
  return;
}


/* $13654 elabora_comando_canale_audio: Elabora la nota e i comandi del canale audio configurando i registri Paula. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Elabora la nota e i comandi del canale audio configurando i registri Paula. */

void elabora_comando_canale_audio(void)

{
  ushort uVar1;
  int iVar2;
  short in_D1w;
  byte bVar3;
  short sVar4;
  int in_A0;
  int unaff_A3;
  undefined4 *unaff_A5;
  short *unaff_A6;
  
  *(undefined4 *)unaff_A6 = *(undefined4 *)(in_A0 + in_D1w);
  bVar3 = *(byte *)(unaff_A6 + 1) >> 4;
  if (bVar3 != 0) {
    sVar4 = (ushort)bVar3 * 0x1e;
    *(undefined4 *)(unaff_A6 + 2) =
         *(undefined4 *)(&tabella_campioni_audio + (short)((ushort)bVar3 << 2));
    unaff_A6[4] = *(short *)(unaff_A3 + sVar4);
    unaff_A6[9] = *(short *)(unaff_A3 + 2 + (int)sVar4);
    uVar1 = *(ushort *)(unaff_A3 + 4 + (int)sVar4);
    if (uVar1 == 0) {
      *(undefined4 *)(unaff_A6 + 5) = *(undefined4 *)(unaff_A6 + 2);
      unaff_A6[7] = *(short *)(unaff_A3 + 6 + (int)sVar4);
      *(short *)(unaff_A5 + 2) = unaff_A6[9];
    }
    else {
      iVar2 = (uint)uVar1 + *(int *)(unaff_A6 + 2);
      *(int *)(unaff_A6 + 2) = iVar2;
      *(int *)(unaff_A6 + 5) = iVar2;
      unaff_A6[4] = *(short *)(unaff_A3 + 6 + (int)sVar4);
      unaff_A6[7] = *(short *)(unaff_A3 + 6 + (int)sVar4);
      *(short *)(unaff_A5 + 2) = unaff_A6[9];
    }
  }
  if (*unaff_A6 != 0) {
    unaff_A6[8] = *unaff_A6;
    _dmacon_registro = unaff_A6[10];
    *unaff_A5 = *(undefined4 *)(unaff_A6 + 2);
    *(short *)(unaff_A5 + 1) = unaff_A6[4];
    *(short *)((int)unaff_A5 + 6) = *unaff_A6;
    _maschera_dma_canali = unaff_A6[10] | _maschera_dma_canali;
  }
  if (*unaff_A6 != 0) {
    unaff_A6[0xb] = *unaff_A6;
  }
  bVar3 = *(byte *)(unaff_A6 + 1) & 0xf;
  if (bVar3 == 0xb) {
    flag_cambio_pattern = ~flag_cambio_pattern;
    stato_riproduzione_audio = (uint)(byte)(*(char *)((int)unaff_A6 + 3) - 1);
    return;
  }
  if (bVar3 == 0xc) {
    *(undefined1 *)(unaff_A5 + 2) = *(undefined1 *)((int)unaff_A6 + 3);
    return;
  }
  if (bVar3 != 0xd) {
    if (bVar3 == 0xe) {
      ciaa_pra_joystick = (*(byte *)((int)unaff_A6 + 3) & 1) << 1 | ciaa_pra_joystick & 0xfd;
      return;
    }
    if (bVar3 != 0xf) {
      return;
    }
    bVar3 = *(byte *)((int)unaff_A6 + 3) & 0xf;
    if (bVar3 != 0) {
      tipo_effetto_pitch = 0;
      bRam000133d1 = bVar3;
    }
    return;
  }
  flag_interruzione_pattern = 1;
  flag_cambio_pattern = ~flag_cambio_pattern;
  return;
}


/* $13784 copia_memoria_indietro: Copia a ritroso un blocco di memoria di 38912 byte dall'indirizzo sorgente al destinazione. */

/* Copia a ritroso un blocco di memoria di 38912 byte dall'indirizzo sorgente al destinazione. */

void copia_memoria_indietro(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&fine_buffer_sorgente;
  puVar3 = (undefined4 *)&fine_buffer_destinazione;
  iVar1 = 0x25ff;
  do {
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *puVar2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


/* $137a4 avvia_sequenza_audio_testo_lungo: Avvia audio con testo lungo, copia 1024 byte e attende pressione fuoco */

/* Avvia audio con testo lungo, copia 1024 byte e attende pressione fuoco */

void avvia_sequenza_audio_testo_lungo(void)

{
  char cVar1;
  char unaff_D6b;
  
  flag_interruzione_pattern = 0;
  uRam000133d1 = 6;
  struttura_dati_musica = "rock5";
  azzera_buffer_testo();
  cVar1 = (&DAT_00013c64)[(byte)(unaff_D6b << 1)];
  if ((&DAT_00013c65)[(byte)(unaff_D6b << 1)] == '\0') {
    for (; cVar1 != '\0'; cVar1 = cVar1 + -1) {
    }
    copia_stringa_1024_byte();
    inizializza_e_avvia_audio();
    do {
      do {
        attendi_passaggio_pennello();
      } while ((ciaa_pra_joystick & 0x40) == 0);
    } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
    return;
  }
  for (; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  copia_stringa_512_byte();
  inizializza_e_avvia_audio();
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  return;
}


/* $13868 azzera_buffer_testo: Azzera un buffer di memoria di 1024 byte a partire dall'indirizzo 13fe6. */

/* Azzera un buffer di memoria di 1024 byte a partire dall'indirizzo 13fe6. */

void azzera_buffer_testo(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = 0xff;
  puVar2 = &buffer_testo_ingresso;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  return;
}


/* $13880 copia_stringa_512_byte: Copia 512 byte nel buffer di testo e aggiunge il terminatore di riga 0x0D. */

/* Copia 512 byte nel buffer di testo e aggiunge il terminatore di riga 0x0D. */

void copia_stringa_512_byte(void)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *in_A0;
  undefined4 *puVar3;
  
  sVar2 = 0x7f;
  puVar1 = &buffer_testo_ingresso;
  do {
    puVar3 = puVar1;
    *puVar3 = *in_A0;
    sVar2 = sVar2 + -1;
    in_A0 = in_A0 + 1;
    puVar1 = puVar3 + 1;
  } while (sVar2 != -1);
  *(undefined1 *)((int)puVar3 + 2) = 0xd;
  return;
}


/* $1388a copia_stringa_1024_byte: Copia 1024 byte nel buffer di testo e aggiunge il terminatore di riga 0x0D. */

/* Copia 1024 byte nel buffer di testo e aggiunge il terminatore di riga 0x0D. */

void copia_stringa_1024_byte(void)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *in_A0;
  undefined4 *puVar3;
  
  sVar2 = 0xff;
  puVar1 = &buffer_testo_ingresso;
  do {
    puVar3 = puVar1;
    *puVar3 = *in_A0;
    sVar2 = sVar2 + -1;
    in_A0 = in_A0 + 1;
    puVar1 = puVar3 + 1;
  } while (sVar2 != -1);
  *(undefined1 *)((int)puVar3 + 2) = 0xd;
  return;
}


/* $138a4 esegui_intro_hamster_attendi_fuoco: Avvia sequenza audio intro hamster, sincronizza col pennello video e attende pressione fuoco joystick */

/* Avvia sequenza audio intro hamster, sincronizza col pennello video e attende pressione fuoco
   joystick */

void esegui_intro_hamster_attendi_fuoco(void)

{
  registro_audio_iniziale = 0xd;
  flag_interruzione_pattern = 0;
  uRam000133d1 = 6;
  struttura_dati_musica = "hamster";
  esegui_sequenza_audio_intro_hamster();
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  return;
}


/* $138f2 avvia_sequenza_audio_buffer_ausiliario: Avvia audio con buffer ausiliario, copia testo e attende pressione fuoco */

/* Avvia audio con buffer ausiliario, copia testo e attende pressione fuoco */

void avvia_sequenza_audio_buffer_ausiliario(void)

{
  char cVar1;
  char unaff_D6b;
  
  flag_interruzione_pattern = 0;
  uRam000133d1 = 6;
  struttura_dati_musica = &DAT_0002a8ec;
  azzera_buffer_2ab44();
  cVar1 = (&DAT_00013c74)[(byte)(unaff_D6b << 1)];
  if ((&DAT_00013c75)[(byte)(unaff_D6b << 1)] == '\0') {
    for (; cVar1 != '\0'; cVar1 = cVar1 + -1) {
    }
    copia_1024_byte_in_buffer_ausiliario();
    inizializza_e_avvia_audio();
    do {
      do {
        attendi_passaggio_pennello();
      } while ((ciaa_pra_joystick & 0x40) == 0);
    } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
    return;
  }
  for (; cVar1 != '\0'; cVar1 = cVar1 + -1) {
  }
  copia_512_byte_in_buffer_ausiliario();
  inizializza_e_avvia_audio();
  do {
    do {
      attendi_passaggio_pennello();
    } while ((ciaa_pra_joystick & 0x40) == 0);
  } while (((ciaa_pra_joystick & 0x80) == 0) || (flag_blocco_input != '\0'));
  return;
}


/* $139ce gestisci_input_e_carica_rock: Verifica la pressione del pulsante di fuoco e avvia il caricamento della risorsa rock5. */

/* Verifica la pressione del pulsante di fuoco e avvia il caricamento della risorsa rock5. */

void gestisci_input_e_carica_rock(void)

{
  char cVar1;
  byte unaff_D6b;
  undefined4 extraout_A0;
  int extraout_A0_00;
  undefined4 extraout_A1;
  
  if ((((ciaa_pra_joystick & 0x40) != 0) && ((char)ciaa_pra_joystick < '\0')) &&
     (flag_blocco_input == '\0')) {
    parametro_canale_input = unaff_D6b & 7;
    stato_joystick_y = tasto_su;
    stato_joystick_x = tasto_giu;
    if (unaff_D6b < 8) {
      direzione_input_sinistra = tasto_sinistra;
      direzione_input_destra = tasto_destra;
    }
    else {
      direzione_input_sinistra = tasto_destra;
      direzione_input_destra = tasto_sinistra;
    }
    posizione_cursore_x = pubblico_band;
    flag_interruzione_pattern = 0;
    uRam000133d1 = 6;
    struttura_dati_musica = "rock5";
    pausa_cicli_d4();
    gestisci_timer_attesa_ciclica(extraout_A0,extraout_A1);
    pausa_cicli_d6();
    copia_blocco_dati_512();
    pausa_cicli_d4();
    pausa_cicli_d6();
    copia_blocco_dati_512();
    pausa_cicli_d4();
    pausa_cicli_d6();
    if (*(byte *)(extraout_A0_00 + 5) < 0xaa) {
      trasponi_e_copia_dati_traccia();
    }
    else {
      copia_blocco_dati_512();
    }
    pausa_cicli_d4();
    pausa_cicli_d6();
    copia_blocco_dati_512();
    inizializza_e_avvia_audio();
    return;
  }
  cVar1 = '\x10';
  do {
    pausa_breve();
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}


/* $13a30 avvia_sequenza_musicale_rock5: Su input joystick+fuoco, prepara e avvia brano 'rock5' copiando e trasponendo dati audio su canali. */

/* Su input joystick+fuoco, prepara e avvia brano 'rock5' copiando e trasponendo dati audio su
   canali. */

void avvia_sequenza_musicale_rock5(void)

{
  int iVar1;
  char unaff_D4b;
  byte unaff_D6b;
  undefined4 extraout_A0;
  int extraout_A0_00;
  undefined4 extraout_A1;
  undefined *puVar2;
  
  if ((((ciaa_pra_joystick & 0x40) != 0) && ((char)ciaa_pra_joystick < '\0')) &&
     (flag_blocco_input == '\0')) {
    puVar2 = &tabella_stati_joystick;
    for (; unaff_D4b != '\0'; unaff_D4b = unaff_D4b + -1) {
      puVar2 = puVar2 + 4;
    }
    if (flag_seleziona_buffer_dati != '\0') {
      unaff_D6b = registro_canale_audio;
    }
    parametro_canale_input = unaff_D6b & 7;
    stato_joystick_y = puVar2[2];
    stato_joystick_x = *puVar2;
    direzione_input_sinistra = puVar2[1];
    direzione_input_destra = puVar2[3];
    posizione_cursore_x = 0xff;
    flag_interruzione_pattern = 0;
    uRam000133d1 = 6;
    struttura_dati_musica = "rock5";
    pausa_cicli_d4();
    gestisci_timer_attesa_ciclica(extraout_A0,extraout_A1,puVar2);
    pausa_cicli_d6();
    copia_blocco_dati_512();
    pausa_cicli_d4();
    pausa_cicli_d6();
    copia_blocco_dati_512();
    pausa_cicli_d4();
    pausa_cicli_d6();
    if (*(byte *)(extraout_A0_00 + 5) < 0xaa) {
      trasponi_e_copia_dati_traccia();
    }
    else {
      copia_blocco_dati_512();
    }
    pausa_cicli_d4();
    pausa_cicli_d6();
    copia_blocco_dati_512();
    inizializza_e_avvia_audio();
    return;
  }
  iVar1 = 0x10;
  do {
    pausa_breve();
    iVar1 = iVar1 + -1;
  } while ((char)iVar1 != '\0');
  return;
}


/* $13b7e pausa_cicli_d4: Esegue un breve ciclo di attesa a vuoto in base al valore del registro D4. */

/* Esegue un breve ciclo di attesa a vuoto in base al valore del registro D4. */

void pausa_cicli_d4(void)

{
  byte bVar1;
  byte unaff_D4b;
  
  for (bVar1 = unaff_D4b & 7; bVar1 != 0; bVar1 = bVar1 - 1) {
  }
  return;
}


/* $13ba0 pausa_cicli_d6: Esegue un breve ciclo di attesa a vuoto in base al valore del registro D6. */

/* Esegue un breve ciclo di attesa a vuoto in base al valore del registro D6. */

void pausa_cicli_d6(void)

{
  byte bVar1;
  byte unaff_D6b;
  
  for (bVar1 = unaff_D6b & 7; bVar1 != 0; bVar1 = bVar1 - 1) {
  }
  return;
}


/* $13bbc copia_blocco_dati_512: Copia 512 byte da A3 ad A1 a blocchi di 16 byte e aggiunge il terminatore 0x0D. */

/* Copia 512 byte da A3 ad A1 a blocchi di 16 byte e aggiunge il terminatore 0x0D. */

void copia_blocco_dati_512(void)

{
  short sVar1;
  undefined4 *in_A1;
  undefined4 *puVar2;
  undefined4 *unaff_A3;
  
  sVar1 = 0x1f;
  do {
    puVar2 = in_A1;
    *puVar2 = *unaff_A3;
    unaff_A3 = unaff_A3 + 4;
    sVar1 = sVar1 + -1;
    in_A1 = puVar2 + 4;
  } while (sVar1 != -1);
  *(undefined1 *)((int)puVar2 + 2) = 0xd;
  return;
}


/* $13be6 trasponi_e_copia_dati_traccia: Copia e traspone le note del buffer audio sottraendo l'offset D6, terminando con 0x0D. */

/* Copia e traspone le note del buffer audio sottraendo l'offset D6, terminando con 0x0D. */

void trasponi_e_copia_dati_traccia(void)

{
  short sVar1;
  short sVar2;
  short unaff_D6w;
  short *in_A1;
  short *psVar3;
  short *unaff_A3;
  
  sVar1 = 0x1f;
  do {
    psVar3 = in_A1;
    sVar2 = *unaff_A3;
    if ((char)sVar2 != '\0') {
      sVar2 = sVar2 - unaff_D6w;
    }
    *psVar3 = sVar2;
    psVar3[1] = unaff_A3[1];
    unaff_A3 = unaff_A3 + 8;
    sVar1 = sVar1 + -1;
    in_A1 = psVar3 + 8;
  } while (sVar1 != -1);
  *(undefined1 *)(psVar3 + 1) = 0xd;
  return;
}


/* $13c22 azzera_buffer_2ab44: Azzera un buffer di memoria di 1024 byte situato all'indirizzo 2ab44. */

/* Azzera un buffer di memoria di 1024 byte situato all'indirizzo 2ab44. */

void azzera_buffer_2ab44(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = 0xff;
  puVar2 = &buffer_dati_ausiliario;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  return;
}


/* $13c3a copia_512_byte_in_buffer_ausiliario: Copia 512 byte dal puntatore A0 nel buffer ausiliario e aggiunge un ritorno a capo. */

/* Copia 512 byte dal puntatore A0 nel buffer ausiliario e aggiunge un ritorno a capo. */

void copia_512_byte_in_buffer_ausiliario(void)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *in_A0;
  undefined4 *puVar3;
  
  sVar2 = 0x7f;
  puVar1 = &buffer_dati_ausiliario;
  do {
    puVar3 = puVar1;
    *puVar3 = *in_A0;
    sVar2 = sVar2 + -1;
    in_A0 = in_A0 + 1;
    puVar1 = puVar3 + 1;
  } while (sVar2 != -1);
  *(undefined1 *)((int)puVar3 + 2) = 0xd;
  return;
}


/* $13c44 copia_1024_byte_in_buffer_ausiliario: Copia 1024 byte dal puntatore A0 nel buffer ausiliario e aggiunge un ritorno a capo. */

/* Copia 1024 byte dal puntatore A0 nel buffer ausiliario e aggiunge un ritorno a capo. */

void copia_1024_byte_in_buffer_ausiliario(void)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *in_A0;
  undefined4 *puVar3;
  
  sVar2 = 0xff;
  puVar1 = &buffer_dati_ausiliario;
  do {
    puVar3 = puVar1;
    *puVar3 = *in_A0;
    sVar2 = sVar2 + -1;
    in_A0 = in_A0 + 1;
    puVar1 = puVar3 + 1;
  } while (sVar2 != -1);
  *(undefined1 *)((int)puVar3 + 2) = 0xd;
  return;
}

