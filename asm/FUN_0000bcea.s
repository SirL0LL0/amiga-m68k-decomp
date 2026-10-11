; FUN_0000bcea -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000bcea:
	dc.w	$41fa,$6aca
	dc.w	$43fa,$6aca
	move.b	(a0)+,d0
	move.b	(a0),d1
	andi.w	#$ff,d1
	move.b	(a1),d2
	lsl.w	#$8,d2
	lsl.w	#$8,d0
	add.w	d2,d0
	andi.w	#$ff00.l,d0
	or.w	d0,d1
	dc.w	$41fa,$fd86
	move.w	d1,(a0)
	move.w	d1,d4
	dc.w	$41fa,$6aa7
	move.b	(a0),d0
	sub.b	d1,d0
	subq.b	#$1,d0
	dc.w	$41fa,$6a6f
	move.b	d0,(a0)
	dc.w	$41fa,$6a69
	moveq	#$0,d0
	move.b	(a0),d0
	dc.w	$41fa,$fd66
	move.w	(a0),d4
	move.l	d0,-(a7)
	move.l	d4,-(a7)
	dc.w	$6100,$f79a
	move.l	(a7)+,d4
	move.l	(a7)+,d0
	moveq	#$7,d1
	move.b	(a3),$1f40(a3)
	adda.l	#$28,a3
	dbra	d1,$52
	addq.w	#$1,d4
	dbra	d0,$44
	dc.w	$6100,$1d1e
	dc.w	$6100,$1dbc
	rts
