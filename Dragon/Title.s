; Show title
showTitle:
	jsr		transferTitleGraphics

	jsr		showScreen1
	jsr		showScreen2
	jsr		showScreen3

	rts

transferTitleGraphics:	
	ldx		#FontPattern			; Decompress the pattern data
	ldu		#DecompressionBuffer
	jsr		zx0_decompress

	tfr		u, d					; Calculate the size of the data
	subd	#DecompressionBuffer

	tfr		d, x					; Transfer the buffer length to X

	pshs	x						; Psuh length to the stack

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

	ldx		#FontColor				; Decompress the color data
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

showScreen1:	
	ldx		#Title1Screen			; Decompress the screen data
	ldu		#DecompressionBuffer
	jsr		zx0_decompress

	tfr		u, d					; Calculate the size of the data
	subd	#DecompressionBuffer

	tfr		d, x					; Transfer the length to X

	ldu		#DecompressionBuffer

	ldd		#ScreenVRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	jsr		turnOnScreen

	jsr		clearTimer

	lda		#ScreenDelay
	jsr		waitForTimerOrButtonPress

	jsr		turnOffScreen

	rts

showScreen2:	
	ldx		#Title2Screen			; Decompress the screen data
	ldu		#DecompressionBuffer
	jsr		zx0_decompress

	tfr		u, d					; Calculate the size of the data
	subd	#DecompressionBuffer

	tfr		d, x					; Transfer the length to X

	ldu		#DecompressionBuffer

	ldd		#ScreenVRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	jsr		turnOnScreen

	jsr		clearTimer

	lda		#ScreenDelay
	jsr		waitForTimerOrButtonPress

	jsr		turnOffScreen

	rts

showScreen3:	
	ldx		#Title3Screen			; Decompress the screen data
	ldu		#DecompressionBuffer
	jsr		zx0_decompress

	tfr		u, d					; Calculate the size of the data
	subd	#DecompressionBuffer

	tfr		d, x					; Transfer the length to X

	ldu		#DecompressionBuffer

	ldd		#ScreenVRAM				; Transfer data to VRAM
	jsr		transferToVRAM

	jsr		turnOnScreen

	jsr		clearTimer

	lda		#ScreenDelay
	jsr		waitForTimerOrButtonPress

	jsr		turnOffScreen

	rts
