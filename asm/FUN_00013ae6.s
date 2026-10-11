; FUN_00013ae6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00013ae6:
	movem.l	a0-a1,-(a7)
	moveq	#$1f,d0
	move.w	(a3),d1
	cmp.b	#$0,d1
	beq.w	.L0012
	sub.w	d6,d1
.L0012:
	move.w	d1,(a1)
	move.w	$2(a3),$2(a1)
	adda.l	#$10,a1
	adda.l	#$10,a3
	dbra	d0,$6
	suba.l	#$e,a1
	move.b	#$d,(a1)
	movem.l	(a7)+,a0-a1
	addq.l	#$4,a1
	rts
