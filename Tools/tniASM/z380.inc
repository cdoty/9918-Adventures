/; 
/; tniASM Z380 definition file v1.0
\; by Patriek Lesparre
\;

%macro ADC A,A          \%def8 8Fh\ %endmacro
%macro ADC A,B          \%def8 88h\ %endmacro
%macro ADC A,C          \%def8 89h\ %endmacro
%macro ADC A,D          \%def8 8Ah\ %endmacro
%macro ADC A,E          \%def8 8Bh\ %endmacro
%macro ADC A,H          \%def8 8Ch\ %endmacro
%macro ADC A,L          \%def8 8Dh\ %endmacro
%macro ADC A,IXH        \%def16 8CDDh\ %endmacro
%macro ADC A,IXL        \%def16 8DDDh\ %endmacro
%macro ADC A,IYH        \%def16 8CFDh\ %endmacro
%macro ADC A,IYL        \%def16 8DFDh\ %endmacro
%macro ADC A,[HL]       \%def8 8Eh\ %endmacro
%macro ADC A,[IX]       \%def24 8EDDh\ %endmacro
%macro ADC A,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 8EDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 8EDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 8EDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADC A,[IY]       \%def24 8EFDh\ %endmacro
%macro ADC A,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 8EFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 8EFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 8EFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADC A,%n         \%def8 CEh,#1\ %endmacro
%macro ADC HL,BC        \%def16 4AEDh\ %endmacro
%macro ADC HL,DE        \%def16 5AEDh\ %endmacro
%macro ADC HL,HL        \%def16 6AEDh\ %endmacro
%macro ADC HL,SP        \%def16 7AEDh\ %endmacro

;Z380
%macro ADC HL,IX        \%def16 8FDDh\ %endmacro
%macro ADC HL,IY        \%def16 8FFDh\ %endmacro
%macro ADC HL,[IX]      \%def24 CEDDh\ %endmacro
%macro ADC HL,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CEDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CEDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CEDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADC HL,[IY]      \%def24 CEFDh\ %endmacro
%macro ADC HL,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CEFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CEFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CEFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADC HL,%n        \%def16 8EEDh,#1\ %endmacro

%macro ADD A,A          \%def8 87h\ %endmacro
%macro ADD A,B          \%def8 80h\ %endmacro
%macro ADD A,C          \%def8 81h\ %endmacro
%macro ADD A,D          \%def8 82h\ %endmacro
%macro ADD A,E          \%def8 83h\ %endmacro
%macro ADD A,H          \%def8 84h\ %endmacro
%macro ADD A,L          \%def8 85h\ %endmacro
%macro ADD A,IXH        \%def16 84DDh\ %endmacro
%macro ADD A,IXL        \%def16 85DDh\ %endmacro
%macro ADD A,IYH        \%def16 84FDh\ %endmacro
%macro ADD A,IYL        \%def16 85FDh\ %endmacro
%macro ADD A,[HL]       \%def8 86h\ %endmacro
%macro ADD A,[IX]       \%def24 86DDh\ %endmacro
%macro ADD A,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 86DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 86DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 86DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADD A,[IY]       \%def24 86FDh\ %endmacro
%macro ADD A,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 86FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 86FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 86FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADD A,%n         \%def8 C6h,#1\ %endmacro
%macro ADD HL,BC        \%def8 09h\ %endmacro
%macro ADD HL,DE        \%def8 19h\ %endmacro
%macro ADD HL,HL        \%def8 29h\ %endmacro
%macro ADD HL,SP        \%def8 39h\ %endmacro
%macro ADD IX,BC        \%def16 09DDh\ %endmacro
%macro ADD IX,DE        \%def16 19DDh\ %endmacro
%macro ADD IX,IX        \%def16 29DDh\ %endmacro
%macro ADD IX,SP        \%def16 39DDh\ %endmacro
%macro ADD IY,BC        \%def16 09FDh\ %endmacro
%macro ADD IY,DE        \%def16 19FDh\ %endmacro
%macro ADD IY,IY        \%def16 29FDh\ %endmacro
%macro ADD IY,SP        \%def16 39FDh\ %endmacro

;Z380
%macro ADD HL,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 C6EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 C6EDC3DDh
   %def24 #1
  %else
   %def32 C6EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro ADD SP,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 82EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 82EDC3DDh
   %def24 #1
  %else
   %def32 82EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro ADDW [IX]        \%def24 C6DDh\ %endmacro
%macro ADDW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 C6DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 C6DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 C6DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADDW [IY]        \%def24 C6FDh\ %endmacro
%macro ADDW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 C6FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 C6FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 C6FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ADDW BC          \%def16 84EDh\ %endmacro
%macro ADDW DE          \%def16 85EDh\ %endmacro
%macro ADDW HL          \%def16 87EDh\ %endmacro
%macro ADDW IX          \%def16 87DDh\ %endmacro
%macro ADDW IY          \%def16 87FDh\ %endmacro
%macro ADDW %n          \%def16 86EDh,#1\ %endmacro

