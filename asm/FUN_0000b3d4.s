; FUN_0000b3d4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b3d4:
	dc.w	$41fa,$ce62
	dc.w	$47fa,$0b12
	movea.l	a3,a1
	moveq	#$f,d0
	move.b	(a0)+,(a1)+
	move.b	(a0)+,(a1)+
	addq.l	#$2,a0
	dbra	d0,$c
	moveq	#$e,d3
	moveq	#$1f,d4
	movea.l	a3,a0
	move.b	(a0),d1
	move.b	d1,d2
	andi.b	#$70,d2
	beq.w	.L002C
	subi.b	#$10,d2
.L002C:
	andi.b	#$7,d1
	beq.w	.L0036
	subq.w	#$1,d1
.L0036:
	or.b	d2,d1
	move.b	d1,(a0)+
	dbra	d4,$1c
	movea.l	a3,a0
	dc.w	$43fa,$0ad6
	dc.w	$41fa,$ce1e
	moveq	#$f,d1
	move.b	(a1)+,(a0)+
	move.b	(a1)+,(a0)+
	addq.l	#$2,a0
	dbra	d1,$4a
	dc.w	$6100,$0078
	dbra	d3,$18
	rts
