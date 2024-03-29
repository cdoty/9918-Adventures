	output	Burger.bin
	size	ROMSize

	define	DISABLE_INTERRUPTS	; Disable interrupts during compressed data transfer
	define	RAM_16K_2000
	
	include	Defines.inc
	include	RamDefines.inc
	include	Startup.s
	include	../Shared/TitleZ80.s
	include	../Shared/GameZ80.s
	include	Routines.s
	include	Interrupt.s
	include	../Shared/BitBusterDepackZ80IO.s
	include	../Shared/DataZ80.s
