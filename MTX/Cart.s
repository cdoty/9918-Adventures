%include "z80r800.inc"
%include "z80().inc"
%include "tniasm.inc"

%outfile "Burger.rom"
%symfile "Burger.map"

DISABLE_INTERRUPTS:	; Disable interrupts during compressed data transfer

%include "CartDefines.inc"
%include "RamDefines.inc"
%include "CartHeader.s"
%include "CartStartup.s"
%include "..\Shared\TitleZ80.s"
%include "..\Shared\GameZ80.s"
%include "Routines.s"
%include "Interrupt.s"
%include "..\Shared\BitBusterDepackZ80IO.s"
%include "..\Shared\DataZ80.s"

%defb	(CartStart+ROMSize)-%apos, FFh	; Pad to ROMSize
