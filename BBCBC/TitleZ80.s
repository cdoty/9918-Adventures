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

	; Wait for timer
	call	clearTimer

	; Turn on screen
	call	turnOnScreen

	ei

	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen

	di

	; Transfer second screen	
	ld		hl, Title2Start
	ld		de, ScreenVRAM
	call	decompressToVRAM

	; Wait for timer
	call	clearTimer

	; Turn on screen
	call	turnOnScreen

	ei

	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen

	di

	; Transfer third screen	
	ld		hl, Title3Start
	ld		de, ScreenVRAM
	call	decompressToVRAM

	; Turn on screen
	call	turnOnScreen

	; Wait for timer
	call	clearTimer

	ei

	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen
	
	di
	
	ret
