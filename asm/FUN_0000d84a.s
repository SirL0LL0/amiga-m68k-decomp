; FUN_0000d84a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d84a:
	dc.w	$41f9,$0001,$1a96
	cmpi.b	#$0,(a0)
	beq.b	.L0018
	dc.w	$41fa,$4f62
	move.b	#$1,(a0)
	bra.w	.L0056
.L0018:
	dc.w	$41fa,$4f56
	move.b	#$0,(a0)
	dc.w	$41fa,$4f4a
	move.w	(a0),d4
	dc.w	$43fa,$4f46
	move.b	(a1),d5
	move.b	d4,d0
	lsl.b	#$3,d0
	subq.b	#$6,d0
	dc.w	$45fa,$f702
	move.b	d0,(a2)+
	move.w	d4,d0
	lsr.w	#$5,d0
	subq.b	#$4,d0
	move.b	d0,(a2)
	dc.w	$41fa,$f6f6
	move.b	d0,(a0)
	move.w	d5,d0
	lsr.w	#$5,d0
	subi.b	#$c,d0
	dc.w	$41fa,$f6e9
	move.b	d0,(a0)
	move.l	d4,-(a7)
.L0056:
	dc.w	$6100,$e448
	dc.w	$6100,$dafe
	dc.w	$6100,$e4e4
	dc.w	$6100,$bfe0
	move.l	(a7)+,d4
.L0068:
	dc.w	$6100,$e2c2
	dc.w	$6100,$e39c
	dc.w	$41fa,$4ecc
	cmpi.b	#$1,(a0)
	bne.w	.L009C
	move.b	#$0,(a0)
	dc.w	$6100,$0106
	dc.w	$6100,$01dc
	dc.w	$6100,$019c
	dc.w	$6100,$023a
	dc.w	$6100,$e4e8
	dc.w	$41fa,$4eda
	move.b	(a0),d6
	rts
.L009C:
	dc.w	$41fa,$f699
	moveq	#$0,d0
	move.b	(a0),d0
	andi.b	#$7,d0
	cmp.b	#$0,d0
	beq.w	.L00B6
	cmp.b	#$7,d0
	bne.b	.L0068
.L00B6:
	move.b	(a0),d0
	andi.b	#$f8,d0
	lsr.b	#$3,d0
	dc.w	$41fa,$4eb0
	move.b	(a0),d1
	dc.w	$43fa,$4ea6
	move.b	(a1),d2
	sub.b	d2,d0
	addq.b	#$1,d0
	cmp.b	d0,d1
	beq.b	.L0068
	move.b	d0,(a0)
	dc.w	$6100,$e43a
	dc.w	$6100,$e3c6
	bra.b	.L0068
