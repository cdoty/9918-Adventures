; Sord M5 BIOS functions definition
;
; June 2009
; $Id: m5bios.def,v 1.1 2009/06/05 05:57:44 stefano Exp $
;

; General routines

RESET   .equ $0000
BOOT    .equ $0000
STARTUP .equ $0000

RST0    .equ $0000	; System reset
RST1    .equ $0008	; Read DIFLGA (A=flag, HL=flag address)
RST4    .equ $0020	; call $2005
RST5    .equ $0028	; call $2008
RST6    .equ $0030	; call $7008
RST7    .equ $0038	; call $700B

RBTCMT  .equ $0033	; Boot tape
M5BOT   .equ $0058	; Init M5 system
NMI     .equ $0066	; Performs non-maskable interrupt procedures.
RSTSP   .equ $05FF	; 

CHKRAM  .equ $008E	; 
TSBYT   .equ $00BC	; Test RAM byte in HL (Z=0 if OK)
RCCSMM  .equ $00C7	; 
CHHALT  .equ $00DB	; 
CHKROM  .equ $00E4	; 

DIVIDS  .equ $0151	; HL=HL/A
DIVID5  .equ $0152	; HL=HL/C
MULTHD  .equ $142C	; HL=HL*DE
MLTAL   .equ $1441	; HL=L*A

CTC3SP  .equ $01DF	; 
CTC3EX  .equ $023C	; 

RETERR  .equ $002B	; SCF / POP HL / EI / RET
EXRET   .equ $002E	; Just RET
ERRRET  .equ $004D	; 
JMPHL   .equ $05FE	; 
EXTBL   .equ $1076	; Jump to address pointer by offset A on word table in HL

ADJSTD  .equ $000D	; 
ADJSTL  .equ $0016	; 
ADJSTU  .equ $001E	; 
ADJSTR  .equ $0023	; 
KEYSP   .equ $0511	; 
JOYSP   .equ $05A5	; 
GTCAPC  .equ $0085	; 
CHGCP   .equ $0707	; 
PTKDT   .equ $0869	; 
GTKDT   .equ $08AC	; 
STRTKT  .equ $0992	; 
LCPATB  .equ $0B86	; 
BELK    .equ $116A	; Keyboard beep
BEL     .equ $1176	; Beeps like CTRL-G


; VDP control routines

