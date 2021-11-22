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

; Load data from ZPStart and register from ZPStart+1.
writeVDPReg:
	lda	VDPBase			; Ensure we are writing to the first byte

	lda	ZPStart			; Write VDP data
	sta	VDPBase + 1

	lda	ZPStart + 1
	sta	VDPBase + 1

	rts
	
clearVRAM:
	ldx	#$00			; Set the total number of bytes to clear
	ldy	#$40
	
	lda	VDPBase			; Ensure we are writing to the first byte

	lda	#$00			; Set VRAM address
	sta	VDPBase + 1
	
	lda	#$00
	ora	#$40
	sta	VDPBase + 1
	
	lda	#0

ClearVRAMLoop:
	sta	VDPBase
	
	dex	
	bne	ClearVRAMLoop
	
	dey	
	bne	ClearVRAMLoop

	rts

; ZPStart: Source address
; ZPStart+2: VRAM address
; ZPStart+4: Size
tranferToVRAM:
	lda	VDPBase			; Ensure we are writing to the first byte

	lda	ZPStart + 2		; Set VRAM address
	sta	VDPBase + 1
	
	lda	ZPStart + 3
	ora	#$40
	sta	VDPBase + 1
	
	ldy	ZPStart

	lda	#0
	sta	ZPStart

TransferVRAMLoop:
	lda	(ZPStart), y
	sta	VDPBase

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
	
	lda	VDPBase + 1		; Ensure we are writing to the first byte

	lda	ZPStart			; Set VRAM address
	sta	VDPBase + 1
	
	lda	ZPStart + 1
	ora	#$40
	sta	VDPBase + 1
	
decompressToVRAMLoop:
	jsr	huffmunch_read
	
	sta	VDPBase

	dec	ZPStart	+ 4
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
	lda	NMICount

	cmp	ZPStart
	bmi	waitForTimerOrButtonPress
	
	rts

seedRandomNumber:
	rts

getRandomNumber:
	rts
