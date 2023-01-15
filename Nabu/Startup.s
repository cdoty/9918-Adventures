	org	ROMStart

	nop							; Padding
	nop
	nop
	
entry:
	di
	jp	start

	ds	(entry + 70h) - $, 0

start:
	ld		sp, StackPointer		; Set stack pointer

	call	enableDisplay			; Enable display
	call	setMode2				; Set mode 2
	call	clearVRAM				; Clear VRAM
	
	call	setupInterrupts			; Setup interrupts
	call	enableVBlankInterrupt	; Enable interrupts
	
	call	showTitle				; Show title
	call	startGame				; Start game
	
endlessLoop:
	jp		endlessLoop
	