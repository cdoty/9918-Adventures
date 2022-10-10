	output	Burger.prg

	define	DISABLE_INTERRUPTS	; Disable interrupts during compressed data transfer
	define	WRITE_OFFSET_2		; Use write offset of 2
	
	include	Defines.inc
	include	RamDefines.inc
	include	Startup.s
	include	../Shared/TitleZ80.s
	include	../Shared/GameZ80.s
	include	Interrupt.s
	include	Routines.s
	include	../Shared/BitBusterDepackZ80IO.s
	include	../Shared/DataZ80.s
