; FUN_000086aa -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000086aa:
	dc.w	$41f9,$0001,$28bd
	cmpi.b	#$0,(a0)
	dc.w	$6600,$0032
	dc.w	$47f9,$0001,$28fb
	move.l	a3,d5
	dc.w	$47f9,$0001,$23d1
