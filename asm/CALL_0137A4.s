; CALL_0137A4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0137A4:
	move.b	#$d,$31b72.l
	move.b	#$0,$13c7c.l
	move.b	#$6,$133d1.l
	dc.w	$41f9,$0002,$e11c
	dc.w	$43fa,$04c6
	move.l	a0,(a1)
	dc.w	$6100,$f790
.L0028:
	dc.w	$4eb9,$0000,$b4a4
	btst.b	#$6,$bfe001.l
	beq.b	.L0028
	btst.b	#$7,$bfe001.l
	beq.b	.L0028
	cmpi.b	#$0,$bb64.l
	bne.b	.L0028
	rts