%macro AND A            \%def8 A7h\ %endmacro
%macro AND B            \%def8 A0h\ %endmacro
%macro AND C            \%def8 A1h\ %endmacro
%macro AND D            \%def8 A2h\ %endmacro
%macro AND E            \%def8 A3h\ %endmacro
%macro AND H            \%def8 A4h\ %endmacro
%macro AND L            \%def8 A5h\ %endmacro
%macro AND IXH          \%def16 A4DDh\ %endmacro
%macro AND IXL          \%def16 A5DDh\ %endmacro
%macro AND IYH          \%def16 A4FDh\ %endmacro
%macro AND IYL          \%def16 A5FDh\ %endmacro
%macro AND [HL]         \%def8 A6h\ %endmacro
%macro AND [IX]         \%def24 A6DDh\ %endmacro
%macro AND [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 A6DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 A6DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 A6DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro AND [IY]         \%def24 A6FDh\ %endmacro
%macro AND [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 A6FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 A6FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 A6FDhC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro AND %n           \%def8 E6h,#1\ %endmacro

;Z380
%macro ANDW BC          \%def16 A4EDh\ %endmacro
%macro ANDW DE          \%def16 A5EDh\ %endmacro
%macro ANDW HL          \%def16 A7EDh\ %endmacro
%macro ANDW IX          \%def16 A7DDh\ %endmacro
%macro ANDW IY          \%def16 A7FDh\ %endmacro
%macro ANDW [IX]        \%def24 E6DDh\ %endmacro
%macro ANDW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 E6DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 E6DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 E6DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ANDW [IY]        \%def24 E6FDh\ %endmacro
%macro ANDW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 E6FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 E6FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 E6FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ANDW %n          \%def16 A6EDh,#1\ %endmacro
%macro BTEST    \%def16 CFEDh\ %endmacro

%macro BIT %n,A
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,47h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,B
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,40h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,C
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,41h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,D
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,42h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,E
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,43h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,H
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,44h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,L
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,45h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,[HL]
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,46h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro BIT %n,[IX]	\BIT #1,[IX+0]\ %endmacro
%macro BIT %n,[IX%n]
%if (#1 >= 0) & (#1 < 8)
  %if %valid(#2)
    %if (#2 <= 127) & (#2 >= -128)
      %def16 CBDDh
      %def8 #2
    %else
      %if (#2 <= 32767) & (#2 >= -32768)
        %def32 CBDDC3DDh
        %def16 #2
      %else
        %if (#2 <= 8388607) & (#2 >= -8388608)
          %def32 CBDDC3FDh
          %def24 #2
        %else
          %def24 0
          %warn "Relative indexing out of range"
        %endif
      %endif
    %endif
    %def8 46h+8*#1
  %else
    %def32 0
  %endif
%else
  %def32 0
  %error "Illegal bit number"
%endif
%endmacro
%macro BIT %n,[IY]	\BIT #1,[IY+0]\ %endmacro
%macro BIT %n,[IY%n]
%if (#1 >= 0) & (#1 < 8)
  %if %valid(#2)
    %if (#2 <= 127) & (#2 >= -128)
      %def16 CBFDh
      %def8 #2
    %else
      %if (#2 <= 32767) & (#2 >= -32768)
        %def32 CBFDC3DDh
        %def16 #2
      %else
        %if (#2 <= 8388607) & (#2 >= -8388608)
          %def32 CBFDC3FDh
          %def24 #2
        %else
          %def24 0
          %warn "Relative indexing out of range"
        %endif
      %endif
    %endif
    %def8 46h+8*#1
  %else
    %def32 0
  %endif
%else
  %def32 0
  %error "Illegal bit number"
%endif
%endmacro

%macro CALL NZ,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 C4h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 C4C3DDh
   %def24 #1
  %else
   %def24 C4C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL Z,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 CCh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 CCC3DDh
   %def24 #1
  %else
   %def24 CCC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL NC,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 D4h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 D4C3DDh
   %def24 #1
  %else
   %def24 D4C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL C,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 DCh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 DCC3DDh
   %def24 #1
  %else
   %def24 DCC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL PO,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 E4h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 E4C3DDh
   %def24 #1
  %else
   %def24 E4C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL PE,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 ECh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 ECC3DDh
   %def24 #1
  %else
   %def24 ECC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL NV,%n       \CALL PO,#1\ %endmacro
%macro CALL V,%n        \CALL PE,#1\ %endmacro
%macro CALL P,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 F4h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 F4C3DDh
   %def24 #1
  %else
   %def24 F4C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL M,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 FCh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 FCC3DDh
   %def24 #1
  %else
   %def24 FCC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro CALL NS,%n       \CALL P,#1\ %endmacro
%macro CALL S,%n        \CALL M,#1\ %endmacro
%macro CALL %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 CDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 CDC3DDh
   %def24 #1
  %else
   %def24 CDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro

;Z380
%macro CALR Z,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 CCEDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 CCDDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 CCFDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR PO,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 E4EDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 E4DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 E4FDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR PE,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 ECEDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 ECDDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 ECFDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR NV,%n\CALR PO,#1\ %endmacro
%macro CALR V,%n\CALR PE,#1\ %endmacro
%macro CALR P,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 F4EDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 F4DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 F4FDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR NZ,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 C4EDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 C4DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 C4FDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR NC,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 D4EDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 D4DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 D4FDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR M,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 FCEDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 FCDDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 FCFDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR NS,%n\CALR P,#1\ %endmacro
%macro CALR S,%n\CALR M,#1\ %endmacro
%macro CALR C,%n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 DCEDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 DCDDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 DCFDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CALR %n
%if %valid(#1)
 %if (#1-($+3) <= 127) & (#1-($+3) >= -128)
  %def16 CDEDh
  %def8 #1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 CDDDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 CDFDh
    %def24 #1-($+3)
   %else
    %def24 0
    %error "Relative call out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro

%macro CCF              \%def8 3Fh\ %endmacro
%macro CP A             \%def8 BFh\ %endmacro
%macro CP B             \%def8 B8h\ %endmacro
%macro CP C             \%def8 B9h\ %endmacro
%macro CP D             \%def8 BAh\ %endmacro
%macro CP E             \%def8 BBh\ %endmacro
%macro CP H             \%def8 BCh\ %endmacro
%macro CP L             \%def8 BDh\ %endmacro
%macro CP IXH           \%def16 BCDDh\ %endmacro
%macro CP IXL           \%def16 BDDDh\ %endmacro
%macro CP IYH           \%def16 BCFDh\ %endmacro
%macro CP IYL           \%def16 BDFDh\ %endmacro
%macro CP [HL]          \%def8 BEh\ %endmacro
%macro CP [IX]          \%def24 BEDDh\ %endmacro
%macro CP [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 BEDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 BEDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 BEDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CP [IY]          \%def24 BEFDh\ %endmacro
%macro CP [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 BEFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 BEFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 BEFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CP %n            \%def8 FEh,#1\ %endmacro
%macro CPD              \%def16 A9EDh\ %endmacro
%macro CPDR             \%def16 B9EDh\ %endmacro
%macro CPI              \%def16 A1EDh\ %endmacro
%macro CPIR             \%def16 B1EDh\ %endmacro
%macro CPL              \%def8 2Fh\ %endmacro
%macro CPL A            \%def8 2Fh\ %endmacro

;Z380
%macro CPL HL           \%def16 2FDDh\ %endmacro
%macro CPLW             \%def16 2FDDh\ %endmacro
%macro CPW BC           \%def16 BCEDh\ %endmacro
%macro CPW DE           \%def16 BDEDh\ %endmacro
%macro CPW HL           \%def16 BFEDh\ %endmacro
%macro CPW IX           \%def16 BFDDh\ %endmacro
%macro CPW IY           \%def16 BFFDh\ %endmacro
%macro CPW [IX]         \%def24 FEDDh\ %endmacro
%macro CPW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 FEDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 FEDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 FEDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CPW [IY]         \%def24 FEFDh\ %endmacro
%macro CPW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 FEFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 FEFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 FEFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro CPW %n           \%def16 BEEDh,#1\ %endmacro

%macro DAA              \%def8 27h\ %endmacro
%macro DEC A            \%def8 3Dh\ %endmacro
%macro DEC B            \%def8 05h\ %endmacro
%macro DEC C            \%def8 0Dh\ %endmacro
%macro DEC D            \%def8 15h\ %endmacro
%macro DEC E            \%def8 1Dh\ %endmacro
%macro DEC H            \%def8 25h\ %endmacro
%macro DEC L            \%def8 2Dh\ %endmacro
%macro DEC IXH          \%def16 25DDh\ %endmacro
%macro DEC IXL          \%def16 2DDDh\ %endmacro
%macro DEC IYH          \%def16 25FDh\ %endmacro
%macro DEC IYL          \%def16 2DFDh\ %endmacro
%macro DEC BC           \%def8 0Bh\ %endmacro
%macro DEC DE           \%def8 1Bh\ %endmacro
%macro DEC HL           \%def8 2Bh\ %endmacro
%macro DEC SP           \%def8 3Bh\ %endmacro
%macro DEC IX           \%def16 2BDDh\ %endmacro
%macro DEC IY           \%def16 2BFDh\ %endmacro
%macro DEC [HL]         \%def8 35h\ %endmacro
%macro DEC [IX]         \%def24 35DDh\ %endmacro
%macro DEC [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 35DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 35DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 35DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro DEC [IY]         \%def24 35FDh\ %endmacro
%macro DEC [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 35FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 35FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 35FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro DI               \%def8 F3h\ %endmacro

;Z380
%macro DI %n            \%def16 F3DDh\%def8 #1\ %endmacro
%macro DIVUW BC         \%def24 B8CBEDh\ %endmacro
%macro DIVUW DE         \%def24 B9CBEDh\ %endmacro
%macro DIVUW HL         \%def24 BBCBEDh\ %endmacro
%macro DIVUW IX         \%def24 BCCBEDh\ %endmacro
%macro DIVUW IY         \%def24 BDCBEDh\ %endmacro
%macro DIVUW [IX]       \%def32 BA00CBDDh\ %endmacro
%macro DIVUW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,BAh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 BAh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 BAh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro DIVUW [IY]       \%def32 BA00CBFDh\ %endmacro
%macro DIVUW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,BAh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 BAh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 BAh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro DIVUW %n         \%def24 BFCBEDh\%def16 #1\ %endmacro
%macro DJNZ %n
%if %valid(#1)
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 10h,#1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 10DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 10FDh
    %def24 #1-($+3)
   %else
    %def16 0
    %error "Relative jump out of range"
   %endif
  %endif
 %endif
%else
 %def16 0
%endif
%endmacro

%macro EI               \%def8 FBh\ %endmacro
%macro EX AF,AF'        \%def8 08h\ %endmacro
%macro EX DE,HL         \%def8 EBh\ %endmacro
%macro EX WORD DE,HL    \%def24 EBC0DDh\ %endmacro
%macro EX LONG DE,HL    \%def24 EBC0FDh\ %endmacro
%macro EX [SP],HL       \%def8 E3h\ %endmacro
%macro EX [SP],WORD HL  \%def24 E3C0DDh\ %endmacro
%macro EX [SP],LONG HL  \%def24 E3C0FDh\ %endmacro
%macro EX [SP],IX       \%def16 E3DDh\ %endmacro
%macro EX [SP],WORD IX  \%def32 E3DDC0DDh\ %endmacro
%macro EX [SP],LONG IX  \%def32 E3DDC0FDh\ %endmacro
%macro EX [SP],IY       \%def16 E3FDh\ %endmacro
%macro EX [SP],WORD IY  \%def32 E3FDC0DDh\ %endmacro
%macro EX [SP],LONG IY  \%def32 E3FDC0FDh\ %endmacro
%macro EXX              \%def8 D9h\ %endmacro

;Z380
%macro EI %n            \%def16 FBDDh\%def8 #1\ %endmacro
%macro EX A,B           \%def16 07EDh\ %endmacro
%macro EX A,C           \%def16 0FEDh\ %endmacro
%macro EX A,D           \%def16 17EDh\ %endmacro
%macro EX A,E           \%def16 1FEDh\ %endmacro
%macro EX A,H           \%def16 27EDh\ %endmacro
%macro EX A,L           \%def16 2FEDh\ %endmacro
%macro EX A,[HL]        \%def16 37EDh\ %endmacro
%macro EX A,A           \%def16 3FEDh\ %endmacro
%macro EX A,A'          \%def16 37CBh\ %endmacro
%macro EX B,B'          \%def16 30CBh\ %endmacro
%macro EX C,C'          \%def16 31CBh\ %endmacro
%macro EX D,D'          \%def16 32CBh\ %endmacro
%macro EX E,E'          \%def16 33CBh\ %endmacro
%macro EX H,H'          \%def16 34CBh\ %endmacro
%macro EX L,L'          \%def16 35CBh\ %endmacro
%macro EX BC,DE         \%def16 05EDh\ %endmacro
%macro EX WORD BC,DE    \%def32 05EDC0DDh\ %endmacro
%macro EX LONG BC,DE    \%def32 05EDC0FDh\ %endmacro
%macro EX BC,HL         \%def16 0DEDh\ %endmacro
%macro EX WORD BC,HL    \%def32 0DEDC0DDh\ %endmacro
%macro EX LONG BC,HL    \%def32 0DEDC0FDh\ %endmacro
%macro EX BC,IX         \%def16 03EDh\ %endmacro
%macro EX WORD BC,IX    \%def32 03EDC0DDh\ %endmacro
%macro EX LONG BC,IX    \%def32 03EDC0FDh\ %endmacro
%macro EX BC,IY         \%def16 0BEDh\ %endmacro
%macro EX WORD BC,IY    \%def32 0BEDC0DDh\ %endmacro
%macro EX LONG BC,IY    \%def32 0BEDC0FDh\ %endmacro
%macro EX DE,IX         \%def16 13EDh\ %endmacro
%macro EX WORD DE,IX    \%def32 13EDC0DDh\ %endmacro
%macro EX LONG DE,IX    \%def32 13EDC0FDh\ %endmacro
%macro EX DE,IY         \%def16 1BEDh\ %endmacro
%macro EX WORD DE,IY    \%def32 1BEDC0DDh\ %endmacro
%macro EX LONG DE,IY    \%def32 1BEDC0FDh\ %endmacro
%macro EX HL,IX         \%def16 33EDh\ %endmacro
%macro EX WORD HL,IX    \%def32 33EDC0DDh\ %endmacro
%macro EX LONG HL,IX    \%def32 33EDC0FDh\ %endmacro
%macro EX HL,IY         \%def16 3BEDh\ %endmacro
%macro EX WORD HL,IY    \%def32 3BEDC0DDh\ %endmacro
%macro EX LONG HL,IY    \%def32 3BEDC0FDh\ %endmacro
%macro EX IX,IY         \%def16 2BEDh\ %endmacro
%macro EX WORD IX,IY    \%def32 2BEDC0DDh\ %endmacro
%macro EX LONG IX,IY    \%def32 2BEDC0FDh\ %endmacro
%macro EX BC,BC'        \%def24 30CBEDh\ %endmacro
%macro EX WORD BC,BC'   \%def16 C0DDh\%def24 30CBEDh\ %endmacro
%macro EX LONG BC,BC'   \%def16 C0FDh\%def24 30CBEDh\ %endmacro
%macro EX DE,DE'        \%def24 31CBEDh\ %endmacro
%macro EX WORD DE,DE'   \%def16 C0DDh\%def24 31CBEDh\ %endmacro
%macro EX LONG DE,DE'   \%def16 C0FDh\%def24 31CBEDh\ %endmacro
%macro EX HL,HL'        \%def24 33CBEDh\ %endmacro
%macro EX WORD HL,HL'   \%def16 C0DDh\%def24 33CBEDh\ %endmacro
%macro EX LONG HL,HL'   \%def16 C0FDh\%def24 33CBEDh\ %endmacro
%macro EX IX,IX'        \%def24 34CBEDh\ %endmacro
%macro EX WORD IX,IX'   \%def16 C0DDh\%def24 34CBEDh\ %endmacro
%macro EX LONG IX,IX'   \%def16 C0FDh\%def24 34CBEDh\ %endmacro
%macro EX IY,IY'        \%def24 35CBEDh\ %endmacro
%macro EX WORD IY,IY'   \%def16 C0DDh\%def24 35CBEDh\ %endmacro
%macro EX LONG IY,IY'   \%def16 C0FDh\%def24 35CBEDh\ %endmacro
%macro EXALL            \%def16 D9EDh\ %endmacro
%macro EXXX             \%def16 D9DDh\ %endmacro
%macro EXXY             \%def16 D9FDh\ %endmacro
%macro EXTS A           \%def16 65EDh\ %endmacro
%macro EXTS             \%def16 65EDh\ %endmacro
%macro EXTS WORD A      \%def32 65EDC0DDh\ %endmacro
%macro EXTS WORD        \%def32 65EDC0DDh\ %endmacro
%macro EXTS LONG A      \%def32 65EDC0FDh\ %endmacro
%macro EXTS LONG        \%def32 65EDC0FDh\ %endmacro
%macro EXTS HL          \%def16 75EDh\ %endmacro
%macro EXTSW            \%def16 75EDh\ %endmacro

%macro HALT             \%def8 76h\ %endmacro
%macro IM 0             \%def16 46EDh\ %endmacro
%macro IM 1             \%def16 56EDh\ %endmacro
%macro IM 2             \%def16 5EEDh\ %endmacro

;Z380
%macro IM 3             \%def16 4EEDh\ %endmacro

%macro IN [C]           \%def16 70EDh\ %endmacro ;!!! DOES THIS EXIST?
%macro IN F,[C]         \%def16 70EDh\ %endmacro ;
%macro IN A,[C]         \%def16 78EDh\ %endmacro
%macro IN B,[C]         \%def16 40EDh\ %endmacro
%macro IN C,[C]         \%def16 48EDh\ %endmacro
%macro IN D,[C]         \%def16 50EDh\ %endmacro
%macro IN E,[C]         \%def16 58EDh\ %endmacro
%macro IN H,[C]         \%def16 60EDh\ %endmacro
%macro IN L,[C]         \%def16 68EDh\ %endmacro
%macro IN A,[%n]        \%def8 DBh,#1\ %endmacro

;Z380
%macro IN BC,[C]        \%def16 40DDh\ %endmacro
%macro IN DE,[C]        \%def16 50DDh\ %endmacro
%macro IN HL,[C]        \%def16 78DDh\ %endmacro
%macro IN0 [%n]         \%def16 30EDh\%def8 #1\ %endmacro
%macro IN0 A,[%n]       \%def16 38EDh\%def8 #1\ %endmacro
%macro IN0 B,[%n]       \%def16 00EDh\%def8 #1\ %endmacro
%macro IN0 C,[%n]       \%def16 08EDh\%def8 #1\ %endmacro
%macro IN0 D,[%n]       \%def16 10EDh\%def8 #1\ %endmacro
%macro IN0 E,[%n]       \%def16 18EDh\%def8 #1\ %endmacro
%macro IN0 H,[%n]       \%def16 20EDh\%def8 #1\ %endmacro
%macro IN0 L,[%n]       \%def16 28EDh\%def8 #1\ %endmacro
%macro INA A,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 DBEDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 DBEDC3DDh
   %def24 #1
  %else
   %def32 DBEDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro INA HL,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 DBFDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 DBFDC3DDh
   %def24 #1
  %else
   %def32 DBFDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro INDW             \%def16 EAEDh\ %endmacro
%macro INDRW            \%def16 FAEDh\ %endmacro
%macro INIW             \%def16 E2EDh\ %endmacro
%macro INIRW            \%def16 F2EDh\ %endmacro

%macro INC A            \%def8 3Ch\ %endmacro
%macro INC B    \%def8 04h\ %endmacro
%macro INC C            \%def8 0Ch\ %endmacro
%macro INC D    \%def8 14h\ %endmacro
%macro INC E            \%def8 1Ch\ %endmacro
%macro INC H    \%def8 24h\ %endmacro
%macro INC L            \%def8 2Ch\ %endmacro
%macro INC IXH  \%def16 24DDh\ %endmacro
%macro INC IXL  \%def16 2CDDh\ %endmacro
%macro INC IYH  \%def16 24FDh\ %endmacro
%macro INC IYL  \%def16 2CFDh\ %endmacro
%macro INC BC   \%def8 03h\ %endmacro
%macro INC DE   \%def8 13h\ %endmacro
%macro INC HL   \%def8 23h\ %endmacro
%macro INC SP   \%def8 33h\ %endmacro
%macro INC IX   \%def16 23DDh\ %endmacro
%macro INC IY   \%def16 23FDh\ %endmacro
%macro INC [HL]         \%def8 34h\ %endmacro
%macro INC [IX]         \%def24 34DDh\ %endmacro
%macro INC [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 34DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 34DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 34DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro INC [IY]         \%def24 34FDh\ %endmacro
%macro INC [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 34FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 34FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 34FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro IND              \%def16 AAEDh\ %endmacro
%macro INDR             \%def16 BAEDh\ %endmacro
%macro INI              \%def16 A2EDh\ %endmacro
%macro INIR             \%def16 B2EDh\ %endmacro
%macro JP [HL]          \%def8 E9h\ %endmacro
%macro JP [IX]          \%def16 E9DDh\ %endmacro
%macro JP [IY]          \%def16 E9FDh\ %endmacro
%macro JP NZ,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 C2h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 C2C3DDh
   %def24 #1
  %else
   %def24 C2C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP Z,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 CAh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 CAC3DDh
   %def24 #1
  %else
   %def24 CAC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP NC,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 D2h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 D2C3DDh
   %def24 #1
  %else
   %def24 D2C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP C,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 DAh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 DAC3DDh
   %def24 #1
  %else
   %def24 DAC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP PO,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 E2h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 E2C3DDh
   %def24 #1
  %else
   %def24 E2C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP PE,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 EAh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 EAC3DDh
   %def24 #1
  %else
   %def24 EAC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP NV,%n         \JP PO,#1\ %endmacro
%macro JP V,%n          \JP PE,#1\ %endmacro
%macro JP P,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 F2h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 F2C3DDh
   %def24 #1
  %else
   %def24 F2C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP M,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 FAh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 FAC3DDh
   %def24 #1
  %else
   %def24 FAC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro JP NS,%n         \JP P,#1\ %endmacro
%macro JP S,%n          \JP M,#1\ %endmacro
%macro JP %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 C3h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 C3C3DDh
   %def24 #1
  %else
   %def24 C3C3FDh
   %def32 #1
  %endif
 %endif
%endmacro

%macro JR Z,%n
%if %valid(#1)
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 28h,#1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 28DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 28FDh
    %def24 #1-($+3)
   %else
    %def16 0
    %error "Relative jump out of range"
   %endif
  %endif
 %endif
%else
 %def16 0
%endif
%endmacro
%macro JR NZ,%n
%if %valid(#1)
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 20h,#1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 20DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 20FDh
    %def24 #1-($+3)
   %else
    %def16 0
    %error "Relative jump out of range"
   %endif
  %endif
 %endif
%else
 %def16 0
%endif
%endmacro
%macro JR NC,%n
%if %valid(#1)
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 30h,#1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 30DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 30FDh
    %def24 #1-($+3)
   %else
    %def16 0
    %error "Relative jump out of range"
   %endif
  %endif
 %endif
%else
 %def16 0
%endif
%endmacro
%macro JR C,%n
%if %valid(#1)
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 38h,#1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 38DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 38FDh
    %def24 #1-($+3)
   %else
    %def16 0
    %error "Relative jump out of range"
   %endif
  %endif
 %endif
%else
 %def16 0
%endif
%endmacro
%macro JR %n
%if %valid(#1)
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 18h,#1-($+1)
 %else
  %if (#1-($+4) <= 32767) & (#1-($+4) >= -32768)
   %def16 18DDh
   %def16 #1-($+2)
  %else
   %if (#1-($+5) <= 8388607) & (#1-($+5) >= -8388608)
    %def16 18FDh
    %def24 #1-($+3)
   %else
    %def16 0
    %error "Relative jump out of range"
   %endif
  %endif
 %endif
%else
 %def16 0
%endif
%endmacro

%macro LD A,A           \%def8 7Fh\ %endmacro
%macro LD A,B           \%def8 78h\ %endmacro
%macro LD A,C           \%def8 79h\ %endmacro
%macro LD A,D           \%def8 7Ah\ %endmacro
%macro LD A,E           \%def8 7Bh\ %endmacro
%macro LD A,H           \%def8 7Ch\ %endmacro
%macro LD A,L           \%def8 7Dh\ %endmacro
%macro LD A,IXH         \%def16 7CDDh\ %endmacro
%macro LD A,IXL         \%def16 7DDDh\ %endmacro
%macro LD A,IYH         \%def16 7CFDh\ %endmacro
%macro LD A,IYL         \%def16 7DFDh\ %endmacro
%macro LD A,[BC]        \%def8 0Ah\ %endmacro
%macro LD A,[DE]        \%def8 1Ah\ %endmacro
%macro LD A,[HL]        \%def8 7Eh\ %endmacro
%macro LD A,[IX]        \%def24 7EDDh\ %endmacro
%macro LD A,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 7EDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 7EDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 7EDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD A,[IY]        \%def24 7EFDh\ %endmacro
%macro LD A,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 7EFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 7EFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 7EFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD A,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 3Ah
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 3AC3DDh
   %def24 #1
  %else
   %def24 3AC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD A,%n          \%def8 3Eh,#1\ %endmacro
%macro LD B,A           \%def8 47h\ %endmacro
%macro LD B,B           \%def8 40h\ %endmacro
%macro LD B,C           \%def8 41h\ %endmacro
%macro LD B,D           \%def8 42h\ %endmacro
%macro LD B,E           \%def8 43h\ %endmacro
%macro LD B,H           \%def8 44h\ %endmacro
%macro LD B,L           \%def8 45h\ %endmacro
%macro LD B,IXH         \%def16 44DDh\ %endmacro
%macro LD B,IXL         \%def16 45DDh\ %endmacro
%macro LD B,IYH         \%def16 44FDh\ %endmacro
%macro LD B,IYL         \%def16 45FDh\ %endmacro
%macro LD B,[HL]        \%def8 46h\ %endmacro
%macro LD B,[IX]        \%def24 46DDh\ %endmacro
%macro LD B,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 46DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 46DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 46DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD B,[IY]        \%def24 46FDh\ %endmacro
%macro LD B,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 46FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 46FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 46FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD B,%n          \%def8 06h,#1\ %endmacro
%macro LD C,A           \%def8 4Fh\ %endmacro
%macro LD C,B           \%def8 48h\ %endmacro
%macro LD C,C           \%def8 49h\ %endmacro
%macro LD C,D           \%def8 4Ah\ %endmacro
%macro LD C,E           \%def8 4Bh\ %endmacro
%macro LD C,H           \%def8 4Ch\ %endmacro
%macro LD C,L           \%def8 4Dh\ %endmacro
%macro LD C,IXH         \%def16 4CDDh\ %endmacro
%macro LD C,IXL         \%def16 4DDDh\ %endmacro
%macro LD C,IYH         \%def16 4CFDh\ %endmacro
%macro LD C,IYL         \%def16 4DFDh\ %endmacro
%macro LD C,[HL]        \%def8 4Eh\ %endmacro
%macro LD C,[IX]        \%def24 4EDDh\ %endmacro
%macro LD C,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 4EDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 4EDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 4EDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD C,[IY]        \%def24 4EFDh\ %endmacro
%macro LD C,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 4EFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 4EFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 4EFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD C,%n          \%def8 0Eh,#1\ %endmacro
%macro LD D,A           \%def8 57h\ %endmacro
%macro LD D,B           \%def8 50h\ %endmacro
%macro LD D,C           \%def8 51h\ %endmacro
%macro LD D,D           \%def8 52h\ %endmacro
%macro LD D,E           \%def8 53h\ %endmacro
%macro LD D,H           \%def8 54h\ %endmacro
%macro LD D,L           \%def8 55h\ %endmacro
%macro LD D,IXH         \%def16 54DDh\ %endmacro
%macro LD D,IXL         \%def16 55DDh\ %endmacro
%macro LD D,IYH         \%def16 54FDh\ %endmacro
%macro LD D,IYL         \%def16 55FDh\ %endmacro
%macro LD D,[HL]        \%def8 56h\ %endmacro
%macro LD D,[IX]        \%def24 56DDh\ %endmacro
%macro LD D,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 56DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 56DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 56DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD D,[IY]        \%def24 56FDh\ %endmacro
%macro LD D,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 56FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 56FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 56FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD D,%n          \%def8 16h,#1\ %endmacro
%macro LD E,A           \%def8 5Fh\ %endmacro
%macro LD E,B           \%def8 58h\ %endmacro
%macro LD E,C           \%def8 59h\ %endmacro
%macro LD E,D           \%def8 5Ah\ %endmacro
%macro LD E,E           \%def8 5Bh\ %endmacro
%macro LD E,H           \%def8 5Ch\ %endmacro
%macro LD E,L           \%def8 5Dh\ %endmacro
%macro LD E,IXH         \%def16 5CDDh\ %endmacro
%macro LD E,IXL         \%def16 5DDDh\ %endmacro
%macro LD E,IYH         \%def16 5CFDh\ %endmacro
%macro LD E,IYL         \%def16 5DFDh\ %endmacro
%macro LD E,[HL]        \%def8 5Eh\ %endmacro
%macro LD E,[IX]        \%def24 5EDDh\ %endmacro
%macro LD E,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 5EDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 5EDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 5EDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD E,[IY]        \%def24 5EFDh\ %endmacro
%macro LD E,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 5EFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 5EFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 5EFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD E,%n          \%def8 1Eh,#1\ %endmacro
%macro LD H,A           \%def8 67h\ %endmacro
%macro LD H,B           \%def8 60h\ %endmacro
%macro LD H,C           \%def8 61h\ %endmacro
%macro LD H,D           \%def8 62h\ %endmacro
%macro LD H,E           \%def8 63h\ %endmacro
%macro LD H,H           \%def8 64h\ %endmacro
%macro LD H,L           \%def8 65h\ %endmacro
%macro LD H,[HL]        \%def8 66h\ %endmacro
%macro LD H,[IX]        \%def24 66DDh\ %endmacro
%macro LD H,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 66DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 66DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 66DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD H,[IY]        \%def24 66FDh\ %endmacro
%macro LD H,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 66FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 66FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 66FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD H,%n          \%def8 26h,#1\ %endmacro
%macro LD L,A           \%def8 6Fh\ %endmacro
%macro LD L,B           \%def8 68h\ %endmacro
%macro LD L,C           \%def8 69h\ %endmacro
%macro LD L,D           \%def8 6Ah\ %endmacro
%macro LD L,E           \%def8 6Bh\ %endmacro
%macro LD L,H           \%def8 6Ch\ %endmacro
%macro LD L,L           \%def8 6Dh\ %endmacro
%macro LD L,[HL]        \%def8 6Eh\ %endmacro
%macro LD L,[IX]        \%def24 6EDDh\ %endmacro
%macro LD L,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 6EDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 6EDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 6EDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD L,[IY]        \%def24 6EFDh\ %endmacro
%macro LD L,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 6EFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 6EFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 6EFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD L,%n          \%def8 2Eh,#1\ %endmacro
%macro LD IXH,A         \%def16 67DDh\ %endmacro
%macro LD IXH,B         \%def16 60DDh\ %endmacro
%macro LD IXH,C         \%def16 61DDh\ %endmacro
%macro LD IXH,D         \%def16 62DDh\ %endmacro
%macro LD IXH,E         \%def16 63DDh\ %endmacro
%macro LD IXH,IXH       \%def16 64DDh\ %endmacro
%macro LD IXH,IXL       \%def16 65DDh\ %endmacro
%macro LD IXH,%n        \%def16 26DDh\%def8 #1\ %endmacro
%macro LD IXL,A         \%def16 6FDDh\ %endmacro
%macro LD IXL,B         \%def16 68DDh\ %endmacro
%macro LD IXL,C         \%def16 69DDh\ %endmacro
%macro LD IXL,D         \%def16 6ADDh\ %endmacro
%macro LD IXL,E         \%def16 6BDDh\ %endmacro
%macro LD IXL,IXH       \%def16 6CDDh\ %endmacro
%macro LD IXL,IXL       \%def16 6DDDh\ %endmacro
%macro LD IXL,%n        \%def16 2EDDh\%def8 #1\ %endmacro
%macro LD IYH,A         \%def16 67FDh\ %endmacro
%macro LD IYH,B         \%def16 60FDh\ %endmacro
%macro LD IYH,C         \%def16 61FDh\ %endmacro
%macro LD IYH,D         \%def16 62FDh\ %endmacro
%macro LD IYH,E         \%def16 63FDh\ %endmacro
%macro LD IYH,IYH       \%def16 64FDh\ %endmacro
%macro LD IYH,IYL       \%def16 65FDh\ %endmacro
%macro LD IYH,%n        \%def16 26FDh\%def8 #1\ %endmacro
%macro LD IYL,A         \%def16 6FFDh\ %endmacro
%macro LD IYL,B         \%def16 68FDh\ %endmacro
%macro LD IYL,C         \%def16 69FDh\ %endmacro
%macro LD IYL,D         \%def16 6AFDh\ %endmacro
%macro LD IYL,E         \%def16 6BFDh\ %endmacro
%macro LD IYL,IYH       \%def16 6CFDh\ %endmacro
%macro LD IYL,IYL       \%def16 6DFDh\ %endmacro
%macro LD IYL,%n        \%def16 2EFDh\%def8 #1\ %endmacro
%macro LD [BC],A        \%def8 02h\ %endmacro
%macro LD [DE],A        \%def8 12h\ %endmacro
%macro LD [HL],A        \%def8 77h\ %endmacro
%macro LD [HL],B        \%def8 70h\ %endmacro
%macro LD [HL],C        \%def8 71h\ %endmacro
%macro LD [HL],D        \%def8 72h\ %endmacro
%macro LD [HL],E        \%def8 73h\ %endmacro
%macro LD [HL],H        \%def8 74h\ %endmacro
%macro LD [HL],L        \%def8 75h\ %endmacro
%macro LD [IX],A        \%def24 77DDh\ %endmacro
%macro LD [IX],B        \%def24 70DDh\ %endmacro
%macro LD [IX],C        \%def24 71DDh\ %endmacro
%macro LD [IX],D        \%def24 72DDh\ %endmacro
%macro LD [IX],E        \%def24 73DDh\ %endmacro
%macro LD [IX],H        \%def24 74DDh\ %endmacro
%macro LD [IX],L        \%def24 75DDh\ %endmacro
%macro LD [IX%n],B
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 70DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 70DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 70DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IX%n],C
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 71DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 71DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 71DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IX%n],D
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 72DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 72DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 72DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IX%n],E
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 73DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 73DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 73DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IX%n],H
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 74DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 74DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 74DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IX%n],L
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 75DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 75DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 75DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IX%n],A
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 77DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 77DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 77DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IY],A        \%def24 77FDh\ %endmacro
%macro LD [IY],B        \%def24 70FDh\ %endmacro
%macro LD [IY],C        \%def24 71FDh\ %endmacro
%macro LD [IY],D        \%def24 72FDh\ %endmacro
%macro LD [IY],E        \%def24 73FDh\ %endmacro
%macro LD [IY],H        \%def24 74FDh\ %endmacro
%macro LD [IY],L        \%def24 75FDh\ %endmacro
%macro LD [IY%n],B
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 70FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 70FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 70FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IY%n],C
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 71FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 71FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 71FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IY%n],D
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 72FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 72FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 72FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IY%n],E
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 73FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 73FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 73FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IY%n],H
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 74FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 74FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 74FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IY%n],L
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 75FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 75FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 75FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD [IY%n],A
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 77FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 77FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 77FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro LD I,HL          \%def16 47DDh\ %endmacro
%macro LD I,WORD HL     \%def32 47DDC0DDh\ %endmacro
%macro LD I,LONG HL     \%def32 47DDC0FDh\ %endmacro
%macro LD HL,I          \%def16 57DDh\ %endmacro
%macro LD WORD HL,I     \%def32 57DDC0DDh\ %endmacro
%macro LD LONG HL,I     \%def32 57DDC0FDh\ %endmacro
%macro LD I,A           \%def16 47EDh\ %endmacro
%macro LD A,I           \%def16 57EDh\ %endmacro
%macro LD R,A           \%def16 4FEDh\ %endmacro
%macro LD A,R           \%def16 5FEDh\ %endmacro
%macro LD SP,HL         \%def8 F9h\ %endmacro
%macro LD WORD SP,HL    \%def24 F9C0DDh\ %endmacro
%macro LD LONG SP,HL    \%def24 F9C0FDh\ %endmacro
%macro LD SP,IX         \%def16 F9DDh\ %endmacro
%macro LD WORD SP,IX    \%def32 F9DDC0DDh\ %endmacro
%macro LD LONG SP,IX    \%def32 F9DDC0FDh\ %endmacro
%macro LD SP,IY         \%def16 F9FDh\ %endmacro
%macro LD WORD SP,IY    \%def32 F9FDC0DDh\ %endmacro
%macro LD LONG SP,IY    \%def32 F9FDC0FDh\ %endmacro

;Z380
%macro LD BC,BC         \%def16 02EDh\ %endmacro
%macro LD WORD BC,BC    \%def32 02EDC0DDh\ %endmacro
%macro LD LONG BC,BC    \%def32 02EDC0FDh\ %endmacro
%macro LD BC,DE         \%def16 02DDh\ %endmacro
%macro LD WORD BC,DE    \%def32 02DDC0DDh\ %endmacro
%macro LD LONG BC,DE    \%def32 02DDC0FDh\ %endmacro
%macro LD BC,HL         \%def16 02FDh\ %endmacro
%macro LD WORD BC,HL    \%def32 02FDC0DDh\ %endmacro
%macro LD LONG BC,HL    \%def32 02FDC0FDh\ %endmacro
%macro LD BC,IX         \%def16 0BDDh\ %endmacro
%macro LD WORD BC,IX    \%def32 0BDDC0DDh\ %endmacro
%macro LD LONG BC,IX    \%def32 0BDDC0FDh\ %endmacro
%macro LD BC,IY         \%def16 0BFDh\ %endmacro
%macro LD WORD BC,IY    \%def32 0BFDC0DDh\ %endmacro
%macro LD LONG BC,IY    \%def32 0BFDC0FDh\ %endmacro
%macro LD BC,[BC]       \%def16 0CDDh\ %endmacro
%macro LD WORD BC,[BC]  \%def32 0CDDC0DDh\ %endmacro
%macro LD LONG BC,[BC]  \%def32 0CDDC0FDh\ %endmacro
%macro LD BC,[DE]       \%def16 0DDDh\ %endmacro
%macro LD WORD BC,[DE]  \%def32 0DDDC0DDh\ %endmacro
%macro LD LONG BC,[DE]  \%def32 0DDDC0FDh\ %endmacro
%macro LD BC,[HL]       \%def16 0FDDh\ %endmacro
%macro LD WORD BC,[HL]  \%def32 0FDDC0DDh\ %endmacro
%macro LD LONG BC,[HL]  \%def32 0FDDC0FDh\ %endmacro
%macro LD BC,[IX]       \%def32 0300CBDDh\ %endmacro
%macro LD WORD BC,[IX]  \%def16 C0DDh\%def32 0300CBDDh\ %endmacro
%macro LD LONG BC,[IX]  \%def16 C0FDh\%def32 0300CBDDh\ %endmacro
%macro LD BC,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,03h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 03h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 03h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD BC,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,03h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 03h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 03h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG BC,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,03h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 03h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 03h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD BC,[IY]       \%def32 0300CBFDh\ %endmacro
%macro LD WORD BC,[IY]  \%def16 C0DDh\%def32 0300CBFDh\ %endmacro
%macro LD LONG BC,[IY]  \%def16 C0FDh\%def32 0300CBFDh\ %endmacro
%macro LD BC,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,03h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 03h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 03h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD BC,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,03h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 03h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 03h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG BC,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,03h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 03h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 03h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD BC,[SP]       \%def32 0100CBDDh\ %endmacro
%macro LD WORD BC,[SP]  \%def16 C0DDh\%def32 0100CBDDh\ %endmacro
%macro LD LONG BC,[SP]  \%def16 C0FDh\%def32 0100CBDDh\ %endmacro
%macro LD BC,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,01h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 01h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 01h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD BC,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,01h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 01h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 01h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG BC,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,01h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 01h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 01h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD DE,BC         \%def16 12EDh\ %endmacro
%macro LD WORD DE,BC    \%def32 12EDC0DDh\ %endmacro
%macro LD LONG DE,BC    \%def32 12EDC0FDh\ %endmacro
%macro LD DE,DE         \%def16 12DDh\ %endmacro
%macro LD WORD DE,DE    \%def32 12DDC0DDh\ %endmacro
%macro LD LONG DE,DE    \%def32 12DDC0FDh\ %endmacro
%macro LD DE,HL         \%def16 12FDh\ %endmacro
%macro LD WORD DE,HL    \%def32 12FDC0DDh\ %endmacro
%macro LD LONG DE,HL    \%def32 12FDC0FDh\ %endmacro
%macro LD DE,IX         \%def16 1BDDh\ %endmacro
%macro LD WORD DE,IX    \%def32 1BDDC0DDh\ %endmacro
%macro LD LONG DE,IX    \%def32 1BDDC0FDh\ %endmacro
%macro LD DE,IY         \%def16 1BFDh\ %endmacro
%macro LD WORD DE,IY    \%def32 1BFDC0DDh\ %endmacro
%macro LD LONG DE,IY    \%def32 1BFDC0FDh\ %endmacro
%macro LD DE,[BC]       \%def16 1CDDh\ %endmacro
%macro LD WORD DE,[BC]  \%def32 1CDDC0DDh\ %endmacro
%macro LD LONG DE,[BC]  \%def32 1CDDC0FDh\ %endmacro
%macro LD DE,[DE]       \%def16 1DDDh\ %endmacro
%macro LD WORD DE,[DE]  \%def32 1DDDC0DDh\ %endmacro
%macro LD LONG DE,[DE]  \%def32 1DDDC0FDh\ %endmacro
%macro LD DE,[HL]       \%def16 1FDDh\ %endmacro
%macro LD WORD DE,[HL]  \%def32 1FDDC0DDh\ %endmacro
%macro LD LONG DE,[HL]  \%def32 1FDDC0FDh\ %endmacro
%macro LD DE,[IX]       \%def32 1300CBDDh\ %endmacro
%macro LD WORD DE,[IX]  \%def16 C0DDh\%def32 1300CBDDh\ %endmacro
%macro LD LONG DE,[IX]  \%def16 C0FDh\%def32 1300CBDDh\ %endmacro
%macro LD DE,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,13h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 13h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 13h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD DE,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,13h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 13h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 13h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG DE,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,13h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 13h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 13h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD DE,[IY]       \%def32 1300CBFDh\ %endmacro
%macro LD WORD DE,[IY]  \%def16 C0DDh\%def32 1300CBFDh\ %endmacro
%macro LD LONG DE,[IY]  \%def16 C0FDh\%def32 1300CBFDh\ %endmacro
%macro LD DE,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,13h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 13h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 13h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD DE,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,13h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 13h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 13h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG DE,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,13h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 13h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 13h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD DE,[SP]       \%def32 1100CBDDh\ %endmacro
%macro LD WORD DE,[SP]  \%def16 C0DDh\%def32 1100CBDDh\ %endmacro
%macro LD LONG DE,[SP]  \%def16 C0fDh\%def32 1100CBDDh\ %endmacro
%macro LD DE,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,11h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 11h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 11h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD DE,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,11h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 11h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 11h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG DE,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,11h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 11h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 11h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD HL,BC         \%def16 32EDh\ %endmacro
%macro LD WORD HL,BC    \%def32 32EDC0DDh\ %endmacro
%macro LD LONG HL,BC    \%def32 32EDC0FDh\ %endmacro
%macro LD HL,DE         \%def16 32DDh\ %endmacro
%macro LD WORD HL,DE    \%def32 32DDC0DDh\ %endmacro
%macro LD LONG HL,DE    \%def32 32DDC0FDh\ %endmacro
%macro LD HL,HL         \%def16 32FDh\ %endmacro
%macro LD WORD HL,HL    \%def32 32FDC0DDh\ %endmacro
%macro LD LONG HL,HL    \%def32 32FDC0FDh\ %endmacro
%macro LD HL,IX         \%def16 3BDDh\ %endmacro
%macro LD WORD HL,IX    \%def32 3BDDC0DDh\ %endmacro
%macro LD LONG HL,IX    \%def32 3BDDC0FDh\ %endmacro
%macro LD HL,IY         \%def16 3BFDh\ %endmacro
%macro LD WORD HL,IY    \%def32 3BFDC0DDh\ %endmacro
%macro LD LONG HL,IY    \%def32 3BFDC0FDh\ %endmacro
%macro LD HL,[BC]       \%def16 3CDDh\ %endmacro
%macro LD WORD HL,[BC]  \%def32 3CDDC0DDh\ %endmacro
%macro LD LONG HL,[BC]  \%def32 3CDDC0FDh\ %endmacro
%macro LD HL,[DE]       \%def16 3DDDh\ %endmacro
%macro LD WORD HL,[DE]  \%def32 3DDDC0DDh\ %endmacro
%macro LD LONG HL,[DE]  \%def32 3DDDC0FDh\ %endmacro
%macro LD HL,[HL]       \%def16 3FDDh\ %endmacro
%macro LD WORD HL,[HL]  \%def32 3FDDC0DDh\ %endmacro
%macro LD LONG HL,[HL]  \%def32 3FDDC0FDh\ %endmacro
%macro LD HL,[IX]       \%def32 3300CBDDh\ %endmacro
%macro LD WORD HL,[IX]  \%def16 C0DDh\%def32 3300CBDDh\ %endmacro
%macro LD LONG HL,[IX]  \%def16 C0FDh\%def32 3300CBDDh\ %endmacro
%macro LD HL,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,33h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 33h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 33h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD HL,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,33h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 33h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 33h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG HL,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,33h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 33h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 33h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD HL,[IY]       \%def32 3300CBFDh\ %endmacro
%macro LD WORD HL,[IY]  \%def16 C0DDh\%def32 3300CBFDh\ %endmacro
%macro LD LONG HL,[IY]  \%def16 C0FDh\%def32 3300CBFDh\ %endmacro
%macro LD HL,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,33h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 33h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 33h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD HL,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,33h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 33h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 33h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG HL,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,33h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 33h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 33h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD HL,[SP]       \%def32 3100CBDDh\ %endmacro
%macro LD WORD HL,[SP]  \%def16 C0DDh\%def32 3100CBDDh\ %endmacro
%macro LD LONG HL,[SP]  \%def16 C0FDh\%def32 3100CBDDh\ %endmacro
%macro LD HL,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,31h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 31h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 31h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD HL,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,31h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 31h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 31h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG HL,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,31h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 31h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 31h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD IX,BC         \%def16 07DDh\ %endmacro
%macro LD WORD IX,BC    \%def32 07DDC0DDh\ %endmacro
%macro LD LONG IX,BC    \%def32 07DDC0FDh\ %endmacro
%macro LD IX,DE         \%def16 17DDh\ %endmacro
%macro LD WORD IX,DE    \%def32 17DDC0DDh\ %endmacro
%macro LD LONG IX,DE    \%def32 17DDC0FDh\ %endmacro
%macro LD IX,HL         \%def16 37DDh\ %endmacro
%macro LD WORD IX,HL    \%def32 37DDC0DDh\ %endmacro
%macro LD LONG IX,HL    \%def32 37DDC0FDh\ %endmacro
%macro LD IX,IY         \%def16 27DDh\ %endmacro
%macro LD WORD IX,IY    \%def32 27DDC0DDh\ %endmacro
%macro LD LONG IX,IY    \%def32 27DDC0FDh\ %endmacro
%macro LD IX,[BC]       \%def16 03DDh\ %endmacro
%macro LD WORD IX,[BC]  \%def32 03DDC0DDh\ %endmacro
%macro LD LONG IX,[BC]  \%def32 03DDC0FDh\ %endmacro
%macro LD IX,[DE]       \%def16 13DDh\ %endmacro
%macro LD WORD IX,[DE]  \%def32 13DDC0DDh\ %endmacro
%macro LD LONG IX,[DE]  \%def32 13DDC0FDh\ %endmacro
%macro LD IX,[HL]       \%def16 33DDh\ %endmacro
%macro LD WORD IX,[HL]  \%def32 33DDC0DDh\ %endmacro
%macro LD LONG IX,[HL]  \%def32 33DDC0FDh\ %endmacro
%macro LD IX,[IY]       \%def32 2300CBFDh\ %endmacro
%macro LD WORD IX,[IY]  \%def16 C0DDh\%def32 2300CBFDh\ %endmacro
%macro LD LONG IX,[IY]  \%def16 C0FDh\%def32 2300CBFDh\ %endmacro
%macro LD IX,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,23h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 23h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 23h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD IX,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,23h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 23h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 23h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG IX,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,23h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 23h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 23h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD IX,[SP]       \%def32 2100CBDDh\ %endmacro
%macro LD WORD IX,[SP]  \%def16 C0DDh\%def32 2100CBDDh\ %endmacro
%macro LD LONG IX,[SP]  \%def16 C0FDh\%def32 2100CBDDh\ %endmacro
%macro LD IX,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,21h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 21h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 21h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD IX,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,21h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 21h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 21h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG IX,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,21h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 21h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 21h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD IY,BC         \%def16 07FDh\ %endmacro
%macro LD WORD IY,BC    \%def32 07FDC0DDh\ %endmacro
%macro LD LONG IY,BC    \%def32 07FDC0FDh\ %endmacro
%macro LD IY,DE         \%def16 17FDh\ %endmacro
%macro LD WORD IY,DE    \%def32 17FDC0DDh\ %endmacro
%macro LD LONG IY,DE    \%def32 17FDC0FDh\ %endmacro
%macro LD IY,HL         \%def16 37FDh\ %endmacro
%macro LD WORD IY,HL    \%def32 37FDC0DDh\ %endmacro
%macro LD LONG IY,HL    \%def32 37FDC0FDh\ %endmacro
%macro LD IY,IX         \%def16 27FDh\ %endmacro
%macro LD WORD IY,IX    \%def32 27FDC0DDh\ %endmacro
%macro LD LONG IY,IX    \%def32 27FDC0FDh\ %endmacro
%macro LD IY,[BC]       \%def16 03FDh\ %endmacro
%macro LD WORD IY,[BC]  \%def32 03FDC0DDh\ %endmacro
%macro LD LONG IY,[BC]  \%def32 03FDC0FDh\ %endmacro
%macro LD IY,[DE]       \%def16 13FDh\ %endmacro
%macro LD WORD IY,[DE]  \%def32 13FDC0DDh\ %endmacro
%macro LD LONG IY,[DE]  \%def32 13FDC0FDh\ %endmacro
%macro LD IY,[HL]       \%def16 33FDh\ %endmacro
%macro LD WORD IY,[HL]  \%def32 33FDC0DDh\ %endmacro
%macro LD LONG IY,[HL]  \%def32 33FDC0FDh\ %endmacro
%macro LD IY,[IX]       \%def32 2300CBDDh\ %endmacro
%macro LD WORD IY,[IX]  \%def16 C0DDh\%def32 2300CBDDh\ %endmacro
%macro LD LONG IY,[IX]  \%def16 C0FDh\%def32 2300CBDDh\ %endmacro
%macro LD IY,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,23h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 23h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 23h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD IY,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,23h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 23h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 23h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG IY,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,23h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 23h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 23h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD IY,[SP]       \%def32 2100CBFDh\ %endmacro
%macro LD WORD IY,[SP]  \%def16 C0DDh\%def32 2100CBFDh\ %endmacro
%macro LD LONG IY,[SP]  \%def16 C0FDh\%def32 2100CBFDh\ %endmacro
%macro LD IY,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,21h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 21h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 21h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD WORD IY,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,21h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 21h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 21h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD LONG IY,[SP%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,21h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 21h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 21h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [BC],BC       \%def16 0CFDh\ %endmacro
%macro LD WORD [BC],BC  \%def32 0CFDC0DDh\ %endmacro
%macro LD LONG [BC],BC  \%def32 0CFDC0FDh\ %endmacro
%macro LD [BC],DE       \%def16 1CFDh\ %endmacro
%macro LD WORD [BC],DE  \%def32 1CFDC0DDh\ %endmacro
%macro LD LONG [BC],DE  \%def32 1CFDC0FDh\ %endmacro
%macro LD [BC],HL       \%def16 3CFDh\ %endmacro
%macro LD WORD [BC],HL  \%def32 3CFDC0DDh\ %endmacro
%macro LD LONG [BC],HL  \%def32 3CFDC0FDh\ %endmacro
%macro LD [BC],IX       \%def16 01DDh\ %endmacro
%macro LD WORD [BC],IX  \%def32 01DDC0DDh\ %endmacro
%macro LD LONG [BC],IX  \%def32 01DDC0FDh\ %endmacro
%macro LD [BC],IY       \%def16 01FDh\ %endmacro
%macro LD WORD [BC],IY  \%def32 01FDC0DDh\ %endmacro
%macro LD LONG [BC],IY  \%def32 01FDC0FDh\ %endmacro
%macro LD [DE],BC       \%def16 0DFDh\ %endmacro
%macro LD WORD [DE],BC  \%def32 0DFDC0DDh\ %endmacro
%macro LD LONG [DE],BC  \%def32 0DFDC0FDh\ %endmacro
%macro LD [DE],DE       \%def16 1DFDh\ %endmacro
%macro LD WORD [DE],DE  \%def32 1DFDC0DDh\ %endmacro
%macro LD LONG [DE],DE  \%def32 1DFDC0FDh\ %endmacro
%macro LD [DE],HL       \%def16 3DFDh\ %endmacro
%macro LD WORD [DE],HL  \%def32 3DFDC0DDh\ %endmacro
%macro LD LONG [DE],HL  \%def32 3DFDC0FDh\ %endmacro
%macro LD [DE],IX       \%def16 11DDh\ %endmacro
%macro LD WORD [DE],IX  \%def32 11DDC0DDh\ %endmacro
%macro LD LONG [DE],IX  \%def32 11DDC0FDh\ %endmacro
%macro LD [DE],IY       \%def16 11FDh\ %endmacro
%macro LD WORD [DE],IY  \%def32 11FDC0DDh\ %endmacro
%macro LD LONG [DE],IY  \%def32 11FDC0FDh\ %endmacro
%macro LD [HL],BC       \%def16 0FFDh\ %endmacro
%macro LD WORD [HL],BC  \%def32 0FFDC0DDh\ %endmacro
%macro LD LONG [HL],BC  \%def32 0FFDC0FDh\ %endmacro
%macro LD [HL],DE       \%def16 1FFDh\ %endmacro
%macro LD WORD [HL],DE  \%def32 1FFDC0DDh\ %endmacro
%macro LD LONG [HL],DE  \%def32 1FFDC0FDh\ %endmacro
%macro LD [HL],HL       \%def16 3FFDh\ %endmacro
%macro LD WORD [HL],HL  \%def32 3FFDC0DDh\ %endmacro
%macro LD LONG [HL],HL  \%def32 3FFDC0FDh\ %endmacro
%macro LD [HL],IX       \%def16 31DDh\ %endmacro
%macro LD WORD [HL],IX  \%def32 31DDC0DDh\ %endmacro
%macro LD LONG [HL],IX  \%def32 31DDC0FDh\ %endmacro
%macro LD [HL],IY       \%def16 31FDh\ %endmacro
%macro LD [HL],WORD IY  \%def32 31FDC0DDh\ %endmacro
%macro LD [HL],LONG IY  \%def32 31FDC0FDh\ %endmacro
%macro LD [IX],BC       \%def32 0B00CBDDh\ %endmacro
%macro LD [IX],WORD BC  \%def16 C0DDh\%def32 0B00CBDDh\ %endmacro
%macro LD [IX],LONG BC  \%def16 C0FDh\%def32 0B00CBDDh\ %endmacro
%macro LD [IX],DE       \%def32 1B00CBDDh\ %endmacro
%macro LD [IX],WORD DE  \%def16 C0DDh\%def32 1B00CBDDh\ %endmacro
%macro LD [IX],LONG DE  \%def16 C0FDh\%def32 1B00CBDDh\ %endmacro
%macro LD [IX],HL       \%def32 3B00CBDDh\ %endmacro
%macro LD [IX],WORD HL  \%def16 C0DDh\%def32 3B00CBDDh\ %endmacro
%macro LD [IX],LONG HL  \%def16 C0FDh\%def32 3B00CBDDh\ %endmacro
%macro LD [IX],IY       \%def32 2B00CBDDh\ %endmacro
%macro LD [IX],WORD IY  \%def16 C0DDh\%def32 2B00CBDDh\ %endmacro
%macro LD [IX],LONG IY  \%def16 C0FDh\%def32 2B00CBDDh\ %endmacro
%macro LD [IX%n],BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,0Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 0Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 0Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IX%n],WORD BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,0Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 0Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 0Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IX%n],LONG BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,0Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 0Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 0Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IX%n],DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,1Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 1Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 1Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IX%n],WORD DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,1Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 1Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 1Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IX%n],LONG DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,1Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 1Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 1Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IX%n],HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,3Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 3Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 3Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IX%n],WORD HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,3Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 3Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 3Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IX%n],LONG HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,3Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 3Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 3Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IX%n],IY
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,2Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 2Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 2Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IX%n],WORD IY
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,2Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 2Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 2Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IX%n],LONG IY
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,2Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 2Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 2Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY],BC       \%def32 0B00CBFDh\ %endmacro
%macro LD [IY],WORD BC  \%def16 C0DDh\%def32 0B00CBFDh\ %endmacro
%macro LD [IY],LONG BC  \%def16 C0FDh\%def32 0B00CBFDh\ %endmacro
%macro LD [IY],DE       \%def32 1B00CBFDh\ %endmacro
%macro LD [IY],WORD DE  \%def16 C0DDh\%def32 1B00CBFDh\ %endmacro
%macro LD [IY],LONG DE  \%def16 C0FDh\%def32 1B00CBFDh\ %endmacro
%macro LD [IY],HL       \%def32 3B00CBFDh\ %endmacro
%macro LD [IY],WORD HL  \%def16 C0DDh\%def32 3B00CBFDh\ %endmacro
%macro LD [IY],LONG HL  \%def16 C0FDh\%def32 3B00CBFDh\ %endmacro
%macro LD [IY],IX       \%def32 2B00CBFDh\ %endmacro
%macro LD [IY],WORD IX  \%def16 C0DDh\%def32 2B00CBFDh\ %endmacro
%macro LD [IY],LONG IX  \%def16 C0FDh\%def32 2B00CBFDh\ %endmacro

%macro LD [IY%n],BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,0Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 0Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 0Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],WORD BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,0Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 0Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 0Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],LONG BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,0Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 0Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 0Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,1Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 1Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 1Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IY%n],WORD DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,1Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 1Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 1Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],LONG DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,1Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 1Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 1Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,3Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 3Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 3Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IY%n],WORD HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,3Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 3Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 3Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],LONG HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,3Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 3Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 3Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],IX
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,2Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 2Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 2Bh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IY%n],WORD IX
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,2Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 2Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 2Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [IY%n],LONG IX
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,2Bh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 2Bh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 2Bh
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP],BC       \%def32 0900CBDDh\ %endmacro
%macro LD [SP],WORD BC  \%def16 C0DDh\%def32 0900CBDDh\ %endmacro
%macro LD [SP],LONG BC  \%def16 C0FDh\%def32 0900CBDDh\ %endmacro
%macro LD [SP],DE       \%def32 1900CBDDh\ %endmacro
%macro LD [SP],WORD DE  \%def16 C0DDh\%def32 1900CBDDh\ %endmacro
%macro LD [SP],LONG DE  \%def16 C0FDh\%def32 1900CBDDh\ %endmacro
%macro LD [SP],HL       \%def32 3900CBDDh\ %endmacro
%macro LD [SP],WORD HL  \%def16 C0DDh\%def32 3900CBDDh\ %endmacro
%macro LD [SP],LONG HL  \%def16 C0FDh\%def32 3900CBDDh\ %endmacro
%macro LD [SP],IX       \%def32 2900CBDDh\ %endmacro
%macro LD [SP],WORD IX  \%def16 C0DDh\%def32 2900CBDDh\ %endmacro
%macro LD [SP],LONG IX  \%def16 C0FDh\%def32 2900CBDDh\ %endmacro
%macro LD [SP],IY       \%def32 2900CBFDh\ %endmacro
%macro LD [SP],WORD IY  \%def16 C0DDh\%def32 2900CBFDh\ %endmacro
%macro LD [SP],LONG IY  \%def16 C0FDh\%def32 2900CBFDh\ %endmacro
%macro LD [SP%n],BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,09h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 09h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 09h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [SP%n],WORD BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,09h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 09h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 09h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],LONG BC
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,09h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 09h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 09h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,19h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 19h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 19h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [SP%n],WORD DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,19h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 19h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 19h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],LONG DE
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,19h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 19h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 19h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,39h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 39h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 39h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [SP%n],WORD HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,39h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 39h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 39h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],LONG HL
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,39h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 39h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 39h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],IX
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,29h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 29h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 29h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [SP%n],WORD IX
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0DDh
  %def8 #1,29h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1DDh
   %def16 #1
   %def8 29h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2DDh
    %def24 #1
    %def8 29h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],LONG IX
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBDDC0FDh
  %def8 #1,29h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC1FDh
   %def16 #1
   %def8 29h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC2FDh
    %def24 #1
    %def8 29h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],IY
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,29h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 29h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 29h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [SP%n],WORD IY
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0DDh
  %def8 #1,29h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1DDh
   %def16 #1
   %def8 29h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2DDh
    %def24 #1
    %def8 29h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro LD [SP%n],LONG IY
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def32 CBFDC0FDh
  %def8 #1,29h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC1FDh
   %def16 #1
   %def8 29h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC2FDh
    %def24 #1
    %def8 29h
   %else
    %def32 0\%def16 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro

