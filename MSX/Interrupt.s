NMIHandler:
	push	af
	
	ld		a, (NMICount)
	inc		a
	ld		(NMICount), a
	
	in		a, (VDPBase + 1)	; Acknowldge interrupt
	nop
	
	pop		af
	
	retn
	