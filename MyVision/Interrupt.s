NMIHandler:
	push	af
	
	ld		a, (NMICount)
	inc		a
	ld		(NMICount), a
	
	ld		a, (VDPBase + 2)	; Acknowldge interrupt

	pop		af
	
	ei
	
	retn
