irqHandler:
	inc	NMICount

	rti

nmiHandler:
	rti
