; FUN_0000a486 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000a486:
	dc.w	$41f9,$0001,$28ba
	moveq	#$0,d0
	moveq	#$0,d4
	move.b	(a0),d0
	move.b	d0,d4
	adda.l	d0,a3
	move.b	(a3),d0
	dc.w	$41f9,$0001,$28be
	add.b	d0,(a0)
	rts
