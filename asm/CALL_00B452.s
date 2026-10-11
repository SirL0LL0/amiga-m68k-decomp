; CALL_00B452 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00B452:
	dc.w	$41f9,$0006,$f146
	move.w	#$f9f,d1
	move.w	#$ffff.l,(a0)
	move.w	#$ffff.l,$1f40(a0)
	move.w	#$ffff.l,$3e80(a0)
	move.w	#$0,$5dc0(a0)
	addq.l	#$2,a0
	dbra	d1,$a
	rts
