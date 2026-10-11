; FUN_0000b510 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b510:
	dc.w	$43f9,$0001,$288a
	move.b	(a0)+,(a1)+
	move.b	(a0)+,(a1)
