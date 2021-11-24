; A: contains the number of vertical blanks to wait
setupInterrupt:
	mvi	a, $F2
	sta	InterruptVector

	mvi	a, <VBlankHandler
	sta	InterruptVector + 1

	mvi	a, >VBlankHandler
	sta	InterruptVector + 2

	ret

VBlankHandler:
	push	psw
	push	hl
	
	lxi		h, NMICount
	inr		m
	
	pop		hl
	pop		psw

	ret