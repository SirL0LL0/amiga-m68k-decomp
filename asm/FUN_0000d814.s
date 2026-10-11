; FUN_0000d814 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d814:
	move.l	(a7)+,d4
	move.w	d5,d0
	andi.w	#$ff00.l,d0
	andi.w	#$ff,d4
	or.w	d0,d4
	subi.w	#$100,d4
	moveq	#$7,d6
	dc.w	$6100,$dca6
.L0018:
	moveq	#$0,d0
	move.b	d0,(a3)
	move.b	d0,$1f40(a3)
	move.b	d0,$3e80(a3)
	move.b	d0,$5dc0(a3)
	addq.w	#$1,d4
	moveq	#$7,d6
	dc.w	$6100,$dc8e
	cmp.b	d4,d5
	bne.b	.L0018
	rts
