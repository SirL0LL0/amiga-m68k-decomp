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

