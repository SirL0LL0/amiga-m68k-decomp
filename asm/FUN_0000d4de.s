; FUN_0000d4de -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d4de:
.L0000:
	cmp.w	#$0,d4
	beq.w	.L0014
.L0008:
	move.b	(a3)+,d6
	btst.l	#$7,d6
	beq.b	.L0008
	subq.w	#$1,d4
	bra.b	.L0000
.L0014:
	rts
