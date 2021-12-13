setupMode2:
	mvi	a, $10			; Set mode 2
	out	VideoMode

	mvi	a, $00			; Turn off screen
	out	VideoEnable	

	mvi	a, $00			; Set border color
	out	ScreenColor

	mvi	a, $00			; Pattern data memory location for Mode 0 and 1. Unused in Mode 2.
	sta	ShadowTextData

	mvi	a, >ScreenVRAM	; Name table memory location
	sta	ShadowNameTable

	mvi	a, >Color1VRAM	; Color data memory location
	cma
	sta	ShadowColorData

	mvi	a, >Tile1VRAM	; Pattern data memory location
	cma
	sta	ShadowPatternData

	ret

turnOffScreen:
	mvi	a, $00
	out	VideoEnable	

	ret

turnOnScreen:
	mvi	a, $10
	out	VideoEnable	

	ret

clearVRAM:
	lxi		h, $0000
	lxi		b, $4000

	mvi		d, 0
clearLoop:
	mov		m, d
	inx		h
	dcx		b
	mov		a, b
	ora		c
	jnz 	clearLoop

	ret

; DE: Dest
; HL: Src
; BC: size
transferToVRAM:
	mov		a, m
	stax	d
	inx		h
	inx		d

	dcx		b
	mov		a, b
	ora		c

	jnz 	transferToVRAM

	ret

clearTimer:
	mvi		a, 0
	sta		NMICount

	ret

; A: contains the number of VBlanks to wait for.
waitForTimerOrButtonPress:
	lxi		h, NMICount
	
VBlankLoop:
	cmp		m
	jnc		VBlankLoop

	ret

enableBank1Rom:
	push	psw

	mvi		a, $FC
	out		BankSwap

	pop		psw

	ei

	ret
		
disableBank1Rom:
	di
	push	psw

	mvi		a, $FF
	out		BankSwap

	pop		psw

	ret
