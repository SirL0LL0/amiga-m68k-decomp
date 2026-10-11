; CALL_008B48 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_008B48:
	dc.w	$6100,$fd9c
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$1,(a0)
	beq.w	.L0016
	dc.w	$6100,$fd4e
.L0016:
	dc.w	$6100,$00c8
	rts
.L001C:
	move.l	d4,-(a7)
	move.l	d5,-(a7)
	move.l	a3,-(a7)
	dc.w	$6100,$fa2e
	movea.l	(a7)+,a3
	move.l	(a7)+,d5
	move.l	(a7)+,d4
	subi.w	#$100,d4
	andi.w	#$ff00.l,d4
	cmp.w	#$0,d4
	bne.b	.L001C
	rts
	dc.w	$47f9,$0001,$2873
	move.l	d6,-(a7)
	andi.b	#$7,d6
	moveq	#$0,d4
	move.b	d6,d4
	lsl.w	#$8,d4
	move.l	(a7)+,d6
	btst.l	#$7,d6
	bne.w	.L008A
	btst.l	#$6,d6
	bne.w	.L0094
	btst.l	#$5,d6
	bne.w	.L009E
	dc.w	$41f9,$0001,$2267
	move.l	a0,d5
.L0070:
	bsr.w	.L00A8
	dc.w	$47f9,$0001,$287c
	bsr.w	.L00A8
	dc.w	$47f9,$0001,$2885
	bsr.w	.L00A8
	rts
.L008A:
	dc.w	$41f9,$0001,$227f
	move.l	a0,d5
	bra.b	.L0070
.L0094:
	dc.w	$41f9,$0001,$2297
	move.l	a0,d5
	bra.b	.L0070
.L009E:
	dc.w	$41f9,$0001,$22af
	move.l	a0,d5
	bra.b	.L0070
.L00A8:
	move.l	d4,-(a7)
	move.l	d5,-(a7)
	bsr.w	.L001C
	movea.l	(a7)+,a3
	moveq	#$8,d4
	adda.l	d4,a3
	movea.l	d5,a0
	move.l	a3,d5
	movea.l	a0,a3
	move.l	(a7)+,d4
	rts
