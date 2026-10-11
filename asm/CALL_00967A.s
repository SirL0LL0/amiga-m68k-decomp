; CALL_00967A -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00967A:
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$1,(a0)
	bne.w	.L0016
	move.w	#$73,d6
	bra.w	.L001A
.L0016:
	move.w	#$87,d6
.L001A:
	dc.w	$41f9,$0000,$e551
	move.b	d6,(a0)
	move.w	#$7e,d4
	dc.w	$6100,$3e52
	moveq	#$73,d6
	moveq	#$32,d4
	dc.w	$6100,$019a
	dc.w	$6100,$f55a
	dc.w	$47f9,$0001,$1ace
	dc.w	$41f9,$0001,$28ba
	moveq	#$0,d4
	move.b	(a0),d4
	lsl.w	#$1,d4
	adda.l	d4,a3
	move.b	(a3)+,d6
	moveq	#$0,d4
	move.b	(a3),d4
	dc.w	$47f9,$0001,$2875
	adda.l	d4,a3
	move.b	d6,(a3)
	dc.w	$47f9,$0001,$287c
	move.l	a3,d5
	dc.w	$47f9,$0001,$2873
	dc.w	$41f9,$0001,$29c4
	moveq	#$0,d4
	move.b	(a0),d4
	lsl.w	#$8,d4
	dc.w	$6100,$f474
	move.w	#$a7,d4
	dc.w	$6100,$3b50
	dc.w	$41f9,$0001,$28ba
	moveq	#$0,d4
	move.b	(a0),d4
	moveq	#$c,d6
	sub.b	d4,d6
	move.b	d6,d4
.L0090:
	move.l	d4,-(a7)
	dc.w	$6100,$1062
	move.l	(a7)+,d4
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0090
	dc.w	$47f9,$0001,$2873
	move.l	a3,d5
	dc.w	$47f9,$0001,$23d1
	dc.w	$6100,$ef9c
	dc.w	$6100,$0464
	rts
