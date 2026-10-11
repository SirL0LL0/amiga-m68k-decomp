; FUN_000095cc -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000095cc:
	dc.w	$47f9,$0001,$147e
	moveq	#$1e,d5
	dc.w	$41f9,$0000,$96fc
	move.b	(a0),d6
	cmp.b	#$0,d6
	beq.b	.L0020
.L0016:
	adda.l	d5,a3
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0016
.L0020:
	dc.w	$41f9,$0001,$283e
	moveq	#$1d,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$28
	rts
