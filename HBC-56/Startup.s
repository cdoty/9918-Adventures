	* = ROMStart
	
start:
	sei
	cld
	
	jsr		setMode2	; Set mode 2
	jsr		clearVRAM	; Clear VRAM

	cli
	
	jsr		showTitle	; Show title
	jsr		startGame	; Start game

endlessLoop:
	jmp		endlessLoop
