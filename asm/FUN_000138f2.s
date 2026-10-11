; FUN_000138f2 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000138f2:
	dc.w	$0007,$10c6
	dc.w	$43f9,$0001,$28cb
	move.b	(a1),(a0)+
	dc.w	$43f9,$0001,$28ca
	move.b	(a1),(a0)+
	dc.w	$43f9,$0001,$28cc
	dc.w	$45f9,$0001,$28c9
	move.l	(a7)+,d6
	cmp.b	#$8,d6
	bcs.b	.L002E
	move.b	(a1),(a0)+
	move.b	(a2),(a0)+
	bra.b	.L0032
.L002E:
	move.b	(a2),(a0)+
	move.b	(a1),(a0)+
.L0032:
	dc.w	$43f9,$0001,$28cd
	move.b	(a1),(a0)
	bra.w	.L00B0
	btst.b	#$6,$bfe001.l
	dc.w	$6700,$ff7a
	tst.b	$bfe001.l
	dc.w	$6a00,$ff70
	cmpi.b	#$0,$bb64.l
	dc.w	$6600,$ff64
	move.l	d6,-(a7)
	dc.w	$47f9,$0001,$21e8
	move.b	d4,d6
	cmp.b	#$0,d4
	beq.b	.L007C
	moveq	#$4,d5
.L0072:
	adda.l	d5,a3
	subq.b	#$1,d4
	cmp.b	#$0,d4
	bne.b	.L0072
.L007C:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	beq.b	.L0092
	move.l	(a7)+,d6
	move.b	$bfe801.l,d6
	bra.b	.L0094
.L0092:
	move.l	(a7)+,d6
.L0094:
	andi.b	#$7,d6
	dc.w	$41fa,$01d2
	move.b	d6,(a0)+
	move.b	$2(a3),(a0)+
	move.b	(a3),(a0)+
	move.b	$1(a3),(a0)+
	move.b	$3(a3),(a0)+
	move.b	#$ff,(a0)
.L00B0:
	move.b	#$0,$13c7c.l
	move.b	#$6,$133d1.l
	dc.w	$41f9,$0001,$3d8e
	dc.w	$43f9,$0001,$3d8a
	move.l	a0,(a1)
	dc.w	$41f9,$0001,$3c5e
	dc.w	$43f9,$0001,$3fe6
	move.b	$1(a0),d4
	dc.w	$6100,$00ac
	movem.l	a0-a1/a3,-(a7)
	moveq	#$7,d6
	dc.w	$6100,$9964
	movem.l	(a7)+,a0-a1/a3
	dc.w	$6100,$00bc
	cmpi.b	#$46,$5(a0)
	bcc.b	.L0102
	adda.l	#$10,a3
.L0102:
	dc.w	$6100,$00c6
	move.b	$2(a0),d4
	dc.w	$6100,$0080
	move.b	(a0),d6
	cmpi.b	#$64,$5(a0)
	dc.w	$6408
