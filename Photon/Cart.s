	include Defines.inc
	include InputDefines.inc
	include RamDefines.inc
	
	include "Header.s"

	defc	SwitchBank1Rom = 1
	
StartRelocate:	
	rorg	$4000

	include "Startup.s"
	include "Interrupt.s"
	include "Routines.s"
	include "Data.s"
	include "Title.s"
	include "Game.s"
	include "../Shared/dzx0-8080.s"

	rend

EndRelocate:
	org	ROMStart + ROMSize
