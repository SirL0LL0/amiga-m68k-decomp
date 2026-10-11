; FUN_000131ea @0x131ea (file 0xb1ea), 22 byte -- RSTAR
; Handler IRQ minimale: salva tutto, chiama worker, ack INTREQ=$74, RTE.
; La BSR punta a FUN_000132c6 (non ancora trascritta): emessa come dc.w
; con gli stessi byte (6100 00d6) finche' il callee non esiste.
; Trascritto byte-per-byte dall'originale (vasm mot syntax).
; 'opt o-' disabilita il peephole vasm.

	opt	o-

FUN_000131ea:
	movem.l	d0-d7/a0-a6,-(sp)
	dc.w	$6100,$00d6	; bsr.w FUN_000132c6 (placeholder)
	movem.l	(sp)+,d0-d7/a0-a6
	move.w	#$74,$dff09c
	rte
