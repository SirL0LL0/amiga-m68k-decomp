; FUN_0000b68e -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000b68e:
	movem.l	d4-d6/a3,-(a7)
.L0004:
	movem.l	d4/d6,-(a7)
	dc.w	$41f9,$0001,$288a
	move.b	(a0),d2
.L0010:
	move.l	d2,-(a7)
	move.l	d6,-(a7)
	dc.w	$6100,$fe2c
	move.l	(a7)+,d6
	move.l	(a7)+,d2
	movea.l	d5,a1
	addq.l	#$1,d5
	moveq	#$0,d0
	move.b	(a1),d0
	dc.w	$45f9,$0001,$28d8
	cmpi.b	#$0,(a2)
	beq.b	.L0034
	move.b	d0,(a3)
	bra.b	.L003A
.L0034:
	eori.b	#$ff,d0
	and.b	d0,(a3)
.L003A:
	adda.l	#$1f40,a3
	and.b	d0,(a3)
	adda.l	#$1f40,a3
	and.b	d0,(a3)
	adda.l	#$1f40,a3
	and.b	d0,(a3)
	addq.w	#$1,d4
	subq.b	#$1,d2
	cmp.b	#$0,d2
	bne.b	.L0010
	movem.l	(a7)+,d4/d6
	addq.l	#$1,d6
	cmp.b	#$8,d6
	bne.b	.L006E
	moveq	#$0,d6
	addi.w	#$100,d4
.L006E:
	dc.w	$41f9,$0001,$288b
	subq.b	#$1,(a0)
	cmpi.b	#$0,(a0)
	bne.b	.L0004
	movem.l	(a7)+,d4-d6/a3
	rts
