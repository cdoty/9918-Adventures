%org	ROMStart

start:
	ld		a, 1
	out 	(1), a
	
	ld		sp, StackStart	; Setup stack pointer

	call	0x0E0B			; Setup VDP
	call	0x1393			; Clear screen
	
	call	setMode2		; Set mode 2

	ld		hl, NMIHandler	; Set VBI handler
	ld		(VBIAddress), hl

	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
	