gameStart:	
	call	setupMode2
	call	clearVRAM

	ei

	call	showTitle
	call	startGame

endlessLoop:
	jmp	endlessLoop