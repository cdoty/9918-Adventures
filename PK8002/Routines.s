setTurboMode:
	mvi	a, $90			; Enable speaker and turbo mode.
	out	KeyboardSelect

	ret

resetTimer:
	mvi	a, $00
	out	TimerChannel0
	out	TimerChannel1
	out	TimerChannel2
	out	TimerMode

	ret

resetSound:
	mvi	a, $00
	out	VolumePort

	ret

setupMode2:
	mvi	a, $90						; Set 2 of 16 color mode, use $92 to set location of attribute table, split screen into 3 character/palette banks, 50 hz, sprites disabled.
	out	VideoMode					; Video ram is located at $8000.

	mvi	a, $00						; Turn off screen.
	out	VideoEnable	

	mvi	a, $11						; Set screen and border color
	out	BorderColor1

	mvi	a, $00
	out	BorderColor2

	mvi	a, SpriteAttributes / $400	; Set sprite attribute location
	out	SpriteAttributeData

	mvi	a, ScreenVRAM / $400		; Name table memory location
	out	NameTable

	mvi	a, Color1VRAM / $400		; Color data memory location
	out	ColorData

	mvi	a, Tile1VRAM / $400		; Pattern data memory location
	out	PatternData

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
	lxi		h, VRAMAddress
	lxi		b, $4000

	mvi		d, $FF

clearVRAMLoop:
	mov		m, d
	inx		h
	dcx		b
	mov		a, b
	ora		c
	jnz 	clearVRAMLoop

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

; Disable ROM, page in RAM, in bank 1.
disableBank1Rom:
	mvi		a, $FF
	out		BankSwap

	ret
