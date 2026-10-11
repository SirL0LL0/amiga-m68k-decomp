; FUN_0000c020 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000c020:
	move.w	#$48,d4
	dc.w	$6100,$14ce
	moveq	#$0,d6
	dc.w	$4eb9,$0001,$38f2
	moveq	#$0,d6
	dc.w	$4eb9,$0001,$38f2
	dc.w	$6100,$1200
	dc.w	$6100,$1994
	dc.w	$6100,$1a2e
	rts
