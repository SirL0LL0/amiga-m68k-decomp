; GAP_008C28 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_008C28:
	dc.w	$61de
	dc.w	$41f9,$0001,$29bf
	move.b	(a0),d6
	dc.w	$6100,$ff50
	dc.w	$41f9,$0001,$29c4
	move.b	(a0),d6
	cmp.b	#$1,d6
	beq.w	.L005E
	dc.w	$41f9,$0001,$29c0
	move.b	(a0),d6
	dc.w	$6100,$ff34
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$2,(a0)
	beq.w	.L005E
	dc.w	$41f9,$0001,$29c1
	move.b	(a0),d6
	dc.w	$6100,$ff1a
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$3,(a0)
	beq.w	.L005E
	dc.w	$41f9,$0001,$29c2
	move.b	(a0),d6
	dc.w	$6100,$ff00
.L005E:
	dc.w	$41f9,$0001,$2893
	move.b	(a0),d6
	btst.l	#$2,d6
	beq.w	.L0076
	move.w	#$74,d4
	bra.w	.L0078
.L0076:
	moveq	#$f,d4
.L0078:
	dc.w	$6100,$4852
	moveq	#$3,d6
	moveq	#$10,d4
	dc.w	$6100,$0b9a
	dc.w	$41f9,$0001,$2890
	move.b	d6,(a0)
	cmp.b	#$0,d6
	beq.w	.L00A6
	cmp.b	#$1,d6
	beq.w	.L00B0
	dc.w	$41f9,$0001,$2885
	bra.w	.L00B6
.L00A6:
	dc.w	$41f9,$0001,$2873
	bra.w	.L00B6
.L00B0:
	dc.w	$41f9,$0001,$287c
.L00B6:
	move.l	a0,d5
	dc.w	$47f9,$0001,$23d1
	dc.w	$6100,$f9de
	rts
