; GAP_013684 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_013684:
	dc.w	$41f9,$0001,$dbe6
	dc.w	$43f9,$0001,$dfe6
	move.l	#$25ff,d0
.L0012:
	move.l	-(a0),-(a1)
	subq.l	#$1,d0
	cmp.l	#$0,d0
	bne.b	.L0012
	rts