%macro LD BC,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 4BEDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 4BEDC3DDh
   %def24 #1
  %else
   %def32 4BEDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD BC,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 4BEDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 4BEDC1DDh
   %def24 #1
  %else
   %def32 4BEDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG BC,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 4BEDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 4BEDC1FDh
   %def24 #1
  %else
   %def32 4BEDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD DE,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 5BEDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 5BEDC3DDh
   %def24 #1
  %else
   %def32 5BEDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD DE,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 5BEDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 5BEDC1DDh
   %def24 #1
  %else
   %def32 5BEDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG DE,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 5BEDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 5BEDC1FDh
   %def24 #1
  %else
   %def32 5BEDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD HL,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 2Ah
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 2AC3DDh
   %def24 #1
  %else
   %def24 2AC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD HL,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 2AC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 2AC1DDh
   %def24 #1
  %else
   %def24 2AC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG HL,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 2AC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 2AC1FDh
   %def24 #1
  %else
   %def24 2AC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD SP,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 7BEDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 7BEDC3DDh
   %def24 #1
  %else
   %def32 7BEDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD SP,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 7BEDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 7BEDC1DDh
   %def24 #1
  %else
   %def32 7BEDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG SP,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 7BEDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 7BEDC1FDh
   %def24 #1
  %else
   %def32 7BEDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD IX,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 2ADDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 2ADDC3DDh
   %def24 #1
  %else
   %def32 2ADDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD IX,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 2ADDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 2ADDC1DDh
   %def24 #1
  %else
   %def32 2ADDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG IX,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 2ADDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 2ADDC1FDh
   %def24 #1
  %else
   %def32 2ADDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD IY,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 2AFDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 2AFDC3DDh
   %def24 #1
  %else
   %def32 2AFDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD IY,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 2AFDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 2AFDC1DDh
   %def24 #1
  %else
   %def32 2AFDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG IY,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 2AFDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 2AFDC1FDh
   %def24 #1
  %else
   %def32 2AFDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD BC,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 01h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 01C3DDh
   %def24 #1
  %else
   %def24 01C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD BC,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 01C0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 01C1DDh
   %def24 #1
  %else
   %def24 01C2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG BC,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 01C0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 01C1FDh
   %def24 #1
  %else
   %def24 01C2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD DE,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 11h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 11C3DDh
   %def24 #1
  %else
   %def24 11C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD DE,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 11C0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 11C1DDh
   %def24 #1
  %else
   %def24 11C2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG DE,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 11C0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 11C1FDh
   %def24 #1
  %else
   %def24 11C2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD HL,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 21h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 21C3DDh
   %def24 #1
  %else
   %def24 21C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD HL,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 21C0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 21C1DDh
   %def24 #1
  %else
   %def24 21C2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG HL,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 21C0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 21C1FDh
   %def24 #1
  %else
   %def24 21C2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD SP,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 31h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 31C3DDh
   %def24 #1
  %else
   %def24 31C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD SP,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 31C0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 31C1DDh
   %def24 #1
  %else
   %def24 31C2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG SP,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 31C0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 31C1FDh
   %def24 #1
  %else
   %def24 31C2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD IX,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 21DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 21DDC3DDh
   %def24 #1
  %else
   %def32 21DDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD IX,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 21DDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 21DDC1DDh
   %def24 #1
  %else
   %def32 21DDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG IX,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 21DDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 21DDC1FDh
   %def24 #1
  %else
   %def32 21DDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD IY,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 21FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 21FDC3DDh
   %def24 #1
  %else
   %def32 21FDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD WORD IY,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 21FDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 21FDC1DDh
   %def24 #1
  %else
   %def32 21FDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD LONG IY,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 21FDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 21FDC1FDh
   %def24 #1
  %else
   %def32 21FDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [HL],%n       \%def8 36h,#1\ %endmacro
