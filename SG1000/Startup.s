	org	ROMStart

	di	
	im	1
	
	jp	start
	
	block	38h-$, 0	; Pad to 38h

IRQ:
	jp	NMIHandler

	block	66h-$, 0	; Pad to 66h
NMI:
	reti
	nop
	
start:
	ld		sp, StackStart	; Set stack pointer

	call	resetSound	; Reset sound to stop noise at startup

	xor		a
	
	ld		hl, RAMStart
	ld		(hl), a
	
	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	ldir

	call	delay		; Delay before starting
	
	call	setMode2	; Set mode 2
	call	clearVRAM	; Clear VRAM
	
	call	showTitle	; Show title
	call	startGame	; Start game
	
gameLoop:
	jp		gameLoop
