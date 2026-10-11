; GAP_0095FC -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_0095FC:
	dc.w	$0000,$47f9
	dc.w	$0001,$28fc
	moveq	#$4,d4
	moveq	#$80,d6
	dc.w	$6100,$f094
	dc.w	$41f9,$0001,$29c5
	dc.w	$43f9,$0001,$29c4
	move.b	(a0),(a1)
	moveq	#$0,d4
	move.b	(a0),d4
	dc.w	$47f9,$0001,$28fc
	dc.w	$6100,$f076
	rts
