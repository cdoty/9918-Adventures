startGame:
	; Turn off screen
	jsr	turnOffScreen
	
	; Transfer font tiles
	lda		#<GamePattern
	sta		HFMStart
	lda		#>GamePattern
	sta		HFMStart + 1
	
	lda		#<Tile1VRAM
	sta		ZPStart + 0
	lda 	#>Tile1VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer font tiles
	lda		#<GamePattern
	sta		HFMStart
	lda		#>GamePattern
	sta		HFMStart + 1

	lda		#<Tile2VRAM
	sta		ZPStart + 0
	lda		#>Tile2VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer font tiles
	lda		#<GamePattern
	sta		HFMStart
	lda		#>GamePattern
	sta		HFMStart + 1
	
	lda		#<Tile3VRAM
	sta		ZPStart + 0
	lda		#>Tile3VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer color table
	lda		#<GameColor
	sta		HFMStart
	lda		#>GameColor
	sta		HFMStart + 1
	
	lda		#<Color1VRAM
	sta		ZPStart + 0
	lda		#>Color1VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer color table
	lda		#<GameColor
	sta		HFMStart
	lda		#>GameColor
	sta		HFMStart + 1
	
	lda		#<Color2VRAM
	sta		ZPStart + 0
	lda		#>Color2VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer color table
	lda		#<GameColor
	sta		HFMStart
	lda		#>GameColor
	sta		HFMStart + 1
	
	lda		#<Color3VRAM
	sta		ZPStart + 0
	lda		#>Color3VRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM
	
	; Transfer first screen	
	lda		#<Game
	sta		HFMStart
	lda		#>Game
	sta		HFMStart + 1
	
	lda		#<ScreenVRAM
	sta		ZPStart + 0
	lda		#>ScreenVRAM
	sta		ZPStart + 1
	
	jsr		decompressToVRAM

	; Turn on screen
	jsr		turnOnScreen
	
	rts
