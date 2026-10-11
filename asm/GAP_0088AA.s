; GAP_0088AA -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_0088AA:
	dc.w	$6100,$ff6c
	move.w	#$d,d4
	dc.w	$6100,$4c40
	dc.w	$6100,$0f84
	cmp.b	#$0,d6
	beq.w	.L0030
	move.w	#$e,d4
	dc.w	$6100,$4c2c
	dc.w	$47f9,$0001,$29da
	move.b	#$0,(a3)+
	dc.w	$6100,$fed2
	rts
.L0030:
	dc.w	$41f9,$0001,$29da
	move.b	#$1,(a0)
	rts
