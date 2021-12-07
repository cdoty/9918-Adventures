startGame:
	call	turnOffScreen
	
	; Transfer game tiles
	lxi		h, GamePattern
	lxi		b, Tile1VRAM
	call	decompressZX0

	; Transfer game tiles
	lxi		h, GamePattern
	lxi		b, Tile2VRAM
	call	decompressZX0

	; Transfer game tiles
	lxi		h, GamePattern
	lxi		b, Tile3VRAM
	call	decompressZX0

	; Transfer game colors
	lxi		h, GameColor
	lxi		b, Color1VRAM
	call	decompressZX0

	; Transfer font colors
	lxi		h, GameColor
	lxi		b, Color2VRAM
	call	decompressZX0

	; Transfer font colors
	lxi		h, GameColor
	lxi		b, Color3VRAM
	call	decompressZX0

	; Transfer screen
	lxi		h, GameScreen
	lxi		b, ScreenVRAM
	call	decompressZX0

	call	turnOnScreen

	ret