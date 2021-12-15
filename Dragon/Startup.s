	org	ROMStart

start:
	jsr		setupInterrupt	; Setup interrupt
	jsr		setMode2		; Set mode 2
	jsr		clearVRAM		; Clear VRAM

	jsr		enableVBlankInterrupt
	
	jsr		showTitle		; Show title
	jsr		startGame		; Start game
	
endlessLoop:
	jmp		endlessLoop