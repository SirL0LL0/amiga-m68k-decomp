; FUN_0000c4cc -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000c4cc:
	dc.w	$41f9,$0001,$29c4
	move.b	(a0),d6
	moveq	#$0,d4
	move.b	d6,d4
	subq.b	#$1,d4
	dc.w	$47fa,$02a5
	adda.l	d4,a3
	move.w	#$700,d4
	move.b	(a3),d4
	dc.w	$41f9,$0001,$285c
	move.b	#$0,(a0)
.L0024:
	move.l	d6,-(a7)
	move.l	d4,-(a7)
	dc.w	$43f9,$0001,$285c
	move.b	(a1),d6
	dc.w	$6100,$ff66
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	dc.w	$6100,$f082
	move.l	(a7)+,d4
	addq.b	#$5,d4
	dc.w	$41f9,$0001,$2891
	move.b	(a0),d6
	addq.b	#$1,d6
	dc.w	$43f9,$0001,$285c
	move.b	d6,(a1)
	move.l	(a7)+,d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0024
	rts
