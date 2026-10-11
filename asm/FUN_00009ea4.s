; FUN_00009ea4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00009ea4:
	dc.w	$41f9,$0001,$28a8
	move.b	(a0),d6
	move.l	d6,-(a7)
	moveq	#$0,d4
	move.b	d6,d4
	dc.w	$47f9,$0001,$23d2
	adda.l	d4,a3
	move.b	(a3),d6
	dc.w	$4eb9,$0001,$39ce
	move.l	(a7)+,d6
	move.l	d6,-(a7)
	cmp.b	#$0,d6
	beq.w	.L0090
	moveq	#$6,d6
	dc.w	$6100,$346e
	cmp.b	#$5,d6
	bne.w	.L0090
	dc.w	$41f9,$0001,$288f
	btst.b	#$0,(a0)
	beq.w	.L0064
	bra.w	.L0090
	move.l	(a7)+,d6
	dc.w	$6100,$00da
	moveq	#$0,d6
	move.b	#$0,(a3)+
	dc.w	$6100,$e8ac
.L005A:
	dc.w	$41f9,$0001,$28a8
	addq.b	#$1,(a0)
	rts
.L0064:
	moveq	#$33,d4
	dc.w	$6100,$333c
	dc.w	$41f9,$0001,$288f
	bset.b	#$0,(a0)
	move.l	(a7)+,d6
	dc.w	$6100,$20f2
	move.w	#$7a,d4
	dc.w	$6100,$3324
	dc.w	$6100,$20f4
	move.w	#$7b,d4
	dc.w	$6100,$3318
	rts
.L0090:
	moveq	#$f,d6
	dc.w	$6100,$3408
	dc.w	$47f9,$0001,$28e4
	moveq	#$0,d4
	move.b	d6,d4
	adda.l	d4,a3
	cmpi.b	#$0,(a3)
	bne.b	.L0090
	move.b	#$1,(a3)
	move.b	d4,d6
	dc.w	$47f9,$0001,$1e37
	addq.b	#$1,d6
	move.b	d6,d0
.L00B8:
	move.b	(a3)+,d6
	cmp.b	#$ff,d6
	bne.b	.L00B8
	subq.b	#$1,d0
	cmp.b	#$0,d0
	bne.b	.L00B8
	move.l	(a7)+,d6
	move.l	a3,-(a7)
	dc.w	$6100,$005a
	move.b	#$1,(a3)+
	move.l	(a7)+,d5
	dc.w	$6100,$e8d8
	move.w	#$7c,d4
	dc.w	$41f9,$0001,$28a8
	move.b	(a0),d6
	addq.b	#$1,d6
	dc.w	$41f9,$0000,$e509
	move.b	d6,(a0)
	dc.w	$41f9,$0000,$e526
	move.b	d6,(a0)
	cmp.b	#$1,d6
	bne.w	.L0106
	andi.w	#$ff,d4
	addq.w	#$1,d4
.L0106:
	dc.w	$6100,$3548
	dc.w	$6100,$f88c
	cmp.b	#$0,d6
	beq.w	.L005A
	moveq	#$e,d4
	dc.w	$6100,$3536
	dc.w	$41f9,$0001,$28a8
	move.b	(a0),d6
	dc.w	$6000
