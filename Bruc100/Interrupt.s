NMIHandler:
	push	af
	
	ld		a, (Ram.NMICount)
	inc		a
	ld		(Ram.NMICount), a
	
	in		a, (VDPBase + 1)	; Acknowldge interrupt
	nop
	
	pop		af
	
	retn
	