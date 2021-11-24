	include Defines.inc
	include InputDefines.inc
	include RamDefines.inc
	
	include "Header.s"

StartRelocate:	
	rorg	$4000

	include "Startup.s"
	include "Interrupt.s"
	include "Routines.s"
	include "Data.s"
	include "Title.s"
	include "Game.s"

	rend

EndRelocate:

	org	ROMStart + ROMSize
