; FUN_0000db30 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000db30:
	dc.w	$41f9,$0006,$f146
	dc.w	$45f9,$0000,$bf68
	movea.l	(a2),a1
	move.l	#$3bf,d0
