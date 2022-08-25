start:
	jsr		setMode2
	jsr		clearVRAM

	; Enable interrupts
	and.w	#$F8FF, sr

	jsr		showTitle
	jsr		startGame
	
endlessLoop:
	bra.s	endlessLoop
