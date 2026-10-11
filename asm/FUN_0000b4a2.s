; FUN_0000b4a2 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b4a2:
	movem.l	d0-d1,-(a7)
	dc.w	$6100,$fefc
	movem.l	(a7)+,d0-d1
	rts
