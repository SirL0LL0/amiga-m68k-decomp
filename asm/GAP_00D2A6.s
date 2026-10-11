; GAP_00D2A6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00D2A6:
	moveq	#$0,d6
.L0002:
	move.l	d6,-(a7)
	bsr.w	.L0014
	move.l	(a7)+,d6
	addq.b	#$1,d6
	cmp.b	#$a,d6
	bne.b	.L0002
	rts
.L0014:
	move.l	d6,-(a7)
	moveq	#$0,d4
	move.b	d6,d4
	dc.w	$47fa,$5058
	dc.w	$43fa,$505e
	dc.w	$41fa,$54d0
	cmpi.b	#$0,(a0)
	beq.b	.L0034
	dc.w	$47fa,$5064
	dc.w	$43fa,$506a
.L0034:
	adda.l	d4,a3
	move.l	a3,d5
	movea.l	a1,a3
	movea.l	d5,a1
	adda.l	d4,a3
	move.b	(a1),d6
	cmp.b	(a3),d6
	beq.w	.L008A
	move.l	(a7)+,d6
	cmp.b	#$0,d6
	beq.w	.L007C
	move.l	d6,-(a7)
	dc.w	$47fa,$502a
	dc.w	$41fa,$549c
	cmpi.b	#$0,(a0)
	beq.b	.L0064
	dc.w	$47fa,$503a
.L0064:
	move.l	(a7)+,d6
.L0066:
	move.l	d6,-(a7)
	move.b	(a1),d6
	cmp.b	(a3),d6
	beq.w	.L0092
	addq.l	#$1,a3
	move.l	(a7)+,d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0066
.L007C:
	move.b	#$3c,d6
.L0080:
	dc.w	$47fa,$5024
	adda.l	d4,a3
	move.b	d6,(a3)
	rts
.L008A:
	move.l	(a7)+,d6
	move.b	#$2a,d6
	bra.b	.L0080
.L0092:
	move.l	(a7)+,d6
	move.b	#$2b,d6
	bra.b	.L0080
