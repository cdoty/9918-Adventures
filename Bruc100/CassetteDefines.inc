ROMStart		%equ	C000h	; Start location for 16k MSX machines, works on all others.
RAMStart		%equ	F800h
VDPBase			%equ	98h
VDPReadBase		%equ	VDPBase
InterruptHook	%equ	FD9Ah
PrimarySlotReg	%equ	A8h
ExpansionTable	%equ	FCC1h
