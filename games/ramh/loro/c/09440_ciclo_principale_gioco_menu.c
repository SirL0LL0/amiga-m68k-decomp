/* $09440 ciclo_principale_gioco_menu: Loop principale del gioco: inizializza schermo, gestisce menu, record tesi e interfaccia completa */

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
/* Loop principale del gioco: inizializza schermo, gestisce menu, record tesi e interfaccia completa
    */

void ciclo_principale_gioco_menu(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  contatore_cicli_ritardo = 3;
  flag_stato_audio = 0;
  flag_inizializzazione_schermo = 0;
  sfonda_colori_e_pulisci_schermo();
  renderizza_schermo_completo_con_colori();
  inizializza_schermo_gioco_completo();
  menu_attendi_scelta();
  tipo_controllo = 0x73;
  tipo_controllo_predefinito = 0x73;
  flag_controllo_secondario = 0;
  flag_tipo_controllo_1 = 1;
  inizializza_schermo_gioco_completo();
  do {
    while( true ) {
      do {
        aggiorna_interfaccia_gioco_completa();
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
      inizializza_schermo_gioco_completo();
      menu_attendi_scelta();
      inizializza_schermo_gioco_completo();
      flag_modalita_schermo = 1;
      if (indice_elemento_tabella != '\0') break;
      indice_elemento_tabella = '3';
    }
    indice_elemento_tabella = indice_elemento_tabella + -1;
  } while( true );
}

