; FUN_0000d538 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d538:
	move.l	d6,-(a7)
	dc.w	$41fa,$5220
	move.b	#$0,(a0)
	dc.w	$47fa,$072c
	dc.w	$6182
.L0010:
	moveq	#$0,d4
	move.b	(a3),d4
	cmp.b	#$ff,d4
	beq.w	.L00F6
	lsl.w	#$8,d4
	andi.w	#$ff00.l,d4
	addq.l	#$1,a3
	moveq	#$0,d0
	move.b	(a3)+,d0
	or.w	d0,d4
	move.l	a3,-(a7)
	btst.l	#$d,d4
	beq.w	.L005E
	move.b	d4,d6
	dc.w	$47fa,$51fc
	moveq	#$9,d5
.L003C:
	cmp.b	#$0,d6
	beq.b	.L0048
	adda.l	d5,a3
	subq.b	#$1,d6
	bra.b	.L003C
.L0048:
	move.l	d4,-(a7)
	moveq	#$6,d0
	cmpi.b	#$0,(a3)
	bne.b	.L0058
	addq.l	#$1,a3
	dbra	d0,$4c
.L0058:
	move.l	(a7)+,d4
	bra.w	.L00DA
.L005E:
	btst.l	#$e,d4
	beq.w	.L00A4
	dc.w	$47fa,$533a
	move.b	d4,d6
	moveq	#$20,d5
	cmp.b	#$c,d6
	bcs.b	.L0084
	subi.b	#$c,d6
	move.l	#$14,d5
	dc.w	$47f9,$0001,$2b5a
.L0084:
	cmp.b	#$0,d6
	beq.w	.L0092
	adda.l	d5,a3
	subq.b	#$1,d6
	bra.b	.L0084
.L0092:
	move.b	(a3)+,d6
	cmp.b	#$0,d6
	beq.w	.L00DA
	dc.w	$6100,$b16c
	bra.w	.L00E4
.L00A4:
	btst.l	#$f,d4
	beq.w	.L00D2
	dc.w	$47fa,$1372
	andi.w	#$7ff,d4
	dc.w	$6100,$fedc
	move.b	(a3),d6
	dc.w	$41fa,$4912
	move.b	d6,(a0)
	move.l	a3,-(a7)
	dc.w	$6100,$fd44
	movea.l	(a7)+,a3
	addq.l	#$1,a3
	moveq	#$0,d4
	move.b	d6,d4
	bra.w	.L00D6
.L00D2:
	dc.w	$47fa,$2ad0
.L00D6:
	dc.w	$6100,$fece
.L00DA:
	movea.l	d5,a0
	move.l	a3,d5
	movea.l	a0,a3
	dc.w	$6100,$0024
.L00E4:
	movea.l	(a7)+,a3
	dc.w	$41fa,$513c
	cmpi.b	#$ff,(a0)
	beq.w	.L00F6
	bra.w	.L0010
.L00F6:
	move.l	(a7)+,d6
	dc.w	$6100,$fe54
	move.l	d4,-(a7)
	dc.w	$6100,$fd56
	move.l	(a7)+,d4
	rts
