%macro casheader
	%defb	((%fpos-1) & (0-8) | 8) - %fpos		;align 8
	%def8	$1f,$a6,$de,$ba,$cc,$13,$7d,$74
%endmacro

%macro bsave %s
	casheader
	%defb	10,$d0
	%def8	#1<<(%len(#1)-6)
	%defb	6-%len(#1)," "
	casheader
%endmacro

%macro csave %s
	casheader
	%defb	10,$d3
	%def8	#1<<(%len(#1)-6)
	%defb	6-%len(#1)," "
	casheader
%endmacro

%macro save %s
	casheader
	%defb	10,$ea
	%def8	#1<<(%len(#1)-6)
	%defb	6-%len(#1)," "
%endmacro
