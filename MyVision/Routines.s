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

writeVDPReg:
	ld		a, (VDPBase + 2)	; Reset register write mode
	
	ld		a, b				; Write VDP data`
	ld		(VDPBase + 2), a

	ld		a, 80h				; Write VDP register | 80h
	or		c
	ld		(VDPBase + 2), a

	ret
	
clearVRAM:
	ld		a, (VDPBase + 2) 	; Reset register write mode

	ld		hl, 0
	ld		de, 4000h

	ld		a, (VDPBase + 2)	; Reset register write mode
	
	ld		a, l
	ld		(VDPBase + 2), a
	
	ld		a, h
	or		40h
	ld		(VDPBase + 2), a
	
clearVRAMLoop:
	xor		a
	ld		(VDPBase), a
		
	dec		de
	ld		a, d
	or		e
	
	jr		nz, clearVRAMLoop
	
	ld		a, (VDPBase + 2) 	; Acknowledge interrupt

	ret
	
; HL - Source address
; BC - Destination address
; DE - Size
tranferToVRAM:
	ld		a, (VDPBase + 2)	; Reset register write mode
	
	ld		a, c
	ld		(VDPBase + 2), a
	
	ld		a, b
	or		40h
	ld		(VDPBase + 2), a
	
transferVRAMLoop:
	ld		a, (hl)
	ld		(VDPBase), a
		
	inc		hl
	dec		de
	ld		a, d
	or		e
	
	jr		nz, transferVRAMLoop
	
	ld		a, (VDPBase + 2)	; Acknowldge interrupt

	ret
	
clearTimer:
	xor		a
	ld		(Ram.NMICount), a

	ret
	
waitForTimerOrButtonPress:
	ld		a, (Ram.NMICount)
	cp		b
	
	jr		nz, waitForTimerOrButtonPress
	
	ret
	
seedRandomNumber:
	ret

getRandomNumber:
	ret
