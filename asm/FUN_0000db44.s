; FUN_0000db44 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000db44:
	move.w	(a0),(a1)
	move.w	$1f40(a0),$1f40(a1)
	move.w	$3e80(a0),$3e80(a1)
	move.w	$5dc0(a0),$5dc0(a1)
	addq.l	#$2,a0
	addq.l	#$2,a1
	dbra	d0,$0
	rts
