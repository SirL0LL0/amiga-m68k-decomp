; FUN_000086c6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000086c6:
	dc.w	$6100,$0022
	dc.w	$41f9,$0001,$28bc
	cmpi.b	#$0,(a0)
	beq.w	.L001E
	dc.w	$41f9,$0001,$28bd
	move.b	#$1,(a0)
	dc.w	$61b0
.L001E:
	dc.w	$6100,$fefc
	rts
