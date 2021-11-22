%include "z80r800.inc"
%include "z80n00b.inc"
%if #0 = 0
  %error "Usage: tniasm asmsx <asMSX source>"
%endif
%if #0 > 1
  %error "Usage: tniasm asmsx <asMSX source>"
%endif

; define as string
asmsx#type %set -1		; 0=rom, 1=basic, 2=msxdos, 3=cassette
asmsx#megarom %set 0		; 0=normal, 1=konami, 2=konamiscc, 3=ascii8, 4=ascii16
asmsx#blocksize %set 0		; 0=no blocks, 8192 or 16384
asmsx#size %set 0
asmsx#phase %set 0
asmsx#source %set #1

; stuff to change manually:
; - local label
;%macro @@\.\%endmacro
; - hex prefix
;%macro #\$\ %endmacro
; - comments: '//' to ';', '{ }' to '/; \;' and '/* */' to '/; \;'
;%macro //\;\%endmacro
;%macro /*\/;\%endmacro			; already supported
;%macro */\\;\%endmacro			; already supported
;%macro {\/;\%endmacro
;%macro }\\;\%endmacro

; additional defines
%macro $\%apos\%endmacro
%macro .BYTE\%res8\%endmacro
%macro .WORD\%res16\%endmacro
%macro .DB\%def8\%endmacro
%macro .DEFB\%def8\%endmacro
%macro .DW\%def16\%endmacro
%macro .DEFW\%def16\%endmacro
%macro .DS\%res8\%endmacro
%macro .DEFS\%res8\%endmacro
%macro .DT\%def8\%endmacro
%macro .DEFT\%def8\%endmacro
%macro DB\%def8\%endmacro
%macro DEFB\%def8\%endmacro
%macro DW\%def16\%endmacro
%macro DEFW\%def16\%endmacro
%macro DS\%res8\%endmacro
%macro DEFS\%res8\%endmacro
%macro DT\%def8\%endmacro
%macro DEFT\%def8\%endmacro
; conditionals
%macro IF\%if\%endmacro
%macro ELSE\%else\ %endmacro
%macro ENDIF\%endif\ %endmacro
; directives
%macro EQU\%equ\%endmacro
%macro .EQU\%equ\%endmacro
%macro .ORG %n
  %org #1
asmsx#start %set #1
  %if asmsx#exec = 0
asmsx#exec %set #1
%endif
%endmacro
%macro .PHASE %n
asmsx#phase %set #1 - %apos
%org #1
%endmacro
%macro .DEPHASE
%org %apos - asmsx#phase
asmsx#phase %set 0
%endmacro
%macro .SIZE %n
  %if asmsx#size = 0
asmsx#size = #1
  %endif
%endmacro
%macro .INCLUDE %s\%include #1\ %endmacro
%macro .INCBIN %s SKIP %n SIZE %n\%incbin #1,#2,#3\ %endmacro
%macro .INCBIN %s SIZE %n\%incbin #1,0,#2\ %endmacro
%macro .INCBIN %s SKIP %n\%incbin #1,#2\ %endmacro
%macro .INCBIN %s\%incbin #1\ %endmacro
%macro .ROM
%if asmsx#type = -1
  %outfile asmsx#source + ".rom"
  %def16 "AB"
asmsx#type %set 0
%endif
%endmacro
%macro .BASIC
%if asmsx#type = -1
  %outfile asmsx#source + ".bin"
  %def8 FEh
  %def16 asmsx#start,asmsx#end,asmsx#exec
