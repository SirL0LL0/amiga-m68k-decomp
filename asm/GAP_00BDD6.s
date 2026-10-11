; GAP_00BDD6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00BDD6:
	dc.w	$41f9,$0000,$bfcf
	move.b	#$aa,(a0)
.L000A:
	move.l	a0,-(a7)
	dc.w	$6100,$005a
	move.l	#$1,d0
	move.l	d0,-(a7)
	dc.w	$6100,$f5b4
	move.l	(a7)+,d0
	dbra	d0,$16
	movea.l	(a7)+,a0
	subi.b	#$11,(a0)
	cmpi.b	#$11,(a0)
	bne.b	.L000A
	move.b	#$22,(a0)
	rts
