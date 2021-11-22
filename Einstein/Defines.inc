ROMStart	%equ	100h
RAMStart	%equ	8000h
RAMSize		%equ	200h
StackStart	%equ	RAMStart + RAMSize
VDPBase		%equ	08h
VDPReadBase	%equ	VDPBase
VBIAddress	%equ	FB06h