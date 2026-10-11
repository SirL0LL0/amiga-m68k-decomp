; CALL_009074 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_009074:
	dc.w	$41f9,$0001,$28ce
	moveq	#$9,d0
	cmpi.b	#$1,(a0)
	beq.w	.L0016
	subq.b	#$1,(a0)
	dbra	d0,$8
.L0016:
	rts
