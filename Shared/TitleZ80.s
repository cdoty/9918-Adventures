ScreenDelay	= 120

showTitle:
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, Tile1VRAM
	call	decompressToVRAM
	
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, Tile2VRAM
	call	decompressToVRAM
	
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, Tile3VRAM
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, Color1VRAM
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, Color2VRAM
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, Color3VRAM
	call	decompressToVRAM
	
	; Transfer first screen	
	ld		hl, Title1Start
	ld		de, ScreenVRAM
	call	decompressToVRAM

	; Clear timer
	call	clearTimer

	; Turn on screen
	call	turnOnScreen

	; Wait for timer or button press
	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen

	; Transfer second screen	
	ld		hl, Title2Start
	ld		de, 3800h
	call	decompressToVRAM

	; Clear timer
	call	clearTimer

	; Turn on screen
	call	turnOnScreen

	; Wait for timer
	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen

	; Transfer third screen	
	ld		hl, Title3Start
	ld		de, 3800h
	call	decompressToVRAM

	; Turn on screen
	call	turnOnScreen

	; Clear timer
	call	clearTimer

	; Wait for timer
	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen
	
	ret
