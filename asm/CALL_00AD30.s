; CALL_00AD30 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00AD30:
.L0000:
	move.l	d4,-(a7)
	move.l	a3,-(a7)
	move.l	d6,-(a7)
	eori.b	#$3,$8f87.l
	move.l	d4,-(a7)
	moveq	#$0,d4
	dc.w	$41f9,$0001,$285e
	move.b	(a0),d6
	move.l	d6,-(a7)
	addq.b	#$1,d6
	dc.w	$41f9,$0001,$285e
	move.b	d6,(a0)
	addi.b	#$69,d6
	move.b	d6,d4
	move.l	(a7)+,d6
	move.l	a3,-(a7)
	dc.w	$6100,$0128
	movea.l	(a7)+,a3
	move.l	(a7)+,d5
	move.l	a3,-(a7)
	subq.l	#$1,d5
	dc.w	$47f9,$0001,$2451
	adda.l	d5,a3
	dc.w	$41f9,$0001,$2887
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$285e
	cmpi.b	#$4b,(a0)
	bne.w	.L0060
	addi.w	#$200,d4
.L0060:
	move.b	(a3),d6
	addq.w	#$2,d4
	dc.w	$6100,$018e
	dc.w	$41f9,$0001,$2887
	move.b	#$0,(a0)
	movea.l	(a7)+,a3
	move.b	(a3),d6
	cmp.b	#$fe,d6
	bne.w	.L0080
	moveq	#$1f,d6
.L0080:
	addi.b	#$50,d6
	moveq	#$0,d4
	move.b	d6,d4
	move.l	(a7)+,d6
	move.l	d6,-(a7)
	dc.w	$6100,$277a
	move.l	(a7)+,d6
	move.l	d6,-(a7)
	dc.w	$6100,$291e
	move.l	(a7)+,d6
	movea.l	(a7)+,a3
	move.b	(a3),d4
	move.l	d6,-(a7)
	cmp.b	#$fe,d4
	beq.w	.L00DE
	move.l	(a7)+,d6
	move.l	a3,-(a7)
	move.l	d6,-(a7)
	addq.b	#$5,d6
	move.l	d6,-(a7)
	move.l	d4,-(a7)
	dc.w	$6100,$28fe
	move.l	(a7)+,d4
	move.l	(a7)+,d6
	dc.w	$6100,$fade
.L00C0:
	move.l	(a7)+,d6
	addq.b	#$1,d6
	movea.l	(a7)+,a3
	subq.l	#$1,a3
	move.l	(a7)+,d4
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.w	.L0000
	move.b	#$0,$8f87.l
	rts
.L00DE:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L00F0
	move.w	#$c3,d6
	bra.b	.L00FC
.L00F0:
	dc.w	$41f9,$0001,$28a4
	move.b	(a0),d6
	addi.b	#$38,d6
.L00FC:
	moveq	#$0,d4
	move.b	d6,d4
	move.l	(a7)+,d6
	move.l	a3,-(a7)
	move.l	d6,-(a7)
	addq.b	#$5,d6
	move.l	d6,-(a7)
	dc.w	$6100,$26fc
	move.l	(a7)+,d6
	dc.w	$6100,$28a2
	dc.w	$41f9,$0001,$28cd
	move.b	(a0),d6
	move.l	d6,-(a7)
	dc.w	$43f9,$0001,$28c8
	move.b	(a1),(a0)
	dc.w	$41f9,$0001,$28a4
	moveq	#$0,d4
	move.b	(a0),d4
	dc.w	$47f9,$0001,$23d2
	adda.l	d4,a3
	move.b	(a3),d6
	move.l	d6,-(a7)
	dc.w	$6100,$2cf4
	dc.w	$6100,$0fe0
	move.l	(a7)+,d6
	dc.w	$4eb9,$0001,$39ce
	move.l	(a7)+,d6
	dc.w	$41f9,$0001,$28cd
	move.b	d6,(a0)
	bra.w	.L00C0
