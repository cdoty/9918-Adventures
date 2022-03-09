	org	ROMStart

start:
	call	setMode2		; Set mode 2
	call	clearVRAM		; Clear VRAM

	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
	