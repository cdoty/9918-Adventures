IRQHandler:
	jp		FC11h

NMIHandler:
	push	af
	
	ld		a, (NMICount)
	inc		a
	ld		(NMICount), a
	
	in		a, (VDPBase + 1)	; Acknowldge interrupt

	pop		af	
	
	jp		FC14h
