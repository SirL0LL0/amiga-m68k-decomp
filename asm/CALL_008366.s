; CALL_008366 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_008366:
	dc.w	$41f9,$0001,$28aa
	move.b	#$1,(a0)
	dc.w	$6100,$3b9a
	moveq	#$0,d4
	move.l	d4,-(a7)
	move.b	#$70,d6
	dc.w	$6100,$5398
	dc.w	$6100,$57ae
	dc.w	$6100,$4ec6
	dc.w	$6100,$538a
	dc.w	$6100,$3c80
	move.l	(a7)+,d4
	addq.l	#$1,d4
	move.l	d4,-(a7)
	dc.w	$6100,$4eb0
	move.l	(a7)+,d4
	addq.l	#$1,d4
	move.l	d4,-(a7)
	dc.w	$6100,$4ea6
	dc.w	$6100,$3c76
	move.l	(a7)+,d4
	addq.l	#$1,d4
	move.l	d4,-(a7)
	dc.w	$6100,$4e98
	dc.w	$6100,$3c5a
	move.l	(a7)+,d4
	addq.l	#$1,d4
	dc.w	$6100,$4e8c
	dc.w	$6100,$3c5c
	rts
