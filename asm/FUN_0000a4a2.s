; FUN_0000a4a2 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000a4a2:
	dc.w	$41f9,$0001,$23cb
	cmpi.b	#$0,(a0)
	beq.w	.L006A
	dc.w	$41f9,$0001,$2893
	btst.b	#$3,(a0)
	bne.w	.L006A
	bset.b	#$3,(a0)
	dc.w	$6100,$1b5c
	moveq	#$70,d4
	dc.w	$6100,$302a
	moveq	#$1,d6
	dc.w	$4eb9,$0001,$38f2
	dc.w	$6100,$f366
	cmp.b	#$0,d6
	beq.w	.L006C
	dc.w	$41f9,$0001,$28ab
	move.b	#$0,(a0)
	moveq	#$73,d4
.L004A:
	dc.w	$6100,$2d5a
	dc.w	$6100,$1b1c
	moveq	#$72,d4
	dc.w	$6100,$2d50
	dc.w	$41f9,$0001,$28aa
	move.b	#$0,(a0)
	dc.w	$6100,$1b40
	dc.w	$6100,$f688
.L006A:
	rts
.L006C:
	dc.w	$6100,$0006
	moveq	#$71,d4
	bra.b	.L004A
