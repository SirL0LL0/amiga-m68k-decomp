/* $08f88 gestisci_click_area_interattiva: Rileva click su aree menu (coordinate Y), carica dati corrispondenti, avvia audio e aggiorna schermo */

/* WARNING: Removing unreachable block (ram,0x00009054) */
/* Rileva click su aree menu (coordinate Y), carica dati corrispondenti, avvia audio e aggiorna
   schermo */

void gestisci_click_area_interattiva(void)

{
  undefined4 uVar1;
  short sVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  azzera_tre_buffer_8_byte();
  if (((area_menu_selezionata == '\0') && (0x3b < valore_cursore_x)) && (0x27 < valore_cursore_y)) {
    if (valore_cursore_y < 0x46) {
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
      if (valore_cursore_y < 0x6e) {
        if (flag_area_2_usata != '\0') {
          return;
        }
        flag_area_2_usata = '\x02';
        area_menu_selezionata = 2;
        puVar5 = &DAT_00012129;
        puVar3 = &DAT_0001212b;
        codice_risorsa_audio_corrente = 0x34;
      }
      else if (valore_cursore_y < 0xa0) {
        if (flag_area_3_usata != '\0') {
          return;
        }
        flag_area_3_usata = '\x03';
        area_menu_selezionata = 3;
        puVar5 = &DAT_0001212d;
        puVar3 = &DAT_0001212f;
        codice_risorsa_audio_corrente = 0x35;
      }
      else if (valore_cursore_y < 0xfa) {
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
    inizializza_schermo_gioco_completo();
    avvia_sequenza_audio_buffer_ausiliario();
    attendi_rilascio_pulsante_mouse();
    flag_abilitazione_schermo = 0;
    area_menu_selezionata = 0;
    inizializza_schermo_gioco_completo();
    pausa_messaggio();
    pausa_messaggio();
    aggiorna_scena_grafica_base();
    return;
  }
  return;
}

