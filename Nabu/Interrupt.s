VBlankHandler:
 	push	af
	
	ld		a, (Ram.NMICount)
	inc		a
	ld		(Ram.NMICount), a

	in   	a, (VDPBase + 1)

	pop		af

	ei

	ret

HCCAReceiveHandler:
	reti

KeyboardHandler:
	ret

OptionHandler:
	ei
	ret
