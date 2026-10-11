; CALL_009CFA -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_009CFA:
	moveq	#$0,d5
	moveq	#$0,d0
	dc.w	$41f9,$0001,$28b2
	move.b	(a0),d5
	moveq	#$0,d4
	dc.w	$41f9,$0001,$289d
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$28c5
	move.b	(a0),d6
	cmpi.b	#$b,(a0)
	bcc.w	.L005E
	cmpi.b	#$0,(a0)
	beq.w	.L005E
	move.b	(a0),d4
	move.b	#$c,d6
	sub.b	d4,d6
	moveq	#$0,d0
	move.b	d6,d0
	dc.w	$41f9,$0001,$289d
	move.b	d6,(a0)
	dc.w	$41f9,$0001,$28a7
	cmpi.b	#$0,(a0)
	bne.w	.L005E
	dc.w	$41f9,$0001,$289d
	move.b	(a0),d6
	lsl.b	#$1,d6
	move.b	d6,(a0)
.L005E:
	dc.w	$41f9,$0001,$28c4
	move.b	(a0),d6
	cmpi.b	#$b,(a0)
	bcc.w	.L008E
	cmpi.b	#$0,(a0)
	beq.w	.L008E
	move.b	(a0),d4
	moveq	#$c,d6
	sub.b	d4,d6
	move.b	d6,d4
	add.b	d0,d6
	move.b	d6,d0
	dc.w	$41f9,$0001,$289d
	move.b	(a0),d6
	add.b	d4,d6
	move.b	d6,(a0)
.L008E:
	move.b	d0,d6
	addq.b	#$1,d6
	dc.w	$47f9,$0001,$23dc
	andi.l	#$ffff.l,d5
	adda.l	d5,a3
	move.b	d6,(a3)
	dc.w	$41f9,$0001,$28b2
	addq.b	#$1,(a0)
	dc.w	$6100,$22ae
	dc.w	$6100,$ee5e
	dc.w	$41f9,$0001,$289d
	cmpi.b	#$0,(a0)
	beq.w	.L0134
	moveq	#$0,d4
	move.b	(a0),d4
	lsl.w	#$8,d4
	dc.w	$41f9,$0001,$287a
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$287b
	move.b	#$2,(a0)
	dc.w	$47f9,$0001,$2873
	dc.w	$41f9,$0001,$287c
	move.l	a0,d5
	dc.w	$6100,$ed80
	dc.w	$47f9,$0001,$2875
	dc.w	$6100,$e8ac
	moveq	#$0,d4
	dc.w	$41f9,$0001,$28bf
	move.b	(a0),d4
	dc.w	$47f9,$0001,$211f
	adda.l	d4,a3
	move.b	(a3),d4
	lsl.w	#$8,d4
	dc.w	$47f9,$0001,$287c
	dc.w	$41f9,$0001,$2873
	move.l	a0,d5
	dc.w	$6100,$ed4e
	dc.w	$47f9,$0001,$23d1
	dc.w	$41f9,$0001,$287c
	move.l	a0,d5
	dc.w	$6100,$e772
	dc.w	$6100,$e7b6
.L0134:
	dc.w	$41f9,$0001,$28c5
	move.b	(a0),d6
	cmp.b	#$0,d6
	beq.w	.L01A8
	cmp.b	#$a,d6
	bcc.w	.L01A8
	move.b	d6,d4
	moveq	#$a,d6
	sub.b	d4,d6
	move.b	d6,d4
	dc.w	$41f9,$0001,$28ac
	move.b	(a0),d6
	add.b	d4,d6
	move.b	d6,(a0)
	cmp.b	#$f6,d6
	bcc.w	.L019E
	cmp.b	#$a7,d6
	bcc.w	.L0194
	cmp.b	#$61,d6
	bcc.w	.L018A
	cmp.b	#$26,d6
	bcs.w	.L01A8
	dc.w	$41f9,$0001,$28ad
	bra.w	.L01A4
.L018A:
	dc.w	$41f9,$0001,$28ae
	bra.w	.L01A4
.L0194:
	dc.w	$41f9,$0001,$28af
	bra.w	.L01A4
.L019E:
	dc.w	$41f9,$0001,$28b0
.L01A4:
	move.b	#$1,(a0)
.L01A8:
	rts
