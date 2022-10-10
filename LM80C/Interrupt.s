NMIHandler:
	push	af
	
	ld		a, (Ram.NMICount)
	inc		a
	ld		(Ram.NMICount), a
	
	in		a, (VDPReadBase + 2)	; Acknowledge interrupt

	pop		af
	
	ei
	
	ret
