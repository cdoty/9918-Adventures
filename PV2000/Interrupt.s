NMIHandler:
	push	af
	
	ld		a, (NMICount)
	inc		a
	ld		(NMICount), a
	
	ld		a, (VDPBase + 1)	; Acknowldge interrupt

	pop		af
	
	retn
