; CALL_0091CE -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0091CE:
	dc.w	$6100,$2e4c
	move.w	#$c4,d4
	dc.w	$6100,$431c
	moveq	#$7,d6
	dc.w	$4eb9,$0001,$37a4
	dc.w	$6100,$2e2a
	move.w	#$72,d4
	dc.w	$6100,$4308
	moveq	#$4,d6
	dc.w	$4eb9,$0001,$37a4
	move.w	#$48,d4
	dc.w	$6100,$42f8
	moveq	#$71,d6
	move.w	#$c7,d4
	dc.w	$6100,$4510
	dc.w	$6100,$2a34
	dc.w	$6100,$47c4
	dc.w	$6100,$489a
	dc.w	$6100,$485a
	dc.w	$6100,$48f8
	rts
