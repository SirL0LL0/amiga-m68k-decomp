; FUN_00009844 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00009844:
.L0000:
	dc.w	$6100,$1b5e
	btst.b	#$6,$bfe001.l
	beq.b	.L0000
	btst.b	#$7,$bfe001.l
	beq.b	.L0000
	cmpi.b	#$0,$bb64.l
	bne.b	.L0000
	dc.w	$41f9,$0001,$28d9
	move.b	#$1,(a0)
	dc.w	$6100,$3ea4
	dc.w	$41f9,$0001,$28d2
	move.b	#$1,(a0)
	dc.w	$6100,$3fca
	dc.w	$41f9,$0001,$28ba
	moveq	#$0,d6
	move.b	(a0),d6
	rts
