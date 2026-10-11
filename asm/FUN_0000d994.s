; FUN_0000d994 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d994:
	dc.w	$6100,$0010
	move.l	#$13f,d0
	dc.w	$6100,$00ba
	dc.w	$6184
	rts
