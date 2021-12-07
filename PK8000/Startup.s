start:
	di
	
	call	enableBank1Rom
	call	setupMode2
	call	clearVRAM
	call	setupInterrupt

	ei

	call	showTitle
	call	startGame

endlessLoop:
	jmp		endlessLoop