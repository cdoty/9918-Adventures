%outfile "Burger.bin"
%symfile "Burger.map"

%include "z80r800.inc"
%include "z80().inc"
%include "tniasm.inc"

DISABLE_INTERRUPTS	; Disable interrupts during compressed data transfer
WRITE_OFFSET_2		; Change depack routine to use an offset of 2

%include "Defines.inc"
%include "RamDefines.inc"
%include "Startup.s"
%include "..\Shared\TitleZ80.s"
%include "..\Shared\GameZ80.s"
%include "Interrupt.s"
%include "Routines.s"
%include "..\Shared\BitBusterDepackZ80Mapped.s"
%include "..\Shared\DataZ80.s"

%defb	(ROMStart+ROMSize)-%apos, FFh	; Pad to ROMSize
