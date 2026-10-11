; CALL_00962A -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00962A:
	dc.w	$47f9,$0001,$29a7
	dc.w	$41f9,$0001,$29a3
	moveq	#$3,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$e
	dc.w	$47f9,$0001,$29b3
	dc.w	$41f9,$0001,$29af
	moveq	#$3,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$22
	dc.w	$47f9,$0001,$29bb
	dc.w	$41f9,$0001,$29b7
	moveq	#$3,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$36
	dc.w	$41f9,$0001,$29c5
	dc.w	$43f9,$0001,$29c4
	move.b	(a0),(a1)
	dc.w	$6100,$4436
	rts
