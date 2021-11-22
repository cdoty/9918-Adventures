startGame:
	; Turn off screen
	call	turnOffScreen
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, 0000h
	call	decompressToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, 0800h
	call	decompressToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		de, 1000h
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, 2000h
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, 2800h
	call	decompressToVRAM
	
	; Transfer game color table
	ld		hl, GameColorStart
	ld		de, 3000h
	call	decompressToVRAM
	
	; Transfer game screen	
	ld		hl, GameStart
	ld		de, 3800h
	call	decompressToVRAM

	; Turn on screen
	call	turnOnScreen
	
	ret