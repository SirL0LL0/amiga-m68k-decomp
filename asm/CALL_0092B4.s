; CALL_0092B4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0092B4:
	dc.w	$41f9,$0001,$28ce
	moveq	#$0,d6
	move.b	(a0),d6
	lsr.w	#$1,d6
	ori.b	#$1,d6
	move.b	d6,(a0)
	rts
