	* = ROMStart
	
start:
	sei
	cld
	
	jsr	startupDelay	; Startup delay
	jsr	clearVRAM		; Clear VRAM
	jsr	showTitle		; Show title
	jsr	startGame		; Start game

endlessLoop:
	jmp	endlessLoop
