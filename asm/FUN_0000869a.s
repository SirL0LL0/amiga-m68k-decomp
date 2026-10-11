; FUN_0000869a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000869a:
	moveq	#$8,d4
	moveq	#$0,d6
.L0004:
	move.b	d6,(a3)+
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0004
	rts
