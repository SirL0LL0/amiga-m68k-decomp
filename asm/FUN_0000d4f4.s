; FUN_0000d4f4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d4f4:
	move.l	d4,-(a7)
	dc.w	$6100,$0550
	dc.w	$6100,$0498
	move.l	(a7)+,d4
	dc.w	$41f9,$0001,$286a
	move.b	#$1,(a0)
	dc.w	$41f9,$0000,$bb92
	move.b	#$0,(a0)
	moveq	#$1,d6
	dc.w	$6100,$0020
	dc.w	$41f9,$0000,$bb92
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$286a
	move.b	#$0,(a0)
	dc.w	$6100,$0600
	dc.w	$6100,$055a
	rts
