ROMStart	%equ	0000h
ROMSize		%equ	(32*1024)
RAMStart	%equ	C000h		; Cartridge can use all of memory
RAMSize		%equ	4000h		; RAM size
StackStart	%equ	FFFFh
VDPBase		%equ	80h
VDPReadBase	%equ	84h
