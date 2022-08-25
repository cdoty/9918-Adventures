ScreenDelay	= 120

showTitle:
	; Transfer font tiles
	lea		FontPattern, a0
	move.w	#Tile1VRAM, d2
	move.w	#(FontPatternEnd - FontPattern), d3
	jsr		transferToVRAM
	
	; Transfer font tiles
	lea		FontPattern, a0
	move.w	#Tile2VRAM, d2
	move.w	#(FontPatternEnd - FontPattern), d3
	jsr		transferToVRAM
	
	; Transfer font tiles
	lea		FontPattern, a0
	move.w	#Tile3VRAM, d2
	move.w	#(FontPatternEnd - FontPattern), d3
	jsr		transferToVRAM
	
	; Transfer color table
	lea		FontColor, a0
	move.w	#Color1VRAM, d2
	move.w	#(FontColorEnd - FontColor), d3
	jsr		transferToVRAM

	; Transfer color table
	lea		FontColor, a0
	move.w	#Color2VRAM, d2
	move.w	#(FontColorEnd - FontColor), d3
	jsr		transferToVRAM

	; Transfer color table
	lea		FontColor, a0
	move.w	#Color3VRAM, d2
	move.w	#(FontColorEnd - FontColor), d3
	jsr		transferToVRAM

	; Transfer 1st screen	
	lea		Title1Screen, a0
	move.w	#ScreenVRAM, d2
	move.w	#(Title1ScreenEnd - Title1Screen), d3
	jsr		transferToVRAM

	; Clear timer
	jsr		clearTimer

	; Turn on screen
	jsr		turnOnScreen

	move.w	#ScreenDelay, d0
	jsr		waitForTimerOrButtonPress

	jsr		turnOffScreen

	; Transfer 2nd screen	
	lea		Title2Screen, a0
	move.w	#ScreenVRAM, d2
	move.w	#(Title1ScreenEnd - Title1Screen), d3
	jsr		transferToVRAM

	; Clear timer
	jsr		clearTimer

	; Turn on screen
	jsr		turnOnScreen

	move.w	#ScreenDelay, d0
	jsr		waitForTimerOrButtonPress

	jsr		turnOffScreen

	; Transfer 3rd screen	
	lea		Title3Screen, a0
	move.w	#ScreenVRAM, d2
	move.w	#(Title1ScreenEnd - Title1Screen), d3
	jsr		transferToVRAM

	; Clear timer
	jsr		clearTimer

	; Turn on screen
	jsr		turnOnScreen

	move.w	#ScreenDelay, d0
	jsr		waitForTimerOrButtonPress

	jsr		turnOffScreen

	rts