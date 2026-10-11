; FUN_0000d38e -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d38e:
	dc.w	$47fa,$4e38
	dc.w	$41fa,$53c9
	move.w	d4,d6
	lsr.w	#$8,d6
	move.b	d6,(a0)
.L000E:
	move.l	d4,-(a7)
	move.l	a3,-(a7)
	dc.w	$41fa,$53ba
	move.b	#$1,(a0)
	dc.w	$41fa,$53c1
	move.b	#$1,(a0)
.L0022:
	cmpi.b	#$ff,(a3)
	beq.w	.L00EA
	cmpi.b	#$20,(a3)
	beq.w	.L00DC
.L0032:
	addq.w	#$1,d4
	dc.w	$41fa,$5398
	addq.b	#$1,(a0)
	addq.l	#$1,a3
	cmp.b	d5,d4
	bne.b	.L0022
.L0040:
	movea.l	(a7)+,a3
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	dc.w	$41fa,$5395
	move.b	(a0),d6
	cmp.b	#$1,d6
	bne.w	.L005A
	moveq	#$0,d6
	move.b	d5,d6
	sub.b	d4,d6
.L005A:
	move.l	d6,-(a7)
	cmpi.b	#$ff,(a3)
	beq.w	.L00D6
	cmpi.b	#$20,(a3)
	bne.w	.L0072
	addq.l	#$1,a3
	move.l	(a7)+,d6
.L0070:
	move.l	d6,-(a7)
.L0072:
	cmpi.b	#$ff,(a3)
	beq.w	.L00D6
	moveq	#$0,d6
	move.b	(a3),d6
	dc.w	$6100,$e208
	addq.l	#$1,a3
	addq.w	#$1,d4
	move.l	(a7)+,d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0070
	move.l	(a7)+,d4
	dc.w	$41fa,$5365
	cmpi.b	#$0,(a0)
	beq.w	.L00A2
	addi.w	#$100,d4
.L00A2:
	addi.w	#$100,d4
	move.w	d4,d6
	andi.w	#$ff00.l,d6
	move.w	d5,d0
	andi.w	#$ff00.l,d0
	cmp.w	d0,d6
	bne.w	.L000E
	dc.w	$41fa,$5315
	andi.l	#$ff,d4
	move.b	(a0),d0
	lsl.w	#$8,d0
	andi.l	#$ff00.l,d0
	or.w	d0,d4
	dc.w	$6100,$003a
	bra.w	.L000E
.L00D6:
	move.l	(a7)+,d6
	move.l	(a7)+,d4
	rts
.L00DC:
	dc.w	$41fa,$52f0
	dc.w	$43fa,$52fb
	move.b	(a0),(a1)
	bra.w	.L0032
.L00EA:
	dc.w	$41fa,$52e2
	dc.w	$43fa,$52ed
	move.b	(a0),(a1)
	bra.w	.L0040
