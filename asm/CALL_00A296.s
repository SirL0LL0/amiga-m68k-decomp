; CALL_00A296 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00A296:
	dc.w	$41f9,$0001,$289b
	btst.b	#$7,(a0)
	bne.w	.L0060
	moveq	#$b,d6
	moveq	#$34,d4
	dc.w	$6100,$f59a
	cmp.b	#$0,d6
	bne.w	.L0060
	moveq	#$35,d4
	dc.w	$6100,$323c
	dc.w	$41f9,$0001,$2b3a
	move.b	#$0,(a0)
	dc.w	$47f9,$0001,$2b3b
	dc.w	$6100,$e4dc
	dc.w	$41f9,$0001,$289b
	bset.b	#$7,(a0)
	moveq	#$36,d4
	dc.w	$6100,$2f6c
	moveq	#$1,d6
	dc.w	$6100,$305e
	addi.b	#$b,d6
	dc.w	$41f9,$0001,$28c5
	move.b	d6,(a0)
	dc.w	$6100,$f8a0
	rts
.L0060:
	moveq	#$37,d4
	dc.w	$6100,$31fa
	dc.w	$41f9,$0001,$2868
	moveq	#$c,d6
	move.b	d6,(a0)
	moveq	#$48,d4
	dc.w	$41f9,$0001,$28d9
	move.b	#$1,(a0)
	dc.w	$6100,$3402
	moveq	#$d,d6
	moveq	#$38,d4
.L0084:
	move.l	d4,-(a7)
	move.l	d6,-(a7)
	dc.w	$6100,$3218
	move.l	(a7)+,d6
	move.l	(a7)+,d4
	addq.w	#$1,d4
	addq.b	#$1,d6
	cmp.b	#$17,d6
	bne.b	.L0084
	dc.w	$6100,$3518
	dc.w	$41f9,$0001,$28be
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$28ba
	dc.w	$43f9,$0001,$28a4
	move.b	(a0),(a1)
	moveq	#$42,d4
	dc.w	$6100,$31a4
	dc.w	$6100,$f4e8
	cmp.b	#$0,d6
	beq.w	.L00D4
	dc.w	$6100,$ed6e
	dc.w	$6100,$ed6a
	bra.w	.L01CA
.L00D4:
	moveq	#$43,d4
	dc.w	$6100,$3186
	moveq	#$17,d6
	moveq	#$44,d4
	dc.w	$6100,$f4ce
	dc.w	$6100,$e88e
	dc.w	$47f9,$0000,$dd60
	dc.w	$6100,$0102
	dc.w	$47f9,$0001,$219d
	moveq	#$7,d5
	cmp.b	#$0,d4
	beq.w	.L010A
.L0100:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0100
.L010A:
	dc.w	$41f9,$0001,$286d
	move.l	a0,d5
	moveq	#$6,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$114
	moveq	#$45,d4
	dc.w	$6100,$3140
	moveq	#$18,d6
	moveq	#$46,d4
	dc.w	$6100,$f488
	dc.w	$47f9,$0000,$dd66
	dc.w	$6100,$00c0
	dc.w	$47f9,$0001,$21c7
	moveq	#$4,d5
	cmp.b	#$0,d4
	beq.w	.L014C
.L0142:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0142
.L014C:
	dc.w	$41f9,$0001,$2878
	move.l	a0,d5
	moveq	#$3,d0
	move.b	(a3)+,(a0)+
	dbra	d0,$156
	moveq	#$47,d4
	dc.w	$6100,$30fe
	moveq	#$19,d6
	moveq	#$48,d4
	dc.w	$41f9,$0001,$28d9
	move.b	#$1,(a0)
	dc.w	$6100,$330e
	moveq	#$f,d6
	moveq	#$49,d4
.L0178:
	move.l	d4,-(a7)
	move.l	d6,-(a7)
	dc.w	$6100,$3124
	move.l	(a7)+,d6
	move.l	(a7)+,d4
	addq.w	#$1,d4
	addq.b	#$1,d6
	cmp.b	#$15,d6
	bne.b	.L0178
	dc.w	$6100,$3424
	dc.w	$47f9,$0000,$dd6a
	dc.w	$6100,$0056
	dc.w	$47f9,$0001,$2873
	dc.w	$41f9,$0001,$287c
	move.l	a0,d5
	dc.w	$6100,$e158
	moveq	#$4f,d4
	dc.w	$6100,$30ac
	dc.w	$47f9,$0001,$23d1
	dc.w	$41f9,$0001,$2873
	move.l	a0,d5
	dc.w	$6100,$e26c
	dc.w	$6100,$2dee
.L01CA:
	dc.w	$6100,$0c94
	dc.w	$41f9,$0001,$289b
	bset.b	#$6,(a0)
	dc.w	$41f9,$0001,$2868
	move.b	#$0,(a0)
	dc.w	$6100,$0fb8
	dc.w	$6100,$1a8e
	dc.w	$6100,$f710
	rts
