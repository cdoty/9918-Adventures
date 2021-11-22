;
; sjasm compatibility mode by Edwin
;
%include "z80r800.inc"
%include "z80().inc"

%macro if\%if\%endmacro
%macro else\%else\ %endmacro
%macro endif\%endif\ %endmacro

%macro org\%org\%endmacro

;
; main assembly stuff
;
%macro DB\%def8\%endmacro
%macro DW\%def16\%endmacro
%macro DT\%def24\%endmacro
%macro DD\%def32\%endmacro
%macro DEFB\%def8\%endmacro
%macro DEFW\%def16\%endmacro
%macro DEFM\%def8\%endmacro
%macro DEFD\%def32\%endmacro
%macro DS\%defb\%endmacro
%macro EQU\%equ\%endmacro
%macro INCBIN\%incbin\%endmacro
%macro INCLUDE\%include\%endmacro
%macro $\%apos\%endmacro
%macro $$\%fpos\%endmacro
%macro DC %s
%def8 #1 << 1 + (#1 >> (%len(#1)-1) | 128)
%endmacro
%macro DZ %s\%def8 #1,0\%endmacro               ; only supports a single string!
;%macro := \%set\%endmacro
;%macro = \%equ\%endmacro
%macro output\%outfile\%endmacro

%macro EX AF,AF        \%def8 08h\ %endmacro
%macro ADD %n AND %n \ADD #1 & #2 \%endmacro
;
; align
;
%macro align %n
  %if %apos & (#1-1)
    %defb #1 - (%apos & (#1-1))
  %endif
%endmacro

;
; map 
;
sjasm#map %set 0

%macro map %n
sjasm#map %set #1
%endmacro

%macro # %n
%equ sjasm#map
sjasm#map %set (sjasm#map+#1)&65535
%endmacro

%macro ## %n
%if sjasm#map & (#1-1)
sjasm#map %set sjasm#map + #1 - (sjasm#map & (#1-1))
%endif
%endmacro

;
; page support (hack)
;
sjasm#totalsize %set 0

%macro defpage %n,%n,%n
%if #1=0
sjasm#pageorg0 %set #2
sjasm#pagesize0 %set #3
sjasm#totalsize %set sjasm#totalsize+sjasm#pagesize0
%else
%if #1=4
sjasm#pageorg4 %set #2
sjasm#pagesize4 %set #3
sjasm#pagestart4 %set sjasm#totalsize
sjasm#totalsize %set sjasm#totalsize+sjasm#pagesize4
%else
%if #1=14
sjasm#pageorg14 %set #2
sjasm#pagesize14 %set #3
sjasm#pagestart14 %set sjasm#totalsize
sjasm#totalsize %set sjasm#totalsize+sjasm#pagesize14
%else
%if #1=16
sjasm#pageorg16 %set #2
sjasm#pagesize16 %set #3
sjasm#pagestart16 %set sjasm#totalsize
sjasm#totalsize %set sjasm#totalsize+sjasm#pagesize16
%else
%if #1=29
sjasm#pageorg29 %set #2
sjasm#pagesize29 %set #3
sjasm#pagestart29 %set sjasm#totalsize
sjasm#totalsize %set sjasm#totalsize+sjasm#pagesize29
%endif
%endif
%endif
%endif
%endif
sjasm#temp %set %fpos
%forg sjasm#totalsize
%forg sjasm#temp
%endmacro

%macro page %n
%if #1=0
%forg 0
%org sjasm#pageorg0
%else
%if #1=4
%forg sjasm#pagestart4
%org sjasm#pageorg4
%else
%if #1=14
%forg sjasm#pagestart14
%org sjasm#pageorg14
%else
%if #1=16
%forg sjasm#pagestart16
%org sjasm#pageorg16
%else
%if #1=29
%forg sjasm#pagestart29
%org sjasm#pageorg29
%endif
%endif
%endif
%endif
%endif
%endmacro


%if #0 > 1
	fname #2
%endif

%if #0 > 0
        %symfile #1+".sym"
	%include #1
%else
	%print ""
	%print "sjasm compatibility layer"
	%print "Usage: tniasm sjasm <source file> [<output file>]"
	%print ""
%endif

