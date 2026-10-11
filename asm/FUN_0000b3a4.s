; FUN_0000b3a4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b3a4:
	dc.w	$6100,$0018
	dc.w	$6100,$0014
	dc.w	$6100,$0010
	dc.w	$6100,$000c
	dc.w	$6100,$0008
	dc.w	$6100,$0004
	rts
