; FUN_0000c054 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000c054:
	dc.w	$47f9,$0001,$23dc
	moveq	#$0,d4
	move.w	#$1721,d4
	dc.w	$41f9,$0001,$285c
	move.b	#$80,(a0)
	moveq	#$34,d6
.L0018:
	move.l	d6,-(a7)
	moveq	#$0,d5
	move.b	(a3),d6
	move.b	d6,d5
	cmp.b	#$0,d6
	beq.w	.L00AA
	lsl.w	#$8,d5
	move.b	#$3,d5
	move.l	d4,-(a7)
	move.l	a3,-(a7)
.L0032:
	moveq	#$0,d6
	move.b	d5,d6
	dc.w	$6100,$f444
	move.l	d4,-(a7)
	dc.w	$41f9,$0001,$285c
	move.b	(a0),d6
	eori.b	#$ff,d6
	and.b	d6,(a3)
	and.b	d6,$1f40(a3)
	and.b	d6,$3e80(a3)
	and.b	d6,$5dc0(a3)
	move.l	(a7)+,d4
	cmp.b	#$0,d5
	bne.w	.L006A
	move.b	#$7,d5
	subi.w	#$100,d4
	bra.b	.L006C
.L006A:
	subq.b	#$1,d5
.L006C:
	subi.w	#$100,d5
	move.w	d5,d6
	andi.w	#$ff00.l,d6
	cmp.w	#$0,d6
	bne.b	.L0032
	movea.l	(a7)+,a3
	addq.l	#$1,a3
	move.l	(a7)+,d4
	dc.w	$41f9,$0001,$285c
	move.b	(a0),d6
	ror.b	#$1,d6
	move.b	d6,(a0)
	cmp.b	#$80,d6
	bne.w	.L009C
	move.b	#$80,(a0)
	addq.l	#$1,d4
.L009C:
	move.l	(a7)+,d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.w	.L0018
	rts
.L00AA:
	move.l	(a7)+,d6
	rts
