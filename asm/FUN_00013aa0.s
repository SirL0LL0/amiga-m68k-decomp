; FUN_00013aa0 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00013aa0:
	andi.b	#$7,d6
	cmp.b	#$0,d6
	beq.b	.L001A
	move.l	#$200,d5
.L0010:
	adda.l	d5,a3
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0010
.L001A:
	rts
