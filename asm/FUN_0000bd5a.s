; FUN_0000bd5a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000bd5a:
	dc.w	$41fa,$6a2f
	moveq	#$0,d0
	move.b	(a0),d0
	dc.w	$41fa,$fd2c
	move.w	(a0),d4
	move.l	d0,-(a7)
	move.l	d4,-(a7)
	dc.w	$6100,$f760
	move.l	(a7)+,d4
	move.l	(a7)+,d0
	moveq	#$7,d1
	move.b	$3e80(a3),$1f40(a3)
	adda.l	#$28,a3
	dbra	d1,$1c
	addq.w	#$1,d4
	dbra	d0,$e
	rts
