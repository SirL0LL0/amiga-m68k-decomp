; FUN_0000d498 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d498:
	movem.l	d4-d5/a3,-(a7)
.L0004:
	move.l	d4,-(a7)
.L0006:
	dc.w	$6100,$e2ea
	addq.w	#$1,d4
	cmp.b	d5,d4
	bne.b	.L0006
	addi.w	#$100,d4
	move.w	d4,d6
	andi.w	#$ff00.l,d6
	move.l	(a7)+,d4
	andi.w	#$ff,d4
	or.w	d6,d4
	move.w	d5,d0
	andi.w	#$ff00.l,d0
	cmp.w	d0,d6
	bne.b	.L0004
	movem.l	(a7)+,d4-d5/a3
	rts
