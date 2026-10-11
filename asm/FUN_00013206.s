; FUN_00013206 @0x13206 (file 0xb206), 158 byte -- RSTAR
; BuildSoundTables: trova il max in tabella 128B, costruisce 15 ptr
; (base+idx*0x400+600), azzera 15 long, mute audio, init variabili.
; I 4 LEA puntano fuori slice: dc.w coi byte originali.
; 'opt o-' disabilita il peephole vasm. Trascritto byte-per-byte (mot syntax).

	opt	o-

FUN_00013206:
	dc.w	$43fa,$0a82	; lea +$A88(pc),a1 (fuori slice: tabella base)
	movea.l	(a1),a0
	adda.l	#$1d8,a0
	move.l	#$80,d0
	moveq	#0,d1
.Max:
	move.l	d1,d2
	subq.w	#1,d0
.Mv:
	move.b	(a0)+,d1
.Cmp:
	cmp.b	d2,d1
	bgt.b	.Max
	dbra	d0,.Mv
	addq.b	#1,d2
	dc.w	$43fa,$0a5e	; lea +$A88(pc),a1 (fuori slice)
	movea.l	(a1),a0
	dc.w	$43fa,$09c8	; lea +$9F8(pc),a1 (fuori slice: tabellaptr)
	asl.l	#8,d2
	asl.l	#2,d2
	addi.l	#$258,d2
	add.l	a0,d2
	moveq	#$e,d0
.Loop2:
	move.l	d2,(a1)+
	moveq	#0,d1
	move.w	$2a(a0),d1
	asl.l	#1,d1
	add.l	d1,d2
	adda.l	#$1e,a0
	dbra	d0,.Loop2
	dc.w	$41fa,$09a0	; lea +$9F8(pc),a0 (fuori slice)
	moveq	#0,d0
.Loop3:
	movea.l	(a0,d0.w),a1
	clr.l	(a1)
	addq.l	#4,d0
	cmp.l	#$3c,d0
	bne.b	.Loop3
	clr.w	$dff0a8
	clr.w	$dff0b8
	clr.w	$dff0c8
	clr.w	$dff0d8
	clr.l	$13cea
	clr.l	$13ce6
	clr.l	$13cf2
	move.b	$13f64,$13d37
	rts
