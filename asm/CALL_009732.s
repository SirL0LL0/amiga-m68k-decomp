; CALL_009732 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_009732:
	dc.w	$6100,$f4d4
	moveq	#$0,d5
	dc.w	$41f9,$0001,$2894
	move.b	(a0),d5
	dc.w	$47f9,$0001,$2161
	adda.l	d5,a3
	dc.w	$43f9,$0001,$287b
	move.b	(a3),(a1)
	dc.w	$41f9,$0001,$28ce
	moveq	#$0,d4
	move.b	(a0),d4
	lsl.w	#$8,d4
	dc.w	$47f9,$0001,$287c
	move.l	a3,d5
	dc.w	$47f9,$0001,$2873
	dc.w	$6100,$f3f8
	dc.w	$47f9,$0001,$286c
	dc.w	$41f9,$0001,$2875
	moveq	#$7,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$4a
	move.l	a0,d5
	bsr.w	.L00DE
	moveq	#$7,d5
	move.l	a3,-(a7)
	adda.l	d5,a3
	movea.l	d5,a0
	move.l	a3,d5
	dc.w	$47f9,$0001,$287c
	dc.w	$6100,$ef50
	movea.l	(a7)+,a3
	dc.w	$41f9,$0001,$28bc
	cmpi.b	#$0,(a0)
	bne.w	.L008A
	dc.w	$41f9,$0001,$286c
	moveq	#$7,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$82
	move.l	a0,d5
.L008A:
	dc.w	$47f9,$0001,$2875
	dc.w	$6100,$eed6
	dc.w	$41f9,$0001,$2894
	moveq	#$0,d4
	move.b	(a0),d4
	move.l	d4,-(a7)
	add.b	(a0),d4
	dc.w	$47f9,$0001,$2166
	adda.l	d4,a3
	dc.w	$41f9,$0001,$287b
	move.b	(a3)+,(a0)
	dc.w	$41f9,$0001,$287c
	move.b	(a3),(a0)
	dc.w	$47f9,$0001,$2170
	move.l	(a7)+,d4
	adda.l	d4,a3
	moveq	#$0,d4
	move.b	(a3),d4
	lsl.w	#$8,d4
	dc.w	$47f9,$0001,$2885
	dc.w	$41f9,$0001,$2873
	move.l	a0,d5
	dc.w	$6100,$f358
	rts
.L00DE:
	dc.w	$47f9,$0001,$2175
	moveq	#$8,d5
	moveq	#$0,d4
	dc.w	$41f9,$0001,$2895
	move.b	(a0),d4
	cmp.b	#$0,d4
	beq.b	.L0100
.L00F6:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L00F6
.L0100:
	rts
