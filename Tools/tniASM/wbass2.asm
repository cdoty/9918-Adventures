%include "z80r800.inc"
%include "z80().inc"
%include "tniasm.inc"
%include "z80n00b.inc"

%if #0 > 1
	%outfile #2
%endif
%if #0 > 0
	%include #1
%else
	%print ""
	%print "WB-ASS2 compatibility layer"
	%print "Usage: tniasm wbass2 <source file> [<output file>]"
	%print "Tokenized sources not supported"
	%print ""
%endif
