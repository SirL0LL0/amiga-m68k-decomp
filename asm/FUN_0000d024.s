; FUN_0000d024 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d024:
	moveq	#$1d,d0
	dc.w	$47fa,$57d8
	move.b	#$20,(a3)+
	dbra	d0,$6
	move.b	#$ff,(a3)
	rts
