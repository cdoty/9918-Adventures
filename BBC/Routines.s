; Set mode 2
setMode2:
	lda	#$02						; Disable external VDP, set M3 for Graphics mode 2
	sta	ZPStart
	lda	#$80
	sta	ZPStart + 1
	jsr	writeVDPReg
	
	lda	#$A2						; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable screen.
	sta	ZPStart
	lda	#$81
	sta	ZPStart + 1
	jsr writeVDPReg
	
	lda	#ScreenVRAM / $400			; Set Name Table location.
	sta	ZPStart
	lda	#$82
	sta	ZPStart + 1
	jsr	writeVDPReg
	
	lda	#(Color1VRAM / $40) | $7F	; Set Color Table location.
	sta	ZPStart
	lda	#$83
	sta	ZPStart + 1
	jsr writeVDPReg

	lda	#(<Tile1VRAM / $8) | 3		; Set Pattern Table location. Assembler doesn't like $0000 / $800
	sta	ZPStart
	lda	#$84
	sta	ZPStart + 1
	jsr writeVDPReg
	
	lda	#SpriteAttributes / $80		; Set Sprite Attribute Table location.
	sta	ZPStart
	lda	#$85
	sta	ZPStart + 1
	jsr writeVDPReg
	
	lda	#SpritePattern / $800		; Set Sprite Pattern Table location.
	sta	ZPStart
	lda	#$86
	sta	ZPStart + 1
	jsr writeVDPReg
	
	lda	#$00						; Set screen color
	sta	ZPStart
	lda	#$87
	sta	ZPStart + 1
	jsr writeVDPReg
	
; Turn on screen
turnOnScreen:
	lda	#$E2		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	sta	ZPStart
	lda	#$81
	sta	ZPStart + 1
	jsr	writeVDPReg

	rts

; Turn off screen
turnOffScreen:
	lda	#$A2		; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable Screen
	sta	ZPStart
	lda	#$81
	sta	ZPStart + 1
	jsr	writeVDPReg

	rts

; Write VDP register
; ZPStart: Data
; ZPStart+1: Register
; Wipes out x, y, ZPStart
writeVDPReg:
	lda	VDPStatus

	lda	ZPStart
	sta	VDPRegister
	
	lda	ZPStart + 1
	sta	VDPRegister

	rts

; Clear VRAM
clearVRAM:
	ldy	#$00			; Set the total number of bytes to clear, adjust for loop
	lda	#$40
	sta	ZPStart
	
	lda	VDPStatus

	lda	#0				; Set VRAM address
	sta	VDPRegister
	
	lda	#0
	ora	#$40
	sta	VDPRegister
	
	lda	#0

ClearVRAMLoop:
	sta	VDPWrite
	
	dey
	bne	ClearVRAMLoop
	
	dec	ZPStart	
	bne	ClearVRAMLoop
	
	rts

; Transfer to VRAM
; ZPStart: Source address
; ZPStart+2: VRAM address
; ZPStart+4: Size
; Wipes out x, y, ZPStart
tranferToVRAM:
	lda	VDPStatus

	lda	ZPStart + 2		; Set VRAM address
	sta	VDPRegister
	
	lda	ZPStart + 3
	ora	#$40
	sta	VDPRegister
	
	ldy	ZPStart

	lda	#0
	sta	ZPStart

TransferVRAMLoop:
	lda	(ZPStart), y
	sta	VDPWrite

	iny

	cpy	#$FF
	bne	TransferSamePage

	inc	ZPStart + 1

TransferSamePage:
	dec	ZPStart + 5	
	bne	TransferVRAMLoop

	rts
	
; Decompress to VRAM
; ZPStart: VRAM address
; Wipes out x, y, ZPStart+4/+5
decompressToVRAM:
	; Always load file zero from compressed data
	ldx	#0
	ldy	#0
	
	jsr	huffmunch_load
		
	stx	ZPStart + 4		; Store the uncompressed size as the count

	cpy	#0
	bne	noUpdate

	iny					; Account for high byte bne branch
	
noUpdate:
	sty	ZPStart + 5

	lda	VDPStatus

	lda	ZPStart			; Set VRAM address
	sta	VDPRegister
	
	lda	ZPStart + 1
	ora	#$40
	sta	VDPRegister
	
decompressToVRAMLoop:
	jsr	huffmunch_read
	
	sta	VDPWrite

	dec	ZPStart + 4	
	bne	decompressToVRAMLoop
	
	dec	ZPStart + 5	
	bne	decompressToVRAMLoop

	rts

clearTimer:
	lda	#0
	sta	NMICount

	rts

; Wait for timer or button press
; ZPStart: Value to wait for
waitForTimerOrButtonPress:
	jsr	waitForVBlank
	
	inc	NMICount
	lda	NMICount

	cmp	ZPStart
	bmi	waitForTimerOrButtonPress

	rts

waitForVBlank:
	lda	VDPStatus
	
	and	#$80
	beq	waitForVBlank

	rts
seedRandomNumber:
	rts

getRandomNumber:
	rts
