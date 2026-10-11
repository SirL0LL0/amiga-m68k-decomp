; FUN_0000bf28 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000bf28:
	dc.w	$41f9,$0001,$28d0
	cmpi.b	#$0,(a0)
	dc.w	$6700,$006a
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$0,(a0)
	dc.w	$6700,$005c
	dc.w	$47f9,$0001,$1a98
	dc.w	$41f9,$0001,$29c4
	move.b	(a0),d6
	dc.w	$41f9,$0001,$285c
	move.b	#$0,(a0)
	move.l	d6,-(a7)
	move.l	a3,-(a7)
	dc.w	$43f9,$0001,$285c
	move.b	(a1),d6
	dc.w	$6100
