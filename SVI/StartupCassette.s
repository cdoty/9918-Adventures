%org	ROMStart

start:
	di	

	im	1

	ld	sp, StackStart	; Set stack pointer

	call	setMode2		; Set mode 2
	call	clearVRAM		; Clear VRAM
	
	call	setInterrupt	; Set interrupt
	
	ei
	
	call	showTitle		; Show title
	call	startGame		; Start game

endlessLoop:
	jp	endlessLoop
