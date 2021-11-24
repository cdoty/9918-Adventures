	include Defines.inc
	include InputDefines.inc
	include RamDefines.inc
	
	org	ROMStart - 6
	dw	ROMStart
	dw	ROMEnd - 1
	dw	start

	include "Startup.s"
	include "Interrupt.s"
	include "Routines.s"
	include "Data.s"
	include "Title.s"
	include "Game.s"
ROMEnd:
	