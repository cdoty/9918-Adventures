%org	RamStart

SpriteTable:
	%res8	128

SpriteOrder:
	%res8	32

WorkBuffer:
	%res8	64


%org	RamStart + 0x23
NMICount:
	%res8	1

%org	RamStart + 0x30
InputTable:	
	%res8	0x0B
