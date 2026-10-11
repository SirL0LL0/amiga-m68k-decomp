; FUN_0000c464 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000c464:
.L0000:
	dc.w	$47f9,$0001,$28fc
	moveq	#$0,d5
	move.b	d6,d5
	adda.l	d5,a3
	move.b	(a3),d6
	btst.l	#$7,d6
	beq.b	.L001A
	move.b	d5,d6
	addq.b	#$1,d6
	bra.b	.L0000
.L001A:
	move.b	d5,d6
	dc.w	$41f9,$0001,$2891
	move.b	d6,(a0)
	dc.w	$47f9,$0001,$29c6
	adda.l	d5,a3
	move.b	(a3),d6
	dc.w	$47f9,$0006,$2e46
	moveq	#$0,d5
	move.w	#$3c0,d5
	cmp.b	#$0,d6
	beq.w	.L004C
.L0042:
	adda.l	d5,a3
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0042
.L004C:
	dc.w	$41f9,$0001,$288a
	move.b	#$5,(a0)
	dc.w	$41f9,$0001,$288b
	move.b	#$30,(a0)
	move.l	a3,d5
	movea.l	d5,a0
	rts
