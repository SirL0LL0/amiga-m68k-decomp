; FUN_0000d9a6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d9a6:
	dc.w	$43f9,$0001,$288d
	move.b	(a1),d6
	dc.w	$41f9,$0004,$d70a
	cmp.b	#$1,d6
	beq.w	.L0024
.L0016:
	adda.l	#$3c00,a0
	subq.b	#$1,d6
	cmp.b	#$1,d6
	bne.b	.L0016
.L0024:
	dc.w	$43f9,$0006,$f8c6
	rts
