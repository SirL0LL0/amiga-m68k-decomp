; FUN_000133fe @0x133fe (file 0xb3fe), 342 byte -- RSTAR
; SoundTick: setup 4 voci audio (AUDx base in A5, struct voce in A6)
; chiamando FUN_00013554 per voce; delay; DMACON=$8000|flags; start voci
; (AUDxLCH/DAT/LEN); avanza posizione; loop pattern.
; Le 4 BSR chiamano FUN_00013554 (funzione successiva, slice+0x156):
; dc.w coi byte originali. I 4 LEA voce puntano fuori slice: dc.w.
; 'opt o-' disabilita il peephole vasm. Trascritto byte-per-byte (mot syntax).

	opt	o-

FUN_000133fe:
	dc.w	$47fa,$088a	; lea +$88E(pc),a3 (fuori slice: songptr)
	movea.l	(a3),a0
	movea.l	a0,a3
	adda.l	#$c,a3
	movea.l	a0,a2
	adda.l	#$1d8,a2
	adda.l	#$258,a0
	move.l	$13cea.l,d0
	moveq	#0,d1
	move.b	(a2,d0.w),d1
	asl.l	#8,d1
	asl.l	#2,d1
	add.l	$13ce6.l,d1
	move.l	d1,$13cf2.l
	clr.w	$13d38.l
	lea.l	$dff0a0.l,a5
	dc.w	$4dfa,$073a	; lea +$782(pc),a6 (fuori slice: voce3)
	dc.w	$6100,$010c	; bsr.w FUN_00013554 (slice+0x156)
	lea.l	$dff0b0.l,a5
	dc.w	$4dfa,$0746	; lea +$79C(pc),a6 (fuori slice: voce2)
	dc.w	$6100,$00fe	; bsr.w FUN_00013554
	lea.l	$dff0c0.l,a5
	dc.w	$4dfa,$0752	; lea +$7B6(pc),a6 (fuori slice: voce1)
	dc.w	$6100,$00f0	; bsr.w FUN_00013554
	lea.l	$dff0d0.l,a5
	dc.w	$4dfa,$075e	; lea +$7D0(pc),a6 (fuori slice: voce0)
	dc.w	$6100,$00e2	; bsr.w FUN_00013554
	move.w	#$1f4,d0
.Delay:
	dbra	d0,.Delay
	move.w	#$8000,d0
	or.w	$13d38.l,d0
	move.w	d0,$dff096.l
	dc.w	$4dfa,$073e	; lea +$7D0(pc),a6 (fuori slice: voce0)
	cmpi.w	#1,$e(a6)
	bne.b	.Ch1
	move.l	$a(a6),$dff0d0.l
	move.w	#1,$dff0d4.l
.Ch1:
	dc.w	$4dfa,$0708	; lea +$7B6(pc),a6 (fuori slice: voce1)
	cmpi.w	#1,$e(a6)
	bne.b	.Ch2
	move.l	$a(a6),$dff0c0.l
	move.w	#1,$dff0c4.l
.Ch2:
	dc.w	$4dfa,$06d2	; lea +$79C(pc),a6 (fuori slice: voce2)
	cmpi.w	#1,$e(a6)
	bne.b	.Ch3
	move.l	$a(a6),$dff0b0.l
	move.w	#1,$dff0b4.l
.Ch3:
	dc.w	$4dfa,$069c	; lea +$782(pc),a6 (fuori slice: voce3)
	cmpi.w	#1,$e(a6)
	bne.b	.Adv
	move.l	$a(a6),$dff0a0.l
	move.w	#1,$dff0a4.l
.Adv:
	move.l	$13ce6.l,d0
	addi.l	#$10,d0
	move.l	d0,$13ce6.l
	cmp.l	#$400,d0
	bne.b	.LoopChk
.Wrap:
	clr.l	$13ce6.l
	addq.l	#1,$13cea.l
	move.b	#1,$13c7d.l
	moveq	#0,d0
	move.w	$13d36.l,d0
	move.l	$13cea.l,d1
	cmp.l	d0,d1
	bne.b	.LoopChk
	clr.l	$13cea.l
.LoopChk:
	tst.w	$13d3a.l
	beq.b	.End
	clr.w	$13d3a.l
	bra.b	.Wrap
.End:
	rts
