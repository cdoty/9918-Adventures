/;
/; tniASM HD64180 additional syntax definition file v1.0
\; by Albert Beevendorp
\;

%macro IN0 B,[%n] \%def16 00EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],B\%def16 01EDh\%def8 #1\ %endmacro
%macro TST B      \%def16 04EDh\ %endmacro
%macro IN0 C,[%n] \%def16 08EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],C\%def16 09EDh\%def8 #1\ %endmacro
%macro TST C      \%def16 0CEDh\ %endmacro
%macro IN0 D,[%n] \%def16 10EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],D\%def16 11EDh\%def8 #1\ %endmacro
%macro TST D      \%def16 14EDh\ %endmacro
%macro IN0 E,[%n] \%def16 18EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],E\%def16 19EDh\%def8 #1\ %endmacro
%macro TST E      \%def16 1CEDh\ %endmacro
%macro IN0 H,[%n] \%def16 20EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],H\%def16 21EDh\%def8 #1\ %endmacro
%macro TST H      \%def16 24EDh\ %endmacro
%macro IN0 L,[%n] \%def16 28EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],L\%def16 29EDh\%def8 #1\ %endmacro
%macro TST L      \%def16 2CEDh\ %endmacro
%macro IN0 F,[%n] \%def16 30EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],0\%def16 31EDh\%def8 #1\ %endmacro
%macro TST [HL]   \%def16 34EDh\ %endmacro
%macro IN0 A,[%n] \%def16 38EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],A\%def16 39EDh\%def8 #1\ %endmacro
%macro TST A      \%def16 3CEDh\ %endmacro
%macro MLT BC     \%def16 4CEDh\ %endmacro
%macro MLT DE     \%def16 4DEDh\ %endmacro
%macro MLT HL     \%def16 4EEDh\ %endmacro
%macro MLT SP     \%def16 4FEDh\ %endmacro
%macro TST %n     \%def16 64EDh\%def8 #1\ %endmacro
%macro TSTIO %n   \%def16 74EDh\%def8 #1\ %endmacro
%macro SLP        \%def16 76EDh\ %endmacro
%macro OTIM       \%def16 83EDh\ %endmacro
%macro OTIMR      \%def16 93EDh\ %endmacro
%macro OTDM       \%def16 8BEDh\ %endmacro
%macro OTDMR      \%def16 9BEDh\ %endmacro

%if %def(tniasm#z80parens.inc)
%macro IN0 B,(%n) \%def16 00EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),B\%def16 01EDh\%def8 #1\ %endmacro
%macro IN0 C,(%n) \%def16 08EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),C\%def16 09EDh\%def8 #1\ %endmacro
%macro IN0 D,(%n) \%def16 10EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),D\%def16 11EDh\%def8 #1\ %endmacro
%macro IN0 E,(%n) \%def16 18EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),E\%def16 19EDh\%def8 #1\ %endmacro
%macro IN0 H,(%n) \%def16 20EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),H\%def16 21EDh\%def8 #1\ %endmacro
%macro IN0 L,(%n) \%def16 28EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),L\%def16 29EDh\%def8 #1\ %endmacro
%macro IN0 F,(%n) \%def16 30EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),0\%def16 31EDh\%def8 #1\ %endmacro
%macro TST (HL)   \%def16 34EDh\ %endmacro
%macro IN0 A,(%n) \%def16 38EDh\%def8 #1\ %endmacro
%macro OUT0 (%n),A\%def16 39EDh\%def8 #1\ %endmacro
%endif
