; FUN_0000d23c -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d23c:
	dc.w	$41fa,$5573
	move.b	d6,(a0)
	rts
