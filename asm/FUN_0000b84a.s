; FUN_0000b84a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b84a:
	moveq	#$4,d0
	move.l	d0,-(a7)
	dc.w	$6100,$fb54
	move.l	(a7)+,d0
	dbra	d0,$2
	rts
