DefaultHandler:
	reti
	
NMIHandler:
	ld	a, (Ram.NMICount)
	inc	a
	ld	(Ram.NMICount), a
	
	in	a, (VDPReadBase + 1)	; Acknowldge interrupt

	ei
	
	retn
	