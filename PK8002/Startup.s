start:
	di
	
	ld		sp, StackStart
	
	call	disableBank1Rom
	call	resetSound
	call	resetTimer
	call	setTurboMode

	call	clearVRAM
	call	setupMode2
	call	setupInterrupt

	ei

	call	showTitle
	call	startGame

endlessLoop:
	jmp		endlessLoop