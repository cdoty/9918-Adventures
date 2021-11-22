	.align 16

Start:
	; Turn off screen
	bl		@turnOffScreen
	
	; Transfer game tiles
	li		r1, 0000h
	li		r2, GamePatternStart
	li		r3, GamePatternSize
	bl		@tranferToVRAM
	
	; Transfer game tiles
	li		r1, 0800h
	li		r2, GamePatternStart
	li		r3, GamePatternSize
	bl		@tranferToVRAM
	
	; Transfer game tiles
	li		r1, 1000h
	li		r2, GamePatternStart
	li		r3, GamePatternSize
	bl		@tranferToVRAM
	
	; Transfer color table
	li		r1, 2000h
	li		r2, GameColorStart
	li		r3, GameColorSize
	bl		@tranferToVRAM
	
	; Transfer color table
	li		r1, 2800h
	li		r2, GameColorStart
	li		r3, GameColorSize
	bl		@tranferToVRAM
	
	; Transfer color table
	li		r1, 3000h
	li		r2, GameColorStart
	li		r3, GameColorSize
	bl		@tranferToVRAM
	
	; Transfer game screen	
	li		r1, 3800h
	li		r2, GameStart
	li		r3, GameSize
	bl		@tranferToVRAM

	; Turn on screen
	bl		@turnOnScreen

EndlessLoop:
	jmp		EndlessLoop
