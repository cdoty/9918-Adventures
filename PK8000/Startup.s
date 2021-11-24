start:
	di
	
	mvi		a, $FC
	out		BankSwap

	call	setupMode2
	call	clearVRAM
	call	setupInterrupt

	ei

	call	showTitle
	call	startGame

endlessLoop:
	jmp	endlessLoop