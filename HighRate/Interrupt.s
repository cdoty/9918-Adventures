VBlankHandler:
	move.l d0, -(a7)

	add.b	#1, NMICount
	
	move.b	VDPStatus, d0	; Acknowldge interrupt

	move.l (a7)+, d0

	rts
