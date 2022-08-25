startGame:
	; Transfer font tiles
	lea		GamePattern, a0
	move.w	#Tile1VRAM, d2
	move.w	#(GamePatternEnd - GamePattern), d3
	jsr		transferToVRAM
	
	; Transfer font tiles
	lea		GamePattern, a0
	move.w	#Tile2VRAM, d2
	move.w	#(GamePatternEnd - GamePattern), d3
	jsr		transferToVRAM
	
	; Transfer font tiles
	lea		GamePattern, a0
	move.w	#Tile3VRAM, d2
	move.w	#(GamePatternEnd - GamePattern), d3
	jsr		transferToVRAM
	
	; Transfer color table
	lea		GameColor, a0
	move.w	#Color1VRAM, d2
	move.w	#(GameColorEnd - GameColor), d3
	jsr		transferToVRAM

	; Transfer color table
	lea		GameColor, a0
	move.w	#Color2VRAM, d2
	move.w	#(GameColorEnd - GameColor), d3
	jsr		transferToVRAM

	; Transfer color table
	lea		GameColor, a0
	move.w	#Color3VRAM, d2
	move.w	#(GameColorEnd - GameColor), d3
	jsr		transferToVRAM

	; Transfer screen	
	lea		GameScreen, a0
	move.w	#ScreenVRAM, d2
	move.w	#(GameScreenEnd - GameScreen), d3
	jsr		transferToVRAM

	; Turn on screen
	jsr		turnOnScreen

	rts
	