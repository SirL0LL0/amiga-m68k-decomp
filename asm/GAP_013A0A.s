; GAP_013A0A -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

GAP_013A0A:
	eori.b	#$2,d6
	andi.b	#$7,d6
	dc.w	$6100,$008c
	addq.l	#$4,a3
	dc.w	$6100,$00a2
	move.b	$3(a0),d4
	dc.w	$6100,$005c
	move.b	(a0),d6
	dc.w	$6100,$0078
	addq.l	#$8,a3
	cmpi.b	#$aa,$5(a0)
	bcc.b	.L0046
	move.b	$5(a0),d0
	moveq	#$0,d6
	move.b	#$ff,d6
	sub.b	d0,d6
	lsr.w	#$4,d6
	ori.b	#$1,d6
	andi.w	#$f,d6
	dc.w	$6100,$009a
	bra.b	.L004A
.L0046:
	dc.w	$6100,$006a
.L004A:
	move.b	$4(a0),d4
	dc.w	$6100,$0024
	move.b	(a0),d6
	cmpi.b	#$96,$5(a0)
	bcc.b	.L0060
	eori.w	#$1,d6
.L0060:
	dc.w	$6100,$0034
	adda.l	#$c,a3
	dc.w	$6100,$0046
	dc.w	$6100,$f6c2
	rts
