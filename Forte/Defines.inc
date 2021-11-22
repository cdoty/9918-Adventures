ROMStart		%equ	4000h
ROMSize			%equ	(48*1024 - 3400h)
RAMStart		%equ	C000h
VDPBase			%equ	98h
VDPReadBase		%equ	VDPBase
InterruptHook	%equ	FD9Ah
PrimarySlotReg	%equ	A8h
ExpansionTable	%equ	FCC1h
