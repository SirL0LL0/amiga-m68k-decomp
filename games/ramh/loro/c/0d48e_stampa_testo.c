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

