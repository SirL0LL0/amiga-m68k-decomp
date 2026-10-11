; FUN_0001313c @0x1313c (file 0xb13c), 174 byte -- RSTAR
; InstallIrq: init flag, chiama worker, installa handler FUN_000131ea
; nel vettore $6C (salvando il vecchio in $13302), giostra INTENA ($3FF7/$C008),
; attende input (CIA $BFE001), ripristina e chiama secondo worker.
; Riferimenti fuori slice (LEA +$D2A, 2 BSR) emessi come dc.w con gli stessi
; byte, finche' i target non sono trascritti.
; 'opt o-' disabilita il peephole vasm (es: cmp.b->tst.b).
; Trascritto byte-per-byte (vasm mot syntax).

	opt	o-

FUN_0001313c:
	dc.w	$41fa,$0d26	; lea +$D26(pc) (fuori slice)
	move.b	#$2,(a0)
	lea.l	$2aac2,a0
	move.b	#$2,(a0)
	move.b	#$0,3(a0)
	dc.w	$6100,$00b0	; bsr.w +$CC (fuori slice; Ghidra: FUN_00013206)
	move.l	#$1,$13cea
	move.w	#$3ff7,$dff09a
	move.l	$6c.w,$13302
	move.l	#$132ea,$6c.w
	move.w	#$8020,$dff09a
.Loop:
	cmp.b	#$0,$13c7c
	bne.w	.Second
	cmp.b	#$0,$bb64
	bne.b	.Restore
	btst.b	#$6,$bfe001
	beq.b	.Restore
	tst.b	$bfe001
	bpl.w	.Restore
	bra.b	.Loop
.Restore:
	move.w	#$3ff7,$dff09a
	move.l	$132f6,$6c.w
	move.w	#$c008,$dff09a
	dc.w	$6100,$00dc	; bsr.w +$16A (fuori slice, x2)
	rts
.Second:
	move.w	#$3ff7,$dff09a
	move.l	$132f6,$6c.w
	move.w	#$c008,$dff09a
	dc.w	$6100,$00be	; bsr.w da .Second (fuori slice)
	rts
