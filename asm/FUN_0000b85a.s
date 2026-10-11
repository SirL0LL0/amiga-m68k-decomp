; FUN_0000b85a @0xb85a (file 0x385a), 508 byte -- RSTAR
; IrqHandler: gestore interrupt livello 3 (tastiera).
; Test INTENAR/INTREQR, delay NOP, ack INTREQ=$8, scancode CIA ($BFED01)
; con catena decode ($40/$C0/$4C/$CC/$4D/$CD -> flag $BB60/$BB62/$BB64),
; matrice tasti $BB66 (+qualifier bit7), logica menu/voci, restore + RTE.
; I 9 LEA sono fuori slice (8 dc.w + 1 lea assoluto coi byte originali).
; Branch .w: target = addr+2+disp (base PC+2 del 68000, verificato sui byte).
; 'opt o-' disabilita il peephole vasm. Trascritto byte-per-byte (mot syntax).

	opt	o-

FUN_0000b85a:
	movem.l	d0-d7/a0-a6,-(sp)
	btst.b	#$e,$dff01c.l
	beq.w	.Exit
	move.w	$dff01c.l,d0
	and.w	$dff01e.l,d0
	btst.l	#3,d0
	beq.w	.Exit
	rept	31
	nop
	endr
	move.w	#$8,$dff09c.l
	move.b	$bfed01.l,d0
	andi.b	#$88,d0
	cmp.b	#$88,d0
	bne.w	.Exit
	ori.b	#$40,$bfee01.l
	move.b	$bfec01.l,d0
	not.b	d0
	ror.b	#1,d0
	move.w	d0,d1
	cmp.b	#$40,d1
	bne.b	.K40
	move.b	#$1,$bb64.l
	bra.b	.Key
.K40:
	cmp.b	#$c0,d1
	bne.b	.KC0
	move.b	#$0,$bb64.l
	bra.b	.Key
.KC0:
	cmp.b	#$4c,d1
	bne.b	.K4C
	move.b	#$1,$bb60.l
	bra.b	.Key
.K4C:
	cmp.b	#$cc,d1
	bne.b	.KCC
	move.b	#$0,$bb60.l
	bra.b	.Key
.KCC:
	cmp.b	#$4d,d1
	bne.b	.K4D
	move.b	#$1,$bb62.l
	bra.b	.Key
.K4D:
	cmp.b	#$cd,d1
	bne.b	.Key
	move.b	#$0,$bb62.l
.Key:
	andi.w	#$7f,d1
	cmp.w	#$67,d1
	bhi.w	.NoKey
	move.w	d1,d2
	andi.w	#7,d2
	lsr.w	#3,d1
	lea.l	$bb66.l,a6
	bclr.b	d2,(a6,d1.w)
	btst.l	#$7,d0
	bne.w	.NoKey
	bset.b	d2,(a6,d1.w)
.NoKey:
	btst.l	#$7,d0
	bne.w	.ExitCIA
	dc.w	$41fa,$6dea	; lea +$6F0C(pc),a0 (fuori slice)
	btst.b	#0,$bb72.l
	bne.w	.Alt1
	btst.b	#1,$bb72.l
	beq.w	.Alt2
.Alt1:
	dc.w	$47fa,$016c	; lea +$2AA(pc),a3 (fuori slice)
	bra.w	.Menu
.Alt2:
	dc.w	$47fa,$00f4	; lea +$23A(pc),a3 (fuori slice)
.Menu:
	moveq	#0,d4
	move.b	d0,d4
	adda.l	d4,a3
	move.b	(a3),(a0)
	dc.w	$41fa,$00e1	; lea +$233(pc),a0 (fuori slice)
	cmpi.b	#7,(a0)
	beq.w	.K57
	dc.w	$43fa,$00ce	; lea +$22E(pc),a1 (fuori slice)
	moveq	#0,d1
	move.b	(a0),d1
	adda.l	d1,a1
	cmp.b	(a1),d0
	bne.w	.Clear
	addq.b	#1,(a0)
	bra.w	.ExitCIA
.Clear:
	move.b	#0,(a0)
	bra.w	.ExitCIA
.K57:
	cmp.b	#$57,d0
	bne.w	.K58
	dc.w	$43fa,$6df0	; lea +$6F74(pc),a1 (fuori slice)
.SetFF:
	move.b	#$ff,(a1)
	bra.w	.ExitCIA
.K58:
	cmp.b	#$58,d0
	bne.w	.K56
	dc.w	$43fa,$6ddb	; lea +$6F73(pc),a1 (fuori slice)
	bra.b	.SetFF
.K56:
	cmp.b	#$56,d0
	bne.w	.ExitCIA
	dc.w	$43fa,$68cb	; lea +$6A71(pc),a1 (fuori slice)
	dc.w	$12bc,$0001	; move.b (pc+1),d1: legge $01 dal flusso (self-ref originale).
				; NOTA: vasm traduce 'move.b #1,(a1)' proprio in questi byte
				; (quirk mot syntax), ma la semantica vera e' la lettura PC-rel.
	bra.w	.ExitCIA
.ExitCIA:
	andi.b	#$bf,$bfee01.l
.Exit:
	movem.l	(sp)+,d0-d7/a0-a6
	rept	31
	nop
	endr
	rte
