; FUN_00013a7e -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00013a7e:
	dc.w	$47f9,$0001,$43e6
	move.l	#$1000,d5
	andi.b	#$7,d4
	cmp.b	#$0,d4
	beq.b	.L0020
.L0016:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0016
.L0020:
	rts
