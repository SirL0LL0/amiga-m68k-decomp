; GAP_00A826 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00A826:
	dc.w	$41f9,$0000,$b43e
	move.l	a0,d5
	dc.w	$47f9,$0001,$2b5a
	moveq	#$1e,d4
.L0010:
	move.l	d4,-(a7)
	move.l	d5,-(a7)
	move.l	a3,-(a7)
	moveq	#$2,d6
	move.l	d5,-(a7)
	dc.w	$6100,$2afe
	movea.l	(a7)+,a3
	moveq	#$0,d5
	move.b	d6,d5
	adda.l	d5,a3
	move.b	(a3),d6
	movea.l	(a7)+,a3
	dc.w	$61ae
	moveq	#$14,d5
	adda.l	d5,a3
	move.l	(a7)+,d5
	addq.l	#$3,d5
	move.l	(a7)+,d4
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0010
	dc.w	$47f9,$0001,$2db2
	moveq	#$1e,d4
.L0046:
	move.l	d4,-(a7)
	moveq	#$0,d6
	move.b	d4,d6
	addi.b	#$1b,d6
	dc.w	$6188
	moveq	#$14,d5
	adda.l	d5,a3
	move.l	(a7)+,d4
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0046
	dc.w	$41f9,$0001,$1aea
	move.b	(a0),d6
	andi.b	#$7,d6
	ori.b	#$1,d6
	move.b	d6,d4
.L0072:
	move.l	d4,-(a7)
	dc.w	$6100,$0176
	move.l	(a7)+,d4
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0072
	dc.w	$47f9,$0001,$201c
	dc.w	$41f9,$0001,$2442
	moveq	#$9,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$90
	dc.w	$41f9,$0001,$2424
	moveq	#$9,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$9e
	rts
