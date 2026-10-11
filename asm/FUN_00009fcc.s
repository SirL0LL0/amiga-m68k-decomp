; FUN_00009fcc -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00009fcc:
	move.b	d6,d0
	dc.w	$47f9,$0001,$29fa
	moveq	#$20,d5
	cmp.b	#$0,d6
	beq.w	.L001C
.L0012:
	adda.l	d5,a3
	subq.b	#$1,d0
	cmp.b	#$0,d0
	bne.b	.L0012
.L001C:
	rts
