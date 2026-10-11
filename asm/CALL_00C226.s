; CALL_00C226 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00C226:
	move.l	d6,-(a7)
	dc.w	$41f9,$0004,$bd28
	move.w	#$61e,d4
	dc.w	$6100,$f34a
	move.l	(a7)+,d6
	moveq	#$0,d4
	move.b	d6,d4
	moveq	#$2a,d6
	dc.w	$6100,$01b4
	moveq	#$2,d6
	dc.w	$6100,$10fa
	addi.b	#$88,d6
	moveq	#$0,d4
	move.b	d6,d4
	moveq	#$2e,d6
	dc.w	$41f9,$0001,$28d8
	move.b	#$1,(a0)
	dc.w	$6100,$12da
	dc.w	$41f9,$0001,$28d8
	move.b	#$0,(a0)
	moveq	#$5,d6
	dc.w	$6100,$18f4
	dc.w	$6100,$fbe0
	rts
