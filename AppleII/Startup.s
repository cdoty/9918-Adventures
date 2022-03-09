	* = ROMStart
	
start:
	jsr		findSlot		; Find slot of the VDP card
		
	jsr		setMode2		; Set mode 2
	jsr		clearVRAM		; Clear VRAM
	jsr		showTitle		; Show title
	jsr		startGame		; Start game

endlessLoop:
	jmp		endlessLoop
