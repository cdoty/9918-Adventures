ScreenDelay	= 120

showTitle:
	; Transfer font tiles
	lxi		h, FontPattern
	lxi		b, Tile1VRAM	
	call	decompressZX0

	; Transfer font tiles
	lxi		h, FontPattern
	lxi		b, Tile2VRAM
	call	decompressZX0

	; Transfer font tiles
	lxi		h, FontPattern
	lxi		b, Tile3VRAM
	call	decompressZX0

	; Transfer font colors
	lxi		h, FontColor
	lxi		b, Color1VRAM
	call	decompressZX0

	; Transfer font colors
	lxi		h, FontColor
	lxi		b, Color2VRAM
	call	decompressZX0

	; Transfer font colors
	lxi		h, FontColor
	lxi		b, Color3VRAM
	call	decompressZX0

	; Transfer screen
	lxi		h, Title1Screen
	lxi		b, ScreenVRAM
	call	decompressZX0

	call	turnOnScreen

	call	clearTimer
	
	mvi		a, ScreenDelay
	call	waitForTimerOrButtonPress

	call	turnOffScreen
	
	; Transfer screen
	lxi		h, Title2Screen
	lxi		b, ScreenVRAM
	call	decompressZX0

	call	turnOnScreen

	call	clearTimer
	
	mvi		a, ScreenDelay
	call	waitForTimerOrButtonPress

	call	turnOffScreen
	
	; Transfer screen
	lxi		h, Title3Screen
	lxi		b, ScreenVRAM
	call	decompressZX0

	call	turnOnScreen

	call	clearTimer
	
	mvi		a, ScreenDelay
	call	waitForTimerOrButtonPress

	ret