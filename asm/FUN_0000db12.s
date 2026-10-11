; FUN_0000db12 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000db12:
	dc.w	$41f9,$0007,$07c6
	dc.w	$45f9,$0000,$bf68
	movea.l	(a2),a1
	adda.l	#$1680,a1
	move.l	#$45f,d0
	dc.w	$6000,$0016
