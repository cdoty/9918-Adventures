%org	ROMStart

%def8	0x83			; ? Random number
%def8	0xE2			; ? Random number
%def8	0x78			; ? Possibly release number
%def16	startAddress	; Start of code
%def16	0				; ?
%def16	0x404E			; ?
%def16	0				; ?
%def16	0				; ?
%def16	0xE31C			; ?
%def16	0				; ?
%def16	0				; ?
%def16	0				; ?
%def16	0				; ?
	ret
%def16	0				; ?
	ret
%def16	0				; ?
	
startAddress:
%def16	start			; Start of code

start:
	di
	
	call	clearVRAM	; Clear VRAM
	call	setMode2	; Set mode 2
	call	showTitle	; Show title
	call	startGame	; Start game
	
endlessLoop:
	jp		endlessLoop
	