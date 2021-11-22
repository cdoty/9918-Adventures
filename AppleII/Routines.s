setMode2:
	lda	#$02
	ldx	#$80

	jsr	writeVDPReg
	
	lda	#$82			; Do not enable interrupts, the Apple IIgs will enter the monitor on startup.
	ldx	#$81
	
	jsr writeVDPReg

	lda	#$0E
	ldx	#$82
	
	jsr	writeVDPReg
	
	lda	#$FF
	ldx	#$83
	
	jsr writeVDPReg

	lda	#$03
	ldx	#$84
	
	jsr writeVDPReg
	
	lda	#$76
	ldx	#$85
	
	jsr writeVDPReg
	
	lda	#$03
	ldx	#$86
	
	jsr writeVDPReg
	
	lda	#$00
	ldx	#$87
	
	jsr writeVDPReg

	rts

turnOnScreen:
	lda	#$C2		; Enable 16K VRAM, Screen, and 16x16 sprites
	ldx	#$81
	
	jsr	writeVDPReg

	rts

turnOffScreen:
	lda	#$82		; Enable 16K VRAM, and 16x16 sprites. Disable Screen
	ldx	#$81
	
	jsr	writeVDPReg

	rts

; ZPStart: Data
; ZPStart+1: Register
; Wipes out x, y, ZPStart
writeVDPReg:
	jsr	writeToVDPRegister

	txa
	jsr	writeToVDPRegister

	rts

readFromVDPData:
	lda	VDPRead

	rts
writeToVDPData:
	sta	VDPWrite

	rts

readFromVDPStatus:
	lda	VDPStatus

	rts

writeToVDPRegister:
	sta	VDPRegister
	
	rts

clearVRAM:
	ldx	#$00			; Set the total number of bytes to clear, adjust for loop
	lda	#$40
	sta	ZPStart

	lda	#0				; Set VRAM address
	jsr	writeToVDPRegister
	
	lda	#0
	ora	#$40
	jsr	writeToVDPRegister
	
	lda	#0

ClearVRAMLoop:
	jsr	writeToVDPData
	
	dex
	bne	ClearVRAMLoop
	
	dec	ZPStart	
	bne	ClearVRAMLoop
	
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

	ldy	#0

	lda	ZPStart			; Set VRAM address
	jsr	writeToVDPRegister
	
	lda	ZPStart + 1
	ora	#$40
	jsr	writeToVDPRegister
	
decompressToVRAMLoop:
	jsr	huffmunch_read
	
	jsr	writeToVDPData

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
	ldy	ZPStart

waitForTimerLoop:
	jsr	waitForVBlank
	
	dey
	bne	waitForTimerLoop

	rts

waitForVBlank:
	jsr	readFromVDPStatus
	and #$80

	beq	waitForVBlank

	rts

; Find a slot modify code with new slot location
findSlot:
	ldx	#$90
	stx	readFromVDPData + 1
	stx	writeToVDPData + 1
	
	ldy	#$91
	sty	readFromVDPStatus + 1
	sty	writeToVDPRegister + 1

findSlotLoop:
	lda	#$00
	jsr	writeToVDPRegister
	lda	#$40
	jsr	writeToVDPRegister
	
	lda	#$55
	jsr	writeToVDPData
	lda	#$AA
	jsr	writeToVDPData
	
	lda	#$00
	jsr	writeToVDPRegister
	lda	#$00
	jsr	writeToVDPRegister

	jsr	readFromVDPData
	cmp	#$55

	bne	nextSlot

	jsr	readFromVDPData
	cmp	#$AA

	beq	foundSlot

nextSlot:
	txa
	clc
	adc	#$10
	sec
	tax

	cmp	#$00
	beq	foundSlot

	stx	readFromVDPData + 1
	stx	writeToVDPData + 1
	
	tay
	iny

	sty	readFromVDPStatus + 1
	sty	writeToVDPRegister + 1

	jmp	findSlotLoop

foundSlot:
	rts

seedRandomNumber:
	rts

getRandomNumber:
	rts
