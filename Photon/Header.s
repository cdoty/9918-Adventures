	org	ROMStart

	di
	jmp	start

	org	$20
	ret

	org	$38
	call	VBlankHandler
	ei
	ret
	
	org	$80
start:
	mvi		a, $82		; PPI Configuration
	out		PPI8255_1	; Set Port A and B to Mode 0, and set Port B for input.

	mvi		a, $84		
	out		PPI8255_2	; Set Port A to Mode 0 and B to Mode 1, and set all ports for output.

	mvi		a, $FC		; Map in ram
	out		BankSwap

	lxi		d, $4000
	lxi		h, StartRelocate
	lxi		b, EndRelocate - StartRelocate

relocateLoop:
	mov		a, m
	stax	d
	inx		h
	inx		d
	dcx		b
	mov		a, b
	ora		c
	jnz 	relocateLoop

	jmp		gameStart