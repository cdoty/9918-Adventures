setMode2:
	move.b	#$80, d0						; Disable external VDP interrupt, set M2 for Graphics mode 2
	move.b	#$02, d1

	jsr		writeVDPReg

	move.b	#$81, d0						; Enable 16K VRAM, NMI interrupt, and 16x16 sprites. Disable screen.
	move.b	#$22, d1

	jsr		writeVDPReg

	move.b	#$82, d0						; Set Name Table location to 3800h, in VRAM
	move.b	#(ScreenVRAM / $400), d1

	jsr		writeVDPReg

	move.b	#$83, d0						; Set Color Table location to 2000h, in VRAM
	move.b	#((Color1VRAM / $40) | $7F), d1

	jsr		writeVDPReg

	move.b	#$84, d0						; Set Pattern Table location to 0000h, in VRAM
	move.b	#((Tile1VRAM / $800) | $03), d1

	jsr		writeVDPReg

	move.b	#$85, d0						; Set Sprite Attribute Table location to 3B00h, in VRAM
	move.b	#(SpriteAttributes / $80), d1

	jsr		writeVDPReg

	move.b	#$86, d0						; Set Sprite Pattern Table location to 1800h, in VRAM
	move.b	#(SpritePattern / $800), d1

	jsr		writeVDPReg

	move.b	#$87, d0						; Set background color to black
	move.b	#$00, d1

	jsr		writeVDPReg

	rts

turnOnScreen:
	move.b	#$81, d0						; Enable screen and NMI interrupt.
	move.b	#$62, d1

	jsr		writeVDPReg

	rts

turnOffScreen:
	move.b	#$81, d0						; Disable screen.
	move.b	#$22, d1

	jsr		writeVDPReg

	rts

; Write VDP register
; D0: Register
; D1: Value
writeVDPReg:
	move.b	VDPStatus, d2		; Reset VDP

	move.b	d1, VDPRegister		; Send value
	move.b	d0, VDPRegister		; Send register

	rts

clearVRAM:	
	move.b	#$00, d0		; Set VRAM write address to 0.
	move.b	#$40, d1

	jsr		writeVDPReg

	move.w	#$4000 - 1, d1

clearVRAMLoop:
	move.b	#$00, VDPWrite
	dbra	d1, clearVRAMLoop

	rts

; A0: Source address
; D2: Destination address
; D3: Size
transferToVRAM:
	move.b	d2, d1
	
	lsr.w	#8, d2
	move.b	d2, d0
	or		#$40, d0

	jsr		writeVDPReg

	sub.w	#1, d3

transferVRAMLoop:
	move.b	(a0)+, VDPWrite
	dbra	d3, transferVRAMLoop

	rts

clearTimer:
	move.b	#0, NMICount

	rts

; D0: Timer value
waitForTimerOrButtonPress:
	jsr		waitVBlank
	dbra	d0, waitForTimerOrButtonPress

	rts

waitVBlank:
	movem.l	d0/d1, -(a7)

waitTransferStatus:
	move.b	#$02, VDPRegister		; Send value
	move.b	#$8F, VDPRegister		; Send register

	move.b	VDPStatus, d0

	btst	#0, d0
	bne.s	waitTransferStatus

waitVBlankActive:
	move.b	#$00, VDPRegister		; Send value
	move.b	#$8F, VDPRegister		; Send register

	move.b	VDPStatus, d0

	btst	#7, d0
	beq.s	waitVBlankActive

	movem.l	(a7)+, d0/d1

	rts