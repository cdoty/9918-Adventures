	org	ROMStart

	db	83h				; Causes an out to 0x00 if the upper bit is set
	dw	0E278h			; Random seed
	dw	startAddress	; Start of code
	dw	0				; ?
	dw	404Eh			; ?
	dw	0				; ?
	dw	0				; ?
	dw	0E31Ch			; Cartridge flag
	dw	0				; ?
	dw	0				; ?
	dw	0				; ?
	dw	0				; ?
	ret
	dw	0				; ?
	ret
	dw	0				; ?
	
startAddress:
	dw	start			; Start of code

start:
	di
	
	ld		sp, StackStart	; Set stack pointer

	call	clearVRAM		; Clear VRAM
	call	setMode2		; Set mode 2

	call	showTitle		; Show title
	call	startGame		; Start game
	
endlessLoop:
	jp		endlessLoop
	