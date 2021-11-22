%macro DB\%def8\%endmacro
%macro DW\%def16\%endmacro
%macro DL\%def32\%endmacro
%macro DS\%defb\%endmacro
%macro RB\%res8\%endmacro
%macro RW\%res16\%endmacro
%macro RL\%res32\%endmacro
%macro EQU\%equ\%endmacro
%macro INCBIN\%incbin\%endmacro
%macro INCLUDE\%include\%endmacro
%macro FORG\%forg\%endmacro
%macro $\%apos\%endmacro
%macro $$\%fpos\%endmacro
%macro DC %s
%def8 #1 << 1 + (#1 >> (%len(#1)-1) | 128)
%endmacro

/;
/; tniASM section and phase support v1.0
\; by Patriek Lesparre
\;

%macro align %n
  %if tniasm#currentsection = 2
    ralign #1
  %else
    %defb ((%apos-1) & (0-#1)) + #1 - %apos
  %endif
%endmacro

%macro ralign %n
  %if %apos & (#1-1)
    %res8 #1 - (%apos & (#1-1))
  %endif
%endmacro

%macro org %n
dephase
orgcode #1
section code
%endmacro

%macro org %n,%n
org #1
%warn "Beware: address limit is not enforced" ; todo: some kind of aposlimit
%endmacro

%macro orgcode %n
%if tniasm#currentsection = 0
%org #1
%endif
tniasm#codesection %set #1
tniasm#fcodesection %set %fpos	; TODO because this uses the current %fpos, "orgcode" must be used at the point where the code section must go.
%endmacro

%macro orgdata %n
%if tniasm#currentsection = 1
%org #1
%endif
tniasm#datasection %set #1
tniasm#fdatasection %set %fpos	; TODO because this uses the current %fpos, "orgdata" must be used at the point where the data section must go.
%endmacro

%macro orgrdata %n
%if tniasm#currentsection = 2
%org #1
%endif
tniasm#rdatasection %set #1
%endmacro

%macro section code
%if tniasm#currentsection <> 0
tniasm#savesection
%org tniasm#codesection
%forg tniasm#fcodesection
tniasm#currentsection %set 0
%endif
%endmacro

%macro section data
%if tniasm#currentsection <> 1
tniasm#savesection
%org tniasm#datasection
%forg tniasm#fdatasection
tniasm#currentsection %set 1
%endif
%endmacro

%macro section rdata
%if tniasm#currentsection <> 2
tniasm#savesection
%org tniasm#rdatasection
tniasm#currentsection %set 2
%endif
%endmacro

%macro phase %n
tniasm#phase %set #1 - %apos
%org #1
%endmacro

%macro dephase
%org %apos - tniasm#phase
tniasm#phase %set 0
%endmacro

; internal
%macro tniasm#savesection
%if tniasm#currentsection = 0
tniasm#codesection %set %apos
tniasm#fcodesection %set %fpos
%else
%if tniasm#currentsection = 1
tniasm#datasection %set %apos
tniasm#fdatasection %set %fpos
%else
%if tniasm#currentsection = 2
tniasm#rdatasection %set %apos
%endif
%endif
%endif
%endmacro

tniasm#savesection
tniasm#rdatasection	%set tniasm#datasection		; swap things here to change the section order
tniasm#datasection	%set tniasm#codesection
tniasm#fdatasection	%set tniasm#fcodesection
tniasm#codesection	%set 0
tniasm#fcodesection	%set 0

tniasm#currentsection	%set -1
