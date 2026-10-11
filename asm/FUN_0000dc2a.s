; FUN_0000dc2a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000dc2a:
	dc.w	$41fa,$4b3a
	move.b	#$0,(a0)
.L0008:
	cmpi.b	#$0,(a0)
	beq.b	.L0008
	move.b	(a0),d6
	rts
