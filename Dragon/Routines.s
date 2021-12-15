; Set mode 2
setMode2:
	lda		$FF7F		; Switch to slot 1 to access the sprite board.
	anda	#$CF
	sta		$FF7F

	lda		#$80		; Disable external VDP interrupt, set M2 for Graphics mode 2
	ldb		#$02		
	jsr		writeVDPReg

	lda		#$81		; Enable 16K VRAM and 16x16 sprites. Disable screen and NMI interrupt.
	ldb		#$80		
	jsr		writeVDPReg

	lda		#$82		; Set Name Table location to 3800h, in VRAM
	ldb		#(ScreenVRAM / $400)
	jsr		writeVDPReg

	lda		#$83		; Set Color Table location to 2000h, in VRAM
	ldb		#((Color1VRAM / $40) | $7F)
	jsr		writeVDPReg

	lda		#$84		; Set Pattern Table location to 0000h, in VRAM
	ldb		#((Tile1VRAM / $800) | 3)
	jsr		writeVDPReg

	lda		#$85		; Set Sprite Attribute Table location to 3B00h, in VRAM
	ldb		#(SpriteAttributes / $80)
	jsr		writeVDPReg

	lda		#$86		; Set Sprite Pattern Table location to 1800h, in VRAM
	ldb		#(SpritePattern / $800)
	jsr		writeVDPReg

	lda		#$87		; Set background color to black
	ldb		#$00		
	jsr		writeVDPReg

	rts

; Turn on screen
turnOnScreen:
	lda		#$81		; Enable 16K VRAM, screen, and 16x16 sprites. Disable NMI interrupt.
	ldb		#$E0		
	jsr		writeVDPReg

	rts

; Turn off screen
turnOffScreen:
	lda		#$81		; Enable 16K VRAM and 16x16 sprites. Disable NMI interrupt and Screen.
	ldb		#$80		
	jsr		writeVDPReg

	rts

; Write VDP register
; A - Register
; B - Value
writeVDPReg:
	stb	VDPRegister
	sta	VDPRegister

	rts

; Clear VRAM
clearVRAM:
	ldd		#$4000			; Set address to $0000 or'ed with $4000 to set the VRAM address
	jsr		writeVDPReg
	
	ldx		#$4000			; Clear $4000 bytes
	lda		#0				; Clear value

clearVRAMLoop:
	sta		VDPWrite
	
	leax	-1, x			; Works as dex, sets flags appropriately
	bhi		clearVRAMLoop

	rts

; Transfer to VRAM
; D - VRAM location
; X - Size
; U - Data to transfer
transferToVRAM:
	ora		#$40			; Or the address with $4000
	jsr		writeVDPReg
	
transferVRAMLoop:
	lda		, u+
	sta		VDPWrite
	
	leax	-1, x			; Works as dex, sets flags appropriately
	bhi		transferVRAMLoop

	rts

;Clear timer
clearTimer:
	lda	#0
	sta	NMICount

	rts

; Wait for timer or button press
; A - VBlank count to wait on
waitForTimerOrButtonPress:
	cmpa	(NMICount)
	bhi		waitForTimerOrButtonPress
	
checkVDPStatus:				; Ensure VBlank is active before returning.
	lda		VDPStatus
	anda	#$80
	bne		checkVDPStatus
	
	rts
