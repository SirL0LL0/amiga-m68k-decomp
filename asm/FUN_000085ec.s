; FUN_000085ec -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_000085ec:
	dc.w	$41f9,$0001,$286a
	move.b	#$1,(a0)
	dc.w	$41f9,$0000,$bb92
	move.b	#$0,(a0)
	move.w	#$43,d6
	move.w	#$a3,d4
	dc.w	$6100,$4f2e
	dc.w	$47f9,$0001,$23ca
	moveq	#$0,d4
	move.b	#$6,d4
	moveq	#$6,d0
	cmpi.b	#$0,(a3)+
	bne.w	.L003C
	addq.b	#$1,d4
	dbra	d0,$2e
.L003C:
	dc.w	$41f9,$0001,$285c
	move.b	d4,(a0)
	move.w	#$1806,d4
	dc.w	$47f9,$0001,$23ca
.L004E:
	dc.w	$41f9,$0001,$285c
	move.b	(a0),d1
	cmp.b	d4,d1
	beq.w	.L006A
	move.b	#$20,d6
	dc.w	$6100,$2fc8
	addq.b	#$1,d4
	addq.l	#$1,a3
	bra.b	.L004E
.L006A:
	move.b	#$60,d6
	dc.w	$6100,$2fba
	addq.b	#$1,d4
.L0074:
	move.b	(a3),d6
	addi.b	#$30,d6
	dc.w	$6100,$2fae
	addq.l	#$1,a3
	addq.b	#$1,d4
	cmp.b	#$f,d4
	bne.b	.L0074
	dc.w	$41f9,$0000,$bb92
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$286a
	move.b	#$0,(a0)
	rts
