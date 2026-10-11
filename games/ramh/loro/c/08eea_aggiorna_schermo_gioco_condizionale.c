/* $08eea aggiorna_schermo_gioco_condizionale: Inizializza schermo completo, attende input menu, se flag attivo copia animazione e buffer soldi poi aggiorna interfaccia e grafica */

/* WARNING: Removing unreachable block (ram,0x00008f50) */
/* WARNING: Removing unreachable block (ram,0x00008f6c) */
/* WARNING: Removing unreachable block (ram,0x00008f6e) */
/* WARNING: Removing unreachable block (ram,0x00008f72) */
/* WARNING: Removing unreachable block (ram,0x00008f7e) */
/* WARNING: Removing unreachable block (ram,0x00008f80) */
/* WARNING: Removing unreachable block (ram,0x00008f84) */
/* Inizializza schermo completo, attende input menu, se flag attivo copia animazione e buffer soldi
   poi aggiorna interfaccia e grafica */

void aggiorna_schermo_gioco_condizionale(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar4;
  undefined1 *puVar3;
  
  inizializza_schermo_gioco_completo();
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
    aggiorna_interfaccia_gioco_completa();
    copia_grafica_707c6_in_buffer_video();
  }
  return;
}

