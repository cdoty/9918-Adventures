%include "z80r800.inc"
%include "z80().inc"
%include "tniasm.inc"
%include "CassetteDefines.inc"

%outfile "DiskHeader.bin"

%include "DiskHeader.s"

%outfile "Disk.bin"
%symfile "Burger.map"

%include "RamDefines.inc"
%include "CassetteStartup.s"
%include "..\Shared\TitleZ80.s"
%include "..\Shared\GameZ80.s"
%include "Routines.s"
%include "Interrupt.s"
%include "..\Shared\BitBusterDepackZ80IO.s"
%include "..\Shared\DataZ80.s"
RomEnd:
	db	00h
	