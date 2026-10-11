; FUN_0000d340 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d340:
	move.l	d6,-(a7)
	moveq	#$f,d6
	dc.w	$6100,$0004
	move.l	(a7)+,d6
