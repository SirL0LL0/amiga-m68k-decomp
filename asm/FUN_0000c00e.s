; FUN_0000c00e -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000c00e:
	moveq	#$1,d6
	dc.w	$41fa,$6798
	move.b	d6,(a0)
	dc.w	$6100,$16fc
	rts
