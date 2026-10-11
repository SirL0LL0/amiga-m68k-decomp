; GAP_00C102 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00C102:
	move.w	#$83,d4
	dc.w	$6100,$1140
	dc.w	$6100,$021c
	moveq	#$3,d6
	dc.w	$6100,$122e
	cmp.b	#$2,d6
	bcs.w	.L0090
	dc.w	$41fa,$6678
	move.b	(a0),d4
.L0020:
	moveq	#$6,d6
	dc.w	$6100,$121a
	andi.b	#$fe,d6
	lsr.b	#$1,d6
	addi.b	#$84,d6
	cmp.b	d4,d6
	beq.b	.L0020
	dc.w	$41fa,$665e
	move.b	d6,(a0)
	dc.w	$6100,$00e8
	dc.w	$41f9,$0001,$286a
	move.b	#$0,(a0)
	dc.w	$41f9,$0000,$bb92
	move.b	#$1,(a0)
	moveq	#$3,d6
	dc.w	$4eb9,$0001,$37a4
	dc.w	$6100,$f2d4
	dc.w	$6100,$fdaa
	move.w	#$92,d4
	dc.w	$6100,$138a
	moveq	#$2,d6
	dc.w	$4eb9,$0001,$37a4
	dc.w	$6100,$fe98
	move.w	#$72,d4
	dc.w	$6100,$1376
	moveq	#$2,d6
	dc.w	$4eb9,$0001,$37a4
	dc.w	$6100,$fe92
	dc.w	$6100,$da04
	rts
.L0090:
	dc.w	$41fa,$6602
	move.b	(a0),d4
.L0096:
	moveq	#$4,d6
	dc.w	$6100,$11a4
	addi.b	#$8c,d6
	cmp.b	d4,d6
	beq.b	.L0096
	dc.w	$41fa,$65ee
	move.b	d6,(a0)
	cmp.b	#$8f,d6
	bne.w	.L00BA
	move.l	d6,-(a7)
	bsr.w	.L010E
	move.l	(a7)+,d6
.L00BA:
	dc.w	$6100,$00c0
	dc.w	$41fa,$65d4
	cmpi.b	#$90,(a0)
	bne.w	.L00F8
	dc.w	$41f9,$0001,$29c4
	subq.b	#$1,(a0)
	moveq	#$0,d6
	dc.w	$41fa,$02f2
	move.b	(a0),d6
	moveq	#$0,d4
	move.b	d6,d4
	dc.w	$47fa,$661a
	adda.l	d4,a3
	bset.b	#$7,(a3)
	addi.b	#$48,d6
	dc.w	$41fa,$2665
	move.b	d6,(a0)
	move.w	#$d0,d4
	bra.b	.L00FC
.L00F8:
	move.w	#$93,d4
.L00FC:
	dc.w	$6100,$12f4
	moveq	#$1,d6
	dc.w	$4eb9,$0001,$37a4
	dc.w	$6100,$d986
	rts
.L010E:
	dc.w	$41fa,$6591
	cmpi.b	#$0,(a0)
	beq.b	.L011A
	subq.b	#$1,(a0)
.L011A:
	rts
