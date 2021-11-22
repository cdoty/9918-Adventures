setMode2:
	ld      a, (1518h)	; Use a difference in ROM to determine if JAP or EUR machine. Based on code from Charlie Robson
    and     1			; Bit one is used to determine if PAL or NTSC.
	
	or		2			; Disable external VDP interrupt, set M2 for Graphics mode 2.
	ld		b, a
	ld		c, 0
	call	writeVDPReg

	ld		b, A2h		; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable Screen
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

	ld      a, (1518h)	; Use a difference in ROM to determine if JAP or EUR machine. Based on code from Charlie Robson
    and     1			; Bit one is used to determine if PAL or NTSC.
	
	ld		b, a		; Set background color to black
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
	in	a, (VDPReadBase + 1)	; Reset register write mode
	
	ld	a, b					; Write VDP data
	out	(VDPBase + 1), a

	ld	a, 80h					; Write VDP register | 0x80
	or	c
	out	(VDPBase + 1), a

	ret
	
clearVRAM:
	ld	hl, 0
	ld	de, $4000

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
	
clearTimer:
	xor		a
	ld		(NMICount), a

	ret
	
waitForTimerOrButtonPress:
	ld	a, (NMICount)
	cp	b
	
	jr	nz, waitForTimerOrButtonPress
	
	ret
	
delay:
	ld	bc, 0
	
delayLoop:
	dec	bc
	
	ld	a, b
	or	c
	
	jr	nz, delayLoop
	
	ret
