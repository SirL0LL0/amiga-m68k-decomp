; FUN_000086ea -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000086ea:
	movea.l	a3,a0
	movea.l	d5,a3
	move.l	a0,d5
	moveq	#$0,d4
	dc.w	$43f9,$0001,$28bc
	move.b	#$0,(a1)
	moveq	#$7,d1
	move.b	(a0),d6
	sub.b	(a3),d6
	bcc.w	.L0024
	clr.l	d3
	sub.b	d4,d6
	bra.w	.L002A
.L0024:
	sub.b	d4,d6
	bcc.w	.L0034
.L002A:
	addi.b	#$a,d6
	moveq	#$1,d4
	bra.w	.L0036
.L0034:
	moveq	#$0,d4
.L0036:
	move.b	d6,(a0)
	subq.l	#$1,a0
	subq.l	#$1,a3
	dbra	d1,$14
	cmp.b	#$0,d4
	beq.w	.L0052
	dc.w	$43f9,$0001,$28bc
	move.b	#$1,(a1)
.L0052:
	move.l	a3,d5
	movea.l	a0,a3
	rts
