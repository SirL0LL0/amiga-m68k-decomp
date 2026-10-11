; FUN_0000a516 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000a516:
	dc.w	$47f9,$0001,$28f4
	dc.w	$6100,$e17c
	dc.w	$41f9,$0001,$28f5
	move.b	#$1,(a0)
	dc.w	$6100,$e17e
	rts
