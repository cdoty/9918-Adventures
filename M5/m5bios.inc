; Sord M5 BIOS functions definition
;
; June 2009
; $Id: m5bios.def,v 1.1 2009/06/05 05:57:44 stefano Exp $
;

; General routines

RESET   = $0000
BOOT    = $0000
STARTUP = $0000

RST0    = $0000	; System reset
RST1    = $0008	; Read DIFLGA (A=flag, HL=flag address)
RST4    = $0020	; call $2005
RST5    = $0028	; call $2008
RST6    = $0030	; call $7008
RST7    = $0038	; call $700B

RBTCMT  = $0033	; Boot tape
M5BOT   = $0058	; Init M5 system
NMI     = $0066	; Performs non-maskable interrupt procedures.
RSTSP   = $05FF	; 

CHKRAM  = $008E	; 
TSBYT   = $00BC	; Test RAM byte in HL (Z=0 if OK)
RCCSMM  = $00C7	; 
CHHALT  = $00DB	; 
CHKROM  = $00E4	; 

DIVIDS  = $0151	; HL=HL/A
DIVID5  = $0152	; HL=HL/C
MULTHD  = $142C	; HL=HL*DE
MLTAL   = $1441	; HL=L*A

CTC3SP  = $01DF	; 
CTC3EX  = $023C	; 

RETERR  = $002B	; SCF / POP HL / EI / RET
EXRET   = $002E	; Just RET
ERRRET  = $004D	; 
JMPHL   = $05FE	; 
EXTBL   = $1076	; Jump to address pointer by offset A on word table in HL

ADJSTD  = $000D	; 
ADJSTL  = $0016	; 
ADJSTU  = $001E	; 
ADJSTR  = $0023	; 
KEYSP   = $0511	; 
JOYSP   = $05A5	; 
GTCAPC  = $0085	; 
CHGCP   = $0707	; 
PTKDT   = $0869	; 
GTKDT   = $08AC	; 
STRTKT  = $0992	; 
LCPATB  = $0B86	; 
BELK    = $116A	; Keyboard beep
BEL     = $1176	; Beeps like CTRL-G


; VDP control routines

