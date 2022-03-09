NMIHandler:
	push	af
	
	ld		a, (Ram.NMICount)
	inc		a
	ld		(Ram.NMICount), a
	
	ld		a, (VDPBase + 2)	; Acknowldge interrupt

	pop		af
	
	ei
	
	retn
