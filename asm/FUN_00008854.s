; FUN_00008854 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00008854:
.L0000:
	movea.l	d5,a0
	move.b	(a0),(a3)
	moveq	#$0,d6
	move.b	(a0),d6
	cmp.b	#$ff,d6
	beq.w	.L0054
	lsl.w	#$8,d6
	andi.w	#$ff00.l,d6
	addq.l	#$1,a3
	addq.l	#$1,a0
	move.b	(a0),(a3)
	moveq	#$0,d4
	move.b	(a0),d4
	or.w	d6,d4
	addq.l	#$1,a3
	addq.l	#$1,a0
	move.l	a0,d5
	btst.l	#$f,d4
	bne.w	.L0036
	moveq	#$0,d6
	bra.w	.L0050
.L0036:
	move.l	a3,-(a7)
	andi.w	#$7ff,d4
	dc.w	$47f9,$0000,$ea58
	dc.w	$6100,$4c32
	moveq	#$0,d6
	move.b	(a3)+,d6
	dc.w	$6100,$4aa0
	movea.l	(a7)+,a3
.L0050:
	move.b	d6,(a3)+
	bra.b	.L0000
.L0054:
	rts
