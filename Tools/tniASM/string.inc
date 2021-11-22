/;
/; tniASM string functions
\; by Patriek Lesparre
\;

; BASIC MID$ function
%macro mid$(%s,%n,%n)\((#1>>#2)<<(%len(#1)-#2-#3))\%endmacro

; Define string with Offset
%macro dbo %s,%n
  dbo #1,#2,0
%endmacro
%macro dbo %s,%n,%n
  %def8 mid$(#1, #3, 1) + #2
  %if #3+1 < %len(#1)
    dbo #1, #2, #3+1
  %endif
%endmacro

; Define mapped string
; In: string, map, 0
%macro dbm %s,%s,%n
  instr(1,#2,mid$(#1,#3,1))
  %if tniasm#instr > 0
    %def8 tniasm#instr-1
  %endif
  %if #3+1 < %len(#1)
    dbm #1,#2,#3+1
  %endif
%endmacro

; BASIC INSTR function
%macro instr(%n,%s,%s)
%if %len(#3) = 0
tniasm#instr %set 1
%else
tniasm#instr %set 0
  instr_impl(#1,#2,#3)
%endif
%endmacro
%macro instr_impl(%n,%s,%s)
%if #1 <= %len(#2)
  %if mid$(#2,#1-1,%len(#3)) = #3
tniasm#instr %set #1
  %else
    instr_impl(#1+1,#2,#3)
  %endif
%endif
%endmacro
