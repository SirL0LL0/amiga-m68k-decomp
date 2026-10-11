; FUN_0000b51a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b51a:
	moveq	#$0,d6
	move.l	d4,-(a7)
	dc.w	$43f9,$0001,$288b
	moveq	#$0,d1
	move.b	(a1),d1
	subq.l	#$1,d1
	move.l	d1,-(a7)
	moveq	#$0,d0
	dc.w	$43f9,$0001,$288a
	move.b	(a1),d0
	subq.l	#$1,d0
	move.l	d4,-(a7)
	move.l	d0,-(a7)
	move.l	d6,-(a7)
	move.l	a0,-(a7)
	dc.w	$618e
	movea.l	(a7)+,a0
	move.l	(a7)+,d6
	move.l	(a7)+,d0
	move.b	(a0)+,(a3)
	move.b	(a0)+,$1f40(a3)
	move.b	(a0)+,$3e80(a3)
	move.b	(a0)+,$5dc0(a3)
	addq.l	#$1,d4
	dbra	d0,$20
	move.l	(a7)+,d4
	addq.l	#$1,d6
	andi.l	#$7,d6
	cmp.l	#$0,d6
	bne.b	.L005A
	addi.l	#$100,d4
.L005A:
	move.l	(a7)+,d1
	dbra	d1,$10
	move.l	(a7)+,d4
	rts