%macro LD [IX],%n       \%def16 36DDh\%def8 0,#1\ %endmacro
%macro LD [IX%n],%n
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 36DDh
  %def8 #1,#2
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 36DDC3DDh
   %def16 #1
   %def8 #2
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 36DDC3FDh
    %def24 #1
    %def8 #2
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [IY],%n       \%def16 36FDh\%def8 0,#1\ %endmacro
%macro LD [IY%n],%n
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 36FDh
  %def8 #1,#2
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 36FDC3DDh
   %def16 #1
   %def8 #2
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 36FDC3FDh
    %def24 #1
    %def8 #2
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro LD [%n],A
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 32h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 32C3DDh
   %def24 #1
  %else
   %def24 32C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],BC
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 43EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 43EDC3DDh
   %def24 #1
  %else
   %def32 43EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],WORD BC
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 43EDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 43EDC1DDh
   %def24 #1
  %else
   %def32 43EDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],LONG BC
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 43EDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 43EDC1FDh
   %def24 #1
  %else
   %def32 43EDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],DE
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 53EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 53EDC3DDh
   %def24 #1
  %else
   %def32 53EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],WORD DE
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 53EDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 53EDC1DDh
   %def24 #1
  %else
   %def32 53EDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],LONG DE
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 53EDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 53EDC1FDh
   %def24 #1
  %else
   %def32 53EDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],HL
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def8 22h
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 22C3DDh
   %def24 #1
  %else
   %def24 22C3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],WORD HL
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 22C0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 22C1DDh
   %def24 #1
  %else
   %def24 22C2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],LONG HL
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def24 22C0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def24 22C1FDh
   %def24 #1
  %else
   %def24 22C2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],SP
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 73EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 73EDC3DDh
   %def24 #1
  %else
   %def32 73EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],WORD SP
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 73EDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 73EDC1DDh
   %def24 #1
  %else
   %def32 73EDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],LONG SP
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 73EDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 73EDC1FDh
   %def24 #1
  %else
   %def32 73EDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],IX
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 22DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 22DDC3DDh
   %def24 #1
  %else
   %def32 22DDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],WORD IX
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 22DDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 22DDC1DDh
   %def24 #1
  %else
   %def32 22DDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],LONG IX
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 22DDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 22DDC1FDh
   %def24 #1
  %else
   %def32 22DDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],IY
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 22FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 22FDC3DDh
   %def24 #1
  %else
   %def32 22FDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],WORD IY
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 22FDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 22FDC1DDh
   %def24 #1
  %else
   %def32 22FDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LD [%n],LONG IY
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 22FDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 22FDC1FDh
   %def24 #1
  %else
   %def32 22FDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDD              \%def16 A8EDh\ %endmacro
