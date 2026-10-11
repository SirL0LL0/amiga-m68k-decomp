; FUN_000090ce -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000090ce:
	dc.w	$41f9,$0001,$29c3
	cmpi.b	#$0,(a0)
	beq.w	.L0010
	subq.b	#$1,(a0)
.L0010:
	rts
