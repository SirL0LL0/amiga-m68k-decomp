; FUN_00009ae4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00009ae4:
	dc.w	$41f9,$0000,$bb92
	move.b	#$0,(a0)
	dc.w	$43f9,$0001,$28b4
	move.b	(a1),d0
	dc.w	$47f9,$0001,$2087
	moveq	#$4,d5
	cmp.b	#$0,d0
	beq.b	.L002A
.L0020:
	adda.l	d5,a3
	subq.b	#$1,d0
	cmp.b	#$0,d0
	bne.b	.L0020
.L002A:
	move.w	#$141a,d4
	moveq	#$4,d6
	move.l	d4,-(a7)
	dc.w	$61b0
	move.l	(a7)+,d4
	addi.w	#$100,d4
	move.l	d4,-(a7)
	dc.w	$41f9,$0001,$2887
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$2864
	move.b	(a0),d6
	addi.b	#$30,d6
	dc.w	$6100,$1ade
	addq.l	#$1,d4
	dc.w	$41f9,$0001,$2865
	move.b	(a0),d6
	addi.b	#$30,d6
	dc.w	$6100,$1acc
	dc.w	$41f9,$0001,$2887
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$28b3
	move.b	(a0),d4
	dc.w	$47f9,$0001,$20a3
	moveq	#$3,d5
	cmpi.b	#$0,d4
	beq.b	.L0092
.L0088:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0088
.L0092:
	move.w	#$3,d6
	move.l	(a7)+,d4
	addi.l	#$200,d4
	dc.w	$6100,$ff44
	dc.w	$41f9,$0000,$bb92
	move.b	#$1,(a0)
	rts
