; FUN_0000d486 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d486:
	dc.w	$6100,$025c
	dc.w	$41fa,$52de
	cmpi.b	#$0,(a0)
	dc.w	$6700,$0004
	rts
