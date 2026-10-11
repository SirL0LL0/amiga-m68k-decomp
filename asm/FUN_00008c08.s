; FUN_00008c08 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_00008c08:
	dc.w	$47f9,$0001,$286c
	dc.w	$6100,$fa8a
	dc.w	$47f9,$0001,$2875
	dc.w	$6100,$fa80
	dc.w	$47f9,$0001,$287e
	dc.w	$6100,$fa76
	rts
