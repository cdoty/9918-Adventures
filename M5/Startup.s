	org	ROMStart

	ifdef	RAM_8K_2000
	db	0			; 0 =  8 KB from 2000H  1 =  8 KB from 4000H  2 = 16 KB from 2000H
	elseif ifdef	RAM_8K_4000
	db	1
	else
	db	2
	endif

	dw	start		; Start of code
	dw	runOnce		; Code ran on initial cartridge load
	dw	unknown		; Unknown entry

runOnce:
	ret

unknown:
	ret

start:
	di
	
	ld		a, 1				; Set Z80CTC channel 1 to control mode
	out 	(1), a
	
	ld		sp, StackStart		; Setup stack pointer

	ld		hl, RAMStart		; Clear RAM
	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	xor		a				
	ld		(hl), a

	ldir

	call	delay				; Delay before starting
	
	call	setMode2			; Set mode 2
	call	clearVRAM			; Clear VRAM

	ld		hl, NMIHandler		; Load VBI handler address
	ld		(VBIAddress), hl	; Store in Z80CTC channel 3 interrupt address.

	ei

	call	showTitle			; Show title
	call	startGame			; Start game
	
endlessLoop:
	jp		endlessLoop
	