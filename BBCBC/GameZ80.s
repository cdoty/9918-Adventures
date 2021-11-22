startGame:
	; Turn off screen
	call	turnOffScreen
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, ColorTable
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, ColorTable + 800h
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, ColorTable + 1000h
	call	decompressToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, PatternTable
	call	decompressToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, PatternTable + 800h
	call	decompressToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, PatternTable + 1000h
	call	decompressToVRAM
	
	; Transfer game screen	
	ld		hl, GameStart
	ld		de, NameTable
	call	decompressToVRAM

	; Turn on screen
	call	turnOnScreen
	
	ret