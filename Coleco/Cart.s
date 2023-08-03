	output	Burger.bin
	size	ROMSize

	define	DISPLAY_COLECO_LOGO
;	define	DISABLE_INTERRUPTS

	include Defines.inc
	include RamDefines.inc
	include Startup.s
	include ../Shared/TitleZ80.s
	include ../Shared/GameZ80.s
	include Interrupt.s
	include Routines.s
	include ../Shared/BitBusterDepackZ80IO.s
	include ../Shared/DataZ80.s
