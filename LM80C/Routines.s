; Set mode 2
setMode2:
	ld		b, 02h						; Disable external VDP interrupt, set M2 for Graphics mode 2
	ld		c, 0
	call	writeVDPReg

	ld		b, 0A2h						; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable screen.
	ld		c, 1
	call	writeVDPReg

	ld		b, ScreenVRAM / 400h		; Set Name Table location.
	ld		c, 2
	call	writeVDPReg

	ld		b, (Color1VRAM / 40h) | 7Fh	; Set Color Table location.
	ld		c, 3
	call	writeVDPReg

	ld		b, (Tile1VRAM / 800h) | 3	; Set Pattern Table location.
	ld		c, 4
	call	writeVDPReg

	ld		b, SpriteAttributes / 80h	; Set Sprite Attribute Table location.
	ld		c, 5
	call	writeVDPReg

	ld		b, SpritePattern / 800h		; Set Sprite Pattern Table location.
	ld		c, 6
	call	writeVDPReg

	ld		b, 00h						; Set background color to black
	ld		c, 7
	call	writeVDPReg

	ret
	
; Turn on screen
turnOnScreen:
	ld		b, 0E2h		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	ld		c, 1
	call	writeVDPReg

	ret
	
; Turn off screen
turnOffScreen:
	ld		b, 0A2h		; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable Screen
	ld		c, 1
	call	writeVDPReg

	ret

; Write VDP register
writeVDPReg:
	in	a, (VDPReadBase + 2)	; Reset register write mode
	
	ld	a, b					; Write VDP data
	out	(VDPBase + 2), a

	ld	a, 80h					; Write VDP register | 80h
	or	c
	out	(VDPBase + 2), a

	ret
	
; Clear VRAM
clearVRAM:
	ld	hl, 0
	ld	de, 4000h

	ld	a, l
	out	(VDPBase + 2), a
	
	ld	a, h
	or	40h
	out	(VDPBase + 2), a
	
clearVRAMLoop:
	xor	a
	out	(VDPBase), a
		
	dec	de
	ld	a, d
	or	e
	
	jr	nz, clearVRAMLoop
	
	in	a, (VDPReadBase + 2)	; Acknowldge interrupt

	ret
	
; HL - Source address
; BC - Destination address
; DE - Size
transferToVRAM:
	in	a, (VDPReadBase + 2)	; Reset register write mode

	ld	a, c
	out	(VDPBase + 2), a
	
	ld	a, b
	or	40h
	out	(VDPBase + 2), a
	
transferVRAMLoop:
	ld	a, (hl)
	out	(VDPBase), a
		
	inc	hl
	dec	de

	ld	a, d
	or	e
	
	jr	nz, transferVRAMLoop
	
	in	a, (VDPReadBase + 2)	; Acknowldge interrupt

	ret
	
clearTimer:
	xor		a
	ld		(Ram.NMICount), a

	ret
	
waitForTimerOrButtonPress:
	call	waitForVBlank
	
	ld		a, (Ram.NMICount)
	inc		a
	ld		(Ram.NMICount), a
	
	cp		b
	
	jr		nz, waitForTimerOrButtonPress
	
	ret
	
waitForVBlank:
	in		a, (VDPReadBase + 2)	; Acknowldge interrupt
	and		80h
	
	jr		z, waitForVBlank

	ret

clearRAM:
	xor		a
	
	ld		hl, RAMStart
	ld		(hl), a

	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	ldir

	ret
	
setupNMIInterrupt:
	ld		a, 0C3h
	ld		hl, NMIHandler
	
	ld		(NMIAddress), a
	ld		a, l
	ld		(NMIAddress + 1), a
	ld		a, h
	ld		(NMIAddress + 2), a
	
	ret
