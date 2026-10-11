; FUN_0000d76c -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d76c:
	move.l	d4,-(a7)
.L0002:
	move.l	d4,-(a7)
	dc.w	$6100,$dd5c
	moveq	#$7,d0
	andi.b	#$7f,(a3)
	andi.b	#$7f,$1f40(a3)
	andi.b	#$7f,$3e80(a3)
	andi.b	#$7f,$5dc0(a3)
	adda.l	#$28,a3
	dbra	d0,$a
	move.l	(a7)+,d4
	addi.w	#$100,d4
	move.w	d4,d6
	andi.w	#$ff00.l,d6
	move.w	d5,d0
	andi.w	#$ff00.l,d0
	cmp.w	d0,d6
	bne.b	.L0002
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	move.b	d5,d4
	subq.w	#$1,d4
.L0048:
	dc.w	$6100,$dd18
	move.l	d4,-(a7)
	moveq	#$7,d0
	andi.b	#$fe,(a3)
	andi.b	#$fe,$1f40(a3)
	andi.b	#$fe,$3e80(a3)
	andi.b	#$fe,$5dc0(a3)
	adda.l	#$28,a3
	dbra	d0,$50
	move.l	(a7)+,d4
	addi.w	#$100,d4
	move.w	d4,d6
	andi.w	#$ff00.l,d6
	move.w	d5,d0
	andi.w	#$ff00.l,d0
	cmp.w	d0,d6
	bne.b	.L0048
	move.l	(a7)+,d4
	dc.w	$6100,$dcd8
	move.l	d4,-(a7)
.L008E:
	moveq	#$0,d0
	move.b	d0,(a3)
	move.b	d0,$1f40(a3)
	move.b	d0,$3e80(a3)
	move.b	d0,$5dc0(a3)
	addq.w	#$1,d4
	dc.w	$6100,$dcc0
	cmp.b	d4,d5
	bne.b	.L008E
