ScreenDelay	%equ	120

showTitle:
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, PatternTable
	call	decompressToVRAM
	
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, PatternTable + 800h
	call	decompressToVRAM
	
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, PatternTable + 1000h
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, ColorTable
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, ColorTable + 800h
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, ColorTable + 1000h
	call	decompressToVRAM

	; Transfer first screen	
	ld		hl, Title1Start
	ld		de, NameTable
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
	ld		de, NameTable
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
	ld		de, NameTable
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
