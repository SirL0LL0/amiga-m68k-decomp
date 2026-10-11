; FUN_00009b92 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00009b92:
	dc.w	$41f9,$0001,$28bd
	cmpi.b	#$0,(a0)
	dc.w	$66e8
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$0,(a0)
	dc.w	$67dc
	dc.w	$41f9,$0001,$28b0
	cmpi.b	#$0,(a0)
	dc.w	$66d0
	dc.w	$41f9,$0001,$28b5
	cmpi.b	#$0,(a0)
	dc.w	$66c4
	dc.w	$41f9,$0001,$28b4
	addq.b	#$1,(a0)
