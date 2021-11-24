; A: contains the number of vertical blanks to wait
VBlankHandler:
	push	psw
	push	hl

	lxi		h, NMICount
	inr		m
	
	pop		hl
	pop		psw

	ret