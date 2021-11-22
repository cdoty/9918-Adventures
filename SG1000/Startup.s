%org	ROMStart

	di	
	im	1
	
	jp	start
	
%defb   0038h-%apos	; Pad to 0038h

IRQ:
	jp	NMIHandler

%defb   0066h-%apos	; Pad to 0066h
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
