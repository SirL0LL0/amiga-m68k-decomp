; FUN_00009ac8 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00009ac8:
.L0000:
	move.l	d6,-(a7)
	move.b	(a3)+,d6
	dc.w	$6100,$1b48
	addq.w	#$1,d4
	move.l	(a7)+,d6
	subq.l	#$1,d6
	bne.b	.L0000
	rts
