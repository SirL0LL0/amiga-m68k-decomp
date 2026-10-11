; FUN_0000859a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000859a:
	dc.w	$41f9,$0001,$28bb
	move.b	#$0,(a0)
	moveq	#$7,d0
	moveq	#$0,d4
	movea.l	d5,a1
	move.b	(a1),d6
	add.b	(a3),d6
	add.b	d4,d6
	cmp.b	#$a,d6
	bcs.w	.L0028
	move.b	#$1,d4
	subi.b	#$a,d6
	bra.b	.L002C
.L0028:
	move.b	#$0,d4
.L002C:
	move.b	d6,(a3)
	subq.l	#$1,a3
	subq.l	#$1,d5
	dbra	d0,$e
	cmp.b	#$0,d4
	beq.b	.L0046
	dc.w	$41f9,$0001,$28bb
	move.b	#$1,(a0)
.L0046:
	rts
