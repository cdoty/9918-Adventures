startGame:
	; Turn off screen
	call	turnOffScreen
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		bc, 0000h
	ld		de, GamePatternSize
	call	tranferToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		bc, 0800h
	ld		de, GamePatternSize
	call	tranferToVRAM
	
	; Transfer game tiles
	ld		hl, GamePatternStart
	ld		bc, 1000h
	ld		de, GamePatternSize
	call	tranferToVRAM
	
	; Transfer color table
	ld		hl, GameColorStart
	ld		bc, 2000h
	ld		de, GameColorSize
	call	tranferToVRAM
	
	; Transfer color table
	ld		hl, GameColorStart
	ld		bc, 2800h
	ld		de, GameColorSize
	call	tranferToVRAM
	
	; Transfer color table
	ld		hl, GameColorStart
	ld		bc, 3000h
	ld		de, GameColorSize
	call	tranferToVRAM
	
	; Transfer game screen	
	ld		hl, GameStart
	ld		bc, 3800h
	ld		de, GameSize
	call	tranferToVRAM

	; Turn on screen
	call	turnOnScreen
	
	ret