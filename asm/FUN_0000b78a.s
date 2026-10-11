; FUN_0000b78a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b78a:
	dc.w	$6100,$fd42
	moveq	#$7,d0
	dc.w	$41f9,$0001,$28d8
	cmpi.b	#$0,(a0)
	bne.w	.L0044
	dc.w	$41f9,$0000,$8f87
	cmpi.b	#$0,(a0)
	bne.w	.L0044
	move.b	#$ff,(a3)
	move.b	#$0,$1f40(a3)
	move.b	#$0,$3e80(a3)
	move.b	#$0,$5dc0(a3)
	adda.l	#$28,a3
	dbra	d0,$22
	rts
.L0044:
	dc.w	$41f9,$0000,$8f87
	cmpi.b	#$0,(a0)
	bne.w	.L0074
	move.b	#$0,(a3)
	move.b	#$0,$1f40(a3)
	move.b	#$0,$3e80(a3)
	move.b	#$0,$5dc0(a3)
	adda.l	#$28,a3
	dbra	d0,$52
	rts
.L0074:
	cmpi.b	#$1,(a0)
	bne.w	.L009E
	move.b	#$ff,(a3)
	move.b	#$ff,$1f40(a3)
	move.b	#$0,$3e80(a3)
	move.b	#$ff,$5dc0(a3)
	adda.l	#$28,a3
	dbra	d0,$7c
	rts
.L009E:
	move.b	#$ff,(a3)
	move.b	#$0,$1f40(a3)
	move.b	#$ff,$3e80(a3)
	move.b	#$ff,$5dc0(a3)
	adda.l	#$28,a3
	dbra	d0,$9e
	rts
