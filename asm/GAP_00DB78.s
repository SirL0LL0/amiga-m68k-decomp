; GAP_00DB78 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00DB78:
	dc.w	$6100,$e2cc
	dc.w	$41f9,$0000,$dcaa
	move.b	#$1,(a0)
	dc.w	$41f9,$0004,$2f56
	dc.w	$6100,$001e
	dc.w	$6100,$e2ba
	dc.w	$4eb9,$0001,$38a4
	dc.w	$6100,$e2b6
	dc.w	$41f9,$0000,$dcaa
	move.b	#$0,(a0)
	rts
	dc.w	$0000,$43f9
	dc.w	$0006,$f146
	movea.l	a1,a2
	adda.l	#$7d00,a2
.L0042:
	moveq	#$0,d1
	move.b	(a0)+,d1
	ext.w	d1
	bpl.w	.L0064
	cmp.b	#$80,d1
	beq.w	.L006A
	neg.w	d1
	moveq	#$0,d2
	move.b	(a0)+,d2
	move.b	d2,(a1)+
	dbra	d1,$5a
	bra.w	.L006A
.L0064:
	move.b	(a0)+,(a1)+
	dbra	d1,$64
.L006A:
	cmpa.l	a2,a1
	ble.b	.L0042
	dc.w	$43f9,$0006,$f146
	dc.w	$49f9,$0000,$bf68
	movea.l	(a4),a0
	move.w	#$c7,d0
	movea.l	a1,a2
	movea.l	a1,a3
	movea.l	a1,a4
	adda.w	#$28,a2
	adda.w	#$50,a3
	adda.w	#$78,a4
	moveq	#$13,d1
	move.w	(a1)+,(a0)
	move.w	(a2)+,$1f40(a0)
	move.w	(a3)+,$3e80(a0)
	move.w	(a4)+,$5dc0(a0)
	addq.l	#$2,a0
	dbra	d1,$94
	adda.w	#$78,a1
	dbra	d0,$80
	rts
