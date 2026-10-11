; GAP_00AF4E -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00AF4E:
	move.b	#$2,(a1)+
	move.b	#$10,(a1)
	move.l	a0,-(a7)
	dc.w	$6100,$05c0
	movea.l	(a7)+,a0
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	addi.w	#$22,d4
	dc.w	$6100,$05b2
	move.l	(a7)+,d4
	moveq	#$0,d6
	rts
