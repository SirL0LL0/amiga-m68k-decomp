; FUN_0000aaba -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000aaba:
	move.l	a3,-(a7)
	moveq	#$4,d5
	addq.l	#$3,a3
	move.b	(a3),d6
	movea.l	(a7)+,a3
	move.b	d6,(a3)
	move.l	d4,-(a7)
	move.l	a3,-(a7)
	dc.w	$41f9,$0001,$288e
	move.b	(a0),d6
	addq.b	#$1,d6
	cmp.b	#$6,d6
	bne.b	.L0022
	moveq	#$0,d6
.L0022:
	move.b	d6,(a0)
	moveq	#$0,d5
	move.b	d6,d5
	dc.w	$47f9,$0001,$21e1
	adda.l	d5,a3
	move.b	(a3),d6
	movea.l	(a7)+,a3
	addq.l	#$1,a3
	move.b	d6,(a3)
	subq.l	#$1,a3
	move.l	(a7)+,d4
	bsr.w	.L0042
	dc.w	$60ae
.L0042:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	dc.w	$6600,$008a
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
	beq.b	.L0092
.L0088:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0088
.L0092:
	move.l	a3,-(a7)
	move.b	d6,d4
	dc.w	$47f9,$0000,$b43e
	moveq	#$3,d5
	cmp.b	#$0,d6
	beq.b	.L00AE
.L00A4:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L00A4
.L00AE:
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
