; FUN_0000b3be @0xb3be (file 0x33be), 22 byte -- RSTAR
; Wait for raster line 0: legge VHPOSR ($DFF006) basso finche' != 0.
; Idioma asm originale: base CUSTOM in A5 (salvato/ripristinato).
; Trascritto byte-per-byte dall'originale (vasm mot syntax).
; NOTA: 'opt o-' disabilita il peephole di vasm, che convertirebbe
; 'cmp.b #0,d0' (b03c 4 byte) in 'tst.b d0' (4a00 2 byte).

	opt	o-

FUN_0000b3be:
	move.l	a5,-(sp)
	lea	$dff000,a5
.wait:	move.b	6(a5),d0
	cmp.b	#0,d0
	bne.s	.wait
	movea.l	(sp)+,a5
	rts
