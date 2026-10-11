; FUN_0000988e -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000988e:
	dc.w	$41f9,$0001,$28d2
	cmpi.b	#$0,(a0)
	beq.w	.L002C
	moveq	#$9,d4
.L0010:
	move.l	d4,-(a7)
	dc.w	$6100,$1fa8
	move.l	(a7)+,d4
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0010
	moveq	#$0,d6
	dc.w	$41f9,$0001,$28d2
	move.b	#$0,(a0)
.L002C:
	rts
