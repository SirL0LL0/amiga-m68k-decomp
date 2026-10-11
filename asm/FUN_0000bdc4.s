; FUN_0000bdc4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000bdc4:
	dc.w	$47fa,$c560
	dc.w	$41f8,$0304
	moveq	#$f,d0
	move.l	(a3)+,(a0)+
	dbra	d0,$a
	rts
