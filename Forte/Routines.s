setMode2:
	ld		b, 02h						; Disable external VDP interrupt, set M2 for Graphics mode 2
	ld		c, 0
	call	writeVDPReg

	ld		b, 0A2h						; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
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

	ld		b, 0						; Set background color to black
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
	in	a, (VDPBase + 1)	; Acknowldge interrupt
	
	ld	a, b				; Write VDP data`
	out	(VDPBase + 1), a

	ld	a, 80h				; Write VDP register | 80h
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
	
	in	a, (VDPBase + 1)	; Acknowldge interrupt

	ret
	
; HL - Source address
; BC - Destination address
; DE - Size
tranferToVRAM:
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
	ld		(Ram.NMICount), a

	ret
	
; B: Count value to wait for (1/60th of a second)
waitForTimerOrButtonPress:
	ld	a, (Ram.NMICount)
	cp	b
	
	jr	nz, waitForTimerOrButtonPress
	
	ret
	
setInterrupt:
	di								; Start of critical region

	im		1
	
	ld		bc, 22Fh				; Clear interrupt vector table by filling it with RET instructions.
	ld		de, 0FD9Bh
	ld		hl, 0FD9Ah
	
	ld		(hl), 0C9h
	ldir
	
	
	ld		a, 0C3h					; 'RET' operation code
	ld		(InterruptHook), a		; Set new hook op-code
	ld		hl, NMIHandler			; Get our interrupt entry point
	ld		(InterruptHook + 1), hl	; Set new interrupt entry point
	
	ei								; End of critical region
	
	ret

seedRandomNumber:
	ret

getRandomNumber:
	ret
	