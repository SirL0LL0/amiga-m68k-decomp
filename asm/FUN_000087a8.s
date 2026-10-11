; FUN_000087a8 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000087a8:
	move.l	a3,-(a7)
.L0002:
	dc.w	$6100,$47d8
	dc.w	$47f9,$0001,$291d
	move.b	#$1e,d4
.L0010:
	move.b	(a3),d6
	subq.l	#$1,a3
	btst.l	#$7,d6
	bne.w	.L0024
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0010
.L0024:
	cmp.b	#$0,d4
	beq.b	.L0002
	cmp.b	#$1,d4
	beq.b	.L0002
.L0030:
	cmpi.b	#$20,(a3)
	bne.w	.L0046
	ori.b	#$80,(a3)
	subq.l	#$1,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0030
.L0046:
	cmp.b	#$0,d4
	beq.b	.L0002
	cmp.b	#$1,d4
	beq.b	.L0002
	move.l	(a7)+,d5
	movea.l	d5,a0
	dc.w	$47f9,$0001,$2900
	move.w	#$1e,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$60
	dc.w	$6100,$529c
	dc.w	$6100,$52fe
	rts
