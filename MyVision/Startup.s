	org	ROMStart

	di
	im		1
	
	jp		start
	
	ds   	38h-$, 0FFh	; Pad to 38h

IRQ:
	jp		NMIHandler

start:
	ld		sp, StackStart	; Set stack pointer

	ld		hl, RAMStart
	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	xor		a
	ld		(hl), a

	ldir

	call	setMode2			; Set mode 2
	call	clearVRAM			; Clear VRAM
	
	ei
	
	call	showTitle			; Show title
	call	startGame			; Start game
	
endlessLoop:
	jp		endlessLoop
