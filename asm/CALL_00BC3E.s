; CALL_00BC3E -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00BC3E:
.L0000:
	dc.w	$6100,$ff36
	dc.w	$41fa,$6b44
	cmpi.b	#$1,(a0)
	bne.b	.L0000
	move.b	#$0,(a0)
	rts
