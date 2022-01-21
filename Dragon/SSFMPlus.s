	include DiskDefines.inc
	include WordPakVDPDefines.inc
	include RamDefines.inc
	include GameDefines.inc
	
	include "DragonPreamble.s"
	
StartAddress:
	include "Startup.s"
	include "Routines.s"
	include "Interrupt.s"
	include "Title.s"
	include "Game.s"
	include "zx0_6809_standard.s"
	include "Data.s"

EndAddress:	
