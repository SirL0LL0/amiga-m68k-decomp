; FUN_0000b4d0 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b4d0:
	dc.w	$47f9,$0006,$f146
	dc.w	$43f9,$0000,$dcaa
	cmpi.b	#$0,(a1)
	beq.b	.L001A
	dc.w	$43f9,$0000,$bf68
	movea.l	(a1),a3
.L001A:
	moveq	#$0,d0
	move.b	d4,d0
	adda.l	d0,a3
	moveq	#$0,d0
	move.w	d4,d0
	andi.w	#$ff00.l,d0
	lsr.w	#$2,d0
	adda.l	d0,a3
	lsl.w	#$2,d0
	adda.l	d0,a3
	andi.l	#$7,d6
	lsl.w	#$3,d6
	adda.l	d6,a3
	lsl.w	#$2,d6
	adda.l	d6,a3
	rts
