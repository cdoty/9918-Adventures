	org	ROMStart

start:
	ld		a, 1
	out 	(1), a
	
	ld		sp, StackStart	; Setup stack pointer

	call	0E0Bh			; Setup VDP
	call	1393h			; Clear screen
	
	call	setMode2		; Set mode 2

	ld		hl, NMIHandler	; Set VBI handler
	ld		(VBIAddress), hl

	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
	