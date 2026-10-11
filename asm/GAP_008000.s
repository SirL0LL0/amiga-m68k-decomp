; GAP_008000 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_008000:
	dc.w	$41fa,$0008
	move.l	a0,$80.w
	trap	#$0
.L000A:
	move.w	#$2700,sr
	movea.l	#$80000.l,a7
	move.w	sr,-(a7)
	movem.l	d0/d6/a0-a2,-(a7)
	dc.w	$41f8,$0142
	move.l	a7,(a0)
	addq.l	#$6,(a0)
	move.w	#$7fff,d6
	dc.w	$41f9,$00df,$f000
	move.w	d6,$9a(a0)
	move.w	d6,$96(a0)
	move.w	#$eaa,$180(a0)
	clr.b	$bfe301.l
	ori.b	#$3,$bfd000.l
	move.b	#$c2,$bfd200.l
	clr.w	$104.w
	movem.l	(a7)+,d0/d6/a0-a2
	move.w	(a7)+,ccr
	nop
	nop
	nop
	nop
	move.w	#$2700,sr
	move.w	#$7fff,$dff09a.l
	move.w	#$7ff,$dff096.l
	dc.w	$41f9,$0000,$b95a
	move.l	a0,$68.w
	move.w	#$8200.l,$dff096.l
	move.w	#$c008.l,$dff09a.l
	move.b	#$88,$bfed01.l
	move.w	#$2000,sr
	dc.w	$4bf9,$00df,$f000
	move.w	#$3a0,$96(a5)
	move.l	#$82d6.l,$80(a5)
	clr.w	$88(a5)
	move.w	#$3981,$8e(a5)
	move.w	#$1c1,$90(a5)
	move.w	#$38,$92(a5)
	move.w	#$d0,$94(a5)
	move.w	#$4200,$100(a5)
	clr.w	$102(a5)
	move.w	#$67,$104(a5)
	clr.w	$108(a5)
	clr.w	$10a(a5)
	move.w	#$83a0.l,$96(a5)
	move.l	#$3,$4.w
	add.w	(a0)+,d1
	dc.w	$6100,$32a2
	dc.w	$4eb9,$0001,$3784
	dc.w	$6100,$5614
	dc.w	$6100,$5610
	dc.w	$41f9,$0001,$23c7
	move.b	#$ff,(a0)
	dc.w	$6100,$2714
	dc.w	$6100,$5a62
	dc.w	$6100,$3318
	dc.w	$6100,$02a6
	dc.w	$6100,$0244
.L0124:
	dc.w	$6100,$121a
.L0128:
	dc.w	$6100,$14d4
	dc.w	$6100,$0a1a
.L0130:
	dc.w	$6100,$0bba
	dc.w	$41f9,$0001,$28d7
	cmpi.b	#$0,(a0)
	bne.w	.L01CC
	dc.w	$6100,$1184
	dc.w	$41f9,$0001,$28b0
	cmpi.b	#$0,(a0)
	beq.w	.L015C
	dc.w	$6100,$10e2
	bra.w	.L0198
.L015C:
	dc.w	$41f9,$0001,$28bd
	cmpi.b	#$0,(a0)
	beq.w	.L0172
	dc.w	$6100,$1062
	bra.w	.L0198
.L0172:
	dc.w	$41f9,$0001,$28b5
	cmpi.b	#$0,(a0)
	beq.w	.L0188
	dc.w	$6100,$109c
	bra.w	.L0198
.L0188:
	dc.w	$41f9,$0001,$29c4
	cmpi.b	#$0,(a0)
	bne.b	.L0130
	dc.w	$6100,$1098
.L0198:
	dc.w	$6100,$3e82
	moveq	#$21,d4
	dc.w	$6100,$5354
	dc.w	$41f9,$0001,$29c4
	move.b	#$0,(a0)
	dc.w	$6100,$58fe
	dc.w	$6100,$168a
	move.l	d6,-(a7)
	dc.w	$6100,$0210
	move.l	(a7)+,d6
	cmp.b	#$0,d6
	bne.w	.L0124
	dc.w	$6100,$1464
	bra.w	.L0128
.L01CC:
	move.b	#$0,(a0)
	dc.w	$6100,$1024
	bra.b	.L0198
