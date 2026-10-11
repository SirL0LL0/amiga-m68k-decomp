; GAP_00A952 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00A952:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L0014
	dc.w	$47f9,$0001,$242e
	bra.b	.L001A
.L0014:
	dc.w	$47f9,$0001,$2410
.L001A:
	moveq	#$a,d4
	move.w	#$ff,d6
	dc.w	$6100,$dd2a
	rts
