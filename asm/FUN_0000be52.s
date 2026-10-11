; FUN_0000be52 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000be52:
	dc.w	$41fa,$0018
	moveq	#$f,d0
	dc.w	$43fa,$c3de
	move.b	(a0)+,(a1)+
	move.b	(a0)+,(a1)+
	addq.l	#$2,a1
	dbra	d0,$a
	rts
