; FUN_0000b4b0 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b4b0:
	move.w	d4,d6
	lsr.w	#$8,d6
	andi.l	#$7,d6
	move.w	d4,d0
	andi.w	#$f100.l,d0
	lsr.w	#$3,d0
	move.w	d4,d1
	andi.w	#$ff,d1
	and.w	d0,d1
	move.w	d1,d4
	dc.w	$6002
