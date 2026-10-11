; FUN_0000ae8a -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000ae8a:
	dc.w	$43f9,$0001,$288a
	move.b	#$2,(a1)+
	move.b	#$10,(a1)
	move.l	d6,-(a7)
	dc.w	$6100,$25ea
	move.l	(a7)+,d6
	move.l	d4,-(a7)
	cmp.b	#$4a,d6
	beq.w	.L0058
	dc.w	$41f9,$0004,$d58a
	move.l	#$80,d5
	subi.b	#$4b,d6
	cmp.b	#$0,d6
	beq.b	.L0040
.L0036:
	suba.l	d5,a0
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0036
.L0040:
	move.l	a0,-(a7)
	dc.w	$6100,$064c
	movea.l	(a7)+,a0
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	addi.w	#$26,d4
	dc.w	$6100,$063e
	move.l	(a7)+,d4
	rts
.L0058:
	dc.w	$41f9,$0004,$d18a
	dc.w	$6100,$0630
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	addq.w	#$2,d4
	dc.w	$41f9,$0004,$d60a
	dc.w	$6100,$0620
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	addi.w	#$24,d4
	dc.w	$41f9,$0004,$d18a
	dc.w	$6100,$060e
	move.l	(a7)+,d4
	move.l	d4,-(a7)
	addi.w	#$26,d4
	dc.w	$41f9,$0004,$d60a
	dc.w	$6100,$05fc
	move.l	(a7)+,d4
	rts
