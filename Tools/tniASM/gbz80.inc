/;
/; tniASM GBZ80 definition file v1.0
\; by Albert Beevendorp and Patriek Lesparre
\;

%macro NOP              \%def8 00h\ %endmacro
%macro LD BC,%n         \%def8 01h\%def16 #1\ %endmacro
%macro LD [BC],A        \%def8 02h\ %endmacro
%macro INC BC           \%def8 03h\ %endmacro
%macro INC B            \%def8 04h\ %endmacro
%macro DEC B            \%def8 05h\ %endmacro
%macro LD B,%n          \%def8 06h,#1\ %endmacro
%macro RLCA             \%def8 07h\ %endmacro
%macro EX AF,AF'        \%def8 08h\ %endmacro
%macro ADD HL,BC        \%def8 09h\ %endmacro
%macro LD A,[BC]        \%def8 0Ah\ %endmacro
%macro DEC BC           \%def8 0Bh\ %endmacro
%macro INC C            \%def8 0Ch\ %endmacro
%macro DEC C            \%def8 0Dh\ %endmacro
%macro LD C,%n          \%def8 0Eh,#1\ %endmacro
%macro RRCA             \%def8 0Fh\ %endmacro

%macro STOP             \%def16 10h\ %endmacro
%macro LD DE,%n         \%def8 11h\%def16 #1\ %endmacro
%macro LD [DE],A        \%def8 12h\ %endmacro
%macro INC DE           \%def8 13h\ %endmacro
%macro INC D            \%def8 14h\ %endmacro
%macro DEC D            \%def8 15h\ %endmacro
%macro LD D,%n          \%def8 16h,#1\ %endmacro
%macro RLA              \%def8 17h\ %endmacro
%macro JR %n
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 18h
  %def8 #1-($+1)
 %else
  %def16 0
  %error "Relative jump out of range"
 %endif
%endmacro
%macro ADD HL,DE        \%def8 19h\ %endmacro
%macro LD A,[DE]        \%def8 1Ah\ %endmacro
%macro DEC DE           \%def8 1Bh\ %endmacro
%macro INC E            \%def8 1Ch\ %endmacro
%macro DEC E            \%def8 1Dh\ %endmacro
%macro LD E,%n          \%def8 1Eh,#1\ %endmacro
%macro RRA              \%def8 1Fh\ %endmacro

%macro JR NZ,%n
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 20h,#1-($+1)
 %else
  %def16 0
  %error "Relative jump out of range"
 %endif
%endmacro
%macro LD HL,%n         \%def8 21h\%def16 #1\ %endmacro
%macro LDI [HL],A       \%def8 22h\ %endmacro
%macro INC HL           \%def8 23h\ %endmacro
%macro INC H            \%def8 24h\ %endmacro
%macro DEC H            \%def8 25h\ %endmacro
%macro LD H,%n          \%def8 26h,#1\ %endmacro
%macro DAA              \%def8 27h\ %endmacro
%macro JR Z,%n
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 28h,#1-($+1)
 %else
  %def16 0
  %error "Relative jump out of range"
 %endif
%endmacro
%macro ADD HL,HL        \%def8 29h\ %endmacro
%macro LDI A,[HL]       \%def8 2Ah\ %endmacro
%macro DEC HL           \%def8 2Bh\ %endmacro
%macro INC L            \%def8 2Ch\ %endmacro
%macro DEC L            \%def8 2Dh\ %endmacro
%macro LD L,%n          \%def8 2Eh,#1\ %endmacro
%macro CPL              \%def8 2Fh\ %endmacro

%macro JR NC,%n
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 30h,#1-($+1)
 %else
  %def16 0
  %error "Relative jump out of range"
 %endif
