; GAP_009BCA -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_009BCA:
	cmpi.b	#$7,(a0)
	bne.w	.L000C
	move.b	#$0,(a0)
.L000C:
	dc.w	$41f9,$0001,$28b3
	move.b	(a0),d6
	lsl.b	#$1,d6
	moveq	#$0,d5
	move.b	d6,d5
	dc.w	$47f9,$0001,$20ca
	adda.l	d5,a3
	dc.w	$41f9,$0001,$2864
	move.b	(a0),d6
	cmp.b	(a3),d6
	bne.w	.L006E
	addq.l	#$1,a3
	dc.w	$41f9,$0001,$2865
	move.b	(a0),d6
	cmp.b	(a3),d6
	bne.w	.L006E
	dc.w	$41f9,$0001,$28b3
	addq.b	#$1,(a0)
	cmpi.b	#$c,(a0)
	beq.w	.L0062
	dc.w	$41f9,$0001,$2864
	move.b	#$0,(a0)+
	move.b	#$1,(a0)
	bra.w	.L008A
.L0062:
	dc.w	$41f9,$0001,$28b5
	move.b	#$1,(a0)
	rts
.L006E:
	dc.w	$41f9,$0001,$2865
	addq.b	#$1,(a0)
	cmpi.b	#$a,(a0)
	bne.w	.L008A
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$2864
	addq.b	#$1,(a0)
.L008A:
	dc.w	$6100,$fe84
	dc.w	$41f9,$0001,$28b4
	move.b	(a0),d6
	cmp.b	#$4,d6
	bne.w	.L0120
	dc.w	$41f9,$0001,$28aa
	move.b	(a0),d6
	move.l	d6,-(a7)
	dc.w	$6100,$23a8
	moveq	#$2c,d4
	dc.w	$6100,$387a
	dc.w	$47f9,$0001,$28f4
	dc.w	$6100,$ea16
	dc.w	$47f9,$0001,$29ca
	dc.w	$41f9,$0001,$29c4
	moveq	#$0,d4
	move.b	(a0),d4
.L00CC:
	move.l	d4,-(a7)
	move.l	a3,-(a7)
	dc.w	$6100,$ef6c
	movea.l	(a7)+,a3
	move.l	a3,-(a7)
	dc.w	$41f9,$0001,$286f
	moveq	#$3,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$e0
	dc.w	$47f9,$0001,$28fb
	dc.w	$41f9,$0001,$2873
	move.l	a0,d5
	dc.w	$6100,$e8da
	movea.l	(a7)+,a3
	moveq	#$4,d5
	adda.l	d5,a3
	move.l	(a7)+,d4
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L00CC
	dc.w	$6100,$e9d6
	dc.w	$6100,$3574
	move.l	(a7)+,d6
	dc.w	$41f9,$0001,$28aa
	move.b	d6,(a0)
	dc.w	$6100,$3a2e
.L011E:
	rts
.L0120:
	cmp.b	#$6,d6
	bne.b	.L011E
	dc.w	$6100,$0ea2
	dc.w	$6100,$3a1e
	rts
