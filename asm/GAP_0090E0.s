; GAP_0090E0 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_0090E0:
	moveq	#$1a,d4
	dc.w	$6100,$4410
	moveq	#$5,d6
	moveq	#$1b,d4
	dc.w	$6100,$0758
	addq.b	#$1,d6
	moveq	#$0,d4
	move.b	d6,d4
	move.l	d4,-(a7)
	dc.w	$47f9,$0001,$28f4
	dc.w	$6100,$f59c
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	lsl.w	#$8,d4
	dc.w	$47f9,$0001,$22c7
	move.l	a3,d5
	dc.w	$47f9,$0001,$28fb
	dc.w	$6100,$fa4e
	dc.w	$6100,$f590
	dc.w	$41f9,$0001,$28bd
	cmpi.b	#$0,(a0)
	beq.w	.L004E
	move.l	(a7)+,d4
	rts
.L004E:
	moveq	#$1c,d4
	dc.w	$6100,$4116
	dc.w	$6100,$2ed8
	move.l	(a7)+,d4
	move.l	d4,-(a7)
.L005C:
	move.l	d4,-(a7)
	moveq	#$1d,d4
	dc.w	$6100,$43b2
	dc.w	$6100,$ff46
	dc.w	$6184
	dc.w	$41f9,$0001,$1aea
	move.b	(a0),d6
	andi.b	#$1f,d6
	dc.w	$4eb9,$0001,$39ce
	dc.w	$6100,$0fea
	move.l	(a7)+,d4
	dc.w	$41f9,$0001,$28bd
	cmpi.b	#$0,(a0)
	bne.w	.L00E6
	move.l	d4,-(a7)
	dc.w	$6100,$0a1e
	move.l	(a7)+,d4
	dc.w	$41f9,$0001,$28bd
	cmpi.b	#$0,(a0)
	bne.w	.L00E6
	dc.w	$41f9,$0001,$28b5
	cmpi.b	#$0,(a0)
	bne.w	.L00E6
	dc.w	$41f9,$0001,$28b0
	cmpi.b	#$0,(a0)
	bne.w	.L00E6
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$0,(a0)
	beq.w	.L00E6
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L005C
	move.l	(a7)+,d4
	dc.w	$6100,$2e60
	moveq	#$1e,d4
	dc.w	$6100,$4086
	rts
.L00E6:
	move.l	(a7)+,d4
	dc.w	$6100,$2e52
	rts
