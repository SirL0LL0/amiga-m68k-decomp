; CALL_00AF70 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00AF70:
	dc.w	$41f9,$0001,$285e
	move.b	#$4a,(a0)
	moveq	#$5,d4
	dc.w	$47f9,$0001,$2423
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L0024
	dc.w	$47f9,$0001,$2441
.L0024:
	moveq	#$1a,d6
	move.b	#$1,$8f87.l
	dc.w	$6100,$fd90
	move.l	a3,-(a7)
	moveq	#$0,d6
	dc.w	$6100,$048a
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L0050
	dc.w	$41f9,$0004,$cada
	bra.w	.L0056
.L0050:
	dc.w	$41f9,$0004,$c52a
.L0056:
	dc.w	$43f9,$0001,$288a
	move.b	#$1a,(a1)+
	move.b	#$e,(a1)
	move.w	#$7,d4
	dc.w	$6100,$0540
	dc.w	$47f9,$0001,$244c
	dc.w	$41f9,$0001,$2451
	moveq	#$4,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$7a
	move.l	a0,d5
	movea.l	(a7)+,a3
	dc.w	$41f9,$0001,$285e
	move.b	#$4f,(a0)
	moveq	#$6,d6
	moveq	#$1a,d6
	moveq	#$5,d4
	move.b	#$1,$8f87.l
	dc.w	$6100,$fd22
	rts
