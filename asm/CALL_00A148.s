; CALL_00A148 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00A148:
	dc.w	$41f9,$0001,$28ad
	cmpi.b	#$0,(a0)
	beq.w	.L0082
	dc.w	$41f9,$0001,$23ca
	cmpi.b	#$0,(a0)+
	bne.w	.L0024
	cmpi.b	#$0,(a0)
	beq.w	.L0082
.L0024:
	dc.w	$41f9,$0001,$2893
	btst.b	#$0,(a0)
	bne.w	.L0054
	moveq	#$4,d6
	dc.w	$6100,$31c2
	cmp.b	#$3,d6
	bne.w	.L0054
	dc.w	$41f9,$0001,$28ae
	cmpi.b	#$0,(a0)
	beq.w	.L0054
	bsr.w	.L0098
	rts
.L0054:
	dc.w	$41f9,$0001,$2893
	btst.b	#$1,(a0)
	bne.w	.L0084
	moveq	#$1,d6
	dc.w	$6100,$3192
	cmp.b	#$0,d6
	beq.w	.L0084
	dc.w	$41f9,$0001,$28af
	cmpi.b	#$0,(a0)
	beq.w	.L0084
	bsr.w	.L00DC
.L0082:
	rts
.L0084:
	dc.w	$41f9,$0001,$2893
	btst.b	#$2,(a0)
	bne.w	.L0096
	bsr.w	.L00FE
.L0096:
	rts
.L0098:
	dc.w	$41f9,$0001,$2893
	bset.b	#$0,(a0)
	dc.w	$41f9,$0001,$28aa
	move.b	(a0),d6
	move.l	d6,-(a7)
	move.b	#$0,(a0)
	dc.w	$6100,$1e26
	move.w	#$78,d4
.L00B8:
	dc.w	$6100,$32f2
	moveq	#$1,d6
	dc.w	$4eb9,$0001,$38f2
	dc.w	$6100,$0308
	dc.w	$6100,$303a
	move.l	(a7)+,d6
	dc.w	$41f9,$0001,$28aa
	move.b	d6,(a0)
	dc.w	$6100,$1e26
	rts
.L00DC:
	dc.w	$41f9,$0001,$2893
	bset.b	#$1,(a0)
	dc.w	$41f9,$0001,$28aa
	move.b	(a0),d6
	move.l	d6,-(a7)
	move.b	#$0,(a0)
	dc.w	$6100,$1de2
	move.w	#$79,d4
	bra.b	.L00B8
.L00FE:
	dc.w	$41f9,$0001,$2893
	bset.b	#$2,(a0)
	dc.w	$41f9,$0001,$28aa
	move.b	(a0),d6
	move.l	d6,-(a7)
	dc.w	$6100,$1dc0
	dc.w	$41f9,$0001,$2890
	cmpi.b	#$0,(a0)
	beq.w	.L014A
	cmpi.b	#$1,(a0)
	beq.w	.L0146
	moveq	#$75,d4
.L012E:
	dc.w	$6100,$2fd0
	dc.w	$6100,$e9ac
	move.l	(a7)+,d6
	dc.w	$41f9,$0001,$28aa
	move.b	d6,(a0)
	dc.w	$6100,$348a
	rts
.L0146:
	moveq	#$76,d4
	bra.b	.L012E
.L014A:
	moveq	#$77,d4
	bra.b	.L012E
