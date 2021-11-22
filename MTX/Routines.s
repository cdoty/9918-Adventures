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
	ld		b, A2h		; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable screen.
	ld		c, 1
	call	writeVDPReg

	ret

setupInterrupt:
	ld		a, C5h		; Set chamnel control register
	out		(08h), a
	
	ld		a, 1
	out		(08h), a
	
	ei
	
	ret
	
resetCTC:
	ld		b, 2		; Reset CTC
	
	ld		a, 3

resetCTCLoop:
	out		(08h), a
	out		(09h), a
	out		(0Ah), a
	out		(0Bh), a
	
	djnz	resetCTCLoop
	
	ld		a, FFh		; Load interrupt vector table address
	ld		i, a		; Upper byte is loaded from i

	ld		a, F0h
	out		(08h), a
	
	ret
	
writeVDPReg:
	in	a, (VDPReadBase + 1)	; Reset register write mode
	
	ld	a, b					; Write VDP data`
	out	(VDPBase + 1), a

	ld	a, 80h					; Write VDP register | 0x80
	or	c
	out	(VDPBase + 1), a

	ret
	
clearVRAM:
	in	a, (VDPReadBase + 1)	; Reset register write mode
	
	ld	hl, 0
	ld	de, $4000
	ld	c, 0

	ld	a, l
	out	(VDPBase + 1), a
	
	ld	a, h
	or	40h
	out	(VDPBase + 1), a
	
clearVRAMLoop:
	ld	a, c
	out	(VDPBase), a
		
	dec	de
	ld	a, d
	or	e
	
	jr	nz, clearVRAMLoop
	
	in	a, (VDPBase + 1)	; Acknowldge interrupt

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
	
	in	a, (VDPBase + 1)	; Acknowldge interrupt

	ret
	
clearTimer:
	xor		a
	ld		(NMICount), a

	ret
	
waitForTimerOrButtonPress:
	ld	a, (NMICount)
	cp	b
	
	jr	nz, waitForTimerOrButtonPress
	
	ret
	
seedRandomNumber:
	; TODO add reading of H and V raster position and transfer to 73c8/9
	
	ret

getRandomNumber:
;	call	1ffdh	
;	ld		a, r
	
	ret
