; FUN_000132c6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000132c6:
	addq.l	#$1,$13cee.l
	cmpi.l	#$6,$13cee.l
	bne.b	.L001C
	clr.l	$13cee.l
	dc.w	$6000,$011e
.L001C:
	dc.w	$4dfa,$089a
	tst.b	$3(a6)
	beq.b	.L002E
	dc.w	$4bf9,$00df,$f0a0
	dc.w	$6138
.L002E:
	dc.w	$4dfa,$08a2
	tst.b	$3(a6)
	beq.b	.L0040
	dc.w	$4bf9,$00df,$f0b0
	dc.w	$6126
.L0040:
	dc.w	$4dfa,$08aa
	tst.b	$3(a6)
	beq.b	.L0052
	dc.w	$4bf9,$00df,$f0c0
	dc.w	$6114
.L0052:
	dc.w	$4dfa,$08b2
	tst.b	$3(a6)
	beq.b	.L0064
	dc.w	$4bf9,$00df,$f0d0
	dc.w	$6002
.L0064:
	rts
