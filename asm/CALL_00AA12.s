; CALL_00AA12 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00AA12:
	dc.w	$6100,$ff3e
	dc.w	$47f9,$0001,$1d0b
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L001C
	dc.w	$47f9,$0001,$1da1
.L001C:
	moveq	#$1e,d4
.L001E:
	move.l	d4,-(a7)
	btst.b	#$7,(a3)
	beq.w	.L005C
	addq.l	#$1,a3
	move.l	a3,-(a7)
	moveq	#$3,d6
	dc.w	$6100,$28fe
	movea.l	(a7)+,a3
	addq.b	#$1,d6
	move.b	d6,d4
	move.b	(a3)+,d6
	sub.b	d4,d6
	bcs.b	.L0046
	cmp.b	#$0,d6
	bne.w	.L0054
.L0046:
	move.b	(a3),d6
	subq.l	#$1,d6
	move.b	d6,(a3)
	subq.l	#$1,a3
	move.l	(a7)+,d4
	bra.w	.L008C
.L0054:
	subq.l	#$1,a3
	move.b	d6,(a3)
	bra.w	.L006E
.L005C:
	addq.l	#$1,a3
	move.l	a3,-(a7)
	moveq	#$4,d6
	dc.w	$6100,$28ca
	movea.l	(a7)+,a3
	move.b	(a3),d4
	add.b	d4,d6
	move.b	d6,(a3)
.L006E:
	subq.l	#$1,a3
	move.b	(a3),d6
	subq.b	#$1,d6
	move.b	d6,(a3)
	move.l	(a7)+,d4
	cmp.b	#$0,d6
	dc.w	$6700,$002a
	andi.b	#$3f,d6
	cmp.b	#$0,d6
	bne.w	.L0098
.L008C:
	move.l	a3,-(a7)
	moveq	#$4,d5
	adda.l	d5,a3
	move.b	(a3),d6
	movea.l	(a7)+,a3
	move.b	d6,(a3)
.L0098:
	moveq	#$5,d5
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.w	.L001E
	rts
