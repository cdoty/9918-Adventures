; -----------------------------------------------------------------------------
; ZX0 8080 decoder by Ivan Gorodetsky
; Based on ZX0 z80 decoder by Einar Saukas
; -----------------------------------------------------------------------------
; Parameters:
;   HL: source address (compressed data)
;   BC: destination address (decompressing)
; -----------------------------------------------------------------------------

decompressZX0:
	di

	call	disableBank1Rom
	call	dzx0_standard
	call	enableBank1Rom

	ei
	
	ret

dzx0_standard:
	lxi		d, 0FFFFh
	push	d
	inx		d
	mvi		a, 80h

dzx0s_literals:
	call	dzx0s_elias
	call	ldir
	jc		dzx0s_new_offset
	call	dzx0s_elias

dzx0s_copy:
	xthl
	push	h
	dad		b
	call	ldir
	pop		h
	xthl
	jnc		dzx0s_literals

dzx0s_new_offset:
	call	dzx0s_elias
	mov		d, a
	pop		psw
	xra		a
	sub		e

	rz

	push	b
	mov		b, d
	rar
	mov		d, a
	mov		a, m
	rar
	mov		e, a
	mov		a, b
	pop		b
	inx		h
	push	d
	lxi		d, 1
	cnc		dzx0s_elias_backtrack
	inx		d
	jmp		dzx0s_copy

dzx0s_elias:
	inr		e

dzx0s_elias_loop:	
	add 	a
	jnz 	dzx0s_elias_skip
	
	mov 	a, m
	inx		h
	ral

dzx0s_elias_skip:
	rc

dzx0s_elias_backtrack:
	xchg
	dad		h
	xchg
	add		a
	jnc		dzx0s_elias_loop
	jmp		dzx0s_elias
		
ldir:
	push	psw						

ldir_loop:
	mov		a, m
	stax	b
	inx		h
	inx		b
	dcx 	d
	mov 	a, d
	ora 	e
	jnz 	ldir_loop

	pop 	psw

	add 	a

	ret
