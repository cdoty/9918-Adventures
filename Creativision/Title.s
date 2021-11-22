	ScreenDelay	= 120

showTitle:
	; Transfer font tiles
	lda		#<FontPattern
	sta		HFMStart
	lda		#>FontPattern
	sta		HFMStart + 1

	lda		#<Tile1VRAM
	sta		ZPStart
	lda		#>Tile1VRAM
	sta		ZPStart + 1

	jsr		decompressToVRAM

	; Transfer font tiles
	lda		#<FontPattern
	sta		HFMStart
	lda		#>FontPattern
	sta		HFMStart + 1

	lda		#<Tile2VRAM
	sta		ZPStart
	lda		#>Tile2VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer font tiles
	lda		#<FontPattern
	sta		HFMStart
	lda		#>FontPattern
	sta		HFMStart + 1
	
	lda		#<Tile3VRAM
	sta		ZPStart
	lda		#>Tile3VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer color table
	lda		#<FontColor
	sta		HFMStart
	lda		#>FontColor
	sta		HFMStart + 1
	
	lda		#<Color1VRAM
	sta		ZPStart + 0
	lda		#>Color1VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer color table
	lda		#<FontColor
	sta		HFMStart
	lda		#>FontColor
	sta		HFMStart + 1
	
	lda		#<Color2VRAM
	sta		ZPStart + 0	
	lda		#>Color2VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer color table
	lda		#<FontColor
	sta		HFMStart
	lda		#>FontColor
	sta		HFMStart + 1
	
	lda		#<Color3VRAM
	sta		ZPStart + 0	
	lda		#>Color3VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer first screen	
	lda		#<Title1
	sta		HFMStart
	lda		#>Title1
	sta		HFMStart + 1
	
	lda		#<ScreenVRAM
	sta		ZPStart + 0
	lda		#>ScreenVRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM

	jsr		turnOnScreen	; Turn on screen

	; Clear timer
	jsr		clearTimer

	cli
	
	; Wait for timer
	lda		#ScreenDelay
	sta		ZPStart
	
	jsr		waitForTimerOrButtonPress
	
	jsr		turnOffScreen	; Turn off screen

	sei

	; Transfer second screen	
	lda		#<Title2
	sta		HFMStart
	lda		#>Title2
	sta		HFMStart + 1
	
	lda		#<ScreenVRAM
	sta		ZPStart + 0
	lda		#>ScreenVRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM

	jsr		turnOnScreen	; Turn on screen

	; Clear timer
	jsr		clearTimer

	; Wait for timer
	lda 	#ScreenDelay
	sta		ZPStart
	
	cli
	
	jsr		waitForTimerOrButtonPress
	
	jsr		turnOffScreen	; Turn off screen

	sei
	
	; Transfer third screen	
	lda		#<Title3
	sta		HFMStart
	lda		#>Title3
	sta		HFMStart + 1
	
	lda		#<ScreenVRAM
	sta		ZPStart + 0
	lda		#>ScreenVRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM

	jsr		turnOnScreen	; Turn on screen

	; Clear timer
	jsr		clearTimer

	; Wait for timer
	lda 	#ScreenDelay
	sta		ZPStart
	
	cli
	
	jsr		waitForTimerOrButtonPress
	
	jsr		turnOffScreen	; Turn off screen

	rts
