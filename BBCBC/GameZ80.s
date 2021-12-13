startGame:
	; Turn off screen
	call	turnOffScreen
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, Tile1VRAM
	call	decompressToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, Tile2VRAM
	call	decompressToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, Tile3VRAM
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, Color1VRAM
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, Color2VRAM
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, Color3VRAM
	call	decompressToVRAM
	
	; Transfer game screen	
	ld		hl, GameStart
	ld		de, ScreenVRAM
	call	decompressToVRAM

	; Turn on screen
	call	turnOnScreen
	
	ret