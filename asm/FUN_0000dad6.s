; FUN_0000dad6 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

FUN_0000dad6:
	dc.w	$41f9,$0001,$288a
	move.b	#$3,(a0)+
	move.b	#$24,(a0)
	move.w	#$1300,d4
	dc.w	$43f9,$0001,$28ad
.L0018:
	cmpi.b	#$1,(a1)+
	bne.w	.L003A
	dc.w	$41f9,$0006,$080a
	move.l	d4,-(a7)
	move.l	a1,-(a7)
	dc.w	$6100,$da18
	movea.l	(a7)+,a1
	move.l	(a7)+,d4
	addq.b	#$4,d4
	cmp.b	#$10,d4
	bne.b	.L0018
.L003A:
	rts
