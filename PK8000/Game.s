startGame:
	call	turnOffScreen
	
	; Transfer game tiles
	lxi		h, GamePattern
	lxi		d, Tile1VRAM
	lxi		b, GamePatternSize
	call	transferToVRAM

	; Transfer game tiles
	lxi		h, GamePattern
	lxi		d, Tile2VRAM
	lxi		b, GamePatternSize
	call	transferToVRAM

	; Transfer game tiles
	lxi		h, GamePattern
	lxi		d, Tile3VRAM
	lxi		b, GamePatternSize
	call	transferToVRAM

	; Transfer game colors
	lxi		h, GameColor
	lxi		d, Color1VRAM
	lxi		b, GameColorSize
	call	transferToVRAM

	; Transfer font colors
	lxi		h, GameColor
	lxi		d, Color2VRAM
	lxi		b, GameColorSize
	call	transferToVRAM

	; Transfer font colors
	lxi		h, GameColor
	lxi		d, Color3VRAM
	lxi		b, GameColorSize
	call	transferToVRAM

	; Transfer screen
	lxi		h, GameScreen
	lxi		d, ScreenVRAM
	lxi		b, GameScreenSize
	call	transferToVRAM

	call	turnOnScreen

	ret