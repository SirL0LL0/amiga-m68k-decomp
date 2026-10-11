; FUN_0000bc54 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000bc54:
	dc.w	$41fa,$6b32
	cmpi.b	#$0,$bb64.l
	bne.w	.L0068
	cmpi.b	#$0,$bb60.l
	bne.w	.L006A
	cmpi.b	#$0,$bb62.l
	bne.w	.L0044
	cmpi.b	#$0,(a0)
	beq.w	.L0066
	cmpi.b	#$1,(a0)
	beq.w	.L0068
	cmpi.b	#$2,(a0)
	beq.w	.L006A
	move.b	#$0,(a0)
.L0044:
	dc.w	$43fa,$12e7
	dc.w	$41fa,$12e5
	move.b	(a0),d0
	move.b	(a1),d1
	cmp.b	d0,d1
	beq.w	.L0066
	dc.w	$6100,$f6f8
	dc.w	$41f9,$0000,$d081
	addq.b	#$1,(a0)
	dc.w	$6100,$00d6
.L0066:
	rts
.L0068:
	rts
.L006A:
	move.b	#$0,(a0)
	dc.w	$43fa,$12bd
	dc.w	$41fa,$12ba
	move.b	(a0),d0
	move.b	(a1),d1
	cmp.b	d0,d1
	beq.b	.L0066
	dc.w	$6100,$f6d0
	dc.w	$41f9,$0000,$d081
	subq.b	#$1,(a0)
	dc.w	$41f9,$0000,$d080
	dc.w	$6100,$00a8
	rts
