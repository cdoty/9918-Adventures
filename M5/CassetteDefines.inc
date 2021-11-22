ROMStart	%equ	7300h
ROMSize		%equ	(8*1024)
RAMStart	%equ	ROMStart + ROMSize
RAMSize		%equ	0400h
StackStart	%equ	RAMStart + RAMSize
VDPBase		%equ	10h
VDPReadBase	%equ	VDPBase
VBIAddress	%equ	7006h