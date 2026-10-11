; GAP_00AB94 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00AB94:
	dc.w	$41f9,$0001,$289b
	cmpi.b	#$0,(a0)
	beq.w	.L0072
	dc.w	$41f9,$0001,$28aa
	move.b	(a0),d6
	move.l	d6,-(a7)
	dc.w	$6100,$146e
	move.w	#$bf,d4
	dc.w	$6100,$293e
	dc.w	$6100,$2692
	dc.w	$6100,$1450
	moveq	#$6,d4
	dc.w	$6100,$2930
	dc.w	$6100,$2684
	dc.w	$41f9,$0001,$289b
	btst.b	#$6,(a0)
	beq.b	.L0046
	bsr.w	.L0086
.L0046:
	dc.w	$41f9,$0001,$289b
	btst.b	#$7,(a0)
	beq.b	.L0056
	bsr.w	.L007C
.L0056:
	dc.w	$6100,$0846
	move.l	(a7)+,d6
	dc.w	$41f9,$0001,$28aa
	move.b	d6,(a0)
	dc.w	$6100,$f100
	dc.w	$6100,$130e
	dc.w	$6100,$ef90
	rts
.L0072:
	dc.w	$6100,$f0f2
	dc.w	$6100,$1300
	rts
.L007C:
	dc.w	$41f9,$0001,$289a
	move.b	#$1,(a0)
.L0086:
	dc.w	$6100,$0816
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.w	.L00A0
	dc.w	$41f9,$0004,$cada
	bra.b	.L00A6
.L00A0:
	dc.w	$41f9,$0004,$c52a
.L00A6:
	dc.w	$43f9,$0001,$288a
	move.b	#$1a,(a1)+
	move.b	#$e,(a1)
	move.w	#$7,d4
	dc.w	$6100,$08cc
	moveq	#$6,d6
	dc.w	$6100,$fdbe
	moveq	#$0,d0
	moveq	#$1e,d4
	dc.w	$47f9,$0001,$1d0c
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L00DE
	dc.w	$47f9,$0001,$1da2
.L00DE:
	dc.w	$41f9,$0001,$285c
	move.b	d0,(a0)
	move.b	(a3),d6
	move.l	d0,-(a7)
	move.l	d4,-(a7)
	move.l	a3,-(a7)
	bsr.w	.L0152
	movea.l	(a7)+,a3
	move.l	(a7)+,d4
	move.l	(a7)+,d0
	addq.b	#$1,d0
	moveq	#$5,d5
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L00DE
	dc.w	$6100,$05be
	dc.w	$6100,$2606
	dc.w	$6100,$02cc
	dc.w	$6100,$036a
	dc.w	$47f9,$0001,$241a
	dc.w	$41f9,$0001,$2424
	moveq	#$9,d4
	dc.w	$43f9,$0001,$289a
	cmpi.b	#$0,(a1)
	beq.b	.L013C
	dc.w	$47f9,$0001,$2438
	dc.w	$41f9,$0001,$2442
.L013C:
	move.b	(a3)+,(a0)+
	dbra	d4,$13c
	move.l	a0,d5
	moveq	#$0,d6
	dc.w	$41f9,$0001,$289a
	move.b	#$0,(a0)
	rts
.L0152:
	moveq	#$a,d4
	dc.w	$47f9,$0001,$2410
	move.l	d6,-(a7)
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L016E
	dc.w	$47f9,$0001,$242e
.L016E:
	move.l	(a7)+,d6
.L0170:
	cmp.b	(a3),d6
	bcc.w	.L0190
	move.l	d6,-(a7)
	dc.w	$6100,$fc6a
	move.l	(a7)+,d6
	move.b	d6,(a3)
	adda.l	#$a,a3
	dc.w	$41f9,$0001,$285c
	move.b	(a0),(a3)
	rts
.L0190:
	addq.l	#$1,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0170
	rts
