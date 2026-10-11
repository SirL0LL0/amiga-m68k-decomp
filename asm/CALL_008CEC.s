; CALL_008CEC -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_008CEC:
	dc.w	$6100,$019a
	moveq	#$11,d4
	dc.w	$6100,$4800
	dc.w	$41f9,$0001,$28bf
	cmpi.b	#$0,(a0)
	bne.w	.L0068
	moveq	#$4,d6
	moveq	#$12,d4
	dc.w	$6100,$0b3a
	cmp.b	#$0,d6
	bne.w	.L002E
.L0028:
	dc.w	$6100,$03ca
	rts
.L002E:
	cmp.b	#$1,d6
	bne.w	.L003C
.L0036:
	dc.w	$6100,$0b98
	rts
.L003C:
	cmp.b	#$2,d6
	bne.w	.L004A
.L0044:
	dc.w	$6100,$33d0
	rts
.L004A:
	cmp.b	#$3,d6
	bne.b	.L0056
.L0050:
	dc.w	$6100,$093c
	rts
.L0056:
	cmp.b	#$4,d6
	bne.b	.L0062
.L005C:
	bsr.w	.L00FE
	rts
.L0062:
	bsr.w	.L00E0
	rts
.L0068:
	dc.w	$41f9,$0001,$28ab
	cmpi.b	#$0,(a0)
	bne.w	.L00AA
	moveq	#$9,d6
	moveq	#$2d,d4
	dc.w	$6100,$0adc
	cmp.b	#$0,d6
	beq.b	.L0028
	cmp.b	#$1,d6
	beq.b	.L0036
	cmp.b	#$2,d6
	beq.b	.L0044
	cmp.b	#$3,d6
	beq.b	.L0050
	cmp.b	#$4,d6
	bne.b	.L00A2
	dc.w	$6100,$1260
	rts
.L00A2:
	cmp.b	#$5,d6
	beq.b	.L005C
	bra.b	.L0062
.L00AA:
	moveq	#$9,d6
	move.w	#$be,d4
	dc.w	$6100,$0aa6
	cmp.b	#$0,d6
	beq.w	.L0028
	cmp.b	#$1,d6
	beq.w	.L0036
	cmp.b	#$2,d6
	beq.w	.L0044
	cmp.b	#$3,d6
	beq.w	.L0050
	cmp.b	#$4,d6
	bne.b	.L00A2
	dc.w	$6100,$14ce
	rts
.L00E0:
	move.w	#$d8,d4
	dc.w	$6100,$4722
	dc.w	$6100,$0a66
	cmp.b	#$0,d6
	bne.b	.L00FC
	dc.w	$41f9,$0001,$28d7
	move.b	#$1,(a0)
.L00FC:
	rts
.L00FE:
	move.w	#$d9,d4
	dc.w	$6100,$4704
	move.w	#$78,d6
	move.w	#$da,d4
	dc.w	$6100,$0a48
	cmp.b	#$2,d6
	beq.w	.L0162
	cmp.b	#$0,d6
	beq.w	.L0164
	dc.w	$41f9,$0000,$8f86
	cmpi.b	#$0,(a0)
	beq.w	.L0162
	dc.w	$43f9,$0001,$1d0b
	dc.w	$41f9,$0007,$6e56
	move.l	#$12b,d0
	move.b	(a0)+,(a1)+
	dbra	d0,$142
	dc.w	$43f9,$0001,$23ca
	move.l	#$c90,d0
	move.b	(a0)+,(a1)+
	dbra	d0,$154
	dc.w	$6100,$4c64
	dc.w	$6100,$4cc6
.L0162:
	rts
.L0164:
	dc.w	$41f9,$0000,$8f86
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$1d0b
	dc.w	$43f9,$0007,$6e56
	move.l	#$12b,d0
	move.b	(a0)+,(a1)+
	dbra	d0,$180
	dc.w	$41f9,$0001,$23ca
	move.l	#$c90,d0
	move.b	(a0)+,(a1)+
	dbra	d0,$192
	rts
	dc.w	$0000,$6100
	dc.b	$fd,$7e
	dc.w	$41f9,$0001,$28bf
	cmpi.b	#$0,(a0)
	bne.w	.L0294
	dc.w	$41f9,$0001,$28cd
	cmpi.b	#$3c,(a0)
	bcs.w	.L0294
	dc.w	$41f9,$0001,$28ce
	cmpi.b	#$28,(a0)
	bcs.w	.L0294
	cmpi.b	#$46,(a0)
	bcc.w	.L0296
	dc.w	$41f9,$0001,$28c0
	cmpi.b	#$0,(a0)
	bne.w	.L0294
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$28bf
	move.b	#$1,(a0)
	dc.w	$47f9,$0001,$2125
	dc.w	$41f9,$0001,$2127
	move.l	a0,d5
	moveq	#$13,d4
