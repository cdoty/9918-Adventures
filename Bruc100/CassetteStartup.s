	%org	ROMStart

start:
	call	delay			; Delay before starting
	
	call	setMode2		; Set mode 2
	call	clearVRAM		; Clear VRAM
	call	changeInterrupt	; Change interrupt
	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
