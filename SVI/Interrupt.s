DefaultHandler:
	reti
	
IRQHandler:
	reti
	
NMIHandler:
	ld	a, (NMICount)
	inc	a
	ld	(NMICount), a
	
	in	a, (VDPReadBase + 1)	; Acknowldge interrupt

	ei
	
	retn
	