.L01FE:
	move.l	d4,-(a7)
	move.l	d5,-(a7)
	dc.w	$41f9,$0001,$286f
	moveq	#$1,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$20a
	movea.l	(a7)+,a3
	dc.w	$41f9,$0001,$287b
	moveq	#$1,d4
	move.b	(a3)+,(a0)+
	dbra	d4,$21a
	dc.w	$6100,$3112
	move.l	(a7)+,d4
	dc.w	$6100,$45e0
	moveq	#$1,d6
	dc.w	$4eb9,$0001,$38f2
	dc.w	$6100,$091c
	cmp.b	#$0,d6
	beq.w	.L0268
	moveq	#$0,d6
	dc.w	$41f9,$0001,$28b1
	move.b	#$0,(a0)
	dc.w	$41f9,$0001,$28bf
	move.b	#$0,(a0)
	moveq	#$19,d4
	dc.w	$6100,$45b0
	dc.w	$6100,$4304
	dc.w	$6100,$4300
	dc.w	$6100,$30f6
	rts
.L0268:
	bsr.w	.L0370
	dc.w	$6100,$0162
	moveq	#$18,d4
	dc.w	$6100,$4594
	dc.w	$47f9,$0001,$23d1
	dc.w	$41f9,$0001,$2873
	move.l	a0,d5
	dc.w	$6100,$f628
	dc.w	$6100,$f66c
	dc.w	$6100,$42d2
	dc.w	$6100,$30c8
.L0294:
	rts
.L0296:
	cmpi.b	#$6e,(a0)
	bcc.w	.L02D6
	dc.w	$41f9,$0001,$28c1
	cmpi.b	#$0,(a0)
	bne.b	.L0294
	move.b	#$2,(a0)
	dc.w	$41f9,$0001,$28bf
	move.b	#$2,(a0)
	dc.w	$47f9,$0001,$2129
	dc.w	$41f9,$0001,$212b
	move.l	a0,d5
	moveq	#$34,d6
.L02C8:
	dc.w	$43f9,$0000,$dea1
	move.b	d6,(a1)
	moveq	#$14,d4
	bra.w	.L01FE
.L02D6:
	cmpi.b	#$a0,(a0)
	bcc.w	.L030A
	dc.w	$41f9,$0001,$28c2
	cmpi.b	#$0,(a0)
	bne.b	.L0294
	move.b	#$3,(a0)
	dc.w	$41f9,$0001,$28bf
	move.b	#$3,(a0)
	dc.w	$47f9,$0001,$212d
	dc.w	$41f9,$0001,$212f
	move.l	a0,d5
	moveq	#$35,d6
	bra.b	.L02C8
.L030A:
	cmpi.b	#$fa,(a0)
	bcc.w	.L0340
	dc.w	$41f9,$0001,$28c3
	cmpi.b	#$0,(a0)
	bne.w	.L0294
	move.b	#$4,(a0)
	dc.w	$41f9,$0001,$28bf
	move.b	#$4,(a0)
	dc.w	$47f9,$0001,$2131
	dc.w	$41f9,$0001,$2133
	move.l	a0,d5
	moveq	#$36,d6
	bra.b	.L02C8
.L0340:
	dc.w	$41f9,$0001,$28c7
	cmpi.b	#$0,(a0)
	bne.w	.L0294
	move.b	#$5,(a0)
	dc.w	$41f9,$0001,$28bf
	move.b	#$5,(a0)
	dc.w	$47f9,$0001,$2135
	dc.w	$41f9,$0001,$2137
	move.l	a0,d5
	moveq	#$37,d6
	bra.w	.L02C8
.L0370:
	dc.w	$41f9,$0001,$28ce
	moveq	#$9,d0
	cmpi.b	#$ff,(a0)
	beq.w	.L0386
	addq.b	#$1,(a0)
	dbra	d0,$378
.L0386:
	rts
