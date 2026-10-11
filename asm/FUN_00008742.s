; FUN_00008742 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00008742:
.L0000:
	move.b	(a3)+,d6
	moveq	#$0,d4
	move.b	d6,d4
	cmp.b	#$ff,d6
	beq.w	.L0064
	lsl.w	#$8,d4
	move.b	(a3)+,d6
	move.b	d6,d4
	btst.l	#$f,d4
	beq.w	.L003E
	move.l	a3,-(a7)
	dc.w	$47f9,$0000,$ea58
	andi.w	#$7ff,d4
	dc.w	$6100,$4d5e
	move.l	(a7)+,d5
	moveq	#$0,d4
	movea.l	d5,a0
	move.b	(a0)+,d4
	move.l	a0,d5
	move.l	d5,-(a7)
	addq.l	#$1,a3
	bra.w	.L0048
.L003E:
	addq.l	#$1,a3
	move.l	a3,-(a7)
	dc.w	$47f9,$0001,$01dc
.L0048:
	dc.w	$6100,$4d52
	movea.l	d5,a0
	move.l	a3,d5
	movea.l	a0,a3
	dc.w	$6100,$4ea8
	movea.l	(a7)+,a3
	dc.w	$41f9,$0001,$285c
	cmpi.b	#$ff,(a0)
	bne.b	.L0000
.L0064:
	rts
