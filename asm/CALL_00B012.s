; CALL_00B012 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00B012:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	bne.w	.L007A
	dc.w	$41f9,$0001,$241c
	move.b	(a0),d6
	bsr.w	.L005C
	addq.l	#$1,a3
	move.b	(a3),d6
	move.l	d6,-(a7)
	dc.w	$41f9,$0001,$241a
	move.b	(a0),d6
	cmp.b	#$fe,d6
	beq.w	.L0058
	bsr.w	.L005C
	move.l	(a7)+,d6
	addq.l	#$1,a3
	move.b	(a3),d6
	addq.b	#$1,d6
	subq.l	#$1,a3
	move.b	(a3),d6
	btst.l	#$7,d6
	beq.w	.L005A
	move.l	a3,-(a7)
	moveq	#$4,d6
	dc.w	$6100,$22e0
	movea.l	(a7)+,a3
	addq.b	#$4,d6
	move.b	d6,(a3)
	rts
.L0058:
	move.l	(a7)+,d6
.L005A:
	rts
.L005C:
	dc.w	$47f9,$0001,$1d0b
	cmp.b	#$0,d6
	beq.w	.L0078
	move.b	d6,d4
	moveq	#$5,d5
.L006E:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L006E
.L0078:
	rts
.L007A:
	dc.w	$41f9,$0001,$243a
	move.b	(a0),d6
	bsr.b	.L005C
	addq.l	#$1,a3
	move.b	(a3),d6
	move.l	d6,-(a7)
	dc.w	$41f9,$0001,$2438
	move.b	(a0),d6
	cmp.b	#$fe,d6
	beq.w	.L00C2
	bsr.w	.L00C6
	move.l	(a7)+,d6
	addq.l	#$1,a3
	move.b	(a3),d6
	addq.b	#$1,d6
	subq.l	#$1,a3
	move.b	(a3),d6
	btst.l	#$7,d6
	beq.w	.L00C4
	move.l	a3,-(a7)
	moveq	#$4,d6
	dc.w	$6100,$2276
	movea.l	(a7)+,a3
	addq.b	#$4,d6
	move.b	d6,(a3)
	rts
.L00C2:
	move.l	(a7)+,d6
.L00C4:
	rts
.L00C6:
	dc.w	$47f9,$0001,$1da1
	cmp.b	#$0,d6
	beq.w	.L00E2
	move.b	d6,d4
	moveq	#$5,d5
.L00D8:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L00D8
.L00E2:
	rts
