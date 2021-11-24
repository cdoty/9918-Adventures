ScreenDelay	= 120

showTitle:
	; Transfer font tiles
	lxi		h, FontPattern
	lxi		d, Tile1VRAM
	lxi		b, FontPatternSize
	call	transferToVRAM

	; Transfer font tiles
	lxi		h, FontPattern
	lxi		d, Tile2VRAM
	lxi		b, FontPatternSize
	call	transferToVRAM

	; Transfer font tiles
	lxi		h, FontPattern
	lxi		d, Tile3VRAM
	lxi		b, FontPatternSize
	call	transferToVRAM

	; Transfer font colors
	lxi		h, FontColor
	lxi		d, Color1VRAM
	lxi		b, FontColorSize
	call	transferToVRAM

	; Transfer font colors
	lxi		h, FontColor
	lxi		d, Color2VRAM
	lxi		b, FontColorSize
	call	transferToVRAM

	; Transfer font colors
	lxi		h, FontColor
	lxi		d, Color3VRAM
	lxi		b, FontColorSize
	call	transferToVRAM

	; Transfer screen
	lxi		h, Title1Screen
	lxi		d, ScreenVRAM
	lxi		b, Title1ScreenSize
	call	transferToVRAM

	call	turnOnScreen

	call	clearTimer
	
	mvi		a, ScreenDelay
	call	waitForTimerOrButtonPress

	call	turnOffScreen
	
	; Transfer screen
	lxi		h, Title2Screen
	lxi		d, ScreenVRAM
	lxi		b, Title2ScreenSize
	call	transferToVRAM

	call	turnOnScreen

	call	clearTimer
	
	mvi		a, ScreenDelay
	call	waitForTimerOrButtonPress

	call	turnOffScreen
	
	; Transfer screen
	lxi		h, Title3Screen
	lxi		d, ScreenVRAM
	lxi		b, Title3ScreenSize
	call	transferToVRAM

	call	turnOnScreen

	call	clearTimer
	
	mvi		a, ScreenDelay
	call	waitForTimerOrButtonPress

	ret