irq:
	jmp	$FF52
	
nmi:
	inc	NMICount

	jmp	$FF3F