%macro LDDR             \%def16 B8EDh\ %endmacro
%macro LDI              \%def16 A0EDh\ %endmacro
%macro LDIR             \%def16 B0EDh\ %endmacro

;Z380
%macro LDCTL A,DSR      \%def16 D0EDh\ %endmacro
%macro LDCTL A,XSR      \%def16 D0DDh\ %endmacro
%macro LDCTL A,YSR      \%def16 D0FDh\ %endmacro
%macro LDCTL HL,SR      \%def16 C0EDh\ %endmacro
%macro LDCTL WORD HL,SR \%def32 C0EDC0DDh\ %endmacro
%macro LDCTL LONG HL,SR \%def32 C0EDC0FDh\ %endmacro
%macro LDCTL SR,A       \%def16 C8DDh\ %endmacro
%macro LDCTL SR,HL      \%def16 C8EDh\ %endmacro
%macro LDCTL SR,WORD HL \%def32 C8EDC0DDh\ %endmacro
%macro LDCTL SR,LONG HL \%def32 C8EDC0FDh\ %endmacro
%macro LDCTL SR,%n      \%def16 CADDh\%def8 #1\ %endmacro
%macro LDCTL DSR,A      \%def16 D8EDh\ %endmacro
%macro LDCTL DSR,%n     \%def16 DAEDh\%def8 #1\ %endmacro
%macro LDCTL XSR,A      \%def16 D8DDh\ %endmacro
%macro LDCTL XSR,%n     \%def16 DADDh\%def8 #1\ %endmacro
%macro LDCTL YSR,A      \%def16 D8FDh\ %endmacro
%macro LDCTL YSR,%n     \%def16 DAFDh\%def8 #1\ %endmacro
%macro LDDW             \%def16 E8EDh\ %endmacro
%macro LDDW WORD        \%def32 E8EDC0DDh\ %endmacro
%macro LDDW LONG        \%def32 E8EDC0FDh\ %endmacro
%macro LDDRW            \%def16 F8EDh\ %endmacro
%macro LDDRW WORD       \%def32 F8EDC0DDh\ %endmacro
%macro LDDRW LONG       \%def32 F8EDC0FDh\ %endmacro
%macro LDIW             \%def16 E0EDh\ %endmacro
%macro LDIW WORD        \%def32 E0EDC0DDh\ %endmacro
%macro LDIW LONG        \%def32 E0EDC0FDh\ %endmacro
%macro LDIRW            \%def16 F0EDh\ %endmacro
%macro LDIRW WORD       \%def32 F0EDC0DDh\ %endmacro
%macro LDIRW LONG       \%def32 F0EDC0FDh\ %endmacro
%macro LDW [BC],WORD %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 06EDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 06EDC1DDh
   %def24 #1
  %else
   %def32 06EDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [BC],LONG %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 06EDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 06EDC1FDh
   %def24 #1
  %else
   %def32 06EDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [BC],%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 06EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 06EDC3DDh
   %def24 #1
  %else
   %def32 06EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [DE],WORD %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 16EDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 16EDC1DDh
   %def24 #1
  %else
   %def32 16EDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [DE],LONG %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 16EDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 16EDC1FDh
   %def24 #1
  %else
   %def32 16EDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [DE],%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 16EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 16EDC3DDh
   %def24 #1
  %else
   %def32 16EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [HL],WORD %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 36EDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 36EDC1DDh
   %def24 #1
  %else
   %def32 36EDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [HL],LONG %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 36EDC0FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 36EDC1FDh
   %def24 #1
  %else
   %def32 36EDC2FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro LDW [HL],%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 36EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 36EDC3DDh
   %def24 #1
  %else
   %def32 36EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro MLT BC           \%def16 4CEDh\ %endmacro