%endmacro
%macro LD SP,%n         \%def8 31h\%def16 #1\ %endmacro
%macro LDD [HL],A       \%def8 32h\ %endmacro
%macro INC SP           \%def8 33h\ %endmacro
%macro INC [HL]         \%def8 34h\ %endmacro
%macro DEC [HL]         \%def8 35h\ %endmacro
%macro LD [HL],%n       \%def8 36h,#1\ %endmacro
%macro SCF              \%def8 37h\ %endmacro
%macro JR C,%n
 %if (#1-($+2) <= 127) & (#1-($+2) >= -128)
  %def8 38h,#1-($+1)
 %else
  %def16 0
  %error "Relative jump out of range"
 %endif
%endmacro
%macro ADD HL,SP        \%def8 39h\ %endmacro
%macro LDD A,[HL]       \%def8 3Ah\ %endmacro
%macro DEC SP           \%def8 3Bh\ %endmacro
%macro INC A            \%def8 3Ch\ %endmacro
%macro DEC A            \%def8 3Dh\ %endmacro
%macro LD A,%n          \%def8 3Eh,#1\ %endmacro
%macro CCF              \%def8 3Fh\ %endmacro

%macro LD B,B           \%def8 40h\ %endmacro
%macro LD B,C           \%def8 41h\ %endmacro
%macro LD B,D           \%def8 42h\ %endmacro
%macro LD B,E           \%def8 43h\ %endmacro
%macro LD B,H           \%def8 44h\ %endmacro
%macro LD B,L           \%def8 45h\ %endmacro
%macro LD B,[HL]        \%def8 46h\ %endmacro
%macro LD B,A           \%def8 47h\ %endmacro
%macro LD C,B           \%def8 48h\ %endmacro
%macro LD C,C           \%def8 49h\ %endmacro
%macro LD C,D           \%def8 4Ah\ %endmacro
%macro LD C,E           \%def8 4Bh\ %endmacro
%macro LD C,H           \%def8 4Ch\ %endmacro
%macro LD C,L           \%def8 4Dh\ %endmacro
%macro LD C,[HL]        \%def8 4Eh\ %endmacro
%macro LD C,A           \%def8 4Fh\ %endmacro

%macro LD D,B   	\%def8 50h\ %endmacro
%macro LD D,C   	\%def8 51h\ %endmacro
%macro LD D,D   	\%def8 52h\ %endmacro
%macro LD D,E   	\%def8 53h\ %endmacro
%macro LD D,H   	\%def8 54h\ %endmacro
%macro LD D,L   	\%def8 55h\ %endmacro
%macro LD D,[HL]        \%def8 56h\ %endmacro
%macro LD D,A   	\%def8 57h\ %endmacro
%macro LD E,B   	\%def8 58h\ %endmacro
%macro LD E,C   	\%def8 59h\ %endmacro
%macro LD E,D   	\%def8 5Ah\ %endmacro
%macro LD E,E   	\%def8 5Bh\ %endmacro
%macro LD E,H   	\%def8 5Ch\ %endmacro
%macro LD E,L   	\%def8 5Dh\ %endmacro
%macro LD E,[HL]        \%def8 5Eh\ %endmacro
%macro LD E,A   	\%def8 5Fh\ %endmacro

%macro LD H,B   	\%def8 60h\ %endmacro
%macro LD H,C   	\%def8 61h\ %endmacro
%macro LD H,D   	\%def8 62h\ %endmacro
%macro LD H,E   	\%def8 63h\ %endmacro
%macro LD H,H   	\%def8 64h\ %endmacro
%macro LD H,L   	\%def8 65h\ %endmacro
%macro LD H,[HL]        \%def8 66h\ %endmacro
%macro LD H,A   	\%def8 67h\ %endmacro
%macro LD L,B   	\%def8 68h\ %endmacro
%macro LD L,C   	\%def8 69h\ %endmacro
%macro LD L,D   	\%def8 6Ah\ %endmacro
%macro LD L,E   	\%def8 6Bh\ %endmacro
%macro LD L,H   	\%def8 6Ch\ %endmacro
%macro LD L,L   	\%def8 6Dh\ %endmacro
%macro LD L,[HL]        \%def8 6Eh\ %endmacro
%macro LD L,A   	\%def8 6Fh\ %endmacro

%macro LD [HL],B        \%def8 70h\ %endmacro
%macro LD [HL],C        \%def8 71h\ %endmacro
%macro LD [HL],D        \%def8 72h\ %endmacro
%macro LD [HL],E        \%def8 73h\ %endmacro
%macro LD [HL],H        \%def8 74h\ %endmacro
%macro LD [HL],L        \%def8 75h\ %endmacro
%macro HALT             \%def8 76h\ %endmacro
%macro LD [HL],A        \%def8 77h\ %endmacro
%macro LD A,B   	\%def8 78h\ %endmacro
%macro LD A,C   	\%def8 79h\ %endmacro
%macro LD A,D   	\%def8 7Ah\ %endmacro
%macro LD A,E   	\%def8 7Bh\ %endmacro
%macro LD A,H   	\%def8 7Ch\ %endmacro
%macro LD A,L   	\%def8 7Dh\ %endmacro
%macro LD A,[HL]        \%def8 7Eh\ %endmacro
%macro LD A,A   	\%def8 7Fh\ %endmacro

%macro ADD A,B  	\%def8 80h\ %endmacro
%macro ADD A,C  	\%def8 81h\ %endmacro
%macro ADD A,D  	\%def8 82h\ %endmacro
%macro ADD A,E  	\%def8 83h\ %endmacro
%macro ADD A,H  	\%def8 84h\ %endmacro
%macro ADD A,L  	\%def8 85h\ %endmacro
%macro ADD A,[HL]       \%def8 86h\ %endmacro
%macro ADD A,A  	\%def8 87h\ %endmacro
%macro ADC A,B  	\%def8 88h\ %endmacro
%macro ADC A,C  	\%def8 89h\ %endmacro
%macro ADC A,D  	\%def8 8Ah\ %endmacro
%macro ADC A,E  	\%def8 8Bh\ %endmacro
%macro ADC A,H  	\%def8 8Ch\ %endmacro
%macro ADC A,L  	\%def8 8Dh\ %endmacro
%macro ADC A,[HL]       \%def8 8Eh\ %endmacro
%macro ADC A,A  	\%def8 8Fh\ %endmacro

%macro SUB B    	\%def8 90h\ %endmacro
%macro SUB C    	\%def8 91h\ %endmacro
%macro SUB D    	\%def8 92h\ %endmacro
%macro SUB E    	\%def8 93h\ %endmacro
%macro SUB H    	\%def8 94h\ %endmacro
%macro SUB L    	\%def8 95h\ %endmacro
%macro SUB [HL] 	\%def8 96h\ %endmacro
%macro SUB A    	\%def8 97h\ %endmacro
%macro SBC A,B  	\%def8 98h\ %endmacro
%macro SBC A,C  	\%def8 99h\ %endmacro
%macro SBC A,D  	\%def8 9Ah\ %endmacro
%macro SBC A,E  	\%def8 9Bh\ %endmacro
%macro SBC A,H  	\%def8 9Ch\ %endmacro
%macro SBC A,L  	\%def8 9Dh\ %endmacro
%macro SBC A,[HL]       \%def8 9Eh\ %endmacro
%macro SBC A,A  	\%def8 9Fh\ %endmacro

%macro AND B    	\%def8 A0h\ %endmacro
%macro AND C    	\%def8 A1h\ %endmacro
%macro AND D    	\%def8 A2h\ %endmacro
%macro AND E    	\%def8 A3h\ %endmacro
%macro AND H    	\%def8 A4h\ %endmacro
%macro AND L    	\%def8 A5h\ %endmacro
%macro AND [HL] 	\%def8 A6h\ %endmacro
%macro AND A    	\%def8 A7h\ %endmacro
%macro XOR B    	\%def8 A8h\ %endmacro
%macro XOR C    	\%def8 A9h\ %endmacro
%macro XOR D    	\%def8 AAh\ %endmacro
%macro XOR E    	\%def8 ABh\ %endmacro
%macro XOR H    	\%def8 ACh\ %endmacro
%macro XOR L    	\%def8 ADh\ %endmacro
%macro XOR [HL] 	\%def8 AEh\ %endmacro
%macro XOR A    	\%def8 AFh\ %endmacro

%macro OR B             \%def8 B0h\ %endmacro
%macro OR C             \%def8 B1h\ %endmacro
%macro OR D             \%def8 B2h\ %endmacro
%macro OR E             \%def8 B3h\ %endmacro
%macro OR H             \%def8 B4h\ %endmacro
%macro OR L             \%def8 B5h\ %endmacro
%macro OR [HL]  	\%def8 B6h\ %endmacro
%macro OR A             \%def8 B7h\ %endmacro
%macro CP B             \%def8 B8h\ %endmacro
%macro CP C             \%def8 B9h\ %endmacro
%macro CP D             \%def8 BAh\ %endmacro
%macro CP E             \%def8 BBh\ %endmacro
%macro CP H             \%def8 BCh\ %endmacro
%macro CP L             \%def8 BDh\ %endmacro
%macro CP [HL]  	\%def8 BEh\ %endmacro
%macro CP A             \%def8 BFh\ %endmacro

%macro RET NZ   	\%def8 C0h\ %endmacro
%macro POP BC   	\%def8 C1h\ %endmacro
%macro JP NZ,%n 	\%def8 C2h\%def16 #1\ %endmacro
%macro JP %n    	\%def8 C3h\%def16 #1\ %endmacro
%macro CALL NZ,%n       \%def8 C4h\%def16 #1\ %endmacro
%macro PUSH BC  	\%def8 C5h\ %endmacro
%macro ADD A,%n 	\%def8 C6h,#1\ %endmacro
%macro RST %n
  %if #1 & C7h
    %error "Illegal RST"
    %def8 0
  %else
    %def8 C7h|#1
  %endif
%endmacro
%macro RET Z    	\%def8 C8h\ %endmacro
%macro RET              \%def8 C9h\ %endmacro
%macro JP Z,%n  	\%def8 CAh\%def16 #1\ %endmacro
%macro CALL Z,%n        \%def8 CCh\%def16 #1\ %endmacro
%macro CALL %n  	\%def8 CDh\%def16 #1\ %endmacro
%macro ADC A,%n 	\%def8 CEh,#1\ %endmacro

%macro RET NC   	\%def8 D0h\ %endmacro
%macro POP DE   	\%def8 D1h\ %endmacro
%macro JP NC,%n 	\%def8 D2h\%def16 #1\ %endmacro
%macro CALL NC,%n       \%def8 D4h\%def16 #1\ %endmacro
%macro PUSH DE  	\%def8 D5h\ %endmacro
%macro SUB %n   	\%def8 D6h,#1\ %endmacro
%macro RET C    	\%def8 D8h\ %endmacro
%macro RETI             \%def8 D9h\ %endmacro
%macro JP C,%n  	\%def8 DAh\%def16 #1\ %endmacro
%macro CALL C,%n        \%def8 DCh\%def16 #1\ %endmacro
%macro SBC A,%n 	\%def8 DEh,#1\ %endmacro

%macro LDH [%n],A
  %if (#1 < 100h) | (#1 >= FF00h)
    %def8 E0h,#1 & FFh
  %else
    %error "Address not in high memory"
  %endif
%endmacro
%macro OUT [%n],A	\LDH [#1],A\ %endmacro
%macro POP HL   	\%def8 E1h\ %endmacro
%macro LDH [C],A 	\%def8 E2h\ %endmacro
%macro OUT [C],A	\LDH [C],A\ %endmacro
%macro PUSH HL  	\%def8 E5h\ %endmacro
%macro AND %n   	\%def8 E6h,#1\ %endmacro
%macro LD SP,SP%n	\%def8 E8h,#1\ %endmacro
%macro JP [HL]  	\%def8 E9h\ %endmacro
%macro LD [%n],A 	\%def8 EAh\%def16 #1\ %endmacro
%macro XOR %n   	\%def8 EEh\%def8 #1\ %endmacro

%macro LDH A,[%n]
  %if (#1 < 100h) | (#1 >= FF00h)
    %def8 F0h,#1 & FFh
  %else
    %error "Address not in high memory"
  %endif
%endmacro
%macro IN A,[%n]	\LDH A,[#1]\ %endmacro
%macro POP AF   	\%def8 F1h\ %endmacro
%macro LDH A,[C]  	\%def8 F2h\ %endmacro
%macro IN A,[C]		\LDH A,[C]\ %endmacro
%macro DI               \%def8 F3h\ %endmacro
%macro CALL P,%n        \%def8 F4h\%def16 #1\ %endmacro
%macro PUSH AF  	\%def8 F5h\ %endmacro
%macro OR %n    	\%def8 F6h,#1\ %endmacro
%macro LD HL,SP%n    	\%def8 F8h,#1\ %endmacro
%macro LD SP,HL 	\%def8 F9h\ %endmacro
%macro LD A,[%n]  	\%def8 FAh\%def16 #1\ %endmacro
%macro EI               \%def8 FBh\ %endmacro
%macro CALL M,%n        \%def8 FCh\%def16 #1\ %endmacro
%macro CP %n    	\%def8 FEh,#1\ %endmacro

%macro RLC B    \%def16 00CBh\ %endmacro
%macro RLC C    \%def16 01CBh\ %endmacro
%macro RLC D    \%def16 02CBh\ %endmacro
%macro RLC E    \%def16 03CBh\ %endmacro
%macro RLC H    \%def16 04CBh\ %endmacro
%macro RLC L    \%def16 05CBh\ %endmacro
%macro RLC [HL] \%def16 06CBh\ %endmacro
%macro RLC A    \%def16 07CBh\ %endmacro
%macro RRC B    \%def16 08CBh\ %endmacro
%macro RRC C    \%def16 09CBh\ %endmacro
%macro RRC D    \%def16 0ACBh\ %endmacro
%macro RRC E    \%def16 0BCBh\ %endmacro
%macro RRC H    \%def16 0CCBh\ %endmacro
%macro RRC L    \%def16 0DCBh\ %endmacro
%macro RRC [HL] \%def16 0ECBh\ %endmacro
%macro RRC A    \%def16 0FCBh\ %endmacro

%macro RL B             \%def16 10CBh\ %endmacro
%macro RL C             \%def16 11CBh\ %endmacro
%macro RL D             \%def16 12CBh\ %endmacro
%macro RL E             \%def16 13CBh\ %endmacro
%macro RL H             \%def16 14CBh\ %endmacro
%macro RL L             \%def16 15CBh\ %endmacro
%macro RL [HL]  	\%def16 16CBh\ %endmacro
%macro RL A             \%def16 17CBh\ %endmacro
%macro RR B             \%def16 18CBh\ %endmacro
%macro RR C             \%def16 19CBh\ %endmacro
%macro RR D             \%def16 1ACBh\ %endmacro
%macro RR E             \%def16 1BCBh\ %endmacro
%macro RR H             \%def16 1CCBh\ %endmacro
%macro RR L             \%def16 1DCBh\ %endmacro
%macro RR [HL]  	\%def16 1ECBh\ %endmacro
%macro RR A             \%def16 1FCBh\ %endmacro

%macro SLA B    \%def16 20CBh\ %endmacro
%macro SLA C    \%def16 21CBh\ %endmacro
%macro SLA D    \%def16 22CBh\ %endmacro
%macro SLA E    \%def16 23CBh\ %endmacro
%macro SLA H    \%def16 24CBh\ %endmacro
%macro SLA L    \%def16 25CBh\ %endmacro
%macro SLA [HL] \%def16 26CBh\ %endmacro
%macro SLA A    \%def16 27CBh\ %endmacro
%macro SRA B    \%def16 28CBh\ %endmacro
%macro SRA C    \%def16 29CBh\ %endmacro
%macro SRA D    \%def16 2ACBh\ %endmacro
%macro SRA E    \%def16 2BCBh\ %endmacro
%macro SRA H    \%def16 2CCBh\ %endmacro
%macro SRA L    \%def16 2DCBh\ %endmacro
%macro SRA [HL] \%def16 2ECBh\ %endmacro
%macro SRA A    \%def16 2FCBh\ %endmacro

%macro SWAP B           \%def16 30CBh\ %endmacro
%macro SWAP C           \%def16 31CBh\ %endmacro
%macro SWAP D           \%def16 32CBh\ %endmacro
%macro SWAP E           \%def16 33CBh\ %endmacro
%macro SWAP H           \%def16 34CBh\ %endmacro
%macro SWAP L           \%def16 35CBh\ %endmacro
%macro SWAP [HL]        \%def16 36CBh\ %endmacro
%macro SWAP A           \%def16 37CBh\ %endmacro

%macro SRL B    \%def16 38CBh\ %endmacro
%macro SRL C    \%def16 39CBh\ %endmacro
%macro SRL D    \%def16 3ACBh\ %endmacro
%macro SRL E    \%def16 3BCBh\ %endmacro
%macro SRL H    \%def16 3CCBh\ %endmacro
%macro SRL L    \%def16 3DCBh\ %endmacro
%macro SRL [HL] \%def16 3ECBh\ %endmacro
%macro SRL A    \%def16 3FCBh\ %endmacro

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
%macro BIT %n,A
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,47h+8*#1
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
%macro RES %n,A
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,87h+8*#1
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
%macro SET %n,A
  %if (#1 >= 0) & (#1 < 8)
    %def8 CBh,C7h+8*#1
  %else
    %def16 0
    %error "Illegal bit number"
  %endif
%endmacro
