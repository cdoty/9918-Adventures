	include Defines.inc
	include RamDefines.inc

	org    	ROMStart

	dc.l	__stack, __start, Default, Default, Default, Default, Default, Default
	dc.l	Default, Default, Default, Default, Default, Default, Default, Default
	dc.l	Default, Default, Default, Default, Default, Default, Default, Default
	dc.l	Default, Default, Default, Default, HBlank,  Default, VBlank,  Default
	dc.l	Default, Default, Default, Default, Default, Default, Default, Default
	dc.l	Default, Default, Default, Default, Default, Default, Default, Default
	dc.l	Default, Default, Default, Default, Default, Default, Default, Default
	dc.l	Default, Default, Default, Default, Default, Default, Default, Default	

Default:
	rte

HBlank:
	rte

VBlank:
	rte

	align	4

__start:
	; Disable interrupts
	move	#$2700, sr

	move.l	#__stack, sp

	bra		start

	include	Startup.s
	include Interrupt.s
	include	Routines.s
	include Title.s
	include	Game.s
	include Data.s
	
ROMEnd:
	org	ROMStart + ROMSize
