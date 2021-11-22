%outfile "Burger.bin"
%symfile "Burger.map"

%include "z80r800.inc"
%include "z80().inc"
%include "tniasm.inc"

%include "Defines.inc"
%include "RamDefines.inc"
%include "Startup.s"
%include "TitleZ80.s"
%include "GameZ80.s"
%include "Interrupt.s"
%include "Routines.s"
%include "..\Shared\BitBusterDepackZ80IO.s"
%include "..\Shared\DataZ80.s"

%defb	(ROMStart+ROMSize)-%apos, FFh	; Pad to ROMSize
