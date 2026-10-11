; CALL_0092C8 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0092C8:
	dc.w	$41f9,$0001,$28bd
	cmpi.b	#$0,(a0)
	bne.w	.L0076
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$0,(a0)
	beq.w	.L0076
	dc.w	$41f9,$0001,$28b5
	cmpi.b	#$0,(a0)
	bne.w	.L0076
	dc.w	$41f9,$0001,$28b0
	cmpi.b	#$0,(a0)
	bne.w	.L0076
	dc.w	$6100,$3d36
	dc.w	$41f9,$0001,$28d6
	subq.b	#$1,(a0)
	andi.b	#$f,(a0)
	cmpi.b	#$0,(a0)
	bne.w	.L005A
	move.b	#$c,(a0)
	dc.w	$6100,$f1a8
	bra.b	.L0072
.L005A:
	cmpi.b	#$3,(a0)
	bne.w	.L0068
	dc.w	$6100,$3e20
	bra.b	.L0072
.L0068:
	cmpi.b	#$7,(a0)
	bne.w	.L0072
	nop
.L0072:
	dc.w	$6100,$ff1a
.L0076:
	rts
