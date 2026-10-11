; FUN_0000bd8e -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000bd8e:
	dc.w	$41fa,$11f0
	movea.l	#$300,a1
	move.b	$1(a0),d0
	addi.b	#$3a,d0
	move.b	d0,(a1)
	addi.b	#$e,d0
	move.b	d0,$2(a1)
	move.b	#$0,$3(a1)
	move.b	(a0),d0
	lsr.b	#$1,d0
	addi.b	#$3e,d0
	move.b	d0,$1(a1)
	dc.w	$47fa,$c4c8
	dc.w	$6000,$0006
