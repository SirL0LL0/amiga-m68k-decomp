; FUN_0000da48 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000da48:
	dc.w	$43f9,$0006,$f146
	dc.w	$41f9,$0005,$c70a
	move.l	#$3bf,d0