%macro MLT DE           \%def16 5CEDh\ %endmacro
%macro MLT HL           \%def16 6CEDh\ %endmacro
%macro MLT SP           \%def16 7CEDh\ %endmacro
%macro MTEST            \%def16 CFDDh\ %endmacro
%macro MULTUW BC        \%def16 98CBEDh\ %endmacro
%macro MULTUW DE        \%def16 99CBEDh\ %endmacro
%macro MULTUW HL        \%def16 9BCBEDh\ %endmacro
%macro MULTUW IX        \%def16 9CCBEDh\ %endmacro
%macro MULTUW IY        \%def16 9DCBEDh\ %endmacro
%macro MULTUW [IX]      \%def32 9A00CBDDh\ %endmacro
%macro MULTUW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,9Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 9Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 9Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro MULTUW [IY]      \%def32 9A00CBFDh\ %endmacro
%macro MULTUW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,9Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 9Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 9Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro MULTUW %n        \%def24 9FCBEDh\%def16 #1\ %endmacro
%macro MULTW BC         \%def16 90CBEDh\ %endmacro
%macro MULTW DE         \%def16 91CBEDh\ %endmacro
%macro MULTW HL         \%def16 93CBEDh\ %endmacro
%macro MULTW IX         \%def16 94CBEDh\ %endmacro
%macro MULTW IY         \%def16 95CBEDh\ %endmacro
%macro MULTW [IX]       \%def32 9200CBDDh\ %endmacro
%macro MULTW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,92h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 92h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 92h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro MULTW [IY]       \%def32 9200CBFDh\ %endmacro
%macro MULTW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,92h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 92h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 92h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro MULTW %n         \%def24 97CBEDh\%def16 #1\ %endmacro
%macro NEGW             \%def16 54EDh\ %endmacro
%macro NEG HL           \%def16 54EDh\ %endmacro

%macro NEG              \%def16 44EDh\ %endmacro
%macro NEG A            \%def16 44EDh\ %endmacro
%macro NOP              \%def8 00h\ %endmacro
%macro OR A             \%def8 B7h\ %endmacro
%macro OR B             \%def8 B0h\ %endmacro
%macro OR C             \%def8 B1h\ %endmacro
%macro OR D             \%def8 B2h\ %endmacro
%macro OR E             \%def8 B3h\ %endmacro
%macro OR H             \%def8 B4h\ %endmacro
%macro OR L             \%def8 B5h\ %endmacro
%macro OR IXH           \%def16 B4DDh\ %endmacro
%macro OR IXL           \%def16 B5DDh\ %endmacro
%macro OR IYH           \%def16 B4FDh\ %endmacro
%macro OR IYL           \%def16 B5FDh\ %endmacro
%macro OR [HL]          \%def8 B6h\ %endmacro
%macro OR [IX]          \%def24 B6DDh\ %endmacro
%macro OR [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 B6DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 B6DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 B6DDC3FDh
    %def24 #1
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0\%def16 0
%endif
%endmacro
%macro OR [IY]          \%def24 B6FDh\ %endmacro
%macro OR [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 B6FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 B6FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 B6FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro OR %n            \%def8 F6h,#1\ %endmacro

;Z380
%macro ORW BC           \%def16 B4EDh\ %endmacro
%macro ORW DE           \%def16 B5EDh\ %endmacro
%macro ORW HL           \%def16 B7EDh\ %endmacro
%macro ORW IX           \%def16 B7DDh\ %endmacro
%macro ORW IY           \%def16 B7FDh\ %endmacro
%macro ORW [IX]         \%def24 F6DDh\ %endmacro
%macro ORW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 F6DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 F6DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 F6DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ORW [IY]         \%def24 F6FDh\ %endmacro
%macro ORW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 F6FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 F6FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 F6FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro ORW %n           \%def16 B6EDh,#1\ %endmacro
%macro OTDM             \%def16 8BEDh\ %endmacro
%macro OTDMR            \%def16 9BEDh\ %endmacro
%macro OTIM             \%def16 83EDh\ %endmacro
%macro OTIMR            \%def16 93EDh\ %endmacro
%macro OTDRW            \%def16 FBEDh\ %endmacro
%macro OTIRW            \%def16 F3EDh\ %endmacro
%macro OUTDW            \%def16 EBEDh\ %endmacro
%macro OUTIW            \%def16 E3EDh\ %endmacro

%macro OTDR             \%def16 BBEDh\ %endmacro
%macro OTIR             \%def16 B3EDh\ %endmacro
%macro OUTD             \%def16 ABEDh\ %endmacro
%macro OUTI             \%def16 A3EDh\ %endmacro
%macro OUT [C],A        \%def16 79EDh\ %endmacro
%macro OUT [C],B        \%def16 41EDh\ %endmacro
%macro OUT [C],C        \%def16 49EDh\ %endmacro
%macro OUT [C],D        \%def16 51EDh\ %endmacro
%macro OUT [C],E        \%def16 59EDh\ %endmacro
%macro OUT [C],H        \%def16 61EDh\ %endmacro
%macro OUT [C],L        \%def16 69EDh\ %endmacro

;Z380
%macro OUT [C],%n       \%def16 71EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],A      \%def16 39EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],B      \%def16 01EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],C      \%def16 09EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],D      \%def16 11EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],E      \%def16 19EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],H      \%def16 21EDh\%def8 #1\ %endmacro
%macro OUT0 [%n],L      \%def16 29EDh\%def8 #1\ %endmacro
%macro OUTA [%n],A
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 D3EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 D3EDC3DDh
   %def24 #1
  %else
   %def32 D3EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro OUTA [%n],HL
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 D3FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 D3FDC3DDh
   %def24 #1
  %else
   %def32 D3FDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro OUTW [C],BC      \%def16 41DDh\ %endmacro
