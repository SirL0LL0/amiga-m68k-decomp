; FUN_0000d716 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d716:
	move.l	d6,-(a7)
	move.l	d4,-(a7)
	dc.w	$61c8
	addq.w	#$1,d5
	subq.w	#$1,d4
	dc.w	$41fa,$5094
	dc.w	$43fa,$5092
	move.w	d4,(a0)
	move.w	d5,(a1)
	addi.w	#$100,d5
	subi.w	#$100,d4
	dc.w	$6100,$fd62
	dc.w	$6100,$0032
	move.l	(a7)+,d4
	move.l	(a7)+,d6
	dc.w	$6100,$fdf6
	dc.w	$41fa,$5074
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$28d9
	cmpi.b	#$0,(a0)
	bne.b	.L004A
	dc.w	$6100,$0316
	dc.w	$6100,$03b4
.L004A:
	dc.w	$41f9,$0001,$28d9
	move.b	#$0,(a0)
	rts
