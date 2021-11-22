%include "z80r800.inc"
%include "z80().inc"
%include "tniasm.inc"

%macro fname\%outfile\%endmacro
%macro if\%if\%endmacro
%macro else\%else\ %endmacro
%macro endif\%endif\ %endmacro

%symfile ""

%if #0 > 1
	fname #2
%endif

%if #0 > 0
	%include #1
%else
	%print ""
	%print "tniASM v0.45 compatibility layer"
	%print "Usage: tniasm compat <source file> [<output file>]"
	%print ""
%endif
