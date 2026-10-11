; FUN_0000d34a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d34a:
	move.l	d4,-(a7)
	dc.w	$41fa,$4bb8
	move.b	d6,(a0)
	movem.l	d4-d5/a3,-(a7)
	dc.w	$6100,$e42a
	movem.l	(a7)+,d4-d5/a3
	andi.b	#$7f,d6
	dc.w	$41fa,$4686
	move.b	d6,(a0)
.L001E:
	dc.w	$47fa,$4b9d
	dc.w	$41fa,$467c
	moveq	#$0,d4
	move.b	(a0),d4
	addq.b	#$1,(a0)
	andi.b	#$3f,(a0)
	adda.l	d4,a3
	dc.w	$41fa,$4b88
	move.b	(a0),d6
	move.b	(a3),d0
	cmp.b	d0,d6
	bcs.b	.L001E
	move.b	(a3),d6
	move.l	(a7)+,d4
	rts
