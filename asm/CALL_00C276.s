; CALL_00C276 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00C276:
	move.l	d6,-(a7)
	bsr.w	.L00B2
	move.l	(a7)+,d6
	moveq	#$0,d4
	move.b	d6,d4
	moveq	#$2a,d6
	bsr.w	.L017E
	moveq	#$3,d6
	dc.w	$6100,$10b4
	addi.b	#$84,d6
	moveq	#$0,d4
	move.b	d6,d4
	dc.w	$41f9,$0001,$28d8
	move.b	#$1,(a0)
	moveq	#$2e,d6
	dc.w	$6100,$1294
	moveq	#$2f,d6
	move.w	#$91,d4
	dc.w	$6100,$128a
	dc.w	$41f9,$0001,$28d8
	move.b	#$0,(a0)
	dc.w	$41fa,$64dd
	move.b	(a0),d6
	cmp.b	#$0,d6
	beq.w	.L0060
	dc.w	$41fa,$64c7
	move.b	(a0),d6
	dc.w	$6100,$0194
	bra.w	.L0064
.L0060:
	bsr.w	.L01DA
.L0064:
	move.w	#$71f,d4
	dc.w	$6100,$f2a8
	dc.w	$41f9,$0000,$c5ca
	dc.w	$43f9,$0001,$2891
	move.b	(a1),(a0)
	dc.w	$41fa,$64a7
	move.b	#$0,(a0)
	moveq	#$5,d6
	dc.w	$6100,$1866
	dc.w	$6100,$fb52
	dc.w	$41f9,$0001,$286a
	move.b	#$0,(a0)
	dc.w	$41f9,$0000,$bb92
	move.b	#$1,(a0)
	moveq	#$3,d6
	dc.w	$4eb9,$0001,$37a4
	dc.w	$6100,$f112
	dc.w	$6100,$fbe8
	rts
.L00B2:
	dc.w	$6100,$f108
	dc.w	$6100,$f14c
	dc.w	$41f9,$0001,$286a
	move.b	#$1,(a0)
	dc.w	$41f9,$0000,$bb92
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$28d8
	move.b	#$1,(a0)
	moveq	#$5,d6
	bsr.w	.L0198
	dc.w	$41f9,$0001,$28d8
	move.b	#$0,(a0)
	move.b	#$a,d6
	bsr.w	.L0198
	moveq	#$0,d6
	dc.w	$6100,$13aa
	moveq	#$0,d6
	dc.w	$41fa,$05f2
	move.l	a0,d5
	move.w	#$1100,d4
.L0102:
	andi.w	#$ff00.l,d4
	move.b	#$2,d4
.L010A:
	move.l	d5,-(a7)
	move.l	d4,-(a7)
	dc.w	$41fa,$6404
	move.w	#$208,(a0)
	moveq	#$0,d6
	dc.w	$6100,$f2fe
	move.l	(a7)+,d4
	move.l	(a7)+,d5
	addq.w	#$2,d4
	cmp.b	#$c,d4
	bne.w	.L012E
	addq.w	#$2,d4
	bra.b	.L010A
.L012E:
	cmp.b	#$18,d4
	bne.b	.L010A
	addi.w	#$100,d4
	move.w	d4,d6
	andi.w	#$ff00.l,d6
	lsr.w	#$8,d6
	cmp.b	#$18,d6
	bne.b	.L0102
	move.w	#$102,d4
	dc.w	$41f9,$0004,$b5a6
	dc.w	$6100,$f1b6
	moveq	#$2b,d6
	move.w	#$80,d4
	dc.w	$6100,$1166
	dc.w	$41f9,$0001,$28d8
	move.b	#$1,(a0)
	moveq	#$2c,d6
	move.w	#$81,d4
	dc.w	$6100,$1152
	dc.w	$41f9,$0001,$28d8
	move.b	#$0,(a0)
	rts
.L017E:
	move.l	d6,-(a7)
	dc.w	$41fa,$638f
	move.b	#$1,(a0)
	move.l	(a7)+,d6
	dc.w	$6100,$1136
	dc.w	$41fa,$6381
	move.b	#$0,(a0)
	rts
.L0198:
	move.b	d6,d0
	dc.w	$47f9,$0000,$c840
	cmp.b	#$0,d6
	beq.w	.L01B8
.L01A8:
	move.b	(a3)+,d6
	cmp.b	#$ff,d6
	bne.b	.L01A8
	subq.b	#$1,d0
	cmp.b	#$0,d0
	bne.b	.L01A8
.L01B8:
	move.b	(a3),d6
	cmp.b	#$ff,d6
	beq.w	.L01D8
	addq.l	#$1,a3
	move.l	a3,-(a7)
	dc.w	$6100,$12a6
	movea.l	(a7)+,a3
	move.b	(a3)+,d6
	move.l	a3,-(a7)
	dc.w	$6100,$1050
	movea.l	(a7)+,a3
	bra.b	.L01B8
.L01D8:
	rts
.L01DA:
	dc.w	$41f9,$0001,$29c4
	move.b	(a0),d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	dc.w	$6704
	dc.w	$6100,$0ede
