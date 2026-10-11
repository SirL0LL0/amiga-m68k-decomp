; GAP_00C5D8 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00C5D8:
	dc.w	$41f9,$0001,$285c
	move.b	#$0,(a0)
.L000A:
	move.l	d6,-(a7)
	move.l	d4,-(a7)
	dc.w	$43f9,$0001,$285c
	move.b	(a1),d6
	dc.w	$6100,$fe74
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	dc.w	$6100,$ef90
	move.l	(a7)+,d4
	addq.b	#$7,d4
	dc.w	$41f9,$0001,$2891
	move.b	(a0),d6
	addq.b	#$1,d6
	dc.w	$43f9,$0001,$285c
	move.b	d6,(a1)
	move.l	(a7)+,d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L000A
	rts
