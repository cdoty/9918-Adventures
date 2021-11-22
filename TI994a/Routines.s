setMode2:
	mov		r11, r10		; Save return address

	li		r1, 0280h		; Disable external VDP interrupt, set M2 for Graphics mode 2
	bl		@writeVDPReg

	li		r1, 0A281h		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	bl		@writeVDPReg

	li		r1, 0E82h		; Set Name Table location to 3800h, in VRAM
	bl		@writeVDPReg

	li		r1, 0FF83h		; Set Color Table location to 2000h, in VRAM
	bl		@writeVDPReg

	li		r1, 0x0384		; Set Pattern Table location to 0000h, in VRAM
	bl		@writeVDPReg

	li		r1, 7685h		; Set Sprite Attribute Table location to 3800h, in VRAM
	bl		@writeVDPReg

	li		r1, 0386h		; Set Sprite Pattern Table location to 1800h, in VRAM
	bl		@writeVDPReg

	li		r1, 0087h		; Set background color to black
	bl		@writeVDPReg

	b		*r10

; Turn on screen
turnOnScreen:
	mov		r11, r10		; Save return address

	li		r1, 0E281h		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	bl		@writeVDPReg

	b		*r10

; Turn off screen
turnOffScreen:
	mov		r11, r10		; Save return address

	li		r1, 0A281h		; Enable 16K VRAM, Screen, NMI interrupt, and 16x16 sprites
	bl		@writeVDPReg

	b		*r10

; R1: Data << 8 | (Register | 0x80)
writeVDPReg:
	movb	r1, @VDPRegister	; Write VDP data`
	swpb	r1
	movb	r1, @VDPRegister 	; Write VDP register | 0x80
	
	movb	@VDPRegister, r0 	; Acknowledge interrupt

	b		*r11

clearVRAM:
	li		r0, 0			; R0 contains the value written to VRAM
	
	li		r1, 0			; Start at address 0, in VRAM
	ori		r1, 4000h		; Or with 4000h to indicate it's a VRAM write
	
	li		r2, 4000h		; Write 4000h bytes
	
	swpb	r1				; Write low byte first. movb transfer from the high byte of a word.

	movb	r1, @VDPRegister

	swpb	r1

	movb	r1, @VDPRegister
				
ClearVRAMLoop:
	movb	r0, @VDPData
	
	dec		r2
	jne		ClearVRAMLoop
	
	b		*r11

; R1: VRAM address
; R2: Source address
; R3: Number of bytes to transfer
tranferToVRAM:
	ori		r1, 4000h		; Or with 4000h to indicate it's a VRAM write
	
	swpb	r1				; Write low byte first. movb transfer from the high byte of a word.

	movb	r1, @VDPRegister

	swpb	r1

	movb	r1, @VDPRegister
				
TransferToVRAMLoop:
	movb	*r2+, @VDPData
	
	dec		r3
	jne		TransferToVRAMLoop
	
	movb	@VDPRegister, r0 	; Acknowledge interrupt

	b		*r11

clearTimer:
	clr		@NMICount
	
	b		*r11

; R1: Count to wait for (1/60th of a second)
waitForTimerOrButtonPress:
	limi	0
	
WaitForInterrupt:
	mov		@VDPStatus, r0			; Read VDP status
	coc   	@VDPInterruptFlag, r0	; Check interrupt flag
	jne		WaitForInterrupt

	mov		@NMICount, r0
	inc		r0
	mov		r0, @NMICount

	c		r0, r1
	
	jne		WaitForInterrupt
	
	b		*r11

VDPInterruptFlag:
	dc.w	8000h
	
seedRandomNumber:
	b		*r11

getRandomNumber:
	b		*r11

; Swap banks on a 74LS379 cartridge
SwapBank:
	li	r0, 04E0h
	mov	r0, @RamBankSwitch
	mov	r1, @RamBankSwitch + 2
	li	r0, 0460h
	mov	r0, @RamBankSwitch + 4
	mov	r2, @RamBankSwitch + 6
	
	b		@RamBankSwitch
