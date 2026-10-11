; FUN_0000d928 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000d928:
	dc.w	$41f9,$0001,$288d
	cmpi.b	#$4,(a0)
	beq.w	.L0066
	cmpi.b	#$2,(a0)
	bne.b	.L0018
	dc.w	$6100,$e5ea
.L0018:
	dc.w	$41f9,$0001,$288d
	move.b	(a0),d6
	dc.w	$41f9,$0001,$28aa
	cmpi.b	#$0,(a0)
	beq.w	.L005E
	dc.w	$47f9,$0001,$1aa8
.L0034:
	addq.l	#$2,a3
	subq.b	#$1,d6
	cmp.b	#$0,d6
	bne.b	.L0034
	cmpi.b	#$0,(a3)+
	bne.b	.L004C
	dc.w	$41f9,$0006,$16f4
	bra.b	.L0052
.L004C:
	dc.w	$41f9,$0006,$1776
.L0052:
	move.w	#$600,d4
	move.b	(a3),d4
	dc.w	$6100,$dbfc
	rts
.L005E:
	dc.w	$47f9,$0001,$1ab2
	bra.b	.L0034
.L0066:
	dc.w	$6100,$eb3c
	bra.b	.L0018
