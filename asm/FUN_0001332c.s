; FUN_0001332c -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0001332c:
	move.b	$2(a6),d0
	andi.b	#$f,d0
	tst.b	d0
	beq.b	.L005A
	cmp.b	#$1,d0
	beq.b	.L001A
	cmp.b	#$2,d0
	beq.b	.L003A
	rts
.L001A:
	moveq	#$0,d0
	move.b	$3(a6),d0
	sub.w	d0,$16(a6)
	cmpi.w	#$71,$16(a6)
	bpl.b	.L0032
	move.w	#$71,$16(a6)
.L0032:
	move.w	$16(a6),$6(a5)
	rts
.L003A:
	moveq	#$0,d0
	move.b	$3(a6),d0
	add.w	d0,$16(a6)
	cmpi.w	#$358,$16(a6)
	bmi.b	.L0052
	move.w	#$358,$16(a6)
.L0052:
	move.w	$16(a6),$6(a5)
	rts
.L005A:
	cmpi.l	#$1,$13cee.l
	beq.b	.L0098
	cmpi.l	#$2,$13cee.l
	beq.b	.L00A2
	cmpi.l	#$3,$13cee.l
	beq.b	.L00AE
	cmpi.l	#$4,$13cee.l
	beq.b	.L0098
	cmpi.l	#$5,$13cee.l
	beq.b	.L00A2
	rts
.L0098:
	moveq	#$0,d0
	move.b	$3(a6),d0
	lsr.b	#$4,d0
	bra.b	.L00B4
.L00A2:
	moveq	#$0,d0
	move.b	$3(a6),d0
	andi.b	#$f,d0
	bra.b	.L00B4
.L00AE:
	move.w	$10(a6),d2
	bra.b	.L00CC
.L00B4:
	asl.w	#$1,d0
	moveq	#$0,d1
	move.w	$10(a6),d1
	dc.w	$41fa,$0852
.L00C0:
	move.w	(a0,d0.w),d2
	cmp.w	(a0),d1
	beq.b	.L00CC
	addq.l	#$2,a0
	bra.b	.L00C0
.L00CC:
	move.w	d2,$6(a5)
	rts
