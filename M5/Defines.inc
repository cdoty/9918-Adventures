ROMStart	%equ	2000h
ROMSize		%equ	(8*1024)
RAMStart	%equ	7300h
RAMSize		%equ	D00h
StackStart	%equ	7FFFh
VDPBase		%equ	10h
VDPReadBase	%equ	VDPBase
VBIAddress	%equ	7006h		; Z80CTC Channel 3 interrupt routine address
