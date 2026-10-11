; CALL_00921E -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00921E:
	dc.w	$6100,$2dfc
	move.w	#$c5,d4
	dc.w	$6100,$42cc
	moveq	#$7,d6
	dc.w	$60ae
