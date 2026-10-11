; FUN_0000a8cc -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000a8cc:
	move.l	d6,-(a7)
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L0018
	dc.w	$47f9,$0001,$2db3
	move.l	(a7)+,d6
	bra.b	.L0020
.L0018:
	move.l	(a7)+,d6
	dc.w	$47f9,$0001,$2b5b
.L0020:
	move.l	d6,-(a7)
	moveq	#$0,d6
	dc.w	$41f9,$0001,$285c
	move.b	#$0,(a0)
	move.b	d4,d6
	dc.w	$41f9,$0001,$28d1
	move.b	d6,(a0)
	cmp.b	#$0,d6
	beq.b	.L004A
	moveq	#$14,d5
.L0040:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0040
.L004A:
	dc.w	$6100,$de2a
	move.l	(a7)+,d6
	dc.w	$6100,$2b68
	dc.w	$6100,$2a6c
	dc.w	$41f9,$0001,$28d1
	move.b	(a0),d6
	moveq	#$0,d4
	move.b	d6,d4
	move.l	d4,-(a7)
	dc.w	$47f9,$0001,$2456
	adda.l	d4,a3
	move.b	(a3),d6
	move.l	d6,-(a7)
	dc.w	$6100,$3222
	dc.w	$6100,$150e
	move.l	(a7)+,d6
	move.l	(a7)+,d4
	dc.w	$4eb9,$0001,$3a30
	rts
