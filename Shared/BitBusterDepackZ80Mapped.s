;-----------------------------------------------------------
; BitBuster v1.2 VRAM Depacker v1.1 - 16Kb version
; HL = RAM/ROM source ; DE = VRAM destination
;-----------------------------------------------------------
decompressToVRAM:
%if %def(DISABLE_INTERRUPTS)
	di
%endif

%if %def(WRITE_OFFSET_2)
WriteOffset	%equ	2
%else
WriteOffset	%equ	1
%endif

; VRAM address setup
	ld		a, (VDPBase + WriteOffset)	; Reset register write mode

	ld		a, e
	ld		(VDPBase + WriteOffset), a

	ld		a, d
	or		40h
	ld		(VDPBase + WriteOffset), a

; Skips 4 bytes data header
	inc		hl
	inc		hl
	inc		hl
	inc		hl

; Initialization
	ld		a, 128
	exx

	ld		de, 1
	exx

; Main depack loop
Depack_loop:
	add		a, a
	jp		nz, @@nxt0

	ld		a, (hl)
	inc		hl
	rla

@@nxt0:
	jp		c, Compressed

	push	af
	
	ld		a, (hl)
	inc		hl
	dec		b

	ld		(VDPBase), a
	
	pop		af
		
	inc		de
	
	jp		Depack_loop

; Compressed data
Compressed:
	ld		c, (hl)
	inc		hl

Match:
	ld		b, 0
	bit		7, c
	jr		z, Match1

	add		a, a
	jp		nz, @@nxt1

	ld		a, (hl)
	inc		hl
	rla

@@nxt1:
	rl		b
	add		a, a
	jp		nz, @@nxt2

	ld		a, (hl)
	inc		hl
	rla

@@nxt2:	
	rl		b
	add		a, a
	jp		nz, @@nxt3

	ld		a, (hl)
	inc		hl
	rla

@@nxt3:	
	rl		b
	add		a, a
	jp		nz, @@nxt4

	ld		a, (hl)
	inc		hl
	rla

@@nxt4:
	jp		c, Match1
	
	res		7, c

Match1:
	inc		bc
	exx

	ld		h, d
	ld		l, e
	ld		b, e

Gamma_size:
	exx
	add		a, a
	jp		nz, @@nxt5

	ld		a, (hl)
	inc		hl
	rla

@@nxt5:	
	exx
	jp		nc, Gamma_size_end

	inc		b
	jp		Gamma_size

Gamma_bits:
	exx
	add		a, a
	jp		nz, @@nxt6

	ld		a, (hl)
	inc		hl
	rla

@@nxt6:
	exx
	adc		hl, hl

Gamma_size_end:
	djnz	Gamma_bits

	inc		hl
	exx
	jp		c, Depack_out

	push	hl
	exx

	push	hl
	exx

	ld		h, d
	ld		l, e
	sbc		hl, bc

	pop		bc
	push	af

@@loop:	
	ld		a, l
	ld		(VDPBase + WriteOffset), a
	nop

	ld		a, h
	ld		(VDPBase + WriteOffset), a
	nop

	ld		a, (VDPReadBase)
	nop
	
	ex		af, af'

	ld		a, e
	ld		(VDPBase + WriteOffset), a

	ld		a, d
	or		40h
	ld		(VDPBase + WriteOffset), a

	ex		af, af'
	
	ld		(VDPBase), a
	nop
	
	inc		de
	
	cpi
	jp		pe, @@loop
	
	pop		af
	pop		hl
	
	jp		Depack_loop

; Depacker exit
Depack_out:
%if %def(DISABLE_INTERRUPTS)
	ei
%endif

	ret
