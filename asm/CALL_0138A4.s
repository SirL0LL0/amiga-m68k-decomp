; CALL_0138A4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0138A4:
	asr.b	#$8,d1
	dc.w	$67e6
	cmpi.b	#$0,$bb64.l
	dc.w	$66dc
	rts
