; GAP_008818 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_008818:
	dc.w	$47f9,$0001,$29da
	move.b	#$1,(a3)+
	dc.w	$41f9,$0001,$20e2
	move.l	a0,d5
	dc.w	$41f9,$0001,$28ca
	cmpi.b	#$0,(a0)
	beq.w	.L0036
	move.b	(a0),d0
.L0022:
	movea.l	d5,a0
	move.b	(a0)+,d6
	move.l	a0,d5
	cmp.b	#$ff,d6
	bne.b	.L0022
	subq.b	#$1,d0
	cmp.b	#$0,d0
	bne.b	.L0022
.L0036:
	dc.w	$6100,$0004
	rts
