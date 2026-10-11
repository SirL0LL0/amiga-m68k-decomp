; FUN_0000d24c -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d24c:
	dc.w	$41fa,$553a
	move.b	#$0,(a0)
	move.l	d4,-(a7)
	moveq	#$4,d1
	move.l	d1,-(a7)
	dc.w	$6100,$e5ee
	move.l	(a7)+,d1
	dbra	d1,$c
	moveq	#$3b,d1
	move.l	d1,-(a7)
	dc.w	$6100,$e5e0
	dc.w	$6100,$e908
	cmpi.b	#$0,$bb64.l
	bne.b	.L004E
	dc.w	$41fa,$550c
	cmpi.b	#$1,(a0)
	beq.w	.L0044
	move.l	(a7)+,d1
	dbra	d1,$1a
	move.l	(a7)+,d4
	rts
.L0044:
	move.b	#$0,(a0)
	move.l	(a7)+,d1
	move.l	(a7)+,d4
	rts
.L004E:
	cmpi.b	#$0,$bb64.l
	bne.b	.L004E
	bra.b	.L0044