%macro OUTW [C],DE      \%def16 51DDh\ %endmacro
%macro OUTW [C],HL      \%def16 79DDh\ %endmacro
%macro OUTW [C],%n      \%def16 79FDh,#1\ %endmacro
%macro OUT [C],BC       \%def16 41DDh\ %endmacro
%macro OUT [C],DE       \%def16 51DDh\ %endmacro
%macro OUT [C],HL       \%def16 79DDh\ %endmacro

%macro OUT [%n],A       \%def8 D3h,#1\ %endmacro
%macro POP AF           \%def8 F1h\ %endmacro
%macro POP WORD AF      \%def24 F1C0DDh\ %endmacro
%macro POP LONG AF      \%def24 F1C0FDh\ %endmacro
%macro POP BC           \%def8 C1h\ %endmacro
%macro POP WORD BC      \%def24 C1C0DDh\ %endmacro
%macro POP LONG BC      \%def24 C1C0FDh\ %endmacro
%macro POP DE           \%def8 D1h\ %endmacro
%macro POP WORD DE      \%def24 D1C0DDh\ %endmacro
%macro POP LONG DE      \%def24 D1C0FDh\ %endmacro
%macro POP HL           \%def8 E1h\ %endmacro
%macro POP WORD HL      \%def24 E1C0DDh\ %endmacro
%macro POP LONG HL      \%def24 E1C0FDh\ %endmacro
%macro POP IX           \%def16 E1DDh\ %endmacro
%macro POP WORD IX      \%def32 E1DDC0DDh\ %endmacro
%macro POP LONG IX      \%def32 E1DDC0FDh\ %endmacro
%macro POP IY           \%def16 E1FDh\ %endmacro
%macro POP WORD IY      \%def32 E1FDC0DDh\ %endmacro
%macro POP LONG IY      \%def32 E1FDC0FDh\ %endmacro
%macro PUSH AF          \%def8 F5h\ %endmacro
%macro PUSH WORD AF     \%def24 F5C0DDh\ %endmacro
%macro PUSH LONG AF     \%def24 F5C0FDh\ %endmacro
%macro PUSH BC          \%def8 C5h\ %endmacro
%macro PUSH WORD BC     \%def24 C5C0DDh\ %endmacro
%macro PUSH LONG BC     \%def24 C5C0FDh\ %endmacro
%macro PUSH DE          \%def8 D5h\ %endmacro
%macro PUSH WORD DE     \%def24 D5C0DDh\ %endmacro
%macro PUSH LONG DE     \%def24 D5C0FDh\ %endmacro
%macro PUSH HL          \%def8 E5h\ %endmacro
%macro PUSH WORD HL     \%def24 E5C0DDh\ %endmacro
%macro PUSH LONG HL     \%def24 E5C0FDh\ %endmacro
%macro PUSH IX          \%def16 E5DDh\ %endmacro
%macro PUSH WORD IX     \%def32 E5DDC0DDh\ %endmacro
%macro PUSH LONG IX     \%def32 E5DDC0FDh\ %endmacro
%macro PUSH IY          \%def16 E5FDh\ %endmacro
%macro PUSH WORD IY     \%def32 E5FDC0DDh\ %endmacro
%macro PUSH LONG IY     \%def32 E5FDC0FDh\ %endmacro

;Z380
%macro PUSH SR          \%def16 C5EDh\ %endmacro
%macro PUSH WORD SR     \%def32 C5EDC0DDh\ %endmacro
%macro PUSH LONG SR     \%def32 C5EDC0FDh\ %endmacro
%macro POP SR           \%def16 C1EDh\ %endmacro
%macro POP WORD SR      \%def32 C1EDC0DDh\ %endmacro
%macro POP LONG SR      \%def32 C1EDC0FDh\ %endmacro
%macro PUSH WORD %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 F5FDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 F5FDC1DDh
   %def24 #1
  %else
   %def32 F5FDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro PUSH LONG %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def32 F5FDC0DDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 F5FDC1DDh
   %def24 #1
  %else
   %def32 F5FDC2DDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro PUSH %n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 F5FDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 F5FDC3DDh
   %def24 #1
  %else
   %def32 F5FDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro RESC LCK         \%def16 FFEDh\ %endmacro
%macro RESC LW          \%def16 FFDDh\ %endmacro

