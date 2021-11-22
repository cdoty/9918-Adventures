	.set	ScreenDelay	= 120

showTitle:
	mov		r11, r9		; Save return address

	; Transfer font tiles
	li		r1, 0000h
	li		r2, FontPatternStart
	li		r3, FontPatternSize
	bl		@tranferToVRAM
	
	; Transfer font tiles
	li		r1, 0800h
	li		r2, FontPatternStart
	li		r3, FontPatternSize
	bl		@tranferToVRAM
	
	; Transfer font tiles
	li		r1, 1000h
	li		r2, FontPatternStart
	li		r3, FontPatternSize
	bl		@tranferToVRAM
	
	; Transfer color table
	li		r1, 2000h
	li		r2, FontColorStart
	li		r3, FontColorSize
	bl		@tranferToVRAM
	
	; Transfer color table
	li		r1, 2800h
	li		r2, FontColorStart
	li		r3, FontColorSize
	bl		@tranferToVRAM
	
	; Transfer color table
	li		r1, 3000h
	li		r2, FontColorStart
	li		r3, FontColorSize
	bl		@tranferToVRAM
	
	; Transfer first screen	
	li		r1, 3800h
	li		r2, Title1Start
	li		r3, Title1Size
	bl		@tranferToVRAM

	; Clear timer
	bl		@clearTimer

	; Turn on screen
	bl		@turnOnScreen

	; Wait for timer
	li		r1, ScreenDelay
	bl		@waitForTimerOrButtonPress
	
	; Turn off screen
	bl		@turnOffScreen

	; Transfer second screen	
	li		r1, 3800h
	li		r2, Title2Start
	li		r3, Title2Size
	bl		@tranferToVRAM

	; Wait for timer
	bl		@clearTimer

	; Turn on screen
	bl		@turnOnScreen

	li		r1, ScreenDelay
	bl		@waitForTimerOrButtonPress
	
	; Turn off screen
	bl		@turnOffScreen

	; Transfer third screen	
	li		r1, 3800h
	li		r2, Title3Start
	li		r3, Title3Size
	bl		@tranferToVRAM

	; Wait for timer
	bl		@clearTimer

	; Turn on screen
	bl		@turnOnScreen

	li		r1, ScreenDelay
	bl		@waitForTimerOrButtonPress
	
	b		*r9
