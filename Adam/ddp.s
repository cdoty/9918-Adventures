	output	Boot.rom

	include	Boot.s
	
	output	Burger.rom

	include	Defines.inc
	include	RamDefines.inc
	include	Startup.s
	include	../Shared/TitleZ80.s
	include	../Shared/GameZ80.s
	include	Routines.s
	include	Interrupt.s
	include	../Shared/BitBusterDepackZ80IO.s
	include	../Shared/DataZ80.s

PadMax		= $ + (BlockSize - 1) - ROMStart
ProgramSize	= PadMax - (PadMax % BlockSize)

	ds	(ROMStart + ProgramSize) - $, 0FFh	; Pad to the next block size
FileEnd:
