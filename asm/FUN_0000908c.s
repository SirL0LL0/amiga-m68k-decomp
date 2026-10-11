; FUN_0000908c -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000908c:
	dc.w	$41f9,$0001,$28cd
	moveq	#$9,d0
	cmpi.b	#$ff,(a0)
	beq.w	.L0016
	addq.b	#$1,(a0)
	dbra	d0,$8
.L0016:
	rts
