ScreenDelay	%equ	120

showTitle:
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, 0000h
	call	decompressToVRAM
	
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, 0800h
	call	decompressToVRAM
	
	; Transfer font tiles
	ld		hl, FontPatternStart
	ld		de, 1000h
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, 2000h
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, 2800h
	call	decompressToVRAM
	
	; Transfer color table
	ld		hl, FontColorStart
	ld		de, 3000h
	call	decompressToVRAM
	
	; Transfer first screen	
	ld		hl, Title1Start
	ld		de, 3800h
	call	decompressToVRAM

	; Wait for timer
	call	clearTimer

	; Turn on screen
	call	turnOnScreen

	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen

	; Transfer second screen	
	ld		hl, Title2Start
	ld		de, 3800h
	call	decompressToVRAM

	; Wait for timer
	call	clearTimer

	; Turn on screen
	call	turnOnScreen

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

	; Wait for timer
	call	clearTimer

	ld		a, ScreenDelay
	ld		b, a
	call	waitForTimerOrButtonPress
	
	; Turn off screen
	call	turnOffScreen
	
	ret
