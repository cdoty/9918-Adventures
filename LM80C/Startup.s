	org	ROMStart

BasicStub:
	dw	NextLine
	dw	10
	db	0ABh
	db	'&H8251:'
	db	080h
	db	0

NextLine:
	dw	0

start:
	call	clearRAM			; Clear ram
	call	setMode2			; Set mode 2
	call	clearVRAM			; Clear VRAM
;	call	setupNMIInterrupt	; Setup interrupt
	
	ei

	call	showTitle			; Show title
	call	startGame			; Start game
	
endlessLoop:
	jp		endlessLoop
