; CALL_009238 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_009238:
	dc.w	$6100,$2de2
	move.w	#$c8,d4
	dc.w	$6100,$42b2
	moveq	#$5,d6
	dc.w	$4eb9,$0001,$37a4
	dc.w	$6100,$2dc0
	move.w	#$c9,d4
	dc.w	$6094
