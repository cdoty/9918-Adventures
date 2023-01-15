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
	in	a, (VDPReadBase + 1)	; Reset register write mode
	
	ld	a, b					; Write VDP data`
	out	(VDPBase + 1), a

	ld	a, 80h					; Write VDP register | 80h
	or	c
	out	(VDPBase + 1), a

	ret
	
clearVRAM:
	ld	hl, 0
	ld	de, 4000h

	ld	a, l
	out	(VDPBase + 1), a
	
	ld	a, h
	or	40h
	out	(VDPBase + 1), a
	
clearVRAMLoop:
	xor	a
	out	(VDPBase), a
		
	dec	de
	ld	a, d
	or	e
	
	jr	nz, clearVRAMLoop
	
	in	a, (VDPReadBase + 1)	; Acknowldge interrupt

	ret
	
; HL - Source address
; BC - Destination address
; DE - Size
tranferToVRAM:
	in	a, (VDPReadBase + 1)	; Reset register write mode

	ld	a, c
	out	(VDPBase + 1), a
	
	ld	a, b
	or	40h
	out	(VDPBase + 1), a
	
transferVRAMLoop:
	ld	a, (hl)
	out	(VDPBase), a
		
	inc	hl
	dec	de

	ld	a, d
	or	e
	
	jr	nz, transferVRAMLoop
	
	in	a, (VDPReadBase + 1)	; Acknowldge interrupt

	ret
	
enableDisplay:
	in	a, (Control)
	or	2
	out	(Control), a
	
	ret

setupInterrupts:
	im		2

	ld		a, 0FFh			; Set interrupt table high byte to FFh
	ld		I, a

	ld		hl, 0FF00h

	ld		de, HCCAReceiveHandler	; Set interrupt jump addresses
	ldi		(hl), e
	ldi		(hl), d
	
	ld		de, 0
	ldi		(hl), e
	ldi		(hl), d

	ld		de, KeyboardHandler
	ldi		(hl), e
	ldi		(hl), d

	ld		de, VBlankHandler
	ldi		(hl), e
	ldi		(hl), d

	ld		de, OptionHandler
	ldi		(hl), e
	ldi		(hl), d

	ld		de, OptionHandler
	ldi		(hl), e
	ldi		(hl), d

	ld		de, OptionHandler
	ldi		(hl), e
	ldi		(hl), d

	ld		de, OptionHandler
	ldi		(hl), e
	ldi		(hl), d

	ld		a, 7			; Select register 7
	out		(AY8910 + 1), a
	
	ld		a, 7Fh			; Enable port A for output and B for input port
	out		(AY8910), a

	ret

enableVBlankInterrupt:
	di
	
	ld		a, 14			; Select register 14
	out		(AY8910 + 1), a
	
	ld		a, 10h			; Enable vblank interrupt
	out		(AY8910), a	 

	ei
	ret

disableVBlankInterrupt:
	di
	
	ld		a, 14			; Select register 14
	out		(AY8910 + 1), a
	
	ld		a, 00h			; Disable all interrupts.
	out		(AY8910), a

	ei
	ret

clearTimer:
	xor		a
	ld		(Ram.NMICount), a

	ret
	
waitForTimerOrButtonPress:
	ld	a, (Ram.NMICount)
	cp	b
	
	jr	nz, waitForTimerOrButtonPress
	
	ret
