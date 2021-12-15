setupInterrupt:
	orcc	#$50		; Disable FIRQ and IRQ interrupts

	lda		#$7E		; Redirect disk interrupt
	sta		$0109
	ldd		#nmiHandler
	std		$010A

	lda		#$7E		; Take over VBlank interrupt
	sta		$010C
	ldd		#irqHandler
	std		$010D

	andcc	#$AF		; Enable FIRQ and IRQ interrupts

	rts

enableVBlankInterrupt:
	lda		$FF03		; Enable VBlank interrupt
	ora		#1
	sta		$FF03

	rts

disableVBlankInterrupt:
	lda		$FF03		; Disable VBlank interrupt
	anda	#$FE
	sta		$FF03

	rts

nmiHandler:
	rti

irqHandler:
	pshs	a

	inc		NMICount
	lda		$FF03
	lda		$FF02

	puls	a

	rti
