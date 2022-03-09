NMIHandler:
	push	af
	
	ld		a, (Ram.NMICount)
	inc		a
	ld		(Ram.NMICount), a
	
	in		a, (VDPBase + 1)	; Acknowldge interrupt

	pop		af
	
	retn

IM1Handler:
	retn
	