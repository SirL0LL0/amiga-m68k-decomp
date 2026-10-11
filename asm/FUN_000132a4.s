; FUN_000132a4 @0x132a4 (file 0xb2a4), 34 byte -- RSTAR
; MuteAudio: azzera i 4 volumi audio (AUDxVOL $A8/$B8/$C8/$D8) e ferma
; il DMA audio (DMACON=$F). Trascritto byte-per-byte (vasm mot syntax).
; 'opt o-' disabilita il peephole vasm.

	opt	o-

FUN_000132a4:
	clr.w	$dff0a8
	clr.w	$dff0b8
	clr.w	$dff0c8
	clr.w	$dff0d8
	move.w	#$f,$dff096
	rts
