%include "z80r800.inc"
%include "z80().inc"
%include "tniasm.inc"

%outfile "Boot.rom"
%symfile "Burger.map"

%include "Boot.s"
	
%outfile "Burger.rom"

%include "Defines.inc"
%include "RamDefines.inc"
%include "Startup.s"
%include "..\Shared\TitleZ80.s"
%include "..\Shared\GameZ80.s"
%include "Routines.s"
%include "Interrupt.s"
%include "..\Shared\BitBusterDepackZ80IO.s"
%include "..\Shared\DataZ80.s"

PadMax		%equ	%apos + (BlockSize - 1) - RomStart
ProgramSize	%equ	PadMax - (PadMax % BlockSize)

%defb	RomStart + ProgramSize - %apos, FFh	; Pad to the next block size
FileEnd: