; CALL_0090BC -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0090BC:
	dc.w	$41f9,$0001,$29c3
	cmpi.b	#$f,(a0)
	beq.w	.L0010
	addq.b	#$1,(a0)
.L0010:
	rts
