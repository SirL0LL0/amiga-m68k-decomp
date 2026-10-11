; CALL_00A978 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00A978:
	move.l	d4,-(a7)
	move.l	d5,-(a7)
	move.l	a3,-(a7)
	move.b	d4,d6
	cmp.b	#$1,d6
	beq.w	.L0092
	subq.b	#$1,d4
	move.l	d4,-(a7)
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.w	.L005C
	dc.w	$47f9,$0001,$2440
	dc.w	$41f9,$0001,$2441
.L002E:
	move.b	(a3),(a0)
	subq.l	#$1,a3
	subq.l	#$1,a0
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L002E
	move.l	(a7)+,d4
	dc.w	$47f9,$0001,$2436
	dc.w	$41f9,$0001,$2437
.L004A:
	move.b	(a3),(a0)
	subq.l	#$1,a0
	subq.l	#$1,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L004A
	bra.w	.L0092
.L005C:
	dc.w	$47f9,$0001,$2422
	dc.w	$41f9,$0001,$2423
.L0068:
	move.b	(a3),(a0)
	subq.l	#$1,a3
	subq.l	#$1,a0
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0068
	move.l	(a7)+,d4
	dc.w	$47f9,$0001,$2418
	dc.w	$41f9,$0001,$2419
.L0084:
	move.b	(a3),(a0)
	subq.l	#$1,a3
	subq.l	#$1,a0
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0084
.L0092:
	movea.l	(a7)+,a3
	move.l	(a7)+,d5
	move.l	(a7)+,d4
	rts
