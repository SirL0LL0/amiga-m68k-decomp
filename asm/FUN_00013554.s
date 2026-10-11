; FUN_00013554 @0x13554 (file 0xb554), 304 byte -- RSTAR
; SoundCmd: processa un comando audio via struct A6 (dati A3, out A5).
; D2 = nibble alto di byte@2: se !=0 lookup tabella (LEA fuori slice) e
; accumulo; poi setup registri audio + DMACON; switch sul nibble basso
; (casi $B/$C/$D/$E/$F: volume slide, copy, flag, motore floppy CIA, select).
; Il LEA fuori slice e' dc.w coi byte originali.
; 'opt o-' disabilita il peephole vasm. Trascritto byte-per-byte (mot syntax).

	opt	o-

FUN_00013554:
	move.l	(a0,d1.w),(a6)
	addq.l	#4,d1
	moveq	#0,d2
	move.b	2(a6),d2
	andi.b	#$f0,d2
	lsr.b	#4,d2
	tst.b	d2
	beq.b	.Tst
	moveq	#0,d3
	dc.w	$43fa,$0688	; lea +$6A6(pc),a1 (fuori slice)
	move.l	d2,d4
	asl.l	#2,d2
	mulu.w	#$1e,d4
	move.l	(a1,d2.w),4(a6)
	move.w	(a3,d4.w),8(a6)
	move.w	2(a3,d4.w),$12(a6)
	move.w	4(a3,d4.w),d3
	tst.w	d3
	beq.b	.Alt
	move.l	4(a6),d2
	add.l	d3,d2
	move.l	d2,4(a6)
	move.l	d2,$a(a6)
	move.w	6(a3,d4.w),8(a6)
	move.w	6(a3,d4.w),$e(a6)
	move.w	$12(a6),8(a5)
	bra.b	.Tst
.Alt:
	move.l	4(a6),d2
	add.l	d3,d2
	move.l	d2,$a(a6)
	move.w	6(a3,d4.w),$e(a6)
	move.w	$12(a6),8(a5)
.Tst:
	tst.w	(a6)
	beq.b	.Sw
	move.w	(a6),$10(a6)
	move.w	$14(a6),$dff096
	move.l	4(a6),(a5)
	move.w	8(a6),4(a5)
	move.w	(a6),6(a5)
	move.w	$14(a6),d0
	or.w	d0,$13d38
.Sw:
	tst.w	(a6)
	beq.b	.Sw2
	move.w	(a6),$16(a6)
.Sw2:
	move.b	2(a6),d0
	andi.b	#$f,d0
	cmp.b	#$b,d0
	beq.b	.CaseB
	cmp.b	#$c,d0
	beq.b	.CaseC
	cmp.b	#$d,d0
	beq.b	.CaseD
	cmp.b	#$e,d0
	beq.b	.CaseE
	cmp.b	#$f,d0
	beq.b	.CaseF
	rts
.CaseB:
	not.w	$13d3a
	moveq	#0,d0
	move.b	3(a6),d0
	subq.b	#1,d0
	move.l	d0,$13cea
	rts
.CaseC:
	move.b	3(a6),8(a5)
	rts
.CaseD:
	move.b	#1,$13c7c
	not.w	$13d3a
	rts
.CaseE:
	moveq	#0,d0
	move.b	3(a6),d0
	andi.b	#1,d0
	rol.b	#1,d0
	andi.b	#$fd,$bfe001
	or.b	d0,$bfe001
	rts
.CaseF:
	move.b	3(a6),d0
	andi.b	#$f,d0
	beq.b	.End
	clr.l	$13cee
	move.b	d0,$133d1
.End:
	rts