VDPINT .equ $0E0B	; VDP initialisation.
VREGI  .equ $0CA3	; VDP registry initialization. Sets registers according to the VDP system variables in SCRNA
VREGRI .equ $0471	; Similar to VREGI but connected to SVSSW.
CMODE  .equ $0DD8	; Set screen mode GI		- CTRL/S
GMODE  .equ $0B1F	; Set screen mode GII		- CTRL/R
TMODE  .equ $0D04	; Set screen mode TEXT		- CTRL/T
MMODE  .equ $0C44	; Set screen mode MULTICOLOR	- CTRL/Q
NRMSC  .equ $0C5C	; Place the cursor in the View Page 0	- CTRL/U
RVDSPP .equ $0C62	; Toggles the visible screen		- CTRL/Y
RVWRTP .equ $0E31	; Switches the cursor on the opposite screen - CTRL/Z
REVSC  .equ $0E2E	; Toggles the cursor and the visible screen  - CTRL/V
WRTSC  .equ $0E33	; Put the cursor into a page.      Input: A - Page (0,1,2)
DSPCS  .equ $0C64	; Make the specified page visible. Input: A - Page (0,1,2)
FRMSC  .equ $0C77	; Make the specified page visible. Input: A - Page (0/1 - page in which the cursor is/isn't present)

STCHR  .equ $0E59	; Define character set. Input: A .equ generator number (0-6), B .equ number of characters, HL .equ address of source font
STCCHR .equ $0E55	; Define model 1 character set.   Input: B .equ number of characters, HL .equ address of source font
IVDPCH .equ $0D2F	; Init character set
LCPAT  .equ $0D89	; Define character set generator to 0 or 1 depending on defaults
RDCHR  .equ $0E75	; Load the character font in RAM. Input: A .equ generator number (0-6), B .equ number of characters, C .equ first character, HL .equ RAM address

STVWAD .equ $149F	; Prepare VDP address to write data
STVRAD .equ $14A1	; Prepare VDP address to read data


; Colors

STICOL .equ $0ED3	; Set colors in GI mode. Input: B .equ number group of characters (0-31), bit 7 - just read color, C .equ color; Upper 4 bits .equ char fore color, lower 4 bits .equ back color
STCTBL .equ $0DF8	; GI defaults
ITG2M  .equ $0DFB	; GII mode. Input: BC (standard=$1800)
STFCOL .equ $0C83	; Fore color in B
STBCOL .equ $0C97	; Back color in B


; Text output

VIEWP  .equ $135C	; Set VIEW (H, D, L, E)
VIEWRS .equ $1353	; Cancel VIEW settings and set it to full screen
DSPCHA .equ $1083	; Print A character to the screen. CTRL codes are interpreted.
DSPCHB .equ $1082	; Similar to DSPCHA, but CTRL codes are printed.
DSPCH  .equ $1088	; Print A character to the screen. CTRL codes printed or interpreted depending on the system variable DIFLGA
DSPLTA .equ $105C	; Print text in (HL) on the screen buffer. Text must be terminated with code 0 or 13. Output: (HL)-1 .equ last printed char.
DSPLTB .equ $105B	; Similar to DSPLTA, but CTRL codes are printed.
DSPLN  .equ $1063	; Print text in (HL) on the screen buffer based on counter (B) or termination code (0 or 13). Output: B=decremented counter, (HL)-1 .equ last printed char.
DSPMX  .equ $11ED	; Put text in (HL) in a "window": top-left corner=current cursor pos., B=columns, C=rows


; Text input

ACSCH  .equ $0F00	; Read char from screen (position D,E) and moves the cursor. Output: A=char
RDSCH  .equ $14B1	; Read char from screen (position D,E). Output: A=char
RDSCHA .equ $14AC	; Read char in current cursor position. Output: A=char, HL .equ cursor address in VRAM
RDSTM  .equ $0EEC	; Copy text (at D,E) from screen to (HL) until termination, max len.in B.
RDSMX  .equ $120E	; Copy text from "window" (see DSPMX) to (HL) 

DELTC  .equ $0FAB	; DELETE		- CTRL/H
TABLT  .equ $1158	; TAB			- CTRL/I
TABLAT .equ $115A	; Tabulation (in A)
LFEED  .equ $10F0	; LF			- CTRL/J
CRET   .equ $13CD	; CR			- CTRL/B
CRETL  .equ $10ED	; CR+LF			- CTRL/M
HOMEP  .equ $13B6	; HOME cursor		- CTRL/K
MVACS  .equ $13DD	; Move cursor at (D,E)
STPCU  .equ $1100	; Position cursor
LFTAW  .equ $10FF	; Left			- CTRL/+
RGTAW  .equ $10FC	; Right			- CTRL/*
UPRAW  .equ $10F9	; Up			- CTRL/@
LWRAW  .equ $10F6	; Down			- CTRL/?
STPCUL .equ $1134	; Move left
STPCUR .equ $1116	; Move right
STPCUU .equ $1147	; Move up
STPCUD .equ $1126	; Move down
SIFTD  .equ $103C	; Insert line at position E (0-22)
SCRLF  .equ $130A	; Scroll screen left	- CTRL/D
SCRRG  .equ $12F9	; Scroll screen right	- CTRL/F
SCRUP  .equ $12B3	; Scroll screen up	- CTRL/E
SCRDW  .equ $12BF	; Scroll screen down	- CTRL/C
STOVRM .equ $0F19	; Overwrite mode	- CTRL/O
STINSM .equ $0F1E	; Insert mode		- CTRL/P
SCTOSD .equ $13D5	; 			- CTRL/B
SNTOSD .equ $13DA	; 			- CTRL/N

EDTLN  .equ $0668	; 
EDTST  .equ $0689	; 
ACEST  .equ $066F	; 

CANCL  .equ $13BB	; Delete right characters  - CTRL/X
CLRSC  .equ $1393	; CLS 			- CTRL/L
CLRSCX .equ $1394	; CLS filling the screen with the character code specified in A
CLRSS  .equ $137E	; Resume normal VIEW, wipe the screen and its sprites. (only from/to text mode)
CLRSS2 .equ $1381	; Resume normal VIEW, wipe the screen and its sprites.


; Sprites

STSCHR .equ $0E58	; 
MAGFY  .equ $04C5	; 
STSCOD .equ $0454	; 
STSCOL .equ $0445	;
GTSPOS .equ $042B	;
MVSPA  .equ $03CE	; Get physical sprite pos. In: A=spr.#, (HL,DE)=logical pos.  Out: (D,E), B=ECB (7 bit)
MVSPR  .equ $040B	; Move sprite. In: A=spr.#, B,C .equ X,Y increment (+/- 127). Out: (HL,DE)=logical pos.
ERSSPR .equ $03CC	; Delete sprite # specified in A.
DELSPR .equ $03C5	; Hide sprite # specified in A.
ERSPRA .equ $1387	; Delete all the sprites

GTSPLC .equ $03EE	; Compute physical position (D,E) basing on a logical one (HL,DE). Input B.equ ECB
GTSPRC .equ $0377	; Compute logical position (HL,DE) basing on a physical one (D,E). Output B.equ ECB
ADDVCT .equ $041B	; 
GTSTEP .equ $049F	; 
GTSATA .equ $0369	; Get sprite table. In: A.equ spr. #   Out: HL=VRAM address


; RAM and VRAM

PBVRID .equ $0010	; VPOKE (HL),A.  Uses DI.  RST call is possible.
GBVRID .equ $0018	; A=VPEEK (HL).  Uses DI.  RST call is possible.
PBVRAM .equ $14BD	; VPOKE (HL),A. (no DI)
GBVRAM .equ $14C5	; A=VPEEK (HL). (no DI)
WDVPM  .equ $1460	; RAM (HL) to VRAM (DE) copy of max 256 bytes (B).
CVTIR  .equ $0E61	; RAM (HL) to VRAM (DE) copy of max 16384 bytes (BC).
RDVPM  .equ $144B	; VRAM (HL) to RAM (DE) copy of max 256 bytes (B).
VCTIR  .equ $0E7D	; VRAM (HL) to RAM (DE) copy of max 16384 bytes (BC).
BLKMV  .equ $0B75	; VRAM (HL) to VRAM (DE) copy of max 16384 bytes (BC).
BLKMV2 .equ $0B81	; VRAM (HL) to VRAM (DE) copy of max 2048 bytes.
BLKMVC .equ $0DCB	; VRAM (HL) to VRAM (DE) copy and invert max 16384 bytes (BC).
PADVRM .equ $0E01	; Fill BC bytes in VRAM (at location HL) with the byte specified in A.
PAD    .equ $0861	; Fill BC bytes in RAM (at location HL) with the byte specified in A.
NULPAD .equ $0860	; Fill BC bytes in RAM (at location HL) with 0.
EXCLOP .equ $0E49	; Swap two memory blocks in RAM. Input: HL - beginning of block 1, DE - beginning of block 2, BC - block length


; Keyboard

SCNKB  .equ $0966	; Scan keyboard. Output: A=key code, B=AKI
ACECH0 .equ $0827	;
ACECHI .equ $0845	; Get char from keyboard buffer. Output: A=ASCII code (CY if no key), B=AKI
CALKAD .equ $097B	; 
DECTR  .equ $090B	; 
DECFN  .equ $0933	; 
DECAD  .equ $08DA	; 

WTKDTC .equ $0756	; Wait for keypress. Output: A=ASCII code, B=AKI
CHKYM  .equ $073F	; 
STDM1  .equ $04FF	; 
CLKBF  .equ $077B	; 
ACELN  .equ $07A9	; Read line long max B bytes, put in HL


; System

CTCINT  .equ $01C2	; Initialize the Z80 CTC
STSCLK  .equ $02CF	; Set Real-Time Clock. Input: A=hours, H=minutes, L=seconds
GTSCLK  .equ $02DB	; Read Real-Time Clock. Output: A=hours, H=minutes, L=seconds
STRTUC  .equ $02FB	; Init UPCOUNTER (A=time constant)
STOPUC  .equ $0313	; Stop UPCOUNTER
RSTRUC  .equ $030D	; Restart UPCOUNTER
STRTDC  .equ $0319	; Init DOWNCOUNTER (A=time constant)
STOPDC  .equ $0340	; Stop DOWNCOUNTER
RSTRDC  .equ $0336	; Restart DOWNCOUNTER
CLOCKSP .equ $0242	; 


; Tape

RDFID  .equ $1598	; 
RFIDC  .equ $1587	; 
BLOAD  .equ $153B	; 
BLODD  .equ $1579	; 
RATBLF .equ $164D	; 
RATBL  .equ $1650	; 
LOADC  .equ $1652	; 

WTFID  .equ $15C3	; 
BSAVE  .equ $1529	; 
BSAVD  .equ $1563	; 
WATBL  .equ $15EB	; 
WATBLF .equ $15E8	; 
STROC  .equ $15ED	; 

STBYT  .equ $1626	; 
OUTPS  .equ $163A	; 
LDBYT  .equ $16B3	; 
SRLAD  .equ $16D1	; 
WAITST .equ $1717	; 
RDCNT  .equ $1739	; 
CPFNM  .equ $1765	; 
MTRON  .equ $1776	; Motor ON
MTROF  .equ $177E	; Motor OFF
LFTBC  .equ $1556	; 
BTCMT  .equ $010D	; 


; Soundchip (SML)

SGINT  .equ $1811	; Full SML initialization
MPLAY  .equ $1861	; Serviced control of SML (connected to CTC channel #3)
PLAY   .equ $186F	; Operate SML
NOTA   .equ $191A	; Play note
V0FAC  .equ $1A31	; Switch off all the three SGC channels



; MSX equivalences

; Accessing to the VDP (T19918)

RDVRM  .equ $0018 ; GBVRID - Reads the VRAM address by [HL].
WRTVRM .equ $0010 ; PBVRID - Write to the VRAM address by [HL].
SETRD  .equ $14A1 ; STVRAD - Sets up the VDP for read.
SETWRT .equ $149F ; STVWAD - Sets up the VDP for write.
FILVRM .equ $0E01 ; PADVRM - Fill the vram with specified data
LDIRMV .equ $0E7D ; VCTIR - Block transfer to memory from VRAM
LDIRVM .equ $0E61 ; CVTIR - Block transfer to VRAM from memory
CLRSPR .equ $1387 ; ERSPRA - Initializes all sprites.
INITXT .equ $0D04 ; TMODE - Initializes screen for text mode (40*24) and sets the VDP.
INIT32 .equ $0DD8 ; CMODE - Initializes screen for text mode (32*24) and sets the VDP.
INIGRP .equ $0B1F ; GMODE - Initializes screen for high-resolution mode and sets the VDP.
INIMLT .equ $0C44 ; MMODE - Initializes screen for multi-color mode and sets the VDP.


; Accessing to the PSG.

GICINI .equ $1811 ; SGINT - Initializes PSG (SML),and static data for PLAY


; Console (i.e. the keyboard and the CRT)

CHGET  .equ $0845 ; ACECHI - Waits for character being input and returns the character codes.
CHPUT  .equ $1083 ; DSPCH - (w/CTRL codes) Outputs a character to the console.
BEEP   .equ $1176 ; BEL - Sounds the buffer
