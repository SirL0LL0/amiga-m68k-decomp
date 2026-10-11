; CALL_0083C4 -- generato da tools/reasm.py, da rinominare/rifattorizzare.
; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.
		opt	o-

CALL_0083C4:
	dc.w	$6100,$306e
	dc.w	$47f9,$0001,$23dc
	move.b	#$59,d4
	dc.w	$6100,$02c8
	dc.w	$6100,$02bc
	move.b	#$13,d6
	dc.w	$6100,$5334
	dc.w	$47f9,$0001,$285c
	move.w	#$147,d4
.L0028:
	move.b	#$0,(a3)+
	subq.w	#$1,d4
	cmp.w	#$0,d4
	bne.b	.L0028
	dc.w	$47f9,$0001,$295f
	move.b	#$ff,d6
	move.b	#$28,d4
	dc.w	$6100,$0296
	dc.w	$41f9,$0001,$28a5
	move.b	#$14,(a0)
	dc.w	$41f9,$0001,$23cd
	move.b	#$5,(a0)
	dc.w	$41f9,$0001,$2975
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$295e
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$2865
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$2923
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$288d
	move.b	#$1,(a0)
	dc.w	$41f9,$0001,$2983
	move.b	#$2,(a0)
	dc.w	$41f9,$0001,$295d
	move.b	#$15,(a0)
	dc.w	$41f9,$0001,$2974
	move.b	#$d,(a0)
	dc.w	$41f9,$0001,$2874
	dc.w	$43f9,$0001,$287d
	dc.w	$45f9,$0001,$2886
	move.b	#$a0,(a0)
	move.b	#$a0,(a1)
	move.b	#$a0,(a2)
	dc.w	$41f9,$0001,$2984
	move.b	#$f,(a0)
	dc.w	$6100,$2410
	dc.w	$6100,$0146
	dc.w	$6100,$163a
	dc.w	$41f9,$0001,$2924
	move.b	#$38,(a0)
	move.b	#$4,d6
	dc.w	$6100,$4e8e
	moveq	#$9,d0
	dc.w	$47f9,$0001,$23d2
	move.b	d6,(a3)+
	addq.b	#$1,d6
	dbra	d0,$f8
	rts
