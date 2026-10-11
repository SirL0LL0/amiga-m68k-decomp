; CALL_00B25A -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_00B25A:
	dc.w	$41f9,$0001,$289a
	cmpi.b	#$0,(a0)
	dc.w	$6600,$ff42
	dc.w	$41f9,$0001,$28c6
	btst.b	#$7,(a0)
	bne.w	.L0092
	dc.w	$41f9,$0001,$29c3
	move.b	(a0),d6
	cmp.b	#$5,d6
	bcc.b	.L002E
	moveq	#$2,d6
	bra.b	.L003A
.L002E:
	cmp.b	#$a,d6
	bcc.b	.L0038
	moveq	#$4,d6
	bra.b	.L003A
.L0038:
	moveq	#$6,d6
.L003A:
	dc.w	$6100,$20aa
	move.b	d6,d4
	dc.w	$41f9,$0001,$28c4
	move.b	(a0),d6
	sub.b	d4,d6
	beq.w	.L0084
	bcs.w	.L0088
	move.b	d6,d4
.L0054:
	dc.w	$41f9,$0001,$289c
	move.b	(a0),d6
	cmp.b	d4,d6
	bcc.b	.L0062
	move.b	d4,d6
.L0062:
	dc.w	$41f9,$0001,$28c4
	move.b	d6,(a0)
	dc.w	$41f9,$0001,$28c6
	move.b	(a0),d6
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L007E
	move.b	#$80,d6
.L007E:
	move.b	d6,(a0)
	bra.w	.L00B4
.L0084:
	addq.b	#$1,d4
	bra.b	.L0054
.L0088:
	dc.w	$41f9,$0001,$289c
	move.b	(a0),d6
	bra.b	.L0062
.L0092:
	dc.w	$41f9,$0001,$28c4
	move.b	(a0),d6
	move.b	d6,d4
	cmp.b	#$b,d6
	bcc.w	.L00E2
	moveq	#$3,d6
	dc.w	$6100,$203e
	add.b	d4,d6
	dc.w	$41f9,$0001,$28c4
	move.b	d6,(a0)
.L00B4:
	dc.w	$41f9,$0001,$28c4
	move.b	(a0),d6
	cmp.b	#$b,d6
	bcc.w	.L00E2
	dc.w	$47f9,$0001,$241a
	moveq	#$0,d5
	move.b	d6,d5
	subq.b	#$1,d5
	adda.l	d5,a3
	moveq	#$b,d6
	sub.b	d5,d6
	moveq	#$0,d4
	move.b	d6,d4
	dc.w	$6100,$f642
	move.b	#$fe,(a3)
.L00E2:
	rts
