%org	ROMStart

StartCart:	
start:
	rst		28h
	db		42h
	
	di
	im		2
	ld		sp, StackStart
	
	call	setMode2	; Set mode 2
	call	clearVRAM	; Clear VRAM

	call	resetCTC

	ld		hl, NMIHandler			; Set VBI handler
	ld		(InterruptTable), hl

	ld		hl, DefaultHandler		; Set rest of the interrupts to the default handler
	ld		(InterruptTable + 2), hl
	ld		(InterruptTable + 4), hl
	ld		(InterruptTable + 6), hl
	
	call	setupInterrupt
	
	call	showTitle	; Show title
	call	startGame	; Start game
	
endlessLoop:
	jp		endlessLoop
	