VDPINT = $0E0B	; VDP initialisation.
VREGI  = $0CA3	; VDP registry initialization. Sets registers according to the VDP system variables in SCRNA
VREGRI = $0471	; Similar to VREGI but connected to SVSSW.
CMODE  = $0DD8	; Set screen mode GI		- CTRL/S
GMODE  = $0B1F	; Set screen mode GII		- CTRL/R
TMODE  = $0D04	; Set screen mode TEXT		- CTRL/T
MMODE  = $0C44	; Set screen mode MULTICOLOR	- CTRL/Q
NRMSC  = $0C5C	; Place the cursor in the View Page 0	- CTRL/U
RVDSPP = $0C62	; Toggles the visible screen		- CTRL/Y
RVWRTP = $0E31	; Switches the cursor on the opposite screen - CTRL/Z
REVSC  = $0E2E	; Toggles the cursor and the visible screen  - CTRL/V
WRTSC  = $0E33	; Put the cursor into a page.      Input: A - Page (0,1,2)
DSPCS  = $0C64	; Make the specified page visible. Input: A - Page (0,1,2)
FRMSC  = $0C77	; Make the specified page visible. Input: A - Page (0/1 - page in which the cursor is/isn't present)

STCHR  = $0E59	; Define character set. Input: A = generator number (0-6), B = number of characters, HL = address of source font
STCCHR = $0E55	; Define model 1 character set.   Input: B = number of characters, HL = address of source font
IVDPCH = $0D2F	; Init character set
LCPAT  = $0D89	; Define character set generator to 0 or 1 depending on defaults
RDCHR  = $0E75	; Load the character font in RAM. Input: A = generator number (0-6), B = number of characters, C = first character, HL = RAM address

STVWAD = $149F	; Prepare VDP address to write data
STVRAD = $14A1	; Prepare VDP address to read data


; Colors

STICOL = $0ED3	; Set colors in GI mode. Input: B = number group of characters (0-31), bit 7 - just read color, C = color; Upper 4 bits = char fore color, lower 4 bits = back color
STCTBL = $0DF8	; GI defaults
ITG2M  = $0DFB	; GII mode. Input: BC (standard=$1800)
STFCOL = $0C83	; Fore color in B
STBCOL = $0C97	; Back color in B


; Text output

VIEWP  = $135C	; Set VIEW (H, D, L, E)
VIEWRS = $1353	; Cancel VIEW settings and set it to full screen
DSPCHA = $1083	; Print A character to the screen. CTRL codes are interpreted.
DSPCHB = $1082	; Similar to DSPCHA, but CTRL codes are printed.
DSPCH  = $1088	; Print A character to the screen. CTRL codes printed or interpreted depending on the system variable DIFLGA
DSPLTA = $105C	; Print text in (HL) on the screen buffer. Text must be terminated with code 0 or 13. Output: (HL)-1 = last printed char.
DSPLTB = $105B	; Similar to DSPLTA, but CTRL codes are printed.
DSPLN  = $1063	; Print text in (HL) on the screen buffer based on counter (B) or termination code (0 or 13). Output: B=decremented counter, (HL)-1 = last printed char.
DSPMX  = $11ED	; Put text in (HL) in a "window": top-left corner=current cursor pos., B=columns, C=rows


; Text input

ACSCH  = $0F00	; Read char from screen (position D,E) and moves the cursor. Output: A=char
RDSCH  = $14B1	; Read char from screen (position D,E). Output: A=char
RDSCHA = $14AC	; Read char in current cursor position. Output: A=char, HL = cursor address in VRAM
RDSTM  = $0EEC	; Copy text (at D,E) from screen to (HL) until termination, max len.in B.
RDSMX  = $120E	; Copy text from "window" (see DSPMX) to (HL) 

DELTC  = $0FAB	; DELETE		- CTRL/H
TABLT  = $1158	; TAB			- CTRL/I
TABLAT = $115A	; Tabulation (in A)
LFEED  = $10F0	; LF			- CTRL/J
CRET   = $13CD	; CR			- CTRL/B
CRETL  = $10ED	; CR+LF			- CTRL/M
HOMEP  = $13B6	; HOME cursor		- CTRL/K
MVACS  = $13DD	; Move cursor at (D,E)
STPCU  = $1100	; Position cursor
LFTAW  = $10FF	; Left			- CTRL/+
RGTAW  = $10FC	; Right			- CTRL/*
UPRAW  = $10F9	; Up			- CTRL/@
LWRAW  = $10F6	; Down			- CTRL/?
STPCUL = $1134	; Move left
STPCUR = $1116	; Move right
STPCUU = $1147	; Move up
STPCUD = $1126	; Move down
SIFTD  = $103C	; Insert line at position E (0-22)
SCRLF  = $130A	; Scroll screen left	- CTRL/D
SCRRG  = $12F9	; Scroll screen right	- CTRL/F
SCRUP  = $12B3	; Scroll screen up	- CTRL/E
SCRDW  = $12BF	; Scroll screen down	- CTRL/C
STOVRM = $0F19	; Overwrite mode	- CTRL/O
STINSM = $0F1E	; Insert mode		- CTRL/P
SCTOSD = $13D5	; 			- CTRL/B
SNTOSD = $13DA	; 			- CTRL/N

EDTLN  = $0668	; 
EDTST  = $0689	; 
ACEST  = $066F	; 

CANCL  = $13BB	; Delete right characters  - CTRL/X
CLRSC  = $1393	; CLS 			- CTRL/L
CLRSCX = $1394	; CLS filling the screen with the character code specified in A
CLRSS  = $137E	; Resume normal VIEW, wipe the screen and its sprites. (only from/to text mode)
CLRSS2 = $1381	; Resume normal VIEW, wipe the screen and its sprites.


; Sprites

STSCHR = $0E58	; 
MAGFY  = $04C5	; 
STSCOD = $0454	; 
STSCOL = $0445	;
GTSPOS = $042B	;
MVSPA  = $03CE	; Get physical sprite pos. In: A=spr.#, (HL,DE)=logical pos.  Out: (D,E), B=ECB (7 bit)
MVSPR  = $040B	; Move sprite. In: A=spr.#, B,C = X,Y increment (+/- 127). Out: (HL,DE)=logical pos.
ERSSPR = $03CC	; Delete sprite # specified in A.
DELSPR = $03C5	; Hide sprite # specified in A.
ERSPRA = $1387	; Delete all the sprites

GTSPLC = $03EE	; Compute physical position (D,E) basing on a logical one (HL,DE). Input B= ECB
GTSPRC = $0377	; Compute logical position (HL,DE) basing on a physical one (D,E). Output B= ECB
ADDVCT = $041B	; 
GTSTEP = $049F	; 
GTSATA = $0369	; Get sprite table. In: A= spr. #   Out: HL=VRAM address


; RAM and VRAM

PBVRID = $0010	; VPOKE (HL),A.  Uses DI.  RST call is possible.
GBVRID = $0018	; A=VPEEK (HL).  Uses DI.  RST call is possible.
PBVRAM = $14BD	; VPOKE (HL),A. (no DI)
GBVRAM = $14C5	; A=VPEEK (HL). (no DI)
WDVPM  = $1460	; RAM (HL) to VRAM (DE) copy of max 256 bytes (B).
CVTIR  = $0E61	; RAM (HL) to VRAM (DE) copy of max 16384 bytes (BC).
RDVPM  = $144B	; VRAM (HL) to RAM (DE) copy of max 256 bytes (B).
VCTIR  = $0E7D	; VRAM (HL) to RAM (DE) copy of max 16384 bytes (BC).
BLKMV  = $0B75	; VRAM (HL) to VRAM (DE) copy of max 16384 bytes (BC).
BLKMV2 = $0B81	; VRAM (HL) to VRAM (DE) copy of max 2048 bytes.
BLKMVC = $0DCB	; VRAM (HL) to VRAM (DE) copy and invert max 16384 bytes (BC).
PADVRM = $0E01	; Fill BC bytes in VRAM (at location HL) with the byte specified in A.
PAD    = $0861	; Fill BC bytes in RAM (at location HL) with the byte specified in A.
NULPAD = $0860	; Fill BC bytes in RAM (at location HL) with 0.
EXCLOP = $0E49	; Swap two memory blocks in RAM. Input: HL - beginning of block 1, DE - beginning of block 2, BC - block length


; Keyboard

SCNKB  = $0966	; Scan keyboard. Output: A=key code, B=AKI
ACECH0 = $0827	;
ACECHI = $0845	; Get char from keyboard buffer. Output: A=ASCII code (CY if no key), B=AKI
CALKAD = $097B	; 
DECTR  = $090B	; 
DECFN  = $0933	; 
DECAD  = $08DA	; 

WTKDTC = $0756	; Wait for keypress. Output: A=ASCII code, B=AKI
CHKYM  = $073F	; 
STDM1  = $04FF	; 
CLKBF  = $077B	; 
ACELN  = $07A9	; Read line long max B bytes, put in HL


; System

CTCINT  = $01C2	; Initialize the Z80 CTC
STSCLK  = $02CF	; Set Real-Time Clock. Input: A=hours, H=minutes, L=seconds
GTSCLK  = $02DB	; Read Real-Time Clock. Output: A=hours, H=minutes, L=seconds
STRTUC  = $02FB	; Init UPCOUNTER (A=time constant)
STOPUC  = $0313	; Stop UPCOUNTER
RSTRUC  = $030D	; Restart UPCOUNTER
STRTDC  = $0319	; Init DOWNCOUNTER (A=time constant)
STOPDC  = $0340	; Stop DOWNCOUNTER
RSTRDC  = $0336	; Restart DOWNCOUNTER
CLOCKSP = $0242	; 


; Tape

RDFID  = $1598	; 
RFIDC  = $1587	; 
BLOAD  = $153B	; 
BLODD  = $1579	; 
RATBLF = $164D	; 
RATBL  = $1650	; 
LOADC  = $1652	; 

WTFID  = $15C3	; 
BSAVE  = $1529	; 
BSAVD  = $1563	; 
WATBL  = $15EB	; 
WATBLF = $15E8	; 
STROC  = $15ED	; 

STBYT  = $1626	; 
OUTPS  = $163A	; 
LDBYT  = $16B3	; 
SRLAD  = $16D1	; 
WAITST = $1717	; 
RDCNT  = $1739	; 
CPFNM  = $1765	; 
MTRON  = $1776	; Motor ON
MTROF  = $177E	; Motor OFF
LFTBC  = $1556	; 
BTCMT  = $010D	; 


; Soundchip (SML)

SGINT  = $1811	; Full SML initialization
MPLAY  = $1861	; Serviced control of SML (connected to CTC channel #3)
PLAY   = $186F	; Operate SML
NOTA   = $191A	; Play note
V0FAC  = $1A31	; Switch off all the three SGC channels



; MSX equivalences

; Accessing to the VDP (T19918)

RDVRM  = $0018 ; GBVRID - Reads the VRAM address by [HL].
WRTVRM = $0010 ; PBVRID - Write to the VRAM address by [HL].
SETRD  = $14A1 ; STVRAD - Sets up the VDP for read.
SETWRT = $149F ; STVWAD - Sets up the VDP for write.
FILVRM = $0E01 ; PADVRM - Fill the vram with specified data
LDIRMV = $0E7D ; VCTIR - Block transfer to memory from VRAM
LDIRVM = $0E61 ; CVTIR - Block transfer to VRAM from memory
CLRSPR = $1387 ; ERSPRA - Initializes all sprites.
INITXT = $0D04 ; TMODE - Initializes screen for text mode (40*24) and sets the VDP.
INIT32 = $0DD8 ; CMODE - Initializes screen for text mode (32*24) and sets the VDP.
INIGRP = $0B1F ; GMODE - Initializes screen for high-resolution mode and sets the VDP.
INIMLT = $0C44 ; MMODE - Initializes screen for multi-color mode and sets the VDP.


; Accessing to the PSG.

GICINI = $1811 ; SGINT - Initializes PSG (SML),and static data for PLAY


; Console (i.e. the keyboard and the CRT)

CHGET  = $0845 ; ACECHI - Waits for character being input and returns the character codes.
CHPUT  = $1083 ; DSPCH - (w/CTRL codes) Outputs a character to the console.
BEEP   = $1176 ; BEL - Sounds the buffer
