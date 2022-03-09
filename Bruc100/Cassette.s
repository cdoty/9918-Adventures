	output	Header.bin

	include	Header.s

	output	Cassette.bin

	include CassetteDefines.inc
	include	RamDefines.inc
	include	CassetteStartup.s
	include	../Shared/TitleZ80.s
	include	../Shared/GameZ80.s
	include	Routines.s
	include	Interrupt.s
	include	../Shared/BitBusterDepackZ80IO.s
	include	../Shared/DataZ80.s
ROMEnd:
	db	00h
	