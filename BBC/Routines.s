setMode2:
	lda	#$02
	sta	ZPStart
	lda	#$80
	sta	ZPStart + 1

	jsr	writeVDPReg
	
	lda	#$A2
	sta	ZPStart
	lda	#$81
	sta	ZPStart + 1
	
	jsr writeVDPReg
	
	lda	#$0E
	sta	ZPStart
	lda	#$82
	sta	ZPStart + 1
	
	jsr	writeVDPReg
	
	lda	#$FF
	sta	ZPStart
	lda	#$83
	sta	ZPStart + 1
	
	jsr writeVDPReg

	lda	#$03
	sta	ZPStart
	lda	#$84
	sta	ZPStart + 1
	
	jsr writeVDPReg
	
	lda	#$76
	sta	ZPStart
	lda	#$85
	sta	ZPStart + 1
	
	jsr writeVDPReg
	
	lda	#$03
	sta	ZPStart
	lda	#$86
	sta	ZPStart + 1
	
	jsr writeVDPReg
	
	lda	#$00
	sta	ZPStart
	lda	#$87
	sta	ZPStart + 1
	
	jsr writeVDPReg
	
turnOnScreen:
	lda	#$E2		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	sta	ZPStart
	
	lda	#$81
	sta	ZPStart + 1
	
	jsr	writeVDPReg

	rts

turnOffScreen:
	lda	#$A2		; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable Screen
	sta	ZPStart
	
	lda	#$81
	sta	ZPStart + 1
	
	jsr	writeVDPReg

	rts

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
	
; ZPStart: VRAM address
; Wipes out x, y, ZPStart+4/+5
decompressToVRAM:
	; Always load file zero from compressed data
	ldx	#0
	ldy	#0
	
	jsr	huffmunch_load
		
	stx	ZPStart + 4		; Store the uncompressed size as the count
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
