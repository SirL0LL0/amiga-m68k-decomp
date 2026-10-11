; FUN_0000b432 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b432:
	dc.w	$61a0
	dc.w	$41f9,$0006,$f146
	move.l	#$0,d0
