turnOnScreen:
	lda	#$E2		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	sta	ZPStart
	
	lda	#$81
	sta	ZPStart + 1
	
	jsr	writeVDPReg

	rts

turnOffScreen:
	lda	#$82		; Enable 16K VRAM, and 16x16 sprites. Disable Screen and NMI interrupt
	sta	ZPStart
	
	lda	#$81
	sta	ZPStart + 1
	
	jsr	writeVDPReg

	rts

; Load data from ZPStart and register from ZPStart+1.
writeVDPReg:
	lda	VDPBase + $1000	; Ensure we are writing to the first byte

	lda	ZPStart			; Write VDP register
	sta	VDPBase + $1001

	lda	ZPStart + 1
	sta	VDPBase + $1001

	rts
	
startupDelay:
	ldx	#$FF			; Set the total number of bytes to clear
	ldy	#$FF
	
startupDelayLoop:
	dex	
	bne	startupDelayLoop
	
	dey	
	bne	startupDelayLoop

	rts

clearVRAM:
	ldx	#$00			; Set the total number of bytes to clear
	ldy	#$40
	
	lda	VDPBase + $1000	; Ensure we are writing to the first byte

	lda	#0		; Set VRAM address
	sta	VDPBase + $1001
	
	lda	#0
	ora	#$40
	sta	VDPBase + $1001
	
	lda	#0

ClearVRAMLoop:
	sta	VDPBase + $1000
	
	dex	
	bne	ClearVRAMLoop
	
	dey	
	bne	ClearVRAMLoop

	rts

; ZPStart: Source address
; ZPStart+2: VRAM address
; ZPStart+4: Size
tranferToVRAM:
	lda	VDPBase + $1000	; Ensure we are writing to the first byte

	lda	ZPStart + 2		; Set VRAM address
	sta	VDPBase + $1001
	
	lda	ZPStart + 3
	ora	#$40
	sta	VDPBase + $1001
	
	ldy	ZPStart

	lda	#0
	sta	ZPStart

TransferVRAMLoop:
	lda	(ZPStart), y
	sta	VDPBase + $1000

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
	sei

	; Always load file zero from compressed data
	ldx	#0
	ldy	#0
	
	jsr	huffmunch_load

	stx	ZPStart + 4		; Store the uncompressed size as the count
	sty	ZPStart + 5

	lda	VDPBase + $1000	; Ensure we are writing to the first byte

	lda	ZPStart			; Set VRAM address
	sta	VDPBase + $1001
	
	lda	ZPStart + 1
	ora	#$40
	sta	VDPBase + $1001
	
decompressToVRAMLoop:
	jsr	huffmunch_read
	
	sta	VDPBase + $1000

	dec	ZPStart	+ 4
	bne	decompressToVRAMLoop
	
	dec	ZPStart + 5
	bne	decompressToVRAMLoop

	cli
	
	rts

; Clear timer
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
