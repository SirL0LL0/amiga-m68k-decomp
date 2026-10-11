; GAP_00D038 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00D038:
	dc.w	$41fa,$5758
	cmpi.b	#$0,(a0)
	bne.w	.L00CC
	dc.w	$41fa,$5788
	cmpi.b	#$96,(a0)
	bcs.w	.L00CA
	moveq	#$a,d6
	dc.w	$6100,$02ec
	cmp.b	#$7,d6
	bne.w	.L00CA
	moveq	#$4,d6
	dc.w	$6100,$02de
	moveq	#$0,d4
	move.b	d6,d4
	dc.w	$47fa,$5734
	adda.l	d4,a3
	cmpi.b	#$0,(a3)
	bne.w	.L00CA
	move.b	#$1,(a3)
	move.b	d4,d6
	addq.b	#$1,d6
	dc.w	$41fa,$5712
	move.b	d6,(a0)
	addi.b	#$22,d6
	dc.w	$41fa,$153d
	move.b	d6,(a0)
	dc.w	$6100,$ef90
	move.w	#$a4,d4
	dc.w	$6100,$045c
	moveq	#$1,d6
	dc.w	$4eb9,$0001,$38f2
	dc.w	$6100,$c798
	cmp.b	#$0,d6
	bne.w	.L00B4
	moveq	#$18,d4
	dc.w	$6100,$0442
	dc.w	$47fa,$573e
	dc.w	$6100,$b5e0
	dc.w	$41fa,$5738
	move.b	#$1,(a0)
	dc.w	$47fa,$520b
	dc.w	$41fa,$5731
	move.l	a0,d5
	dc.w	$6100,$b4ca
	dc.w	$6100,$b50e
	dc.w	$6100,$0174
	dc.w	$6100,$ef6a
	dc.w	$41fa,$56c3
	move.b	#$a,(a0)
	dc.w	$6100,$caaa
	rts
.L00B4:
	moveq	#$19,d4
	dc.w	$6100,$0158
	dc.w	$6100,$ef52
	dc.w	$41fa,$569a
	move.b	#$0,(a0)
	dc.w	$6100,$ca92
.L00CA:
	rts
.L00CC:
	dc.w	$41fa,$569d
	cmpi.b	#$0,(a0)
	bne.b	.L00CA
	dc.w	$6100,$ef10
	move.w	#$a9,d4
	dc.w	$6100,$03dc
	moveq	#$1,d6
	dc.w	$4eb9,$0001,$38f2
	dc.w	$47fa,$56d0
	dc.w	$6100,$b572
	dc.w	$41fa,$56ca
	move.b	#$1,(a0)
	dc.w	$6100,$b576
	dc.w	$6100,$0114
	dc.w	$6100,$ef0a
	dc.w	$6100,$ca52
	dc.w	$41fa,$564e
	move.b	#$0,(a0)
	rts
