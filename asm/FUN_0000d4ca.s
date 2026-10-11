; FUN_0000d4ca -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d4ca:
.L0000:
	cmp.w	#$0,d4
	beq.b	.L0012
.L0006:
	move.b	(a3)+,d6
	cmp.b	#$ff,d6
	bne.b	.L0006
	subq.w	#$1,d4
	bra.b	.L0000
.L0012:
	rts
