; FUN_0000b0f6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b0f6:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	bne.w	.L00B0
	dc.w	$47f9,$0001,$2474
	moveq	#$0,d4
	dc.w	$41f9,$0001,$28a4
	move.b	(a0),d4
	adda.l	d4,a3
	cmpi.b	#$0,(a3)
	beq.b	.L0034
	moveq	#$0,d6
	dc.w	$41f9,$0001,$28be
	move.b	#$0,(a0)
	bra.b	.L0038
.L0034:
	moveq	#$1,d6
	move.b	d6,(a3)
.L0038:
	moveq	#$a,d4
	dc.w	$41f9,$0001,$28be
	move.b	(a0),d6
	dc.w	$47f9,$0001,$1aeb
.L0048:
	cmp.b	(a3),d6
	beq.b	.L005A
	bcs.b	.L0058
	addq.l	#$1,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0048
.L0058:
	addq.b	#$1,d4
.L005A:
	moveq	#$a,d0
	dc.w	$41f9,$0001,$28ce
	move.b	(a0),d6
	dc.w	$47f9,$0001,$21d7
.L006A:
	cmp.b	(a3),d6
	beq.w	.L007E
	bcs.b	.L007C
	addq.l	#$1,a3
	subq.b	#$1,d0
	cmp.b	#$0,d0
	bne.b	.L006A
.L007C:
	addq.b	#$1,d0
.L007E:
	move.b	d4,d6
	cmp.b	d0,d6
	bcc.b	.L0086
	move.b	d0,d6
.L0086:
	dc.w	$41f9,$0001,$289c
	move.b	d6,(a0)
	moveq	#$3,d6
	dc.w	$6100,$21b8
	addi.b	#$11,d6
	dc.w	$41f9,$0001,$28c4
	move.b	d6,(a0)
	moveq	#$2,d6
	dc.w	$6100,$21a6
	addq.b	#$5,d6
	dc.w	$41f9,$0001,$28c6
	move.b	d6,(a0)
.L00B0:
	rts
