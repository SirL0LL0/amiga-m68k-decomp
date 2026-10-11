; FUN_0000b588 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b588:
	moveq	#$0,d6
	move.l	d4,-(a7)
	dc.w	$43f9,$0001,$288b
	moveq	#$0,d1
	move.b	(a1),d1
	subq.l	#$1,d1
	move.l	d1,-(a7)
	moveq	#$0,d0
	dc.w	$43f9,$0001,$288a
	move.b	(a1),d0
	subq.l	#$1,d0
	move.l	d4,-(a7)
	move.l	d0,-(a7)
	move.l	d6,-(a7)
	move.l	a0,-(a7)
	dc.w	$6100,$ff20
	movea.l	(a7)+,a0
	move.l	(a7)+,d6
	move.l	(a7)+,d0
	moveq	#$0,d2
	move.b	(a0)+,d2
	and.b	(a0)+,d2
	and.b	(a0)+,d2
	and.b	(a0),d2
	subq.l	#$3,a0
	and.b	d2,(a3)
	and.b	d2,$1f40(a3)
	and.b	d2,$3e80(a3)
	and.b	d2,$5dc0(a3)
	eori.b	#$ff,d2
	move.b	(a0)+,d3
	and.b	d2,d3
	or.b	d3,(a3)
	move.b	(a0)+,d3
	and.b	d2,d3
	or.b	d3,$1f40(a3)
	move.b	(a0)+,d3
	and.b	d2,d3
	or.b	d3,$3e80(a3)
	move.b	(a0)+,d3
	and.b	d2,d3
	or.b	d3,$5dc0(a3)
	addq.w	#$1,d4
	dbra	d0,$20
	move.l	(a7)+,d4
	addq.l	#$1,d6
	andi.b	#$7,d6
	cmp.b	#$0,d6
	bne.b	.L0084
	addi.w	#$100,d4
.L0084:
	move.l	(a7)+,d1
	dbra	d1,$10
	move.l	(a7)+,d4
	rts
