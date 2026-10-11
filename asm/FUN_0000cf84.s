; FUN_0000cf84 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000cf84:
.L0000:
	dc.w	$6100,$009e
	moveq	#$0,d6
	moveq	#$5,d4
	dc.w	$6100,$0788
	dc.w	$6100,$03fc
	dc.w	$41fa,$586a
	move.l	a0,d5
.L0016:
	dc.w	$6100,$0b76
	dc.w	$6100,$0774
	dc.w	$6100,$0c86
	andi.b	#$7f,d6
	cmp.b	#$1b,d6
	beq.b	.L0000
	cmp.b	#$7f,d6
	bne.w	.L0050
	cmp.b	#$1,d4
	beq.b	.L0016
	dc.w	$6100,$e7ca
	subq.b	#$1,d4
	moveq	#$40,d6
	dc.w	$6100,$e64e
	subq.w	#$1,d5
	moveq	#$20,d6
	movea.l	d5,a0
	move.b	(a0),d6
	bra.b	.L0016
.L0050:
	cmp.b	#$d,d6
	bne.w	.L0068
	move.b	#$a0,d6
	movea.l	d5,a0
	move.b	d6,(a0)
	dc.w	$4eb9,$0000,$d814
	rts
.L0068:
	cmp.b	#$1f,d6
	bcs.b	.L0016
	cmp.b	#$5b,d6
	bcc.b	.L0016
	move.b	d4,d6
	cmp.b	#$1d,d6
	beq.b	.L0016
	dc.w	$41fa,$5764
	movea.l	d5,a1
	move.b	(a0),(a1)
	move.b	(a0),d6
	move.l	d6,-(a7)
	dc.w	$6100,$e77c
	move.l	(a7)+,d6
	addq.w	#$1,d5
	dc.w	$6100,$e600
	addq.w	#$1,d4
	moveq	#$40,d6
	dc.w	$6100,$e5f8
	bra.w	.L0016
