	include Defines.inc
	include InputDefines.inc
	include RamDefines.inc
	
	org	ROMStart - 0x26	; Append the header data before ROMStart

	db		$1F, $A6, $DE, $BA, $CC, $13, $7D, $74
	db		$A0, $A0, $A0, $A0, $A0, $A0, $A0, $A0, $A0, $A0
	text	'BURGER'
	db		$1F, $A6, $DE, $BA, $CC, $13, $7D, $74

	dw		ROMStart
	dw		ROMEnd
	dw		start

	include "Startup.s"
	include "Interrupt.s"
	include "Routines.s"
	include "Data.s"
	include "Title.s"
	include "Game.s"
	include "../Shared/dzx0-8080.s"
ROMEnd:
	org	ROMStart + ROMSize
	