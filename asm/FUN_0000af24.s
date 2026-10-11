; FUN_0000af24 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000af24:
	move.l	d4,-(a7)
	cmp.b	#$3c,d6
	bne.b	.L0010
	dc.w	$41f9,$0004,$d10a
	bra.b	.L0024
.L0010:
	cmp.b	#$2b,d6
	bne.b	.L001E
	dc.w	$41f9,$0004,$d08a
	bra.b	.L0024
.L001E:
	dc.w	$41f9,$0004,$d68a
.L0024:
	dc.w	$43f9,$0001,$288a
