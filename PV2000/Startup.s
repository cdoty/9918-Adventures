	org	ROMStart

	; Jump to start location, must be jp and not jr. The system looks for C3h to identify a cartridge.
	jp		start
	
start:
	xor		a
	
	ld		hl, RAMStart
	ld		(hl), a
	
	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	ldir

	call	delay				; Delay before starting
	
	call	setMode2			; Set mode 2
	call	clearVRAM			; Clear VRAM
	call	setupNMIInterrupt	; Setup interrupt
	
	call	showTitle			; Show title
	call	startGame			; Start game
	
endlessLoop:
	jp		endlessLoop