asmsx#type %set 1
%endif
%endmacro
%macro .START %n
%if (asmsx#type = 0)
  %def16 #1
%else
asmsx#exec %set #1
%endif
%endmacro
%macro .MSXDOS
%outfile asmsx#source + ".com"
  %org 100h
asmsx#type %set 2
%endmacro
%macro .PAGE %n
  %if (#1 >= 0) & (#1 < 4)
    %org #1 << 14
  %else
    %error "Illegal page number"
  %endif
%endmacro

%macro .DEBUG %s
  ld d,d
  jr $+2+.#len
.#str: db #1
.#len: equ $-.#str
%endmacro
%macro .BREAK
  ld b,b
  jr $+2
%endmacro
%macro .BREAKPOINT\.BREAK\%endmacro
%macro .BREAK %n
  ld b,b
  jr $+4
  dw #1
%endmacro
%macro .BREAKPOINT %n\.BREAK #1\ %endmacro

; unsupported
%macro REPT %n
  %print "REPT() unsupported"
%endmacro
%macro ENDR
  %print "ENDR unsupported"
%endmacro
%macro .RANDOM(%n)
  %print ".RANDOM() unsupported"
%endmacro
%macro .PRINT %n
  %print ".PRINT unsupported"
%endmacro
%macro .PRINTDEC %n
  %print ".PRINTDEC unsupported"
%endmacro
%macro .PRINTHEX %n
  %print ".PRINTHEX unsupported"
%endmacro
%macro .PRINTFIX %n
  %print ".PRINTFIX unsupported"
%endmacro
%macro .PRINTTEXT %s
	%print #1
%endmacro
%macro .PRINTSTRING %s
	%print #1
%endmacro
%macro .CAS %s
%if asmsx#type = 1
  %if %apos & C000h = 8000h
    %outfile asmsx#source + ".cas"
    %defb ((%fpos - 1) & (0 - 8) | 8) - %fpos	;align 8
    %def8 1Fh,A6h,DEh,BAh,CCh,13h,7Dh,74h
    %defb 10,D0h
    %def8 #1 << (%len(#1) - 6)
    %defb 6 - %len(#1)," "
    %defb ((%fpos - 1) & (0 - 8) | 8) - %fpos	;align 8
    %def8 1Fh,A6h,DEh,BAh,CCh,13h,7Dh,74h
    %def16 asmsx#start,asmsx#end,asmsx#exec
asmsx#type %set 3
  %endif
%endif
%endmacro
%macro .CAS
  .CAS asmsx#source
%endmacro
%macro .CASSETTE %s
  .CAS #1
%endmacro
%macro .CASSETTE
  .CAS asmsx#source
%endmacro
%macro .WAV %s
  %print ".WAV unsupported"
%endmacro

%macro .BIOS
CHKRAM:	%equ	00h
SYNCHR:	%equ	08h
RDSLT:	%equ	0Ch
CHRGTR:	%equ	10h
WRTSLT:	%equ	14h
OUTDO:	%equ	18h
CALSLT:	%equ	1Ch
DCOMPR:	%equ	20h
ENASLT:	%equ	24h
GETYPR:	%equ	28h
CALLF:	%equ	30h
KEYINT:	%equ	38h
INITIO:	%equ	3Bh
INIFNK:	%equ	3Eh
DISSCR:	%equ	41h
ENASCR:	%equ	44h
WRTVDP:	%equ	47h
RDVRM:	%equ	4Ah
WRTVRM:	%equ	4Dh
SETRD:	%equ	50h
SETWRT:	%equ	53h
FILVRM:	%equ	56h
LDIRMV:	%equ	59h
LDIRVM:	%equ	5Ch
CHGMOD:	%equ	5Fh
CHGCLR:	%equ	62h
NMI:	%equ	66h
CLRSPR:	%equ	69h
INITXT:	%equ	6Ch
INIT32:	%equ	6Fh
INIGRP:	%equ	72h
INIMLT:	%equ	75h
SETTXT:	%equ	78h
SETT32:	%equ	7Bh
SETGRP:	%equ	7Eh
SETMLT:	%equ	81h
CALPAT:	%equ	84h
CALATR:	%equ	87h
GSPSIZ:	%equ	8Ah
GRPPRT:	%equ	8Dh
GICINI:	%equ	90h
WRTPSG:	%equ	93h
RDPSG:	%equ	96h
STRTMS:	%equ	99h
CHSNS:	%equ	9Ch
CHGET:	%equ	9Fh
CHPUT:	%equ	A2h
LPTOUT:	%equ	A5h
LPTSTT:	%equ	A8h
CNVCHR:	%equ	ABh
PINLIN:	%equ	AEh
INLIN:	%equ	B1h
QINLIN:	%equ	B4h
BREAKX:	%equ	B7h
ISCNTC:	%equ	BAh
CKCNTC:	%equ	BDh
BEEP:	%equ	C0h
CLS:	%equ	C3h
POSIT:	%equ	C6h
FNKSB:	%equ	C9h
ERAFNK:	%equ	CCh
DSPFNK:	%equ	CFh
TOTEXT:	%equ	D2h
GTSTCK:	%equ	D5h
GTTRIG:	%equ	D8h
GTPAD:	%equ	DBh
GTPDL:	%equ	DEh
TAPION:	%equ	E1h
TAPIN:	%equ	E4h
TAPIOF:	%equ	E7h
TAPOON:	%equ	EAh
TAPOUT:	%equ	EDh
TAPOOF:	%equ	F0h
STMOTR:	%equ	F3h
LFTQ:	%equ	F6h
PUTQ:	%equ	F9h
RIGHTC:	%equ	FCh
LEFTC:	%equ	FFh
UPC:	%equ	102h
TUPC:	%equ	105h
DOWNC:	%equ	108h
TDOWNC:	%equ	10Bh
SCALXY:	%equ	10Eh
MAPXYC:	%equ	111h
FETCHC:	%equ	114h
STOREC:	%equ	117h
SETATR:	%equ	11Ah
READC:	%equ	11Dh
SETC:	%equ	120h
NSETCX:	%equ	123h
GTASPC:	%equ	126h
PNTINI:	%equ	129h
SCANR:	%equ	12Ch
SCANL:	%equ	12Fh
CHGCAP:	%equ	132h
CHGSND:	%equ	135h
RSLREG:	%equ	138h
WSLREG:	%equ	13Bh
RDVDP:	%equ	13Eh
SNSMAT:	%equ	141h
PHYDIO:	%equ	144h
FORMAT:	%equ	147h
ISFLIO:	%equ	14Ah
OUTDLP:	%equ	14Dh
GETVCP:	%equ	150h
GETVC2:	%equ	153h
KILBUF:	%equ	156h
CALBAS:	%equ	159h
SUBROM:	%equ	15Ch
EXTROM:	%equ	15Fh
CHKSLZ:	%equ	162h
CHKNEW:	%equ	165h
EOL:	%equ	168h
BIGFIL:	%equ	16Bh
NSETRD:	%equ	16Eh
NSTWRT:	%equ	171h
NRDVRM:	%equ	174h
NWRVRN:	%equ	177h
RDBTST:	%equ	17Ah
WRBTST:	%equ	17Dh
CHGCPU:	%equ	180h
GETCPU:	%equ	183h
PCMPLY:	%equ	186h
PCMREC:	%equ	189h
%endmacro

%macro .CALLBIOS %n
%if asmsx#type = 2
  ld	ix,#1
  ld	iy,[fcc0h]
  call	1ch
%endif
%endmacro
%macro .CALLDOS %n
%if asmsx#type = 2
  ld	c,#1
  call	05h
%endif
%endmacro
%macro .SEARCH
  call	138h
  rrca
  rrca
  and	03h
  ld	c,a
  ld	hl,fcc1h
  add	a,l
  ld	l,a
  ld	a,[hl]
  and	80h
  or	c
  ld	c,a
  inc	l
  inc	l
  inc	l
  inc	l
  ld	a,[hl]
  and	0ch
  or	c
  ld	h,80h
  call	24h
%endmacro

%macro .MEGAROM Konami
%if asmsx#megarom = 0
asmsx#type %set 0
asmsx#megarom %set 1
asmsx#blocksize: %equ 2000h
%endif
%endmacro

%macro .MEGAROM KonamiSCC
%if asmsx#megarom = 0
asmsx#type %set 0
asmsx#megarom %set 2
asmsx#blocksize: %equ 2000h
%endif
%endmacro

%macro .MEGAROM ASCII8
%if asmsx#megarom = 0
asmsx#type %set 0
asmsx#megarom %set 3
asmsx#blocksize: %equ 2000h
%endif
%endmacro

%macro .MEGAROM ASCII16
%if asmsx#megarom = 0
asmsx#type %set 0
asmsx#megarom %set 4
asmsx#blocksize: %equ 4000h
%endif
%endmacro

; fill remainder of block up to block #1 with 0 and start the next (phase #2/dephase)
%macro SUBPAGE %n AT %n
  %if asmsx#blocksize > 0
    %forg #1 * asmsx#blocksize
    %org #2
  %endif
%endmacro
%macro .SUBPAGE %n AT %n\SUBPAGE #1 AT #2\ %endmacro

; select block for area
%macro SELECT %n AT %n
%if (#2 >= 4000h) & (#2 < c000h)
.#test: %equ #2 >> 13
%if asmsx#megarom = 1
%if (.#test = 2)
  %warn "Block will not change"
%endif
  ld	a,#1 & 1fh
  ld	[#2 & e000h],a
%endif
%if asmsx#megarom = 2
  ld	a,#1 & 3fh
  ld	[#2 & e000h | 1000h],a
%endif
%if asmsx#megarom = 3
.#address: %equ ((.#test & 3) - 2) << 11
  ld	a,#1
  ld	[.#address | 6000h],a
%endif
%if asmsx#megarom = 4
.#address: %equ (.#test >> 2 & 1) << 11
  ld	a,#1
  ld	[.#address | 6000h],a
%endif
%else
  %error "Address out of range"
%endif
%endmacro
%macro .SELECT %n AT %n\SELECT #1 AT #2\ %endmacro

; write symbol file and include asMSX source
%if #1 >> (%len(#1) - 4) = ".asm"
asmsx#source %set (#1 << 4)
%endif
%symfile asmsx#source + ".sym"
%include asmsx#source + ".asm"

; file size adjustment
%if (asmsx#size <> 0)
  ds (#1 * 1024) - %fpos
%else
  %if (asmsx#type = 0)
    %if (asmsx#megarom = 0)
        %defb 2000h - (%fpos & 1fffh)
    %else
        %defb asmsx#blocksize - ((%fpos & (asmsx#blocksize - 1))
    %endif
  %endif
%endif
asmsx#end %set %apos-1
