; GAP_00A530 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_00A530:
	bsr.w	.L0276
	dc.w	$41f9,$0001,$2891
	dc.w	$43f9,$0000,$c5cb
	move.b	(a1),(a0)
	dc.w	$41f9,$0000,$c5ca
	move.b	(a1),(a0)
	cmp.b	#$9,d6
	bcc.w	.L0192
	move.l	d6,-(a7)
	dc.w	$6100,$e6b2
	moveq	#$8,d6
	dc.w	$6100,$2de4
	addq.b	#$1,d6
	dc.w	$41f9,$0001,$286f
	move.b	d6,(a0)
	move.l	(a7)+,d6
	cmp.b	#$4,d6
	bcs.w	.L00D4
	dc.w	$41f9,$0001,$2889
	move.b	#$0,(a0)
	dc.w	$41f9,$0000,$c5cb
	move.b	(a0),d6
	move.l	d6,-(a7)
	addi.b	#$48,d6
	dc.w	$41f9,$0000,$e972
	move.b	d6,(a0)
	dc.w	$41f9,$0000,$e9f0
	move.b	d6,(a0)
	dc.w	$41f9,$0001,$28af
	cmpi.b	#$0,(a0)
	beq.w	.L007C
	bra.w	.L0116
.L007C:
	move.w	#$d1,d4
	dc.w	$6100,$2f42
	dc.w	$6100,$f286
	cmp.b	#$0,d6
	bne.w	.L00B4
.L0090:
	dc.w	$47f9,$0001,$23d1
	dc.w	$41f9,$0001,$2873
	move.l	a0,d5
	dc.w	$6100,$e0f6
	bsr.w	.L0244
	move.l	(a7)+,d6
	moveq	#$0,d4
	move.b	d6,d4
	adda.l	d4,a3
	move.b	#$f,(a3)
	rts
.L00B4:
	dc.w	$6100,$1a28
	move.w	#$d2,d4
	dc.w	$6100,$2c5a
	dc.w	$47f9,$0001,$29b7
	move.l	(a7)+,d6
	moveq	#$0,d4
	move.b	d6,d4
	adda.l	d4,a3
	move.b	#$2,(a3)
	rts
.L00D4:
	moveq	#$2,d6
	dc.w	$6100,$2d38
	cmp.b	#$1,d6
	beq.w	.L01B2
.L00E2:
	dc.w	$41f9,$0001,$2889
	move.b	#$0,(a0)
	dc.w	$41f9,$0000,$c5cb
	move.b	(a0),d6
	move.l	d6,-(a7)
	addi.b	#$48,d6
	dc.w	$41f9,$0000,$e9b4
	move.b	d6,(a0)
	dc.w	$41f9,$0000,$e9f0
	move.b	d6,(a0)
	dc.w	$41f9,$0001,$28ae
	cmpi.b	#$0,(a0)
	beq.b	.L0122
.L0116:
	move.w	#$d5,d4
	dc.w	$6100,$2bfc
	bra.w	.L015A
.L0122:
	move.w	#$d3,d4
	dc.w	$6100,$2e9c
	dc.w	$6100,$f1e0
	cmp.b	#$0,d6
	bne.w	.L015A
	dc.w	$47f9,$0001,$23d1
	dc.w	$41f9,$0001,$2873
	move.l	a0,d5
	dc.w	$6100,$e050
	bsr.w	.L0244
	move.l	(a7)+,d6
	moveq	#$0,d4
	move.b	d6,d4
	adda.l	d4,a3
	move.b	#$14,(a3)
	rts
.L015A:
	dc.w	$6100,$1982
	move.w	#$d4,d4
	dc.w	$6100,$2bb4
	dc.w	$47f9,$0001,$28fc
	move.l	(a7)+,d6
	moveq	#$0,d4
	move.b	d6,d4
	adda.l	d4,a3
	move.b	#$80,(a3)
	dc.w	$41f9,$0001,$29c4
	subq.b	#$1,(a0)
	dc.w	$6100,$ec02
	dc.w	$6100,$305e
	dc.w	$6100,$186e
	dc.w	$6100,$184e
.L0190:
	rts
.L0192:
	bsr.w	.L0244
	dc.w	$41f9,$0001,$2889
	move.b	#$0,(a0)
	moveq	#$a,d6
	dc.w	$6100,$2c6c
	cmp.b	#$7,d6
	bne.b	.L0190
	dc.w	$6100,$fa6a
	rts
.L01B2:
	dc.w	$41f9,$0001,$2889
	cmpi.b	#$0,(a0)
	bne.w	.L00E2
	dc.w	$41f9,$0000,$c5cb
	move.b	(a0),d6
	move.l	d6,-(a7)
	addi.b	#$48,d6
	dc.w	$41f9,$0000,$e02c
	move.b	d6,(a0)
	dc.w	$6100,$e500
	moveq	#$7,d6
	dc.w	$6100,$2c32
	addq.b	#$1,d6
	dc.w	$41f9,$0001,$286f
	move.b	d6,(a0)
	moveq	#$25,d4
	dc.w	$6100,$2b2a
	dc.w	$41f9,$0001,$2899
	move.b	#$1,(a0)
	dc.w	$41f9,$0000,$c5cb
	dc.w	$43f9,$0000,$c5ca
	move.b	(a0),(a1)
	dc.w	$43f9,$0001,$2891
	move.b	(a0),(a1)
	moveq	#$2,d6
	dc.w	$6100,$2bfc
	cmp.b	#$1,d6
	beq.w	.L0232
	move.w	#$a5,d6
	dc.w	$6100,$1b22
	move.w	#$a7,d4
.L022A:
	dc.w	$6100,$2aec
	bra.w	.L0090
.L0232:
	move.w	#$a6,d6
	dc.w	$6100,$1b0e
	move.w	#$a8,d4
	bra.b	.L022A
	moveq	#$0,d4
	bra.b	.L0246
.L0244:
	moveq	#$1,d4
.L0246:
	dc.w	$47f9,$0001,$29b7
	moveq	#$3,d0
	move.l	a3,-(a7)
	move.b	(a3),d6
	cmp.b	#$0,d6
	beq.w	.L026E
	cmp.b	#$ff,d6
	beq.w	.L026E
	cmp.b	#$1,d4
	beq.b	.L026C
	addq.b	#$1,(a3)+
	bra.b	.L026E
.L026C:
	subq.b	#$1,(a3)+
.L026E:
	dbra	d0,$250
	movea.l	(a7)+,a3
	rts
.L0276:
	dc.w	$41f9,$0001,$28fc
	move.l	a0,d5
	dc.w	$47f9,$0001,$29b7
	dc.w	$43f9,$0001,$285c
	move.b	#$ff,(a1)
	moveq	#$0,d4
.L0290:
	move.b	(a0),d6
	btst.l	#$7,d6
	bne.w	.L02B0
	dc.w	$43f9,$0001,$285c
	move.b	(a1),d6
	cmp.b	(a3),d6
	bcs.b	.L02B0
	move.b	(a3),(a1)
	dc.w	$45f9,$0001,$285d
	move.b	d4,(a2)
.L02B0:
	addq.b	#$1,d4
	addq.l	#$1,a3
	addq.l	#$1,a0
	cmp.b	#$4,d4
	bne.b	.L0290
	move.l	a0,d5
	dc.w	$45f9,$0001,$285d
	dc.w	$41f9,$0000,$c5cb
	move.b	(a2),(a0)
	move.b	(a1),d6
	rts
