; CALL_0088E6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0088E6:
	dc.w	$41f9,$0001,$29da
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$29c3
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$29c4
	move.b	(a0),d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	beq.w	.L0048
	subq.b	#$1,d6
	cmp.b	#$0,d6
	beq.w	.L00BC
	subq.b	#$1,d6
	cmp.b	#$0,d6
	beq.w	.L011E
	dc.w	$41f9,$0001,$285c
	move.b	#$50,(a0)
	bra.w	.L0160
.L0048:
	dc.w	$47f9,$0001,$300a
	dc.w	$41f9,$0001,$29da
	moveq	#$13,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$56
	move.l	a0,d5
	dc.w	$41f9,$0001,$29a3
	move.b	(a0),d6
	moveq	#$3,d4
	dc.w	$47f9,$0001,$29a4
	dc.w	$6100,$fd48
	dc.w	$41f9,$0001,$29af
	move.b	(a0),d6
	moveq	#$3,d4
	dc.w	$47f9,$0001,$29b0
	dc.w	$6100,$fd34
	dc.w	$41f9,$0001,$285c
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$29ab
	move.b	(a0),d6
	moveq	#$3,d4
	dc.w	$47f9,$0001,$29ac
	dc.w	$6100,$fd16
	dc.w	$41f9,$0001,$29bf
	move.b	(a0),d6
	moveq	#$3,d4
	dc.w	$47f9,$0001,$29c0
	dc.w	$6100,$fd02
	bra.w	.L0160
.L00BC:
	dc.w	$41f9,$0001,$29a3
	dc.w	$43f9,$0001,$29a5
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29a4
	dc.w	$43f9,$0001,$29a6
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$285c
	move.b	#$28,(a0)
	dc.w	$41f9,$0001,$29ab
	dc.w	$43f9,$0001,$29ad
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ac
	dc.w	$43f9,$0001,$29ae
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29bf
	dc.w	$43f9,$0001,$29c1
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29c0
	dc.w	$43f9,$0001,$29c2
	move.b	(a0),(a1)
	bra.w	.L0160
.L011E:
	dc.w	$41f9,$0001,$285c
	move.b	#$3c,(a0)
	dc.w	$41f9,$0001,$29a3
	dc.w	$43f9,$0001,$29a6
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29b1
	dc.w	$43f9,$0001,$29b2
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ad
	dc.w	$43f9,$0001,$29ae
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29c1
	dc.w	$43f9,$0001,$29c2
	move.b	(a0),(a1)
.L0160:
	dc.w	$47f9,$0001,$29af
	moveq	#$3,d0
	bsr.w	.L0258
	lsr.b	#$2,d6
	dc.w	$41f9,$0001,$28cd
	move.b	d6,(a0)
	dc.w	$47f9,$0001,$29a3
	moveq	#$3,d0
	bsr.w	.L0258
	move.b	d6,d4
	dc.w	$41f9,$0001,$285c
	move.b	(a0),d6
	add.b	d4,d6
	lsr.b	#$2,d6
	dc.w	$41f9,$0001,$28ce
	move.b	d6,(a0)
	dc.w	$41f9,$0001,$29bf
	move.b	(a0),d6
	btst.l	#$7,d6
	beq.w	.L01E2
	dc.w	$41f9,$0001,$29ab
	dc.w	$43f9,$0001,$28cb
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ac
	dc.w	$43f9,$0001,$28cc
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ad
	dc.w	$43f9,$0001,$28ca
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ae
	dc.w	$43f9,$0001,$28c9
	move.b	(a0),(a1)
	rts
.L01E2:
	dc.w	$41f9,$0001,$29ab
	dc.w	$43f9,$0001,$28ca
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29c0
	move.b	(a0),d6
	btst.l	#$7,d6
	beq.w	.L022C
	dc.w	$41f9,$0001,$29ac
	dc.w	$43f9,$0001,$28cb
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ad
	dc.w	$43f9,$0001,$28cc
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ae
	dc.w	$43f9,$0001,$28c9
	move.b	(a0),(a1)
	rts
.L022C:
	dc.w	$41f9,$0001,$29ac
	dc.w	$43f9,$0001,$28cc
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ad
	dc.w	$43f9,$0001,$28cb
	move.b	(a0),(a1)
	dc.w	$41f9,$0001,$29ae
	dc.w	$43f9,$0001,$28c9
	move.b	(a0),(a1)
	rts
.L0258:
	move.b	(a3)+,d6
	add.b	(a3)+,d6
	dbra	d0,$25a
	rts
