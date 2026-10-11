; FUN_0000d63e -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d63e:
	move.l	a3,-(a7)
	dc.w	$47fa,$4b86
	dc.w	$41fa,$5116
	move.b	(a0),d6
	cmp.b	#$ff,d6
	beq.w	.L00A2
	moveq	#$0,d4
	move.b	d6,d4
	adda.l	d4,a3
.L001A:
	movea.l	d5,a1
	move.b	(a1),d6
	cmp.b	#$a,d6
	bcc.b	.L0030
	andi.b	#$7f,d6
	addi.b	#$30,d6
	bra.w	.L0076
.L0030:
	movea.l	d5,a1
	move.b	(a1),d6
	andi.b	#$7f,d6
	cmp.b	#$21,d6
	beq.w	.L0056
	cmp.b	#$2c,d6
	beq.w	.L0056
	cmp.b	#$2e,d6
	beq.b	.L0056
	cmp.b	#$3f,d6
	bne.w	.L006E
.L0056:
	subq.l	#$1,a3
	move.b	(a3),d6
	cmp.b	#$20,d6
	bne.w	.L006C
	movea.l	d5,a1
	move.b	(a1),d6
	move.b	d6,(a3)
	bra.w	.L0086
.L006C:
	addq.l	#$1,a3
.L006E:
	movea.l	d5,a1
	move.b	(a1),d6
	andi.b	#$7f,d6
.L0076:
	move.b	d6,(a3)
	dc.w	$41fa,$50a4
	addq.b	#$1,(a0)
	cmpi.b	#$ff,(a0)
	beq.w	.L009E
.L0086:
	addq.l	#$1,a3
	movea.l	d5,a1
	move.b	(a1),d6
	andi.b	#$80,d6
	cmp.b	#$80,d6
	beq.w	.L009E
	addq.l	#$1,d5
	bra.w	.L001A
.L009E:
	move.b	#$ff,(a3)
.L00A2:
	movea.l	(a7)+,a3
	rts
