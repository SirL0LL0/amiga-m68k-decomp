; FUN_0000d9d2 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d9d2:
	dc.w	$61d2
	move.l	#$77f,d0
	dc.w	$6100,$007e
	dc.w	$6100,$ff48
	dc.w	$41f9,$0001,$28b1
	cmpi.b	#$0,(a0)
	beq.w	.L0062
	dc.w	$41f9,$0001,$288d
	cmpi.b	#$1,(a0)
	bne.b	.L003C
	move.w	#$a16,d4
	dc.w	$41f9,$0006,$09ba
.L0034:
	dc.w	$6100,$db08
	bra.w	.L0062
.L003C:
	cmpi.b	#$2,(a0)
	bne.w	.L0050
	move.w	#$a03,d4
	dc.w	$41f9,$0006,$0d7c
	bra.b	.L0034
.L0050:
	move.w	#$b1d,d4
	dc.w	$41f9,$0006,$127e
	dc.w	$6100,$db50
	bra.w	.L0062
.L0062:
	dc.w	$41f9,$0001,$288d
	cmpi.b	#$4,(a0)
	bne.w	.L0074
	dc.w	$6100,$ea88
.L0074:
	rts
