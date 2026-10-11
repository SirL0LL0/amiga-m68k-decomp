; FUN_0000d6e4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d6e4:
	moveq	#$4,d5
	moveq	#$0,d4
	dc.w	$47fa,$430c
	cmp.b	#$0,d6
	beq.b	.L001E
.L000E:
	cmpi.b	#$ff,(a3)
	beq.b	.L001E
	adda.l	d5,a3
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L000E
.L001E:
	move.b	(a3)+,d0
	lsl.w	#$8,d0
	move.b	(a3)+,d4
	or.w	d0,d4
	move.b	(a3)+,d0
	lsl.w	#$8,d0
	move.b	(a3),d5
	or.w	d0,d5
	rts
