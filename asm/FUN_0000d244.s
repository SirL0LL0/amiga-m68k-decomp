; FUN_0000d244 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d244:
	moveq	#$0,d6
	dc.w	$60f4
