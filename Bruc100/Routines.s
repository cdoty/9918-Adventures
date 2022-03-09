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
	in	a, (VDPBase + 1)	; Acknowldge interrupt
	
	ld	a, b				; Write VDP data`
	out	(VDPBase + 1), a
	nop
	
	ld	a, 80h				; Write VDP register | 80h
	or	c
	out	(VDPBase + 1), a
	nop

	ret
	
clearVRAM:
	ld	hl, 0
	ld	de, 4000h

	ld	a, l
	out	(VDPBase + 1), a
	nop
	
	ld	a, h
	or	40h
	out	(VDPBase + 1), a
	nop
	
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
	nop
		
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
	
; Change interrupt, used for cassette and disk games
changeInterrupt:
	di								; Start of critical region

	ld		de, Ram.OldInterrupt	; Get address of old int. hook saved area
	ld		hl, InterruptHook		; Get address of interrupt entry hook
	ld		bc, 5					; Length of hook is 5 bytes
	ldir							; Transfer

	ld		a, 0C3h					; Set new hook code
	ld		(InterruptHook), a		; 
	ld		hl, NMIHandler			; Get our interrupt entry point
	ld		(InterruptHook + 1), hl	; Set new interrupt entry point
	ld		a, 0C9h					; 'RET' operation code
	ld		(InterruptHook + 3), a	; set operation code of 'RET'
	
	ei								; End of critical region
	
	ret

; Set interrupt, used for cartridge games
setInterrupt:
	di								; Start of critical region

	ld		de, Ram.OldInterrupt	; Get address of old int. hook saved area
	ld		hl, InterruptHook		; Get address of interrupt entry hook
	ld		bc, 5					; Length of hook is 5 bytes
	ldir							; Transfer

	call	getMySlot 				; Get my slot address

	ld		(InterruptHook+1), a	; set slot address
	ld		a, 0F7h					; 'RST 30H' inter-slot call operation code
	ld		(InterruptHook), a		; Set new hook op-code
	ld		hl, NMIHandler			; Get our interrupt entry point
	ld		(InterruptHook+2), hl	; Set new interrupt entry point
	ld		a, 0C9h					; 'RET' operation code
	ld		(InterruptHook + 4), a	; set operation code of 'RET'
	
	ei								; End of critical region
	
	ret

getMySlot:
	push	bc
	push	hl
	
	in		a, (PrimarySlotReg)	; Read primary slot register
	rrca						; Move it to bit 0,1 of A
	rrca
	and		00000011b			; Get bit 1,0
	ld		c, a				; Set primary slot No.
	ld		b, 0
	ld		hl,	ExpansionTable	; See if the slot is expanded or not
	add		hl, bc
	or		(hl)				; set MSB if so
	ld		c, a
	inc		hl					; point to SLTTBL entry
	inc		hl
	inc		hl
	inc		hl
	ld		a, (hl)				; Get what is currently output to expansion slot register

	and		00001100b			; Get bits 3,2
	or		c					; Finally form slot address

	pop		hl
	pop		bc
	
	ret

delay:
	ld	bc, 0
	
delayLoop:
	dec	bc
	
	ld	a, b
	or	c
	
	jr	nz, delayLoop
	
	ret
	
seedRandomNumber:
	ret

getRandomNumber:
	ret
	