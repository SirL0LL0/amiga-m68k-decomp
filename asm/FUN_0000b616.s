; FUN_0000b616 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b616:
	dc.w	$41fa,$047a
	cmpi.b	#$0,(a0)
	beq.w	.L0018
	movem.l	d0-d7/a0-a6,-(a7)
	dc.w	$6100,$0162
	movem.l	(a7)+,d0-d7/a0-a6
.L0018:
	movem.l	d4-d6/a3,-(a7)
	dc.w	$41f9,$0001,$2887
	subq.l	#$1,d6
	cmpi.b	#$0,(a0)
	bne.b	.L0050
	dc.w	$47fa,$1083
	moveq	#$6,d5
	adda.l	d5,a3
	dbra	d6,$30
	move.l	a3,d5
	dc.w	$41f9,$0001,$288a
	move.b	#$1,(a0)+
	move.b	#$6,(a0)
	moveq	#$1,d6
	dc.w	$612e
	movem.l	(a7)+,d4-d6/a3
	rts
.L0050:
	dc.w	$47fa,$0f24
	moveq	#$1c,d5
	adda.l	d5,a3
	dbra	d6,$56
	move.l	a3,d5
	dc.w	$41f9,$0001,$288a
	move.b	#$2,(a0)+
	move.b	#$e,(a0)
	moveq	#$1,d6
	dc.w	$6108
	movem.l	(a7)+,d4-d6/a3
	addq.w	#$1,d4
	rts
