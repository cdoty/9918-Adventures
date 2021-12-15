; Start game
startGame:
	jsr		transferGameGraphics
	jsr		showGameScreen

	rts

transferGameGraphics:
	ldx		#GamePattern			; Decompress the pattern data
	ldu		#DecompressionBuffer
	jsr		zx0_decompress

	tfr		u, d					; Calculate the size of the data
	subd	#DecompressionBuffer

	tfr		d, x					; Transfer the buffer length to X

	pshs	x						; Push length to the stack

	ldu		#DecompressionBuffer	; Load the location of the decompressed data

	ldd		#Tile1VRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	puls	x						; Transfer the length to X
	pshs	x

	ldu		#DecompressionBuffer	; Load the location of the decompressed data

	ldd		#Tile2VRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	puls	x						; Pull the length from the stack

	ldu		#DecompressionBuffer

	ldd		#Tile3VRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	ldx		#GameColor				; Decompress the color data
	ldu		#DecompressionBuffer
	jsr		zx0_decompress

	tfr		u, d					; Calculate the size of the data
	subd	#DecompressionBuffer

	tfr		d, x					; Transfer the length to X

	pshs	x						; Store the length for later use

	ldu		#DecompressionBuffer	; Load the location of the decompressed data

	ldd		#Color1VRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	puls	x						; Pull the length from the stack
	pshs	x

	ldu		#DecompressionBuffer	; Load the location of the decompressed data

	ldd		#Color2VRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	puls	x						; Pull the length from the stack

	ldu		#DecompressionBuffer

	ldd		#Color3VRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	rts

showGameScreen:
	ldx		#GameScreen				; Decompress the screen data
	ldu		#DecompressionBuffer
	jsr		zx0_decompress

	tfr		u, d					; Calculate the size of the data
	subd	#DecompressionBuffer

	tfr		d, x					; Transfer the length to X

	ldu		#DecompressionBuffer

	ldd		#ScreenVRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	jsr		turnOnScreen

	rts
