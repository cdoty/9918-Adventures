	org	ROMStart

	db	'AB'	; Cartridge header
	dw	start	; Init routine
	dw	0		; Do not add instructions to basic
	dw	0		; Device number
	dw	0		; Do not provide a tokenize basic program
	ds	6		; Reserved block

start:
	xor		a
	
	ld		hl, RAMStart
	ld		(hl), a
	
	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	ldir

	call	delay			; Delay before starting
	
	call	setMode2		; Set mode 2
	call	clearVRAM		; Clear VRAM
	call	setInterrupt	; Set interrupt
	
	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
