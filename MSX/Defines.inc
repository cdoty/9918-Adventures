ROMStart		%equ	4000h
ROMSize			%equ	(32*1024)
RAMStart		%equ	E000h	; C000h for 16kb machines and E000h 8kb machines
RAMSize			%equ	1000h
VDPBase			%equ	98h
VDPReadBase		%equ	VDPBase
InterruptHook	%equ	FD9Ah
PrimarySlotReg	%equ	A8h
ExpansionTable	%equ	FCC1h
