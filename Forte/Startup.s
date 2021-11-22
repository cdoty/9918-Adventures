	%org	ROMStart

	%def16	'AB'
	%def16	start
	%def16	0
	%def16	0
	%def16	0
	%defb	6

%defb	407eh-%apos, FFh	; Pad to start addess used in the hacked bios

start:
	di

	ld		sp, E800h
	
	call	setMode2		; Set mode 2
	call	clearVRAM		; Clear VRAM
	call	setInterrupt	; Set interrupt
	
	ei
	
	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
