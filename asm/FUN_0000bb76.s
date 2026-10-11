; FUN_0000bb76 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000bb76:
	dc.w	$41fa,$6c10
	move.b	#$0,(a0)
	btst.b	#$6,$bfe001.l
	dc.w	$6700,$004e
	tst.b	$bfe001.l
	dc.w	$6a00,$0058
	cmpi.b	#$0,$bb64.l
	dc.w	$6600,$0060
	cmpi.b	#$0,$aaaaaaaa.l
