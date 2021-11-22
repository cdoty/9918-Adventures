	%org	ROMStart

	%def16	'AB'
	%def16	start
	%def16	0
	%def16	0
	%def16	0
	%defb	6

start:
	xor		a
	
	ld		hl, RAMStart
	ld		(hl), a
	
	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	ldir

	call	delay		; Delay before starting
	
	call	setMode2		; Set mode 2
	call	clearVRAM		; Clear VRAM
	call	setInterrupt	; Set interrupt
	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
