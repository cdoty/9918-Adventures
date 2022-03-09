	org	ROMStart

	db	'AB'
	dw	start
	dw	0
	dw	0
	dw	0
	db	6

	ds	407Eh-$, 0FFh	; Pad to start addess used in the hacked bios

start:
	di

	ld		sp, 0E800h
	
	call	setMode2		; Set mode 2
	call	clearVRAM		; Clear VRAM
	call	setInterrupt	; Set interrupt
	
	ei
	
	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
