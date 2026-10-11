; FUN_0000c52a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000c52a:
	dc.w	$41f9,$0001,$29c4
	move.b	(a0),d6
	cmpi.b	#$0,(a0)
	beq.w	.L009E
	dc.w	$41f9,$0001,$1af5
	cmpi.b	#$0,(a0)
	beq.b	.L002C
	dc.w	$41f9,$0001,$28d1
	cmpi.b	#$0,(a0)
	beq.w	.L009E
	move.b	(a0),d6
.L002C:
	move.w	#$1314,d4
	moveq	#$2,d0
	cmp.b	#$4,d6
	bne.b	.L003E
	addq.w	#$1,d4
	bra.w	.L0052
.L003E:
	cmp.b	#$1,d6
	bne.w	.L004A
	move.b	#$12,d4
.L004A:
	cmp.b	#$2,d6
	bne.b	.L0052
	moveq	#$5,d0
.L0052:
	dc.w	$41f9,$0001,$285c
	move.b	#$0,(a0)
.L005C:
	move.l	d6,-(a7)
	move.l	d4,-(a7)
	move.l	d0,-(a7)
	dc.w	$43f9,$0001,$285c
	move.b	(a1),d6
	dc.w	$6100,$fece
	move.l	(a7)+,d0
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	move.l	d0,-(a7)
	dc.w	$6100,$efe6
	move.l	(a7)+,d0
	move.l	(a7)+,d4
	sub.b	d0,d4
	dc.w	$41f9,$0001,$2891
	move.b	(a0),d6
	addq.b	#$1,d6
	dc.w	$43f9,$0001,$285c
	move.b	d6,(a1)
	move.l	(a7)+,d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L005C
	rts
.L009E:
	move.w	#$1210,d4
	dc.w	$41f9,$0006,$17f8
	dc.w	$6100,$ef3c
	rts
