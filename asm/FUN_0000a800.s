; FUN_0000a800 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000a800:
	move.l	a3,-(a7)
	move.b	d6,d4
	move.b	#$1,(a3)+
	dc.w	$41f9,$0001,$1e37
.L000E:
	cmpi.b	#$ff,(a0)+
	bne.b	.L000E
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L000E
	move.l	a0,d5
	dc.w	$6100,$e034
	movea.l	(a7)+,a3
	rts
