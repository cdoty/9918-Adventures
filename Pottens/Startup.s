	org	ROMStart
	
	di
	ld	sp, StackStart
	im	2
	
	jp	start
	
	ds	38h-$, 00h	; Pad to 38h

IRQ:
	jp	NMIHandler

	ds	80h-$, 00h	; Pad to 80h

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
	
;	ei
	
	call	showTitle			; Show title
	call	startGame			; Start game
	
endlessLoop:
	jp		endlessLoop
