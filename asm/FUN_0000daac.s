; FUN_0000daac -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000daac:
	dc.w	$41f9,$0005,$e50a
	dc.w	$43f9,$0007,$07c6
	move.l	#$45f,d0
	dc.w	$619a
	dc.w	$6100,$e592
	dc.w	$6100,$0010
	dc.w	$6100,$c01a
	dc.w	$6100,$ab1e
	dc.w	$6100,$ea58
	rts
