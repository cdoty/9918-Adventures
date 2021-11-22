setMode2:
	ld		b, 02h		; Disable external VDP interrupt, set M2 for Graphics mode 2
	ld		c, 0
	call	writeVDPReg

	ld		b, A2h		; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable screen.
	ld		c, 1
	call	writeVDPReg

	ld		b, 0Eh		; Set Name Table location to 3800h, in VRAM
	ld		c, 2
	call	writeVDPReg

	ld		b, FFh		; Set Color Table location to 2000h, in VRAM
	ld		c, 3
	call	writeVDPReg

	ld		b, 03h		; Set Pattern Table location to 0000h, in VRAM
	ld		c, 4
	call	writeVDPReg

	ld		b, 76h		; Set Sprite Attribute Table location to 3B00h, in VRAM
	ld		c, 5
	call	writeVDPReg

	ld		b, 03h		; Set Sprite Pattern Table location to 1800h, in VRAM
	ld		c, 6
	call	writeVDPReg

	ld		b, 00h		; Set background color to black
	ld		c, 7
	call	writeVDPReg

	ret
	
; Turn on screen
turnOnScreen:
	ld		b, E2h		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	ld		c, 1
	call	writeVDPReg

	ret
	
; Turn off screen
turnOffScreen:
	ld		b, A2h		; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable Screen
	ld		c, 1
	call	writeVDPReg

	ret

writeVDPReg:
	ld	a, (VDPBase + 2)	; Reset register write mode
	
	ld	a, b				; Write VDP data`
	ld	(VDPBase + 2), a

	ld	a, 80h				; Write VDP register | 0x80
	or	c
	ld	(VDPBase + 2), a

	ret
	
clearVRAM:
	ld	a, (VDPBase + 2) 	; Reset register write mode

	ld	hl, 0
	ld	de, $4000

	ld	a, (VDPBase + 2)	; Reset register write mode
	
	ld	a, l
	ld	(VDPBase + 2), a
	
	ld	a, h
	or	40h
	ld	(VDPBase + 2), a
	
clearVRAMLoop:
	xor	a
	ld	(VDPBase), a
		
	dec	de
	ld	a, d
	or	e
	
	jr	nz, clearVRAMLoop
	
	ld	a, (VDPBase + 2) 	; Acknowledge interrupt

	ret
	
; HL - Source address
; BC - Destination address
; DE - Size
tranferToVRAM:
	ld	a, (VDPBase + 2)	; Reset register write mode
	
	ld	a, c
	ld	(VDPBase + 2), a
	
	ld	a, b
	or	40h
	ld	(VDPBase + 2), a
	
transferVRAMLoop:
	ld	a, (hl)
	ld	(VDPBase), a
		
	inc	hl
	dec	de
	ld	a, d
	or	e
	
	jr	nz, transferVRAMLoop
	
	ld	a, (VDPBase + 2)	; Acknowldge interrupt

	ret
	
clearTimer:
	xor	a
	ld	(NMICount), a

	ret
	
waitForTimerOrButtonPress:
	ld	a, (NMICount)
	cp	b
	
	jr	nz, waitForTimerOrButtonPress
	
	ret
	
seedRandomNumber:
	ret

getRandomNumber:
	ret
