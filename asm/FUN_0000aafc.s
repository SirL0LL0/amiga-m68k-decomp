; FUN_0000aafc -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000aafc:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	bne.w	.L0096
	move.l	d5,-(a7)
	move.l	a3,-(a7)
	move.l	d4,-(a7)
	moveq	#$1e,d6
	sub.b	d4,d6
	move.l	d6,-(a7)
	dc.w	$47f9,$0001,$2456
	moveq	#$0,d4
	move.b	d6,d4
	adda.l	d4,a3
	dc.w	$41f9,$0001,$1aea
	move.b	(a0),d6
	andi.b	#$1f,d6
	move.b	d6,(a3)
	move.l	(a7)+,d6
	move.b	d6,d4
	dc.w	$47f9,$0001,$2b5a
	moveq	#$14,d5
	cmp.b	#$0,d6
	beq.b	.L0050
.L0046:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0046
.L0050:
	move.l	a3,-(a7)
	move.b	d6,d4
	dc.w	$47f9,$0000,$b43e
	moveq	#$3,d5
	cmp.b	#$0,d6
	beq.b	.L006C
.L0062:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0062
.L006C:
	move.l	a3,-(a7)
	moveq	#$2,d6
	move.l	d4,-(a7)
	move.l	a3,-(a7)
	move.l	d5,-(a7)
	dc.w	$6100,$27cc
	move.l	(a7)+,d5
	movea.l	(a7)+,a3
	move.l	(a7)+,d4
	moveq	#$0,d5
	move.b	d6,d5
	movea.l	(a7)+,a3
	adda.l	d5,a3
	move.b	(a3),d6
	movea.l	(a7)+,a3
	dc.w	$6100,$fc76
	move.l	(a7)+,d4
	movea.l	(a7)+,a3
	move.l	(a7)+,d5
.L0096:
	rts
