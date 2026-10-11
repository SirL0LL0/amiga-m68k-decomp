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