%macro RES %n,A
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,87h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,B
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,80h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,C
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,81h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,D
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,82h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,E
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,83h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,H
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,84h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,L
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,85h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,[HL]
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,86h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro RES %n,[IX]	\RES #1,[IX+0]\ %endmacro
%macro RES %n,[IX%n]
%if (#1 >= 0) & (#1 < 8)
  %if %valid(#2)
    %if (#2 <= 127) & (#2 >= -128)
      %def16 CBDDh
      %def8 #2
    %else
      %if (#2 <= 32767) & (#2 >= -32768)
        %def32 CBDDC3DDh
        %def16 #2
      %else
        %if (#2 <= 8388607) & (#2 >= -8388608)
          %def32 CBDDC3FDh
          %def24 #2
        %else
          %def24 0
          %warn "Relative indexing out of range"
        %endif
      %endif
    %endif
    %def8 86h+8*#1
  %else
    %def32 0
  %endif
%else
  %def32 0
  %error "Illegal bit number"
%endif
%endmacro
%macro RES %n,[IY]	\RES #1,[IY+0]\ %endmacro
%macro RES %n,[IY%n]
%if (#1 >= 0) & (#1 < 8)
  %if %valid(#2)
    %if (#2 <= 127) & (#2 >= -128)
      %def16 CBFDh
      %def8 #2
    %else
      %if (#2 <= 32767) & (#2 >= -32768)
        %def32 CBFDC3DDh
        %def16 #2
      %else
        %if (#2 <= 8388607) & (#2 >= -8388608)
          %def32 CBFDC3FDh
          %def24 #2
        %else
          %def24 0
          %warn "Relative indexing out of range"
        %endif
      %endif
    %endif
    %def8 86h+8*#1
  %else
    %def32 0
  %endif
%else
  %def32 0
  %error "Illegal bit number"
%endif
%endmacro

%macro RET NZ           \%def8 C0h\ %endmacro
%macro RET Z            \%def8 C8h\ %endmacro
%macro RET NC           \%def8 D0h\ %endmacro
%macro RET C            \%def8 D8h\ %endmacro
%macro RET PO           \%def8 E0h\ %endmacro
%macro RET PE           \%def8 E8h\ %endmacro
%macro RET NV           \%def8 E0h\ %endmacro
%macro RET V            \%def8 E8h\ %endmacro
%macro RET P            \%def8 F0h\ %endmacro
%macro RET M            \%def8 F8h\ %endmacro
%macro RET NS           \%def8 F0h\ %endmacro
%macro RET S            \%def8 F8h\ %endmacro
%macro RET              \%def8 C9h\ %endmacro
%macro RETB             \%def16 55EDh\ %endmacro
%macro RETI             \%def16 4DEDh\ %endmacro
%macro RETN             \%def16 45EDh\ %endmacro
%macro RL A             \%def16 17CBh\ %endmacro
%macro RL B             \%def16 10CBh\ %endmacro
%macro RL C             \%def16 11CBh\ %endmacro
%macro RL D             \%def16 12CBh\ %endmacro
%macro RL E             \%def16 13CBh\ %endmacro
%macro RL H             \%def16 14CBh\ %endmacro
%macro RL L             \%def16 15CBh\ %endmacro
%macro RL [HL]          \%def16 16CBh\ %endmacro
%macro RL [IX]          \%def32 1600CBDDh\ %endmacro
%macro RL [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,16h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 16h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 16h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RL [IY]          \%def32 1600CBFDh\ %endmacro
%macro RL [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,16h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 16h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 16h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RLA              \%def8 17h\ %endmacro
%macro RLCA             \%def8 07h\ %endmacro
%macro RLC A            \%def16 07CBh\ %endmacro
%macro RLC B            \%def16 00CBh\ %endmacro
%macro RLC C            \%def16 01CBh\ %endmacro
%macro RLC D            \%def16 02CBh\ %endmacro
%macro RLC E            \%def16 03CBh\ %endmacro
%macro RLC H            \%def16 04CBh\ %endmacro
%macro RLC L            \%def16 05CBh\ %endmacro
%macro RLC [HL]         \%def16 06CBh\ %endmacro
%macro RLC [IX]         \%def32 0600CBDDh\ %endmacro
%macro RLC [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,06h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 06h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 06h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RLC [IY]         \%def32 0600CBFDh\ %endmacro
%macro RLC [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,06h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 06h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 06h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RLD              \%def16 6FEDh\ %endmacro

;Z380
%macro RLW BC           \%def24 10CBEDh\ %endmacro
%macro RLW DE           \%def24 11CBEDh\ %endmacro
%macro RLW HL           \%def24 13CBEDh\ %endmacro
%macro RLW IX           \%def24 14CBEDh\ %endmacro
%macro RLW IY           \%def24 15CBEDh\ %endmacro
%macro RLW [HL]         \%def24 12CBEDh\ %endmacro
%macro RLW [IX]         \%def32 1200CBDDh\ %endmacro
%macro RLW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,12h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 12h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 12h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RLW [IY]         \%def32 1200CBFDh\ %endmacro
%macro RLW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,12h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 12h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 12h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RLCW BC          \%def24 00CBEDh\ %endmacro
%macro RLCW DE          \%def24 01CBEDh\ %endmacro
%macro RLCW HL          \%def24 03CBEDh\ %endmacro
%macro RLCW IX          \%def24 04CBEDh\ %endmacro
%macro RLCW IY          \%def24 05CBEDh\ %endmacro
%macro RLCW [HL]        \%def24 02CBEDh\ %endmacro
%macro RLCW [IX]        \%def32 0200CBDDh\ %endmacro
%macro RLCW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,02h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 02h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 02h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RLCW [IY]        \%def32 0200CBFDh\ %endmacro
%macro RLCW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,02h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 02h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 02h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro

%macro RR A             \%def16 1FCBh\ %endmacro
%macro RR B             \%def16 18CBh\ %endmacro
%macro RR C             \%def16 19CBh\ %endmacro
%macro RR D             \%def16 1ACBh\ %endmacro
%macro RR E             \%def16 1BCBh\ %endmacro
%macro RR H             \%def16 1CCBh\ %endmacro
%macro RR L             \%def16 1DCBh\ %endmacro
%macro RR [HL]          \%def16 1ECBh\ %endmacro
%macro RR [IX]          \%def32 1E00CBDDh\ %endmacro
%macro RR [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,1Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 1Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 1Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RR [IY]          \%def32 1E00CBFDh\ %endmacro
%macro RR [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,1Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 1Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 1Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RRA              \%def8 1Fh\ %endmacro
%macro RRCA             \%def8 0Fh\ %endmacro
%macro RRC A            \%def16 0FCBh\ %endmacro
%macro RRC B            \%def16 08CBh\ %endmacro
%macro RRC C            \%def16 09CBh\ %endmacro
%macro RRC D            \%def16 0ACBh\ %endmacro
%macro RRC E            \%def16 0BCBh\ %endmacro
%macro RRC H            \%def16 0CCBh\ %endmacro
%macro RRC L            \%def16 0DCBh\ %endmacro
%macro RRC [HL]         \%def16 0ECBh\ %endmacro
%macro RRC [IX]         \%def32 0E00CBDDh\ %endmacro
%macro RRC [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,0Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 0Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 0Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RRC [IY]         \%def32 0E00CBFDh\ %endmacro
%macro RRC [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,0Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 0Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 0Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RRD              \%def16 67EDh\ %endmacro

;Z380
%macro RRW BC           \%def24 08CBEDh\ %endmacro
%macro RRW DE           \%def24 09CBEDh\ %endmacro
%macro RRW HL           \%def24 0BCBEDh\ %endmacro
%macro RRW IX           \%def24 0CCBEDh\ %endmacro
%macro RRW IY           \%def24 0DCBEDh\ %endmacro
%macro RRW [HL]         \%def24 0ACBEDh\ %endmacro
%macro RRW [IX]         \%def32 0A00CBDDh\ %endmacro
%macro RRW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,0Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 0Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 0Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RRW [IY]         \%def32 0A00CBFDh\ %endmacro
%macro RRW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,0Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 0Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 0Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RRCW BC          \%def24 18CBEDh\ %endmacro
%macro RRCW DE          \%def24 19CBEDh\ %endmacro
%macro RRCW HL          \%def24 1BCBEDh\ %endmacro
%macro RRCW IX          \%def24 1CCBEDh\ %endmacro
%macro RRCW IY          \%def24 1DCBEDh\ %endmacro
%macro RRCW [HL]        \%def24 1ACBEDh\ %endmacro
%macro RRCW [IX]        \%def32 1A00CBDDh\ %endmacro
%macro RRCW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,1Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 1Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 1Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro RRCW [IY]        \%def32 1A00CBFDh\ %endmacro
%macro RRCW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,1Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 1Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 1Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro

%macro RST %n
  %if #1 & C7h
    %error "Illegal RST"
    %def8 0
  %else
    %def8 C7h|#1
  %endif
%endmacro

%macro SBC A,A  \%def8 9Fh\ %endmacro
%macro SBC A,B  \%def8 98h\ %endmacro
%macro SBC A,C  \%def8 99h\ %endmacro
%macro SBC A,D  \%def8 9Ah\ %endmacro
%macro SBC A,E  \%def8 9Bh\ %endmacro
%macro SBC A,H  \%def8 9Ch\ %endmacro
%macro SBC A,L  \%def8 9Dh\ %endmacro
%macro SBC A,IXH        \%def16 9CDDh\ %endmacro
%macro SBC A,IXL        \%def16 9DDDh\ %endmacro
%macro SBC A,IYH        \%def16 9CFDh\ %endmacro
%macro SBC A,IYL        \%def16 9DFDh\ %endmacro
%macro SBC A,[HL]       \%def8 9Eh\ %endmacro
%macro SBC A,[IX]       \%def24 9EDDh\ %endmacro
%macro SBC A,[IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 9EDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 9EDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 9EDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SBC A,[IY]       \%def24 9EFDh\ %endmacro
%macro SBC A,[IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 9EFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 9EFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 9EFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SBC A,%n         \%def8 DEh,#1\ %endmacro
%macro SBC HL,BC        \%def16 42EDh\ %endmacro
%macro SBC HL,DE        \%def16 52EDh\ %endmacro
%macro SBC HL,HL        \%def16 62EDh\ %endmacro
%macro SBC HL,SP        \%def16 72EDh\ %endmacro

;Z380
%macro SBCW BC          \%def16 9CEDh\ %endmacro
%macro SBCW DE          \%def16 9DEDh\ %endmacro
%macro SBCW HL          \%def16 9FEDh\ %endmacro
%macro SBCW IX          \%def16 9FDDh\ %endmacro
%macro SBCW IY          \%def16 9FFDh\ %endmacro
%macro SBCW [IX]        \%def24 DEDDh\ %endmacro
%macro SBCW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 DEDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 DEDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 DEDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SBCW [IY]        \%def24 DEFDh\ %endmacro
%macro SBCW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 DEFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 DEFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 DEFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SBCW %n          \%def16 9EEDh,#1\ %endmacro

%macro SCF              \%def8 37h\ %endmacro

%macro SET %n,A
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C7h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,B
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C0h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,C
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C1h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,D
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C2h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,E
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C3h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,H
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C4h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,L
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C5h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,[HL]
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C6h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
%macro SET %n,[IX]	\SET #1,[IX+0]\ %endmacro
%macro SET %n,[IX%n]
%if (#1 >= 0) & (#1 < 8)
  %if %valid(#2)
    %if (#2 <= 127) & (#2 >= -128)
      %def16 CBDDh
      %def8 #2
    %else
      %if (#2 <= 32767) & (#2 >= -32768)
        %def32 CBDDC3DDh
        %def16 #2
      %else
        %if (#2 <= 8388607) & (#2 >= -8388608)
          %def32 CBDDC3FDh
          %def24 #2
        %else
          %def24 0
          %warn "Relative indexing out of range"
        %endif
      %endif
    %endif
    %def8 C6h+8*#1
  %else
    %def32 0
  %endif
%else
  %def32 0
  %error "Illegal bit number"
%endif
%endmacro
%macro SET %n,[IY]	\SET #1,[IY+0]\ %endmacro
%macro SET %n,[IY%n]
%if (#1 >= 0) & (#1 < 8)
  %if %valid(#2)
    %if (#2 <= 127) & (#2 >= -128)
      %def16 CBFDh
      %def8 #2
    %else
      %if (#2 <= 32767) & (#2 >= -32768)
        %def32 CBFDC3DDh
        %def16 #2
      %else
        %if (#2 <= 8388607) & (#2 >= -8388608)
          %def32 CBFDC3FDh
          %def24 #2
        %else
          %def24 0
          %warn "Relative indexing out of range"
        %endif
      %endif
    %endif
    %def8 C6h+8*#1
  %else
    %def32 0
  %endif
%else
  %def32 0
  %error "Illegal bit number"
%endif
%endmacro

%macro SETC LCK         \%def16 F7EDh\ %endmacro
%macro SETC LW          \%def16 F7DDh\ %endmacro
%macro SETC XM          \%def16 F7FDh\ %endmacro

%macro SLA A            \%def16 27CBh\ %endmacro
%macro SLA B            \%def16 20CBh\ %endmacro
%macro SLA C            \%def16 21CBh\ %endmacro
%macro SLA D            \%def16 22CBh\ %endmacro
%macro SLA E            \%def16 23CBh\ %endmacro
%macro SLA H            \%def16 24CBh\ %endmacro
%macro SLA L            \%def16 25CBh\ %endmacro
%macro SLA [HL]         \%def16 26CBh\ %endmacro
%macro SLA [IX]         \%def32 2600CBDDh\ %endmacro
%macro SLA [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,26h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 26h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 26h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SLA [IY]         \%def32 2600CBFDh\ %endmacro
%macro SLA [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,26h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 26h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 26h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRA A            \%def16 2FCBh\ %endmacro
%macro SRA B            \%def16 28CBh\ %endmacro
%macro SRA C            \%def16 29CBh\ %endmacro
%macro SRA D            \%def16 2ACBh\ %endmacro
%macro SRA E            \%def16 2BCBh\ %endmacro
%macro SRA H            \%def16 2CCBh\ %endmacro
%macro SRA L            \%def16 2DCBh\ %endmacro
%macro SRA [HL]         \%def16 2ECBh\ %endmacro
%macro SRA [IX]         \%def32 2E00CBDDh\ %endmacro
%macro SRA [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,2Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 2Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 2Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRA [IY]         \%def32 2E00CBFDh\ %endmacro
%macro SRA [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,2Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 2Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 2Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRL A            \%def16 3FCBh\ %endmacro
%macro SRL B            \%def16 38CBh\ %endmacro
%macro SRL C            \%def16 39CBh\ %endmacro
%macro SRL D            \%def16 3ACBh\ %endmacro
%macro SRL E            \%def16 3BCBh\ %endmacro
%macro SRL H            \%def16 3CCBh\ %endmacro
%macro SRL L            \%def16 3DCBh\ %endmacro
%macro SRL [HL]         \%def16 3ECBh\ %endmacro
%macro SRL [IX]         \%def32 3E00CBDDh\ %endmacro
%macro SRL [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,3Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 3Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 3Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRL [IY]         \%def32 3E00CBFDh\ %endmacro
%macro SRL [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,3Eh
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 3Eh
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 3Eh
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro

;Z380
%macro SLP              \%def16 76EDh\ %endmacro
%macro SLAW BC          \%def24 20CBEDh\ %endmacro
%macro SLAW DE          \%def24 21CBEDh\ %endmacro
%macro SLAW HL          \%def24 23CBEDh\ %endmacro
%macro SLAW IX          \%def24 24CBEDh\ %endmacro
%macro SLAW IY          \%def24 25CBEDh\ %endmacro
%macro SLAW [HL]        \%def24 22CBEDh\ %endmacro
%macro SLAW [IX]        \%def32 2200CBDDh\ %endmacro
%macro SLAW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,22h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 22h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 22h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SLAW [IY]        \%def32 2200CBFDh\ %endmacro
%macro SLAW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,22h
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 22h
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 22h
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRAW BC          \%def24 28CBEDh\ %endmacro
%macro SRAW DE          \%def24 29CBEDh\ %endmacro
%macro SRAW HL          \%def24 2BCBEDh\ %endmacro
%macro SRAW IX          \%def24 2CCBEDh\ %endmacro
%macro SRAW IY          \%def24 2DCBEDh\ %endmacro
%macro SRAW [HL]        \%def24 2ACBEDh\ %endmacro
%macro SRAW [IX]        \%def32 2A00CBDDh\ %endmacro
%macro SRAW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,2Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 2Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 2Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRAW [IY]        \%def32 2A00CBFDh\ %endmacro
%macro SRAW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,2Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 2Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 2Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRLW BC          \%def24 38CBEDh\ %endmacro
%macro SRLW DE          \%def24 39CBEDh\ %endmacro
%macro SRLW HL          \%def24 3BCBEDh\ %endmacro
%macro SRLW IX          \%def24 3CCBEDh\ %endmacro
%macro SRLW IY          \%def24 3DCBEDh\ %endmacro
%macro SRLW [HL]        \%def24 3ACBEDh\ %endmacro
%macro SRLW [IX]        \%def32 3A00CBDDh\ %endmacro
%macro SRLW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBDDh
  %def8 #1,3Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBDDC3DDh
   %def16 #1
   %def8 3Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBDDC3FDh
    %def24 #1
    %def8 3Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro
%macro SRLW [IY]        \%def32 3A00CBFDh\ %endmacro
%macro SRLW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 CBFDh
  %def8 #1,3Ah
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 CBFDC3DDh
   %def16 #1
   %def8 3Ah
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 CBFDC3FDh
    %def24 #1
    %def8 3Ah
   %else
    %def32 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def32 0
%endif
%endmacro

%macro SUB A    \%def8 97h\ %endmacro
%macro SUB B    \%def8 90h\ %endmacro
%macro SUB C    \%def8 91h\ %endmacro
%macro SUB D    \%def8 92h\ %endmacro
%macro SUB E    \%def8 93h\ %endmacro
%macro SUB H    \%def8 94h\ %endmacro
%macro SUB L    \%def8 95h\ %endmacro
%macro SUB IXH          \%def16 94DDh\ %endmacro
%macro SUB IXL          \%def16 95DDh\ %endmacro
%macro SUB IYH          \%def16 94FDh\ %endmacro
%macro SUB IYL          \%def16 95FDh\ %endmacro
%macro SUB [HL]         \%def8 96h\ %endmacro
%macro SUB [IX]         \%def24 96DDh\ %endmacro
%macro SUB [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 96DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 96DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 96DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SUB [IY]         \%def24 96FDh\ %endmacro
%macro SUB [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 96FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 96FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 96FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SUB %n           \%def8 D6h,#1\ %endmacro
%macro XOR A    \%def8 AFh\ %endmacro
%macro XOR B    \%def8 A8h\ %endmacro
%macro XOR C    \%def8 A9h\ %endmacro
%macro XOR D    \%def8 AAh\ %endmacro
%macro XOR E    \%def8 ABh\ %endmacro
%macro XOR H    \%def8 ACh\ %endmacro
%macro XOR L    \%def8 ADh\ %endmacro
%macro XOR IXH  \%def16 ACDDh\ %endmacro
%macro XOR IXL  \%def16 ADDDh\ %endmacro
%macro XOR IYH  \%def16 ACFDh\ %endmacro
%macro XOR IYL  \%def16 ADFDh\ %endmacro
%macro XOR [HL] \%def8 AEh\ %endmacro
%macro XOR [IX]         \%def24 AEDDh\ %endmacro
%macro XOR [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 AEDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 AEDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 AEDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro XOR [IY]         \%def24 AEFDh\ %endmacro
%macro XOR [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 AEFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 AEFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 AEFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro XOR %n           \%def8 EEh,#1\ %endmacro

;Z380
%macro SUB HL,[%n]
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 D6EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 D6EDC3DDh
   %def24 #1
  %else
   %def32 D6EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro SUB SP,%n
 %if (#1 <= FFFFh) & (#1 >= 0)
  %def16 92EDh
  %def16 #1
 %else
  %if (#1 <= FFFFFFh) & (#1 >= 0)
   %def32 92EDC3DDh
   %def24 #1
  %else
   %def32 92EDC3FDh
   %def32 #1
  %endif
 %endif
%endmacro
%macro SUBW [IX]        \%def24 D6DDh\ %endmacro
%macro SUBW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 D6DDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 D6DDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 D6DDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SUBW [IY]        \%def24 D6FDh\ %endmacro
%macro SUBW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 D6FDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 D6FDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 D6FDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro SUBW BC          \%def16 94EDh\ %endmacro
%macro SUBW DE          \%def16 95EDh\ %endmacro
%macro SUBW HL          \%def16 97EDh\ %endmacro
%macro SUBW IX          \%def16 97DDh\ %endmacro
%macro SUBW IY          \%def16 97FDh\ %endmacro
%macro SUBW %n          \%def16 96EDh,#1\ %endmacro
%macro SWAP BC          \%def16 0EEDh\ %endmacro
%macro SWAP DE          \%def16 1EEDh\ %endmacro
%macro SWAP HL          \%def16 3EEDh\ %endmacro
%macro SWAP IX          \%def16 3EDDh\ %endmacro
%macro SWAP IY          \%def16 3EFDh\ %endmacro
%macro TST A            \%def16 3CEDh\ %endmacro
%macro TST B            \%def16 04EDh\ %endmacro
%macro TST C            \%def16 0CEDh\ %endmacro
%macro TST D            \%def16 14EDh\ %endmacro
%macro TST E            \%def16 1CEDh\ %endmacro
%macro TST H            \%def16 24EDh\ %endmacro
%macro TST L            \%def16 2CEDh\ %endmacro
%macro TST [HL]         \%def16 34EDh\ %endmacro
%macro TST %n           \%def16 64EDh\%def8 #1\ %endmacro
%macro TSTIO %n         \%def16 74EDh\%def8 #1\ %endmacro
%macro XORW [IX]        \%def24 EEDDh\ %endmacro
%macro XORW [IX%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 EEDDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 EEDDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 EEDDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro XORW [IY]        \%def24 EEFDh\ %endmacro
%macro XORW [IY%n]
%if %valid(#1)
 %if (#1 <= 127) & (#1 >= -128)
  %def16 EEFDh
  %def8 #1
 %else
  %if (#1 <= 32767) & (#1 >= -32768)
   %def32 EEFDC3DDh
   %def16 #1
  %else
   %if (#1 <= 8388607) & (#1 >= -8388608)
    %def32 EEFDC3FDh
    %def24 #1
   %else
    %def24 0
    %warn "Relative indexing out of range"
   %endif
  %endif
 %endif
%else
 %def24 0
%endif
%endmacro
%macro XORW BC          \%def16 ACEDh\ %endmacro
%macro XORW DE          \%def16 ADEDh\ %endmacro
%macro XORW HL          \%def16 AFEDh\ %endmacro
%macro XORW IX          \%def16 AFDDh\ %endmacro
%macro XORW IY          \%def16 AFFDh\ %endmacro
%macro XORW %n          \%def16 AEEDh,#1\ %endmacro
