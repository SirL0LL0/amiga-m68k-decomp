; GAP_00B1A8 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00B1A8:
	dc.w	$41f9,$0001,$28c4
	cmpi.b	#$9,(a0)
	bcc.w	.L00A0
	cmpi.b	#$0,(a0)
	beq.w	.L00A0
	move.b	(a0),d4
	dc.w	$41f9,$0001,$28c5
	cmpi.b	#$0,(a0)
	beq.w	.L0044
	cmpi.b	#$6,(a0)
	bcc.w	.L0044
	dc.w	$41f9,$0001,$28c4
	cmpi.b	#$0,(a0)
	beq.w	.L00A0
	cmpi.b	#$6,(a0)
	bcc.w	.L00A0
.L0044:
	moveq	#$9,d6
	sub.b	d4,d6
	ori.b	#$4,d6
	lsr.b	#$2,d6
	move.b	d6,d4
	dc.w	$41f9,$0001,$28c5
	move.b	(a0),d6
.L0058:
	cmp.b	#$1,d6
	beq.b	.L0068
	subq.b	#$1,d6
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0058
.L0068:
	dc.w	$41f9,$0001,$28c5
	move.b	d6,(a0)
.L0070:
	dc.w	$41f9,$0001,$28c5
	move.b	(a0),d6
	cmp.b	#$b,d6
	bcc.w	.L009E
	dc.w	$47f9,$0001,$2438
	moveq	#$0,d5
	move.b	d6,d5
	subq.b	#$1,d5
	adda.l	d5,a3
	moveq	#$b,d6
	sub.b	d5,d6
	moveq	#$0,d4
	move.b	d6,d4
	dc.w	$6100,$f738
	move.b	#$fe,(a3)
.L009E:
	rts
.L00A0:
	dc.w	$41f9,$0001,$28c5
	cmpi.b	#$14,(a0)
	beq.b	.L00B0
	addq.b	#$1,(a0)
	bra.b	.L0070
.L00B0:
	rts
